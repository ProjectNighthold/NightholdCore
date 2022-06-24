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

#ifndef DEF_NAXXRAMAS_H
#define DEF_NAXXRAMAS_H

enum Encounter
{
    BOSS_ANUBREKHAN,
    BOSS_FAERLINA,
    BOSS_MAEXXNA,
    BOSS_NOTH,
    BOSS_HEIGAN,
    BOSS_LOATHEB,
    BOSS_PATCHWERK,
    BOSS_GROBBULUS,
    BOSS_GLUTH,
    BOSS_THADDIUS,
    BOSS_RAZUVIOUS,
    BOSS_GOTHIK,
    BOSS_HORSEMEN,
    BOSS_SAPPHIRON,
    BOSS_KELTHUZAD,
    MAX_BOSS_NUMBER
};

enum Data
{
    DATA_HEIGAN_ERUPT,
    DATA_GOTHIK_GATE,
    DATA_SAPPHIRON_BIRTH,

    DATA_HORSEMEN0,
    DATA_HORSEMEN1,
    DATA_HORSEMEN2,
    DATA_HORSEMEN3,
};

enum Data64
{
    DATA_FAERLINA,
    DATA_MAEXXNA,
    DATA_THANE,
    DATA_LADY,
    DATA_BARON,
    DATA_SIR,
    DATA_LOATHEB,
    DATA_THADDIUS,
    DATA_HEIGAN,
    DATA_FEUGEN,
    DATA_STALAGG,
    DATA_KELTHUZAD,
    DATA_KELTHUZAD_PORTAL01,
    DATA_KELTHUZAD_PORTAL02,
    DATA_KELTHUZAD_PORTAL03,
    DATA_KELTHUZAD_PORTAL04,
    DATA_KELTHUZAD_TRIGGER,
    DATA_THADDIUS_TESLA05,
    DATA_THADDIUS_TESLA06,
};

#define GO_BIRTH                181356

#endif