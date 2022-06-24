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

#ifndef DEF_THE_EYE_H
#define DEF_THE_EYE_H

#define TheEyeScriptName "instance_the_eye"

uint32 const EncounterCount = 4;

enum TEDataTypes
{
    // Encounter States/Boss GUIDs
    DATA_KAELTHAS                       = 0,
    DATA_ALAR                           = 1,
    DATA_HIGH_ASTROMANCER_SOLARIAN      = 2,
    DATA_VOID_REAVER                    = 3,

    DATA_ASTROMANCER                    = 4,
    DATA_GRANDASTROMANCERCAPERNIAN      = 5,
    DATA_LORDSANGUINAR                  = 6,
    DATA_MASTERENGINEERTELONICUS        = 7,
    DATA_THALADREDTHEDARKENER           = 8,

    // Additional Data
    DATA_KAEL_STATUE_LEFT               = 9,
    DATA_KAEL_STATUE_RIGHT              = 10,
    DATA_TEMPEST_BRIDGE_WINDOW          = 11
};

enum TECreatureIds
{
    NPC_SANGUINAR                       = 20060,
    NPC_CAPERNIAN                       = 20062,
    NPC_TELONICUS                       = 20063,
    NPC_THALADRED                       = 20064,
    NPC_KAELTHAS                        = 19622,
    NPC_HIGH_ASTROMANCER_SOLARIAN       = 18805,
    NPC_ALAR                            = 19514
};

enum TEGameObjectIds
{
    GO_TEMPEST_BRIDDGE_WINDOW           = 184069,
    GO_KAEL_STATUE_RIGHT                = 184596,
    GO_KAEL_STATUE_LEFT                 = 184597,
    GO_ARCANE_DOOR_LEFT                 = 184324,
    GO_ARCANE_DOOR_RIGHT                = 184325
};

#endif
