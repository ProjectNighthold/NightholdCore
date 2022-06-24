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

#include "LFG.h"
#include "Language.h"
#include "ObjectMgr.h"

namespace lfg
{
LockData::LockData(): status(LFG_LOCKSTATUS_OK), currItemLevel(0), reqItemLevel(0)
{
}

std::string ConcatenateDungeons(LfgDungeonSet const& dungeons)
{
    std::string dungeonstr;
    if (!dungeons.empty())
    {
        std::ostringstream o;
        auto it = dungeons.cbegin();
        o << *it;
        for (++it; it != dungeons.end(); ++it)
            o << ", " << uint32(*it);
        dungeonstr = o.str();
    }
    return dungeonstr;
}

std::string GetRolesString(uint8 roles)
{
    std::string rolesstr;

    if (roles & PLAYER_ROLE_TANK)
        rolesstr.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_LFG_ROLE_TANK));

    if (roles & PLAYER_ROLE_HEALER)
    {
        if (!rolesstr.empty())
            rolesstr.append(", ");
        rolesstr.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_LFG_ROLE_HEALER));
    }

    if (roles & PLAYER_ROLE_DAMAGE)
    {
        if (!rolesstr.empty())
            rolesstr.append(", ");
        rolesstr.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_LFG_ROLE_DAMAGE));
    }

    if (roles & PLAYER_ROLE_LEADER)
    {
        if (!rolesstr.empty())
            rolesstr.append(", ");
        rolesstr.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_LFG_ROLE_LEADER));
    }

    if (rolesstr.empty())
        rolesstr.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_LFG_ROLE_NONE));

    return rolesstr;
}

std::string GetStateString(LfgState state)
{
    int32 entry = LANG_LFG_ERROR;
    switch (state)
    {
        case LFG_STATE_NONE:
            entry = LANG_LFG_STATE_NONE;
            break;
        case LFG_STATE_ROLECHECK:
            entry = LANG_LFG_STATE_ROLECHECK;
            break;
        case LFG_STATE_QUEUED:
            entry = LANG_LFG_STATE_QUEUED;
            break;
        case LFG_STATE_PROPOSAL:
            entry = LANG_LFG_STATE_PROPOSAL;
            break;
        case LFG_STATE_DUNGEON:
            entry = LANG_LFG_STATE_DUNGEON;
            break;
        case LFG_STATE_BOOT:
            entry = LANG_LFG_STATE_BOOT;
            break;
        case LFG_STATE_FINISHED_DUNGEON:
            entry = LANG_LFG_STATE_FINISHED_DUNGEON;
            break;
        case LFG_STATE_RAIDBROWSER:
            entry = LANG_LFG_STATE_RAIDBROWSER;
            break;
        default:
            break;
    }

    return std::string(sObjectMgr->GetTrinityStringForDBCLocale(entry));
}

float GetShortagePercent()
{
    return sWorld->getIntConfig(CONFIG_LFG_SHORTAGE_PERCENT) / 100.0f;
}

} // namespace lfg
