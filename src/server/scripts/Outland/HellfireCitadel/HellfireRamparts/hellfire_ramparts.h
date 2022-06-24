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

#ifndef DEF_RAMPARTS_H
#define DEF_RAMPARTS_H

uint32 const EncounterCount       = 4;

enum HRDataTypes
{
    DATA_WATCHKEEPER_GARGOLMAR    = 0,
    DATA_OMOR_THE_UNSCARRED       = 1,
    DATA_VAZRUDEN                 = 2,
    DATA_NAZAN                    = 3
};

enum HRCreatureIds
{
    NPC_HELLFIRE_SENTRY           = 17517,
    NPC_VAZRUDEN_HERALD           = 17307,
    NPC_VAZRUDEN                  = 17537,
    NPC_NAZAN                     = 17536,
    NPC_LIQUID_FIRE               = 22515
};

enum HRGameobjectIds
{
    GO_FEL_IRON_CHEST_NORMAL      = 185168,
    GO_FEL_IRON_CHEST_HEROIC      = 185169
};

#endif
