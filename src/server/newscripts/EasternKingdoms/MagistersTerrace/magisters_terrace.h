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

#ifndef DEF_MAGISTERS_TERRACE_H
#define DEF_MAGISTERS_TERRACE_H

#define ERROR_INST_DATA      "TSCR Error: Instance Data not set properly for Magister's Terrace instance (map 585). Encounters will be buggy."
#endif

enum Data
{
    DATA_SELIN_EVENT            = 0,
    DATA_VEXALLUS_EVENT         = 1,
    DATA_DELRISSA_EVENT         = 2,
    DATA_KAELTHAS_EVENT         = 3,

    DATA_SELIN                  = 4,
    DATA_FEL_CRYSTAL            = 5,
    DATA_FEL_CRYSTAL_SIZE       = 6,

    DATA_VEXALLUS_DOOR          = 7,
    DATA_SELIN_DOOR             = 8,
    DATA_DELRISSA               = 9,
    DATA_DELRISSA_DOOR          = 10,
    DATA_SELIN_ENCOUNTER_DOOR   = 11,

    DATA_KAEL_DOOR              = 12,
    DATA_KAEL_STATUE_LEFT       = 13,
    DATA_KAEL_STATUE_RIGHT      = 14,

    DATA_DELRISSA_DEATH_COUNT   = 15,

    DATA_ESCAPE_ORB             = 16
};
