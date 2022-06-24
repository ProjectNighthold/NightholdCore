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

#ifndef TRINITY_WAYPOINTMANAGER_H
#define TRINITY_WAYPOINTMANAGER_H

struct WaypointData
{
    uint32 id;
    float x, y, z, orientation;
    bool run;
    float speed;
    uint32 delay;
    uint8 delay_chance;
    uint32 event_id;
    uint8 event_chance;
};

typedef std::vector<WaypointData*> WaypointPath;
typedef std::unordered_map<uint32, WaypointPath> WaypointPathContainer;

class WaypointMgr
{
    public:
        static WaypointMgr* instance()
        {
            static WaypointMgr instance;
            return &instance;
        }

        // Attempts to reload a single path from database
        void ReloadPath(uint32 id);

        // Loads all paths from database, should only run on startup
        void Load();

        // Returns the path from a given id
        WaypointPath const* GetPath(uint32 id) const
        {
            return Trinity::Containers::MapGetValuePtr(_waypointStore, id);
        }

        // Returns the path from a given id
        WaypointPath const* GetPathScript(uint32 id) const
        {
            return Trinity::Containers::MapGetValuePtr(_waypointScriptStore, id);
        }

    private:
        WaypointMgr();
        ~WaypointMgr();

        WaypointPathContainer _waypointStore;
        WaypointPathContainer _waypointScriptStore;
};

#define sWaypointMgr WaypointMgr::instance()

#endif

