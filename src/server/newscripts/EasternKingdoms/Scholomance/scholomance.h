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

#ifndef DEF_SCHOLOMANCE_H
#define DEF_SCHOLOMANCE_H

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

enum DataTyped
{ 
    DATA_INSTRUCTOR           = 0,
    DATA_BAROV                = 1,
    DATA_RATTLEGORE           = 2,
    DATA_LILIAN               = 3,
    DATA_DARKMASTER           = 4
};

enum CreatureIds
{
    NPC_INSTRUCTOR_CHILLHEART = 58633,
    NPC_JANDICE_BAROV         = 59184,
    NPC_RATTLEGORE            = 59153,
    NPC_LILIAN_VOSS           = 59200,
    NPC_DARKMASTER_GANDLING   = 59080
};

#endif

