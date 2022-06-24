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

#include "TotemAI.h"
#include "Totem.h"
#include "Creature.h"
#include "ObjectAccessor.h"
#include "SpellMgr.h"

#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "PartyPackets.h"

int TotemAI::Permissible(Creature const* creature)
{
    if (creature->isTotem())
        return PERMIT_BASE_PROACTIVE;

    return PERMIT_BASE_NO;
}

TotemAI::TotemAI(Creature* c) : CreatureAI(c)
{
    ASSERT(c->isTotem());
}

void TotemAI::InitializeAI()
{
    CreatureAI::InitializeAI();

    if (PetStats const* pStats = sObjectMgr->GetPetStats(me->GetEntry()))
        if (pStats->state)
        {
            me->SetReactState(ReactStates(pStats->state));
            if (Unit* victim = me->GetTargetUnit())
                me->Attack(victim, !me->GetCasterPet());
        }

    i_victimGuid.Clear();
}

void TotemAI::MoveInLineOfSight(Unit* /*who*/)
{ }

void TotemAI::EnterEvadeMode()
{
    me->CombatStop(true);
}

void TotemAI::UpdateAI(uint32 /*diff*/)
{
    if (me->ToTotem()->GetTotemType() != TOTEM_ACTIVE)
        return;

    if (!me->isAlive())
        return;

    // Search spell
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(me->ToTotem()->GetSpell());
    if (!spellInfo)
        return;

    Unit* owner = me->GetCharmerOrOwner();
    Unit* victim = !i_victimGuid.IsEmpty() ? ObjectAccessor::GetUnit(*me, i_victimGuid) : nullptr;
    if (!owner)
        return;

    Unit* targetOwner = owner->getAttackerForHelper();
    if (targetOwner != nullptr && targetOwner != victim && me->IsWithinDistInMap(targetOwner, spellInfo->GetMaxRange(false, me)))
    {
        victim = targetOwner;
        i_victimGuid = victim->GetGUID();
    }

    if (me->IsNonMeleeSpellCast(false))
    {
        if (victim && victim->HasCrowdControlAura())
            victim = nullptr;
        else
            return;
    }

    if (victim)
    {
        if (!owner->isInCombat())
            owner->SetInCombatWith(victim);

        me->SetInFront(victim);                         // client change orientation by self
        me->CastSpell(victim, spellInfo, false);
    }
}

void TotemAI::AttackStart(Unit* /*victim*/)
{
    if (me->GetEntry() == SENTRY_TOTEM_ENTRY && me->GetOwner()->IsPlayer())
    {
        WorldPackets::Party::MinimapPing ping;
        ping.Sender = me->GetGUID();
        ping.PositionX = me->GetPositionX();
        ping.PositionY = me->GetPositionY();
        me->GetOwner()->ToPlayer()->SendDirectMessage(ping.Write());
    }
}
