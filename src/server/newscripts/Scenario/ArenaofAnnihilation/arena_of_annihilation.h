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

#ifndef DEF_ARENAOFANNIHILATION
#define DEF_ARENAOFANNIHILATION

enum eEnums
{
    DATA_SCAR_SHELL         = 1,
    DATA_JOLGRUM            = 2,
    DATA_LIUYANG            = 3,
    DATA_CHAGAN             = 4,
    DATA_FINAL_STAGE        = 5,
    MAX_ENCOUNTER,
    DATA_DOOR,
    DATA_START_EVENT,
    DATA_SATAY,
    DATA_KOBO,
    DATA_MAKI,
};

enum eCreatures
{
    NPC_SCAR_SHELL  = 63311,
    NPC_JOLGRUM     = 63312,
    NPC_LIUYANG     = 63313,
    NPC_FIREHOOF    = 63318,
    NPC_SATAY_BYU   = 64281,
    NPC_KOBO        = 63316,
    NPC_MAKI        = 64280,
    NPC_GURGTHOCK   = 63315,
};

enum eGameObects
{
    GO_INNER_DOORS  = 211693,
};

enum eSays
{
    //Gurgthock
    SAY_START_EVENT_1       = 0,
    SAY_START_EVENT_2       = 1,
    SAY_START_EVENT_3       = 2,
    SAY_SCAR_SHELL_START    = 3,
    SAY_SCAR_SHELL_END      = 4,
    SAY_JOLGRUM_START       = 6,
    SAY_JOLGRUM_END         = 7,
    SAY_LIUYANG_START       = 8,
    SAY_LIUYANG_END         = 9,
    SAY_CHAGAN_START        = 10,
    SAY_CHAGAN_END          = 11,
    SAY_SATAY_START         = 12,
    SAY_SATAY_END           = 13,
    SAY_KOBO_START          = 14,
    SAY_KOBO_END            = 15,
    SAY_MAKI_START          = 16,
    SAY_MAKI_END            = 17,
    SAY_SCENARIO_FINISH     = 18,
};

const Position centerPos = {3795.26f, 533.56f, 639.40f, 6.14f};
#endif
