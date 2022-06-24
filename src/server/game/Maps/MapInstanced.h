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

#ifndef TRINITY_MAP_INSTANCED_H
#define TRINITY_MAP_INSTANCED_H

#include "Map.h"
#include "InstanceSaveMgr.h"
#include "DBCEnums.h"

class GarrisonMap;

typedef std::unordered_map< uint32, Map*> InstancedMaps;

class MapInstanced : public Map
{
    friend class MapManager;

    public:

        MapInstanced(uint32 id, time_t expiry);
        ~MapInstanced() {}

        // functions overwrite Map versions
        void Update(const uint32) override;
        void DelayedUpdate(const uint32 diff) override;
        void UpdateTransport(uint32 diff) override;
        void UpdateSessions(uint32 diff) override;
        void StopInstance();

        void UnloadAll() override;
        bool CanEnter(Player* player) override;

        Map* CreateInstanceForPlayer(const uint32 mapId, Player* player);
        Map* CreateZoneForPlayer(const uint32 mapId, Player* player);
        Map* FindInstanceMap(uint32 instanceId) const;
        Map* FindGarrisonMap(uint32 instanceId) const;

        bool DestroyInstance(InstancedMaps::iterator &itr);
        bool DestroyGarrison(InstancedMaps::iterator &itr);

        void AddGridMapReference(const GridCoord& p);
        void RemoveGridMapReference(GridCoord const& p);

        InstancedMaps &GetInstancedMaps() { return m_InstancedMaps; }
        void InitVisibilityDistance() override;

        void TerminateThread();

        InstancedMaps m_InstancedMaps;
        InstancedMaps m_GarrisonedMaps;
        std::map<uint32, std::thread*> _zoneThreads;

    private:
        InstanceMap* CreateInstance(uint32 InstanceId, InstanceSave* save, Difficulty difficulty);
        GarrisonMap* CreateGarrison(uint32 instanceId, Player* owner);
        BattlegroundMap* CreateBattleground(uint32 InstanceId, Battleground* bg);
        ZoneMap* CreateZoneMap(uint32 zoneId, Player* player);

        std::recursive_mutex m_lock;

        uint16 GridMapReference[MAX_NUMBER_OF_GRIDS][MAX_NUMBER_OF_GRIDS];
};
#endif
