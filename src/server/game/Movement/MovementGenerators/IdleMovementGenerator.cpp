/*
 *###############################################################################
 *#                                                                             #
 *# Copyright (C) 2022 Project Nighthold <https://github.com/ProjectNighthold>  #
 *#                                                                             #
 *# This file is free software; as a special exception the author gives         #
 *# unlimited permission to copy and/or distribute it, with or without          #
 *# modifications, as long as this notice is preserved.                         #
 *#                                                                             #
 *# This program is distributed in the hope that it will be useful, but         #
 *# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the      #
 *# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.    #
 *#                                                                             #
 *# Read the THANKS file on the source root directory for more info.            #
 *#                                                                             #
 *###############################################################################
 */

#include "IdleMovementGenerator.h"
#include "CreatureAI.h"
#include "Creature.h"

IdleMovementGenerator si_idleMovement;

// StopMoving is needed to make unit stop if its last movement generator expires
// But it should not be sent otherwise there are many redundent packets
void IdleMovementGenerator::Initialize(Unit &owner)
{
    Reset(owner);
}

void IdleMovementGenerator::Reset(Unit& owner)
{
    if (!owner.IsStopped())
        owner.StopMoving();
}

void RotateMovementGenerator::Initialize(Unit& owner)
{
    if (!owner.IsStopped())
        owner.StopMoving();

    if (owner.getVictim())
        owner.SetInFront(owner.getVictim());

    owner.AddUnitState(UNIT_STATE_ROTATING);

    owner.AttackStop();
}

bool RotateMovementGenerator::Update(Unit& owner, const uint32& diff)
{
    float angle = owner.GetOrientation();
    if (m_direction == ROTATE_DIRECTION_LEFT)
    {
        angle += (float)diff * static_cast<float>(M_PI * 2) / m_maxDuration;
        while (angle >= static_cast<float>(M_PI * 2)) angle -= static_cast<float>(M_PI * 2);
    }
    else
    {
        angle -= (float)diff * static_cast<float>(M_PI * 2) / m_maxDuration;
        while (angle < 0) angle += static_cast<float>(M_PI * 2);
    }

    owner.SetFacingTo(angle);

    if (m_duration > diff)
        m_duration -= diff;
    else if (repeat)
        m_duration = m_maxDuration;
    else
        return false;

    return true;
}

void RotateMovementGenerator::Finalize(Unit &unit)
{
    unit.ClearUnitState(UNIT_STATE_ROTATING);
    if (unit.IsCreature())
      unit.ToCreature()->AI()->MovementInform(ROTATE_MOTION_TYPE, 0);
}

void DistractMovementGenerator::Initialize(Unit& owner)
{
    // Distracted creatures stand up if not standing
    if (!owner.IsStandState())
        owner.SetStandState(UNIT_STAND_STATE_STAND);

    owner.AddUnitState(UNIT_STATE_DISTRACTED);
}

void DistractMovementGenerator::Finalize(Unit& owner)
{
    owner.ClearUnitState(UNIT_STATE_DISTRACTED);
    owner.GetMotionMaster()->MoveTargetedHome();
}

bool DistractMovementGenerator::Update(Unit& /*owner*/, const uint32& time_diff)
{
    if (time_diff > m_timer)
        return false;

    m_timer -= time_diff;
    return true;
}

void AssistanceDistractMovementGenerator::Finalize(Unit &unit)
{
    unit.ClearUnitState(UNIT_STATE_DISTRACTED);
    unit.ToCreature()->SetReactState(REACT_AGGRESSIVE);
    if (Unit* victim = unit.getVictim())
    {
        if (unit.isAlive())
        {
            unit.AttackStop();
            if (((Creature*)&unit)->IsAIEnabled)
                ((Creature*)&unit)->AI()->AttackStart(victim);
        }
    }
}
