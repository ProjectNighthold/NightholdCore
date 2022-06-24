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

#ifndef COURT_OF_STARS_H_
#define COURT_OF_STARS_H_

enum eData
{
    DATA_CAPTAIN_GERDO          = 0,
    DATA_TALIXAE                = 1,
    DATA_MELANDRUS              = 2,
    DATA_MELANDRUS_EVENT        = 3,  // для дверей и корректности
    MAX_ENCOUNTER,

    DATA_BEACON_ACTIVATE
};

enum eCreatures
{
    //Patrol Captain Gerdo
    NPC_PATROL_CAPTAIN_GERDO    = 104215,
    NPC_GERDO_TRIG_FRONT        = 104384,
    NPC_GERDO_TRIG_BACK         = 104400,
    NPC_GERDO_ARCANE_BEACON     = 104245,

    //Talixae adds
    NPC_JAZSHARIU               = 104273,
    NPC_BAALGAR_THE_WATCHFUL    = 104274,
    NPC_IMACUTYA                = 104275,
    NPC_FELBOUND_ENFORCER       = 104278,
    NPC_INFERNAL_IMP            = 112668,

    //Melandrus adds
    NPC_IMAGE_MELANDRUS         = 105754,
    NPC_ENVELOPING_WINDS        = 112687,

    NPC_MELANDRUS               = 104218,
};

enum eGameObjects
{
    GO_GERDO_DOOR               = 251849,
    GO_MELANDRUS_DOOR_1         = 251847,
    GO_MELANDRUS_DOOR_2         = 251848,
};

#endif