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

#ifndef EVENTOBJECTOBJECT_H
#define EVENTOBJECTOBJECT_H

#include "Object.h"
#include "GridObject.h"

struct EventObjectData
{
    explicit EventObjectData() { }

    std::set<uint32> PhaseID;
    ObjectGuid::LowType guid = 0;
    Position Pos;
    uint32 id = 0;                                              // entry in eventobject_template
    uint32 phaseMask = 1;
    uint16 mapid = 0;
    uint16 zoneId = 0;
    uint16 areaId = 0;
    uint64 spawnMask = 1;
    bool dbData = true;
};

struct EventObjectTemplate
{
    uint32 Entry;
    uint32 SpellID = 0;
    uint32 WorldSafeLocID = 0;
    uint32 ScriptID = 0;
    uint32 Flags = 0;
    float radius = 0.0f;
    std::string Name;
    bool RemoveSpell = false;
};

enum EventObjectFlags
{
    EO_FLAG_ONE_ACTION = 0x00000001,
};

typedef std::unordered_map<uint32, EventObjectTemplate> EventObjectTemplateContainer;

class EventObject : public WorldObject, public GridObject<EventObject>
{
    public:
        EventObject();
        ~EventObject();

        bool Create(ObjectGuid::LowType guidlow, Map* map, uint32 phaseMask, uint32 entry, float x, float y, float z, float ang, float radius, uint32 spell, uint32 worldsafe);

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool LoadFromDB(ObjectGuid::LowType guid, Map* map) { return LoadEventObjectFromDB(guid, map); }
        bool LoadEventObjectFromDB(ObjectGuid::LowType guid, Map* map);
        void SaveToDB(uint32 mapid, uint64 spawnMask, uint32 phaseMask);

        void Update(uint32 p_time) override;
        void Remove();

        void MoveInLineOfSight(Unit* who);

        uint64 GetDBTableGUIDLow() const { return m_DBTableGuid; }

        uint32 GetScriptId() const;

        bool ActivatedForPlayer(Player* player) const;

        EventObjectTemplate const* eventTemplate = nullptr;
        uint64 m_DBTableGuid;
        GuidSet affectedPlayers;
        GuidSet affectedPermamentPlayers;
};
#endif
