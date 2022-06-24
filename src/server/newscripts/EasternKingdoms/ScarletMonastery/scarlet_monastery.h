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

#ifndef DEF_SCARLET_M
#define DEF_SCARLET_M

enum eEnums
{
    DATA_THALNOS                = 1,
    DATA_KORLOFF                = 2,
    DATA_WHITEMANE              = 3,
    DATA_DURAND                 = 4,
    MAX_ENCOUNTER,

    DATA_HORSEMAN_EVENT         = 6,
    GAMEOBJECT_PUMPKIN_SHRINE   = 7,
};

enum eCreatures
{
    NPC_HORSEMAN            = 23682,
    NPC_HEAD                = 23775,
    NPC_PUMPKIN             = 23694,
    NPC_THALNOS             = 59789,
    NPC_BROTHER_KORLOFF     = 59223,
    NPC_WHITEMANE           = 3977,
    
    //Summons Thalnos
    NPC_EVICTED_SOUL        = 59974,
    NPC_EMPOWERING_SPIRIT   = 59893,
    NPC_FALLEN_CRUSADER     = 59884,
    NPC_EMPOWERED_ZOMBIE    = 59930,

    //Summons Korloff
    NPC_TRAINING_DUMMY      = 64446,
    NPC_SCORCHED_EARTH      = 59507,

    //Summons Whitemane
    NPC_DURAND              = 60040,
    NPC_SCARLET_JUDICATOR   = 58605,
};

enum eGameObects
{
    GO_THALNOS_DOOR      = 211844,
    GO_KORLOFF_DOOR      = 210564,
    GO_WHITEMANE_DOOR    = 210563,
    GO_PUMPKIN_SHRINE    = 186267,
};
#endif
