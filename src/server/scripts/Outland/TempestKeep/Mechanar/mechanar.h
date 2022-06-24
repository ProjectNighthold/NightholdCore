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

#ifndef DEF_MECHANAR_H
#define DEF_MECHANAR_H

uint32 const EncounterCount             = 5;

enum DataTypes
{
    DATA_GATEWATCHER_GYROKILL           = 0,
    DATA_GATEWATCHER_IRON_HAND          = 1,
    DATA_MECHANOLORD_CAPACITUS          = 2,
    DATA_NETHERMANCER_SEPRETHREA        = 3,
    DATA_PATHALEON_THE_CALCULATOR       = 4,
    DATA_GO_CHAHCE_LEGION               = 5
};

enum GameobjectIds
{
    GO_DOOR_MOARG_1                     = 184632,
    GO_DOOR_MOARG_2                     = 184322,
    GO_CHACHE_LEGION                    = 184465,
    GO_DOOR_NETHERMANCER                = 184449
};

#endif