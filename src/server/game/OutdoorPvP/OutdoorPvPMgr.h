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

#ifndef OUTDOOR_PVP_MGR_H_
#define OUTDOOR_PVP_MGR_H_

#define OUTDOORPVP_OBJECTIVE_UPDATE_INTERVAL 1000

#include "OutdoorPvP.h"

class Player;
class GameObject;
class Creature;
class ZoneScript;
struct GossipMenuItems;

struct OutdoorPvPData
{
    OutdoorPvPTypes TypeId;
    uint32 ScriptId;
};

// class to handle player enter / leave / areatrigger / GO use events
class OutdoorPvPMgr
{
        OutdoorPvPMgr();
        ~OutdoorPvPMgr() {}

    public:
        static OutdoorPvPMgr* instance();

        // create outdoor pvp events
        void InitOutdoorPvP();

        // cleanup
        void Die();

        // called when a player enters an outdoor pvp area
        void HandlePlayerEnterZone(ObjectGuid guid, uint32 areaflag);

        // called when player leaves an outdoor pvp area
        void HandlePlayerLeaveZone(ObjectGuid guid, uint32 areaflag);

        // called when a player enters an outdoor pvp map
        void HandlePlayerEnterMap(ObjectGuid guid, uint32 zoneID);

        // called when a player leaves an outdoor pvp map
        void HandlePlayerLeaveMap(ObjectGuid guid, uint32 zoneID);

        // called when a player enters an outdoor pvp area
        void HandlePlayerEnterArea(ObjectGuid guid, uint32 aeaID);

        // called when a player leaves an outdoor pvp area
        void HandlePlayerLeaveArea(ObjectGuid guid, uint32 aeaID);

        // called when player resurrects
        void HandlePlayerResurrects(Player* player, uint32 areaflag);

        // return assigned outdoor pvp
        OutdoorPvP* GetOutdoorPvPToZoneId(uint32 zoneid);

        // handle custom (non-exist in dbc) spell if registered
        bool HandleCustomSpell(Player* player, uint32 spellId, GameObject* go);

        // handle custom go if registered
        bool HandleOpenGo(Player* player, ObjectGuid guid);

        ZoneScript* GetZoneScript(uint32 zoneId);

        void AddZone(uint32 zoneid, OutdoorPvP* handle);

        std::set<OutdoorPvP*>* GetOutdoorPvPMap(uint32 MapID);

        void Update(uint32 diff);

        void HandleGossipOption(Player* player, ObjectGuid guid, uint32 gossipid);

        bool CanTalkTo(Player* player, Creature* creature, GossipMenuItems const& gso);

        void HandleDropFlag(Player* player, uint32 spellId);

        void HandleGameEventStart(uint32 event);

        OutdoorPvPData* GetOutdoorPvPData(OutdoorPvPTypes type) { return m_OutdoorPvPDatas[type]; }
        void AddOutdoorPvP(OutdoorPvP* pvp) { m_OutdoorPvPSet.push_back(pvp); }
    private:
        typedef std::vector<OutdoorPvP*> OutdoorPvPSet;
        typedef std::map<uint32 /* zoneid */, OutdoorPvP*> OutdoorPvPZone;
        typedef std::map<uint32 /* mapId */, std::set<OutdoorPvP*>> OutdoorPvPMap;
        typedef std::map<OutdoorPvPTypes, OutdoorPvPData*> OutdoorPvPDataMap;

        // contains all initiated outdoor pvp events
        // used when initing / cleaning up
        OutdoorPvPSet  m_OutdoorPvPSet;

        // maps the zone ids to an outdoor pvp event
        // used in player event handling
        OutdoorPvPZone m_OutdoorPvPZone;
        OutdoorPvPMap m_OutdoorPvPMap;

        // Holds the outdoor PvP templates
        OutdoorPvPDataMap m_OutdoorPvPDatas;

        // update interval
        uint32 m_UpdateTimer;
};

#define sOutdoorPvPMgr OutdoorPvPMgr::instance()

#endif /*OUTDOOR_PVP_MGR_H_*/
