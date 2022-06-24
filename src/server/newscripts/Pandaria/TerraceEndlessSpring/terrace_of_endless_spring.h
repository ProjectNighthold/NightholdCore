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

#ifndef TERRACE_OF_ENDLESS_SPRING_H_
#define TERRACE_OF_ENDLESS_SPRING_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

enum eData
{
    DATA_PROTECTORS,
    DATA_TSULONG,
    DATA_LEI_SHI,
    DATA_SHA_OF_FEAR,
    DATA_MAX_BOSS_DATA
};

enum eSpells
{
    SPELL_RITUAL_OF_PURIFICATION = 126848
};

enum eActions
{
    ACTION_START_TSULONG_WAYPOINT = 1,
    ACTION_INTRO_FINISHED = 2
};

enum eCreatures
{
    // Protectors of the Endless
    NPC_ANCIENT_ASANI = 60586,
    NPC_ANCIENT_REGAIL = 60585,
    NPC_PROTECTOR_KAOLAN = 60583,
    NPC_DEFILED_GROUND = 60906,
    NPC_COALESCED_CORRUPTION = 60886,
    NPC_MINION_OF_FEAR_CONTROLLER = 60957,
    NPC_MINION_OF_FEAR = 60885,

    // Tsulong
    NPC_TSULONG = 62442,

    // Lei Shi
    NPC_LEI_SHI = 62983,
    NPC_ANIMATED_PROTECTOR = 62995,
    NPC_LEI_SHI_HIDDEN = 63099,

    // Sha of Fear
    NPC_SHA_OF_FEAR = 60999,
    NPC_PURE_LIGHT_TERRACE = 60788,
    NPC_TERROR_SPAWN = 61034,

    // Thrashs
    NPC_APPARITION_OF_FEAR = 64368,
    NPC_APPARITION_OF_TERROR = 66100,
    NPC_NIGHT_TERRORS = 64390,
    NPC_NIGHT_TERROR_SUMMON = 64393
};

enum eGameObjects
{
    GOB_WALL_OF_COUNCILS_VORTEX = 214854,
    GOB_COUNCILS_VORTEX = 214853,

    GOB_WALL_OF_LEI_SHI = 214852,
    GOB_LEI_SHIS_VORTEX = 214851,
    GOB_LEI_SHI_CHEST_NORMAL = 213076,
    GOB_LEI_SHI_CHEST_HEROIC = 213075
};

enum ePhases
{
};

enum eWeapons
{
};

enum eEvents
{
};

enum eTypes
{
    INTRO_DONE
};

enum eTimers
{
    TIMER_TSULONG_SPAWN = 10000,
};

#endif // TERRACE_OF_ENDLESS_SPRING_H_
