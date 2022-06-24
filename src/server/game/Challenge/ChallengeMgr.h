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

#ifndef TRINITY_CHALLENGEMGR_H
#define TRINITY_CHALLENGEMGR_H
#include "Common.h"
#include "FunctionProcessor.h"


struct ChallengeMember
{
    ObjectGuid guid;
    uint16 specId;
    uint32 Date;                    /// time when recorde done
    uint32 ChallengeLevel;          /// 2-15 but blizzard store it as uint32? rly?
    uint32 ChestID;

    bool operator <(const ChallengeMember& i) const;
    bool operator ==(const ChallengeMember& i) const;
};

typedef std::set<ChallengeMember> ChallengeMemberList;

struct ChallengeData
{
    std::array<uint32, 3> Affixes;  /// key modifiers
    ObjectGuid::LowType GuildID;    /// is it guild group
    ObjectGuid::LowType ID;         /// challenge id
    uint32 RecordTime;              /// time taken for complite challenge
    uint32 Date;                    /// time when recorde done
    uint32 ChallengeLevel;          /// 2-15 but blizzard store it as uint32? rly?
    uint32 ChestID;
    uint16 MapID;
    uint16 ChallengeID;
    uint8  TimerLevel;              /// like 0 - not in time; 1-2-3 'timer deal' by db2 data 1-2-3 chests

    ChallengeMemberList member;
};

struct OploteLoot
{
    ObjectGuid guid;
    uint32 Date;
    uint32 ChallengeLevel;
    std::set<uint32> chestListID;
    bool needSave = true;
};

typedef std::unordered_map<uint16 /*ChallengeID*/, ChallengeData*> ChallengeByMap;
typedef std::unordered_map<ObjectGuid::LowType /*ID*/, ChallengeData*> ChallengeMap;
typedef std::unordered_map<ObjectGuid /*MemberGUID*/, ChallengeByMap> ChallengesOfMember;
typedef std::unordered_map<ObjectGuid::LowType /*guild*/, ChallengeByMap> GuildBestRecord;
typedef std::unordered_map<ObjectGuid /*MemberGUID*/, std::set<ChallengeData*>> ChallengeWeekListMap;
typedef std::unordered_map<ObjectGuid /*MemberGUID*/, OploteLoot> OploteLootMap;

static const std::list<uint32> ChallengeChestList = {252674,252677,252686,252668,252665,252056,252680,252671,252683,269852,269871,269843,272689,252676/*is for other intstance without mythic mode*/};

class Challenge;

class ChallengeMgr
{
    ChallengeMgr();
    ~ChallengeMgr();

public:
    static ChallengeMgr* instance();

    void LoadFromDB();
    void SaveChallengeToDB(ChallengeData const* challengeData);

    void CheckBestMapId(ChallengeData* challengeData);
    void CheckBestGuildMapId(ChallengeData* challengeData);
    bool CheckBestMemberMapId(ObjectGuid const& guid, ChallengeData* challengeData);

    ChallengeData* BestServerChallenge(uint16 ChallengeID);
    ChallengeData* BestGuildChallenge(ObjectGuid::LowType const& guildId, uint16 ChallengeID);
    void SetChallengeMapData(ObjectGuid::LowType const& ID, ChallengeData* data);
    ChallengeByMap* BestForMember(ObjectGuid const& guid);
    ChallengeByMap* LastForMember(ObjectGuid const& guid);
    ChallengeData* LastForMemberMap(ObjectGuid const& guid, uint32 ChallengeID);
    ChallengeData* BestForMemberMap(ObjectGuid const& guid, uint32 ChallengeID);
    bool HasOploteLoot(ObjectGuid const& guid);
    OploteLoot* GetOploteLoot(ObjectGuid const& guid);
    void SaveOploteLootToDB();
    void DeleteOploteLoot(ObjectGuid const& guid);
    void GenerateOploteLoot(bool manual = false);
    static bool GetStartPosition(uint32 mapID, float& x, float& y, float& z, float& o, ObjectGuid OwnerGuid);

    void GenerateCurrentWeekAffixes();
	void GenerateManualAffixes();
    uint8 GetActiveAffixe();

    static uint32 GetLootTreeMod(int32& levelBonus, uint32& challengeLevel, Challenge* challenge = nullptr);
    static uint32 GetCAForLoot(Challenge* const challenge, uint32 goEntry);
    static uint32 GetBigCAForLoot(Challenge* const challenge, uint32 goEntry, uint32& count);
    static uint32 GetCAForOplote(uint32 challengeLevel);
    static uint32 GetBigCAForOplote(uint32 challengeLevel, uint32& count);
    static float GetChanceItem(uint8 mode, uint32 challengeLevel);
    static bool IsChest(uint32 goEntry);
    static bool IsDoor(uint32 goEntry);

protected:
    ChallengeMap _challengeMap;
    ChallengesOfMember _lastForMember;
    ChallengesOfMember _challengesOfMember;
    ChallengeByMap _bestForMap;
    GuildBestRecord m_GuildBest;
    ChallengeWeekListMap _challengeWeekList;
    OploteLootMap _oploteWeekLoot;
};

#define sChallengeMgr ChallengeMgr::instance()

#endif
