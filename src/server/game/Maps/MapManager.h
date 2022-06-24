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

#ifndef TRINITY_MAPMANAGER_H
#define TRINITY_MAPMANAGER_H

#include "Common.h"
#include "Map.h"
#include "Position.h"

class WorldLocation;
class ChatHandler;

class MapManager
{
    typedef std::vector<Map*> MapMapType;

    MapManager();
    ~MapManager();

    MapManager(const MapManager &) = delete;
    MapManager& operator=(const MapManager &) = delete;

    public:
        static MapManager* instance();

        Map* CreateBaseMap(uint32 mapId);
        Map* FindBaseNonInstanceMap(uint32 mapId) const;
        Map* CreateMap(uint32 mapId, Player* player);
        Map* FindMap(uint32 mapId, uint32 instanceId) const;

        uint32 GetAreaId(uint32 mapid, float x, float y, float z) const;
        uint32 GetZoneId(uint32 mapid, float x, float y, float z) const;
        void GetZoneAndAreaId(uint32& zoneid, uint32& areaid, uint32 mapid, float x, float y, float z);

        void Initialize();
        void Update(uint32);

        void SetGridCleanUpDelay(uint32 t);

        void SetMapUpdateInterval(uint32 t);

        //void LoadGrid(int mapid, int instId, float x, float y, const WorldObject* obj, bool no_unload = false);
        void UnloadAll();

        static bool ExistMapAndVMap(uint32 mapid, float x, float y);
        static bool IsValidMAP(uint32 mapid, bool startUp);

        static bool IsValidMapCoord(uint32 mapid, float x, float y);
        static bool IsValidMapCoord(uint32 mapid, float x, float y, float z);
        static bool IsValidMapCoord(uint32 mapid, float x, float y, float z, float o);
        static bool IsValidMapCoord(WorldLocation const& loc);

        void DoDelayedMovesAndRemoves();

        bool CanPlayerEnter(uint32 mapid, Player* player, bool loginCheck = false);
        void InitializeVisibilityDistanceInfo();

        /* statistics */
        uint32 GetNumInstances();
        uint32 GetNumPlayersInInstances();

        // Instance ID management
        void InitInstanceIds();
        uint32 GenerateInstanceId();

        void FindSessionInAllMaps(uint32 accId, ChatHandler* handler);
        void LogInfoAllMaps();
        void SetUnloadGarrison(uint32 lowGuid);

        Map* FindBaseMap(uint32 mapId) const { return i_maps[mapId]; }
        std::vector<std::thread*> _mapThreads;
        uint16 _mapCount;

    private:

        uint32 i_gridCleanUpDelay;
        MapMapType i_maps;

        uint32 _nextInstanceId;
        uint8 _mapInfoCounter;

};
#define sMapMgr MapManager::instance()
#endif
