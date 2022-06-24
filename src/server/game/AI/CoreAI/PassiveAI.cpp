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

#include "PassiveAI.h"
#include "Creature.h"

PassiveAI::PassiveAI(Creature* c) : CreatureAI(c) { me->SetReactState(REACT_PASSIVE); }
PossessedAI::PossessedAI(Creature* c) : CreatureAI(c) { me->SetReactState(REACT_PASSIVE); }
NullCreatureAI::NullCreatureAI(Creature* c) : CreatureAI(c) { me->SetReactState(REACT_PASSIVE); }

void PassiveAI::UpdateAI(uint32)
{
    if (me->isInCombat() && me->getAttackers()->empty())
        EnterEvadeMode();
}

void PossessedAI::AttackStart(Unit* target)
{
    me->Attack(target, true);
}

void PossessedAI::UpdateAI(uint32 /*diff*/)
{
    if (me->getVictim())
    {
        if (!me->IsValidAttackTarget(me->getVictim()))
            me->AttackStop();
        else
            DoMeleeAttackIfReady();
    }
}

void PossessedAI::JustDied(Unit* /*u*/)
{
    // We died while possessed, disable our loot
    me->RemoveFlag(OBJECT_FIELD_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
}

void PossessedAI::KilledUnit(Unit* victim)
{
    // We killed a creature, disable victim's loot
    if (victim->IsCreature())
        victim->RemoveFlag(OBJECT_FIELD_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
}

void CritterAI::InitializeAI()
{
    if (me->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH))
        return;

    me->AddDelayedEvent(2000, [this]
    {
        auto movementType = me->GetDefaultMovementType();
        if (movementType < MAX_DB_MOTION_TYPE && movementType != WAYPOINT_MOTION_TYPE)
            me->GetMotionMaster()->MoveRandom(urand(30, 50));
    });
}

void CritterAI::EnterCombat(Unit * who)
{
    if (!me->HasUnitState(UNIT_STATE_FLEEING))
        me->GetMotionMaster()->MoveFleeing(who);
}

void CritterAI::DamageTaken(Unit* /*done_by*/, uint32&, DamageEffectType /*dmgType*/)
{
    if (!me->HasUnitState(UNIT_STATE_FLEEING))
        me->SetControlled(true, UNIT_STATE_FLEEING);
}

void CritterAI::EnterEvadeMode()
{
    if (me->HasUnitState(UNIT_STATE_FLEEING))
        me->SetControlled(false, UNIT_STATE_FLEEING);
    CreatureAI::EnterEvadeMode();
}

void CritterAI::AttackedBy(Unit * who)
{
    EnterCombat(who);
}

void TriggerAI::IsSummonedBy(Unit* summoner)
{
    if (me->m_templateSpells[0])
        me->CastSpell(me, me->m_templateSpells[0], false, nullptr, nullptr, summoner->GetGUID());
}
