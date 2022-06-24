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

#ifndef ARENA_1V1_H
#define ARENA_1V1_H

#include "SharedDefines.h"


const uint32 DisableSpecs[]
{
    SPEC_PALADIN_HOLY,
    SPEC_PALADIN_PROTECTION,
    
    SPEC_WARRIOR_PROTECTION,
    
    SPEC_DRUID_BEAR,
    SPEC_DRUID_RESTORATION,
    
    SPEC_DK_BLOOD,
    
    SPEC_PRIEST_DISCIPLINE,
    SPEC_PRIEST_HOLY,
    
    SPEC_SHAMAN_RESTORATION, 
    
    SPEC_MONK_MISTWEAVER,
    SPEC_MONK_BREWMASTER,
    
    SPEC_DEMON_HUNER_VENGEANCE 
};

// Return false, if player have tank/heal spec
static bool Arena1v1CheckTalents(Player* player)
{
    if (!player)
        return false;
    
    if (player->getLevel() < 110)
        return false;
    
    for (uint32 curSpec : DisableSpecs)
        if (player->GetUInt32Value(PLAYER_FIELD_CURRENT_SPEC_ID) == curSpec)
        {
            ChatHandler(player).PSendSysMessage("You can't use tank/heal spec");
            return false;
        }
        
    return true;
}

#endif