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

#include "GuardAI.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "World.h"
#include "CreatureAIImpl.h"
#include "ScriptedCreature.h"

int GuardAI::Permissible(Creature const* creature)
{
    if (creature->isGuard())
        return PERMIT_BASE_SPECIAL;

    return PERMIT_BASE_NO;
}

GuardAI::GuardAI(Creature* creature) : ScriptedAI(creature)
{
}

bool GuardAI::CanSeeAlways(WorldObject const* obj)
{
    if (!obj->IsUnit())
        return false;

    auto threatList = me->getThreatManager().getThreatList();
    for (std::list<HostileReference*>::const_iterator itr = threatList.begin(); itr != threatList.end(); ++itr)
        if ((*itr)->getUnitGuid() == obj->GetGUID())
            return true;

    return false;
}

void GuardAI::EnterEvadeMode()
{
    if (!me->isAlive())
    {
        me->GetMotionMaster()->MoveIdle();
        me->CombatStop(true);
        me->DeleteThreatList();
        me->ClearSaveThreatTarget();
        return;
    }

    TC_LOG_DEBUG(LOG_FILTER_UNITS, "Guard entry: %u enters evade mode.", me->GetEntry());

    me->RemoveAllAuras();
    me->DeleteThreatList();
    me->ClearSaveThreatTarget();
    me->CombatStop(true);

    // Remove ChaseMovementGenerator from MotionMaster stack list, and add HomeMovementGenerator instead
    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == CHASE_MOTION_TYPE)
        me->GetMotionMaster()->MoveTargetedHome();
}

void GuardAI::JustDied(Unit* killer)
{
    if (Player* player = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
        me->SendZoneUnderAttackMessage(player);
}
