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

#ifndef SHADOWMOON_BURIAL_GROUNDS_H_
#define SHADOWMOON_BURIAL_GROUNDS_H_

enum eData
{
    DATA_SADANA     = 0,
    DATA_NHALLISH   = 1,
    DATA_BONEMAW    = 2,
    DATA_NERZHUL    = 3,
    MAX_ENCOUNTER,
};

enum eCreatures
{
    NPC_WORD_TRIGGER        = 83816,
    //Sadana
    NPC_SADANA_BLOODFURY    = 75509,
    NPC_SHADOW_RUNE         = 75778,
    NPC_DARK_ECLIPSE        = 76052,
    NPC_DAGGERFALL          = 75981,
    NPC_DEFILED_SPIRIT      = 75966,
    //Nhallish
    NPC_POSSESSED_SOUL      = 75899,
    //Bonemaw
    NPC_INHALE              = 76250,
    NPC_CARRION_WORM        = 76057,
    //Ner'zhul
    NPC_NERZHUL             = 76407,
    NPC_PORTAL              = 85541,
    NPC_OMEN_OF_DEATH       = 76462,
    NPC_RITUAL_OF_BONES     = 76518,
};

enum eGameObjects
{
    GO_SADANA_DOOR_ENTER    = 233921,
    GO_SADANA_DOOR_EXIT     = 233919,
    GO_NHALLISH_DOOR        = 227851,
    GO_BONEMAW_DOOR_ENTER   = 233990,
    GO_BONEMAW_DOOR_EXIT    = 233989,
};

#endif