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

#ifndef DEF_SERPENT_SHRINE_H
#define DEF_SERPENT_SHRINE_H

enum WaterEventState
{
    WATERSTATE_NONE                 = 0,
    WATERSTATE_FRENZY               = 1,
    WATERSTATE_SCALDING             = 2
};

enum DataTypes
{
    DATA_CANSTARTPHASE3             = 1,
    DATA_CARIBDIS                   = 2,
    DATA_HYDROSSTHEUNSTABLEEVENT    = 3,
    DATA_KARATHRESS                 = 4,
    DATA_KARATHRESSEVENT            = 5,
    DATA_KARATHRESSEVENT_STARTER    = 6,
    DATA_LADYVASHJ                  = 7,
    DATA_LADYVASHJEVENT             = 8,
    DATA_LEOTHERASTHEBLINDEVENT     = 9,
    DATA_MOROGRIMTIDEWALKEREVENT    = 10,
    DATA_SHARKKIS                   = 11,
    DATA_SHIELDGENERATOR1           = 12,
    DATA_SHIELDGENERATOR2           = 13,
    DATA_SHIELDGENERATOR3           = 14,
    DATA_SHIELDGENERATOR4           = 15,
    DATA_THELURKERBELOW             = 16,
    DATA_THELURKERBELOWEVENT        = 17,
    DATA_TIDALVESS                  = 18,
    DATA_FATHOMLORDKARATHRESSEVENT  = 19,
    DATA_LEOTHERAS                  = 20,
    DATA_LEOTHERAS_EVENT_STARTER    = 21,
    DATA_CONTROL_CONSOLE            = 22,
    DATA_STRANGE_POOL               = 23,
    DATA_WATER                      = 24,
    DATA_TRASH                      = 25
};

#endif

