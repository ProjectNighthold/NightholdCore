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

#ifndef BATTLEFIELD_MGR_H_
#define BATTLEFIELD_MGR_H_

#include "Battlefield.h"

class Player;
class GameObject;
class Creature;
class ZoneScript;
struct GossipMenuItems;

class BattlefieldMgr
{
  private:
    BattlefieldMgr();
  public:
    static BattlefieldMgr* instance()
    {
        static BattlefieldMgr instance;
        return &instance;
    }

    ~BattlefieldMgr();

    void InitBattlefield();
    void HandlePlayerEnterZone(ObjectGuid guid, uint32 areaflag);
    void HandlePlayerLeaveZone(ObjectGuid guid, uint32 areaflag);
    void EventPlayerLoggedOut(Player* player);
    Battlefield* GetBattlefieldToZoneId(uint32 zoneid);
    Battlefield* GetBattlefieldByBattleId(uint32 battleid);
    Battlefield* GetBattlefieldByQueueID(uint64 const& id);

    ZoneScript* GetZoneScript(uint32 zoneId);

    void AddZone(uint32 zoneid, Battlefield* handle);

    std::set<Battlefield*>* GetBattlefieldMap(uint32 MapID);

    void Update(uint32 diff);

    typedef std::vector<Battlefield*>BattlefieldSet;
    typedef std::map<uint32 /*zoneid*/ , Battlefield*>BattlefieldZone;
    typedef std::map<uint32 /* mapId */, std::set<Battlefield*>> BattlefieldMap;
  private:
    BattlefieldSet m_BattlefieldSet;
    BattlefieldZone m_BattlefieldZone;
    BattlefieldMap m_BattlefieldMap;
    uint32 m_UpdateTimer;
};

#define sBattlefieldMgr BattlefieldMgr::instance()

#endif
