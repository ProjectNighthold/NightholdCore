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

#ifndef DEF_A_BROKEN_ISLANDS
#define DEF_A_BROKEN_ISLANDS

enum Spells
{
};

enum Data
{
    DATA_SCENARIO_TEAM = 0,
};

enum steps
{
    SCENARIO_STEP_8 = 7,
    SCENARION_STEP_9 = 8,
    SCENARION_STEP_END
};

enum eCreatures : uint32
{
    VIEWPOINT = 93219,
    STEP6_VEHICLE = 100959,
    NPC_KROSS = 90544,

    NPC_VARIAN = 90713, //0x202090B680589640001EFF000053DF33
    NPC_JAINA = 90714,
    NPC_TIRION = 91951,
    NPC_GULDAN = 94276,

    NPC_LORD_JAR = 105179,
    NPC_BRUTAL = 91902,
    NPC_TIHONDR = 90688,

    NPC_STAGE3_HORDE_FEL_COMMANDER = 93719,

    //Horde at stage 4 (others)
    NPC_HORDE_BAINE_BLOODHOOF = 90710,
    NPC_SYLVANA = 90709,
};

enum eGameObects
{
    GO_ALLIANCE_SHIP = 251604,
    GO_HORDE_SHIP = 255203,
    TRANSPORT_ALLIANCE = 251513,
    TRANSPORT_HORDE = 254124,
    //Spires of Woe destroyed
    GO_SPIRES_OF_WOE = 240194,
};

#endif
