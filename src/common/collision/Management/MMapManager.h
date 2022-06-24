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

#ifndef _MMAP_MANAGER_H
#define _MMAP_MANAGER_H

#include "Define.h"
#include "DetourNavMesh.h"
#include "DetourNavMeshQuery.h"
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>

//  move map related classes
namespace MMAP
{
    typedef std::map<uint32, dtTileRef> MMapTileSet;
    typedef std::map<uint64, dtNavMeshQuery*> NavMeshQuerySet;

    // dummy struct to hold map's mmap data
    struct MMapData
    {
        MMapData(dtNavMesh* mesh, uint32 mapId) : navMesh(mesh), _mapId(mapId) { }
        ~MMapData()
        {
            for (NavMeshQuerySet::iterator i = navMeshQueries.begin(); i != navMeshQueries.end(); ++i)
                dtFreeNavMeshQuery(i->second);

            if (navMesh)
                dtFreeNavMesh(navMesh);
        }

        // we have to use single dtNavMeshQuery for every instance, since those are not thread safe
        NavMeshQuerySet navMeshQueries;     // instanceId to query

        std::recursive_mutex navMeshQueries_lock;
        std::recursive_mutex navModelMeshQueries_lock;
        std::recursive_mutex tilesLoading_lock;

        dtNavMesh* navMesh;
        MMapTileSet loadedTileRefs;        // maps [map grid coords] to [dtTile]
        uint32 _mapId;
    };


    typedef std::unordered_map<uint32, MMapData*> MMapDataSet;

    // singleton class
    // holds all all access to mmap loading unloading and meshes
    class MMapManager
    {
        public:
            MMapManager() : loadedTiles(0), thread_safe_environment(true) {}
            ~MMapManager();

            void InitializeThreadUnsafe(std::unordered_map<uint32, std::vector<uint32>> const& mapData);
            bool loadMap(std::string const& basePath, uint32 mapId, int32 x, int32 y);
            bool loadMapInstance(std::string const& basePath, uint32 mapId, uint64 instanceId);
            bool unloadMap(uint32 mapId, int32 x, int32 y);
            bool unloadMap(uint32 mapId);
            bool unloadMapInstance(uint32 mapId, uint64 instanceId);
            bool loadGameObject(uint32 displayId, std::string patch);

            // the returned [dtNavMeshQuery const*] is NOT threadsafe
            dtNavMeshQuery const* GetNavMeshQuery(uint32 mapId, uint64 instanceId);
            dtNavMeshQuery const* GetModelNavMeshQuery(uint32 displayId, uint64 instanceId);
            dtNavMesh const* GetNavMesh(uint32 mapId);

            uint32 getLoadedTilesCount() const { return loadedTiles; }
            uint32 getLoadedMapsCount() const { return uint32(loadedMMaps.size()); }
        private:
            bool loadMapData(std::string const& basePath, uint32 mapId);
            bool loadMapImpl(std::string const& basePath, uint32 mapId, int32 x, int32 y);
            bool loadMapInstanceImpl(std::string const& basePath, uint32 mapId, uint64 instanceId);
            bool unloadMapImpl(uint32 mapId, int32 x, int32 y);
            bool unloadMapImpl(uint32 mapId);
            uint32 packTileID(int32 x, int32 y);

            MMapDataSet::const_iterator GetMMapData(uint32 mapId) const;
            MMapDataSet loadedMMaps;
            uint32 loadedTiles;
            bool thread_safe_environment;
            MMapDataSet loadedModels;

            std::unordered_map<uint32, std::vector<uint32>> childMapData;
            std::unordered_map<uint32, uint32> parentMapData;
    };
}

#endif
