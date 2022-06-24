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

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "MoveSpline.h"
#include "MoveSplineFlag.h"
#include "MoveSplineInit.h"
#include "Map.h"
#include "ScriptedCreature.h"

#ifndef DEF_BLOODMAUL_SLAG_MINES_H
#define DEF_BLOODMAUL_SLAG_MINES_H

enum DataTypes
{
    DATA_SLAVE_WATCHER_CRUSHTO = 1,

    DATA_FORGEMASTER_GOGDUH,
    DATA_MAGMOLATUS,

    DATA_ROLTALL,

    DATA_GUGROKK,

    //< Misc data
    DATA_DEFENCE_WALL,
    DATA_DEFENCE_WALL_2,
    DATA_DRAW_BRIDGE,
    DATA_SLAVE_WATCHER_CRUSHTO_EVENT,
    DATA_FORGEMASTER_GOGDUH_EVENT,
    DATA_CROMAN_SUMMONER,
    DATA_CROMAN_PROGRESS,
    DATA_CROMAN_GUID,

    DATA_BOULDER_R,
    DATA_BOULDER_L,
    DATA_BOULDER_M,
};

enum GameObjects
{
    GO_DEFENCE_WALL                         = 224643,
    GO_DEFENCE_WALL_2                       = 225693,
    GO_DRAW_BRIDGE                          = 224487,
};

enum Creatures
{
    BOSS_SLAVE_WATCHER_CRUSHTO              = 74787,
    BOSS_FORGEMASTER_GOGDUH                 = 74366,
    BOSS_MAGMOLATUS                         = 74475,
    BOSS_ROLTALL                            = 75786,
    BOSS_GUGROKK                            = 74790,

    NPC_CROMAN                              = 81032,
};

enum iSpells
{
    SPELL_SUMMON_CRO_MO                     = 163647,
    SPELL_CINDER_SPLASH_I                   = 152299, // summon 75360 - pre event for lh1 boss
    SPELL_PILLAR_OF_FLAMES                  = 151626, // summon 75327
};

#endif // DEF_BLOODMAUL_SLAG_MINES_H