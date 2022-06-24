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

#ifndef _GUILDMGR_H
#define _GUILDMGR_H

#include "Guild.h"

struct GuildChallengeReward
{
    uint32 Gold;
    uint32 ChallengeCount;
    uint32 Gold2;
};
typedef std::vector<GuildChallengeReward> GuildChallengeRewardData;

class GuildMgr
{
    GuildMgr();
    ~GuildMgr();

public:
    typedef std::unordered_map<ObjectGuid::LowType, Guild*> GuildContainer;

    static GuildMgr* instance();

    Guild* GetGuildByLeader(ObjectGuid const& guid) const;
    Guild* GetGuildById(ObjectGuid::LowType guildId) const;
    Guild* GetGuildByGuid(ObjectGuid const& guid) const;
    Guild* GetGuildByName(std::string const& guildName) const;
    std::string GetGuildNameById(ObjectGuid::LowType const& guildId) const;

    void LoadGuildXpForLevel();
    void LoadGuildRewards();
    void LoadGuildChallengeRewardInfo();

    void LoadGuilds();
    void AddGuild(Guild* guild);
    void RemoveGuild(ObjectGuid::LowType guildId);

    void SaveGuilds();
    void UnloadAll();

    ObjectGuid::LowType GenerateGuildId();
    void SetNextGuildId(ObjectGuid::LowType Id);
    std::vector<GuildReward> const& GetGuildRewards() const;

    GuildChallengeRewardData const& GetGuildChallengeRewardData() const;

protected:
    ObjectGuid::LowType NextGuildId;
    GuildContainer GuildStore;
    std::vector<uint64> GuildXPperLevel;
    std::vector<GuildReward> GuildRewards;
    GuildChallengeRewardData _challengeRewardData;
};

#define sGuildMgr GuildMgr::instance()

#endif
