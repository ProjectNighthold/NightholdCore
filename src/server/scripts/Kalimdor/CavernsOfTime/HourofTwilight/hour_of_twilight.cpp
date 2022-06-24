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

#include "hour_of_twilight.h"

enum Adds
{
    NPC_TWILIGHT_DRAKE              = 55636,
    NPC_HARBRINGER_OF_TWILIGHT      = 55969,
    NPC_CHAMPION_OF_LIFE            = 55911,
    NPC_HARBRINGER_OF_DESTRUCTION   = 55967,
    NPC_CHAMPION_OF_TIME            = 55913,
    NPC_DARK_HAZE                   = 54628, // 102287  102255
    NPC_FLAILING_TENTACLE           = 54696,
    NPC_BLOOD                       = 54644,
    NPC_THROW_LOC                   = 54735,
    NPC_SHADOW_BORER                = 54686,
    NPC_TWILIGHT_PORTAL             = 58233,

    NPC_EARTHEN_SHELL_TARGET        = 55445,
};

class npc_hour_of_twilight_life_warden : public CreatureScript
{
    public:
        npc_hour_of_twilight_life_warden() : CreatureScript("npc_hour_of_twilight_life_warden") { }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            if (pPlayer->isInCombat())
                return true;

            pPlayer->NearTeleportTo(teleportPos.GetPositionX(), teleportPos.GetPositionY(), teleportPos.GetPositionZ(), teleportPos.GetOrientation());

            return true;
        }
};

void AddSC_hour_of_twilight()
{
    new npc_hour_of_twilight_life_warden();
}