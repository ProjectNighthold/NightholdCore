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

#ifndef DEF_LOST_CITY_OF_THE_TOLVIR_H
#define DEF_LOST_CITY_OF_THE_TOLVIR_H

enum Data64
{
    DATA_GENERAL_HUSAM,
    DATA_LOCKMAW,
    DATA_AUGH,
    DATA_HIGH_PROPHET_BARIM,
    DATA_SIAMAT,
    MAX_ENCOUNTER,
    DATA_HARBINGER,
    DATA_BLAZE,
};

enum Creatures
{
    // Dungeon Bosses
    BOSS_GENERAL_HUSAM           = 44577,
    BOSS_HIGH_PROPHET_BARIM      = 43612,
    BOSS_LOCKMAW                 = 43614,
    BOSS_AUGH                    = 49045,
    BOSS_SIAMAT                  = 44819,
    // Various NPCs
    NPC_WIND_TUNNEL              = 48092,
};

enum GameObjects
{
    SIAMAT_PLATFORM              = 205365,
};

#endif