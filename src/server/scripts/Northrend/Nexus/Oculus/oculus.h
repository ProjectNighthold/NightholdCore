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

#ifndef OCULUS_H_
#define OCULUS_H_

uint32 const EncounterCount = 4;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_DRAKOS                 = 0,
    DATA_VAROS                  = 1,
    DATA_UROM                   = 2,
    DATA_EREGOS                 = 3
};

enum CreatureIds
{
    NPC_DRAKOS                  = 27654,
    NPC_VAROS                   = 27447,
    NPC_UROM                    = 27655,
    NPC_EREGOS                  = 27656,

    NPC_AZURE_RING_GUARDIAN     = 28236,
    NPC_CENTRIFUGE_CONSTRUCT    = 27641,
    NPC_RUBY_DRAKE_VEHICLE      = 27756,
    NPC_EMERALD_DRAKE_VEHICLE   = 27692,
    NPC_AMBER_DRAKE_VEHICLE     = 27755,
    NPC_VERDISA                 = 27657,
    NPC_BELGARISTRASZ           = 27658,
    NPC_ETERNOS                 = 27659,
    NPC_GREATER_WHELP           = 28276
};

enum GameObjectIds
{
    GO_DRAGON_CAGE_DOOR         = 193995,
    GO_EREGOS_CACHE_N           = 191349,
    GO_EREGOS_CACHE_H           = 193603
};

enum SpellEvents
{
    EVENT_CALL_DRAGON           = 12229
};

enum CreatureActions
{
    ACTION_CALL_DRAGON_EVENT    = 1
};

enum OculusSpells
{
    SPELL_CENTRIFUGE_SHIELD     = 50053,
    SPELL_DEATH_SPELL           = 50415
};

enum Misc
{
    POINT_MOVE_OUT              = 1
};

template<class AI>
CreatureAI* GetInstanceAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_oculus"))
                return new AI(creature);
    return NULL;
}

#endif // OCULUS_H_
