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

#ifndef ZONE_SCRIPT_H_
#define ZONE_SCRIPT_H_

#include "Define.h"
#include "ObjectGuid.h"

class Creature;
class GameObject;
class InstanceScript;
class Player;
class Unit;
class WorldObject;

struct CreatureData;

enum ZoneType
{
    ZONE_TYPE_MAP       = 0,
    ZONE_TYPE_INSTANCE  = 1,
};

class ZoneScript
{
        uint8 m_type;
    public:
        ZoneScript();
        virtual ~ZoneScript() = default;

        void SetType(uint8 type);
        virtual uint32 GetCreatureEntry(uint32 /*guidlow*/, CreatureData const* data);
        virtual uint32 GetGameObjectEntry(uint32 /*guidlow*/, uint32 entry) { return entry; }

        virtual void OnCreatureCreate(Creature* /*creature*/) {}
        virtual void OnCreatureRemove(Creature* /*creature*/) {}
        virtual void CreatureDies(Creature* /*creature*/, Unit* /*killer*/) {}
        virtual void OnGameObjectCreate(GameObject* /*go*/) {}
        virtual void OnGameObjectRemove(GameObject* /*go*/) {}

        virtual void OnCreatureCreateForScript(Creature* /*creature*/) {}
        virtual void OnCreatureRemoveForScript(Creature* /*creature*/) {}
        virtual void OnCreatureUpdateDifficulty(Creature* /*creature*/) {}
        virtual void EnterCombatForScript(Creature* /*creature*/, Unit* /*enemy*/) {}
        virtual void CreatureDiesForScript(Creature* /*creature*/, Unit* /*killer*/) {}
        virtual void OnGameObjectCreateForScript(GameObject* /*go*/) {}
        virtual void OnGameObjectRemoveForScript(GameObject* /*go*/) {}

        virtual void OnUnitDeath(Unit* /*unit*/) {}
        virtual void OnUnitCharmed(Unit* /*unit*/, Unit* /*charmer*/) {}
        virtual void OnUnitRemoveCharmed(Unit* /*unit*/, Unit* /*charmer*/) {}

        //All-purpose data storage 64 bit
        virtual ObjectGuid GetGuidData(uint32 /*DataId*/) const { return ObjectGuid::Empty; }
        virtual void SetGuidData(uint32 /*DataId*/, ObjectGuid /*Value*/) { }

        virtual uint64 GetData64(uint32 /*DataId*/) { return 0; }
        virtual void SetData64(uint32 /*DataId*/, uint64 /*Value*/) {}

        //All-purpose data storage 32 bit
        virtual uint32 GetData(uint32 /*DataId*/) const { return 0; }
        virtual void SetData(uint32 /*DataId*/, uint32 /*Value*/) {}

        virtual void ProcessEvent(WorldObject* /*obj*/, uint32 /*eventId*/) {}

        InstanceScript* ToInstanceScript();
};

#endif
