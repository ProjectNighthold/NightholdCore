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

#include "PointMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "World.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "Player.h"
#include "ScriptMgr.h"

//----- Point Movement Generator
template<class T>
void PointMovementGenerator<T>::DoInitialize(T &unit)
{
    if (!unit.IsStopped())
        unit.StopMoving();

    unit.AddUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE);
    i_recalculateSpeed = false;
    Movement::MoveSplineInit init(unit);
    if (unit.GetTransport())
        init.DisableTransportPathTransformations();
    init.MoveTo(i_x, i_y, i_z, m_generatePath);
    if (speed > 0.0f)
        init.SetVelocity(speed);
    if (angle != -1000.0f)
        init.SetFacing(angle);
    init.Launch();
}

template<class T>
bool PointMovementGenerator<T>::DoUpdate(T &unit, const uint32 & /*diff*/)
{
    if (!&unit)
        return false;

    if (unit.HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED))
    {
        unit.ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        return true;
    }

    unit.AddUnitState(UNIT_STATE_ROAMING_MOVE);

    if (!unit.movespline->Finalized())
    {
        if (unit.IsStopped() || (unit.IsCreature() && unit.ToCreature()->GetReactState() != REACT_PASSIVE && unit.isInCombat()))
            i_restartMove = true;

        if (!unit.IsStopped() && (i_recalculateSpeed || (i_restartMove && !unit.isInCombat())))
        {
            i_recalculateSpeed = false;
            i_restartMove = false;
            Movement::MoveSplineInit init(unit);
            init.MoveTo(i_x, i_y, i_z, m_generatePath);
            if (speed > 0.0f) // Default value for point motion type is 0.0, if 0.0 spline will use GetSpeed on unit
                init.SetVelocity(speed);
            init.Launch();
        }
    }

    return !unit.movespline->Finalized();
}

template<class T>
void PointMovementGenerator<T>::DoFinalize(T &unit)
{
    unit.ClearUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE);

    if (unit.movespline->Finalized())
        MovementInform(unit);
    if (unit.IsPlayer() && unit.IsInWorld())
        unit.UpdatePosition(i_x, i_y, i_z, unit.GetOrientation(), false);
}

template<class T>
void PointMovementGenerator<T>::DoReset(T &unit)
{
    if (!unit.IsStopped())
        unit.StopMoving();

    unit.AddUnitState(UNIT_STATE_ROAMING|UNIT_STATE_ROAMING_MOVE);
}

template<class T>
void PointMovementGenerator<T>::MovementInform(T& unit)
{ }

template <>
void PointMovementGenerator<Player>::MovementInform(Player& unit)
{
    sScriptMgr->OnMovementInform(&unit, POINT_MOTION_TYPE, id);
}

template <> void PointMovementGenerator<Creature>::MovementInform(Creature &unit)
{
    if (unit.AI())
        unit.AI()->MovementInform(POINT_MOTION_TYPE, id);
}

template void PointMovementGenerator<Player>::DoInitialize(Player&);
template void PointMovementGenerator<Creature>::DoInitialize(Creature&);
template void PointMovementGenerator<Player>::DoFinalize(Player&);
template void PointMovementGenerator<Creature>::DoFinalize(Creature&);
template void PointMovementGenerator<Player>::DoReset(Player&);
template void PointMovementGenerator<Creature>::DoReset(Creature&);
template bool PointMovementGenerator<Player>::DoUpdate(Player &, const uint32 &);
template bool PointMovementGenerator<Creature>::DoUpdate(Creature&, const uint32 &);

void AssistanceMovementGenerator::DoFinalize(Unit &unit)
{
    unit.ToCreature()->SetNoCallAssistance(false);
    unit.ToCreature()->CallAssistance();
    if (unit.isAlive())
        unit.GetMotionMaster()->MoveSeekAssistanceDistract(sWorld->getIntConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_DELAY));
}

bool EffectMovementGenerator::Update(Unit &unit, const uint32&)
{
    return !unit.movespline->Finalized();
}

void EffectMovementGenerator::Finalize(Unit &unit)
{
    if (!unit.IsCreature() && !unit.IsPlayer())
        return;

    unit.ClearUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE);

    if (((Creature&)unit).AI())
        ((Creature&)unit).AI()->MovementInform(EFFECT_MOTION_TYPE, m_Id);
    if (!unit.GetTransport())
        if (unit.IsPlayer() && unit.IsInWorld())
            unit.UpdatePosition(i_x, i_y, i_z, unit.GetOrientation(), false);

    // Effect event. Used for delay cast after jump for example
    if (m_event)
    {
        m_event->Execute(&unit);
        delete m_event;
        m_event = nullptr;
    }
}

//----- Charge Movement Generator
void ChargeMovementGenerator::_setTargetLocation(Unit &unit)
{
    if(!i_path)
        i_path = new PathGenerator(&unit);

    bool forceDest = unit.m_movementInfo.HasMovementFlag(MOVEMENTFLAG_FALLING | MOVEMENTFLAG_FALLING_FAR);
    if (forceDest)
    {
        float x, y, z;
        unit.GetPosition(x, y, z);
        float ground = unit.GetHeight(x, y, z, true);
        if ((z - ground) < 2.0f)
            forceDest = false;
    }
    if (unit.IsInWater())
        forceDest = true;

    i_path->_charges = true;

    if (forceDest)
        i_path->CalculateShortcutPath(i_x, i_y, i_z);
    else
        i_path->CalculatePath(i_x, i_y, i_z, false);

    if (i_path->GetPathType() & PATHFIND_NOPATH)
        return;

    if (i_path->GetTotalLength() > 40)
        return;

    i_targetReached = false;
    i_recalculateTravel = false;

    Movement::MoveSplineInit init(unit);
    if (i_path->GetPathType() & PATHFIND_NOPATH)
        init.MoveTo(i_x, i_y, i_z);
    else
        init.MovebyPath(i_path->GetPath());
    if (speed > 0.0f)
        init.SetVelocity(speed);
    init.Launch();
}

bool ChargeMovementGenerator::Update(Unit &unit, const uint32&)
{
    return !unit.movespline->Finalized();
}

void ChargeMovementGenerator::Initialize(Unit &unit)
{
    //TC_LOG_DEBUG(LOG_FILTER_SPELLS_AURAS, "ChargeMovementGenerator Initialize (%f %f %f)", i_x, i_y, i_z);

    if (!unit.IsStopped())
        unit.StopMoving();

    unit.AddUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE | UNIT_STATE_CHARGING);
    _setTargetLocation(unit);
}

void ChargeMovementGenerator::Finalize(Unit &unit)
{
    if (!unit.IsCreature() && !unit.IsPlayer())
        return;

    //TC_LOG_DEBUG(LOG_FILTER_SPELLS_AURAS, "ChargeMovementGenerator Finalize (%f %f %f) spellId %i", i_x, i_y, i_z, triggerspellId);

    unit.ClearUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE | UNIT_STATE_CHARGING);

    if (((Creature&)unit).AI())
        ((Creature&)unit).AI()->MovementInform(POINT_MOTION_TYPE, m_Id);
    if (unit.IsPlayer() && unit.IsInWorld())
        unit.UpdatePosition(i_x, i_y, i_z, unit.GetOrientation(), false);

    if(triggerspellId)
        unit.CastSpell(i_x, i_y, i_z, triggerspellId, true);
}