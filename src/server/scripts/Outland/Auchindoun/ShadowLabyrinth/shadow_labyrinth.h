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

#ifndef SHADOW_LABYRINTH_H_
#define SHADOW_LABYRINTH_H_

#define SLScriptName "instance_shadow_labyrinth"
#define DataHeader "SL"

uint32 const EncounterCount = 4;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_AMBASSADOR_HELLMAW             = 0,
    DATA_BLACKHEART_THE_INCITER         = 1,
    DATA_GRANDMASTER_VORPIL             = 2,
    DATA_MURMUR                         = 3,

    // Additional Data
    DATA_FEL_OVERSEER                   = 4
};

enum CreatureIds
{
    NPC_AMBASSADOR_HELLMAW              = 18731,
    NPC_GRANDMASTER_VORPIL              = 18732,
    NPC_FEL_OVERSEER                    = 18796
};

enum GameObjectIds
{
    GO_REFECTORY_DOOR                   = 183296, // door opened when blackheart the inciter dies
    GO_SCREAMING_HALL_DOOR              = 183295  // door opened when grandmaster vorpil dies
};

enum Misc
{
    ACTION_AMBASSADOR_HELLMAW_INTRO     = 1,
    ACTION_AMBASSADOR_HELLMAW_BANISH    = 2,
};

#endif // SHADOW_LABYRINTH_H_

