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

#ifndef __BATTLEGROUNDQUEUE_H
#define __BATTLEGROUNDQUEUE_H

#include "Common.h"
#include "EventProcessor.h"
#include "FunctionProcessor.h"
#include "Packets/BattlegroundPackets.h"

struct GroupQueueInfo;                                      // type predefinition
struct PlayerQueueInfo                                      // stores information for players in queue
{
    uint32  LastOnlineTime;                                 // for tracking and removing offline players from queue after 5 minutes
    GroupQueueInfo* GroupInfo;                              // pointer to the associated groupqueueinfo
};

struct GroupQueueInfo                                       // stores information about the group in queue (also used when joined as solo!)
{
    std::map<ObjectGuid, PlayerQueueInfo*> Players;         // player queue info map
    WorldPackets::Battleground::IgnorMapInfo ignore;
    uint64 GroupId;                                         // group id if rated match
    uint32 Team;                                            // Player team (ALLIANCE/HORDE
    uint32 JoinTime;                                        // time when group was added
    uint32 RemoveInviteTime;                                // time when we will remove invite for players in group
    uint32 IsInvitedToBGInstanceGUID;                       // was invited to certain BG
    uint32 MatchmakerRating;                                // if rated match, inited to the rating of the team
    uint32 OpponentsMatchmakerRating;                       // for rated arena matches
    uint16 BgTypeId;                                        // battleground type id
    uint16 NativeBgTypeId;                                  // Native battleground type id
    uint8 JoinType;                                         // 2v2, 3v3, 5v5, 10v10 or 0 when BG
    bool  IsRated;                                          // rated
    uint8 index = 0;
    uint8 RoleSoloQ;
};

class Battleground;
class BattlegroundQueue
{
public:
    BattlegroundQueue();
    ~BattlegroundQueue();

    void BattlegroundQueueUpdate(uint32 diff, uint16 bgTypeId, uint8 bracketID, uint8 joinType = 0, bool isRated = false, Roles role = ROLES_DEFAULT, uint8 bracket_MinLevel = 0);
    void UpdateEvents(uint32 diff);

    void FillPlayersToBG(Battleground* bg, uint8 bracketID);
    bool CheckPremadeMatch(uint8 bracketID, uint32 MinPlayersPerTeam, uint32 MaxPlayersPerTeam);
    bool CheckNormalMatchDeathMatch(uint8 bracketID, uint32 MinPlayers, uint32 MaxPlayers);
    bool CheckNormalMatch(Battleground* bg_template, uint8 bracketID, uint32 minPlayers, uint32 maxPlayers);
    bool CalculateSoloQTeams(uint8 bracketID);
    bool SelectRatedTeams(uint32 bracket_id, GroupQueueInfo* & team1, GroupQueueInfo* & team2);

    uint16 GenerateRandomMap(uint16 bgTypeId);
    bool TryChooseCommandWithRoles(uint8 bracketID, uint8 teamId, uint8 healers, uint8 tanks, uint8 dd, uint8 teamIdPool);
    bool CheckSkirmishOrLFGBrawl(uint8 bracketID, bool isSkirmish = true);
    GroupQueueInfo* AddGroup(Player* leader, Group* group, uint16 bgTypeId, PVPDifficultyEntry const* bracketEntry, uint8 ArenaType = 0, bool isRated = false, bool isPremade = false, WorldPackets::Battleground::IgnorMapInfo ignore = WorldPackets::Battleground::IgnorMapInfo(), uint32 mmr = 0, uint32 _Team = 0);
    void RemovePlayer(ObjectGuid guid, bool decreaseInvitedCount);
    void RemovePlayerQueue(ObjectGuid guid, bool decreaseInvitedCount);
    bool IsPlayerInvited(ObjectGuid pl_guid, uint32 const bgInstanceGuid, uint32 const removeTime);
    bool GetPlayerGroupInfoData(ObjectGuid guid, GroupQueueInfo* ginfo);
    void PlayerInvitedToBGUpdateAverageWaitTime(GroupQueueInfo* ginfo, uint8 bracketID);
    uint32 GetAverageQueueWaitTime(GroupQueueInfo* ginfo, uint8 bracketID) const;

    class SelectionPool
    {
    public:
        SelectionPool();
        void Init();
        bool AddGroup(GroupQueueInfo* ginfo, uint32 desiredCount);
        bool KickGroup(uint32 size);
        uint32 GetPlayerCount() const;
        std::list<GroupQueueInfo*> SelectedGroups;
        SelectionPool& operator=(SelectionPool const& second);
    private:
        uint32 PlayerCount;
    };

    SelectionPool m_SelectionPools[MAX_TEAMS];

    class CheckMMR
    {
    public:
        CheckMMR(uint32 mmr, uint32 diff);
        bool operator()(GroupQueueInfo* group);
    private:
        uint32 _mmr;
        uint32 _diff;
    };

    class SortMMR
    {
    public:
        SortMMR();
        bool operator()(GroupQueueInfo* groupA, GroupQueueInfo* groupB);
    };

    bool InviteGroupToBG(GroupQueueInfo* ginfo, Battleground* bg, uint32 side);
    void AddDelayedEvent(uint64 timeOffset, std::function<void()>&& function);
    void KillAllDelayedEvents();
private:

    std::map<ObjectGuid, PlayerQueueInfo> _queuedPlayers;
    std::list<GroupQueueInfo*> _queuedGroups[MS::Battlegrounds::MaxBrackets][MS::Battlegrounds::QueueGroupTypes::Max];
    uint32 _waitTimes[MAX_TEAMS][MS::Battlegrounds::MaxBrackets][MS::Battlegrounds::CountOfPlayersToAverageWaitTime]{};
    uint32 _waitTimeLastPlayer[MAX_TEAMS][MS::Battlegrounds::MaxBrackets]{};
    uint32 _sumOfWaitTimes[MAX_TEAMS][MS::Battlegrounds::MaxBrackets]{};
    EventProcessor m_events;
    FunctionProcessor m_Functions;
};

class BGQueueInviteEvent : public BasicEvent
{
public:
    BGQueueInviteEvent(ObjectGuid pl_guid, uint32 BgInstanceGUID, uint16 BgTypeId, uint32 removeTime);
    virtual ~BGQueueInviteEvent() = default;;
    bool Execute(uint64 e_time, uint32 p_time) override;
private:
    ObjectGuid m_PlayerGuid;
    uint32 m_BgInstanceGUID;
    uint16 m_BgTypeId;
    uint32 m_RemoveTime;
};

class BGQueueRemoveEvent : public BasicEvent
{
public:
    BGQueueRemoveEvent(ObjectGuid pl_guid, uint32 bgInstanceGUID, uint16 BgTypeId, uint8 bgQueueTypeId, uint32 removeTime);

    virtual ~BGQueueRemoveEvent() = default;
    bool Execute(uint64 e_time, uint32 p_time) override;
private:
    ObjectGuid m_PlayerGuid;
    uint32 m_BgInstanceGUID;
    uint32 m_RemoveTime;
    uint16 m_BgTypeId;
    uint8 m_BgQueueTypeId;
};

#endif
