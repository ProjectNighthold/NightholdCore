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

#ifndef DEF_BLACKWING_LAIR_H
#define DEF_BLACKWING_LAIR_H

uint32 const EncounterCount     = 8;

enum BWLEncounter
{
    BOSS_RAZORGORE              = 0,
    BOSS_VAELASTRAZ             = 1,
    BOSS_BROODLORD              = 2,
    BOSS_FIREMAW                = 3,
    BOSS_EBONROC                = 4,
    BOSS_FLAMEGOR               = 5,
    BOSS_CHROMAGGUS             = 6,
    BOSS_NEFARIAN               = 7
};

enum CreatureIds
{
    NPC_RAZORGORE               = 12435,
    NPC_BLACKWING_DRAGON        = 12422,
    NPC_BLACKWING_TASKMASTER    = 12458,
    NPC_BLACKWING_LEGIONAIRE    = 12416,
    NPC_BLACKWING_WARLOCK       = 12459,
    NPC_VAELASTRAZ              = 13020,
    NPC_BROODLORD               = 12017,
    NPC_FIRENAW                 = 11983,
    NPC_EBONROC                 = 14601,
    NPC_FLAMEGOR                = 11981,
    NPC_CHROMAGGUS              = 14020,
    NPC_VICTOR_NEFARIUS         = 10162,
    NPC_NEFARIAN                = 11583
};

enum DoorsIds
{
    GO_DOOR_0   = 176964,
    GO_DOOR_1   = 176965,
    GO_DOOR_2   = 179364,
    GO_DOOR_3   = 179365,
    GO_DOOR_4   = 179115,
    GO_DOOR_5   = 179117,
    GO_DOOR_6   = 176966
};

enum BWLData64
{
    DATA_RAZORGORE_THE_UNTAMED = 1,
    DATA_VAELASTRAZ_THE_CORRUPT,
    DATA_BROODLORD_LASHLAYER,
    DATA_FIRENAW,
    DATA_EBONROC,
    DATA_FLAMEGOR,
    DATA_CHROMAGGUS,
    DATA_LORD_VICTOR_NEFARIUS,
    DATA_NEFARIAN
};

enum BWLEvents
{
    EVENT_RAZOR_SPAWN       = 1,
    EVENT_RAZOR_PHASE_TWO   = 2,
    EVENT_RESPAWN_NEFARIUS  = 3
};

enum BWLMisc
{
    // Razorgore Egg Event
    ACTION_PHASE_TWO            = 1,
    DATA_EGG_EVENT
};

template<class AI>
CreatureAI* GetInstanceAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_blackwing_lair"))
                return new AI(creature);
    return NULL;
}

#endif