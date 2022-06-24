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

#ifndef DEF_ZF_H
#define DEF_ZF_H

enum zfEntries
{
    ENTRY_ZUMRAH        = 7271,
    ENTRY_BLY           = 7604,
    ENTRY_RAVEN         = 7605,
    ENTRY_ORO           = 7606,
    ENTRY_WEEGLI        = 7607,
    ENTRY_MURTA         = 7608,

    GO_END_DOOR         = 146084,

    EVENT_PYRAMID       = 1,
    EVENT_GAHZRILLA
};

enum zfPyramidPhases
{
    PYRAMID_NOT_STARTED,        //default
    PYRAMID_CAGES_OPEN,         //happens in GO hello for cages
    PYRAMID_ARRIVED_AT_STAIR,   //happens in Weegli's movementinform
    PYRAMID_WAVE_1,
    PYRAMID_PRE_WAVE_2,
    PYRAMID_WAVE_2,
    PYRAMID_PRE_WAVE_3,
    PYRAMID_WAVE_3,
    PYRAMID_KILLED_ALL_TROLLS
};

#endif