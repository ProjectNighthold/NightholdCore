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

#include "GuildFinderMgr.h"
#include "GuildPackets.h"

void WorldSession::HandleLFGuildAddRecruit(WorldPackets::Guild::LFGuildAddRecruit& packet)
{
    if (sGuildFinderMgr->GetAllMembershipRequestsForPlayer(GetPlayer()->GetGUID()).size() == 10)
        return;

    if (!packet.GuildGUID.IsGuild())
        return;

    if (!(packet.ClassRoles & GUILDFINDER_ALL_ROLES) || packet.ClassRoles > GUILDFINDER_ALL_ROLES)
        return;

    if (!(packet.Availability & ALL_WEEK) || packet.Availability > ALL_WEEK)
        return;

    if (!(packet.PlayStyle & ALL_PLAY_STYLES) || packet.PlayStyle > ALL_PLAY_STYLES)
        return;

    sGuildFinderMgr->AddMembershipRequest(packet.GuildGUID, MembershipRequest(GetPlayer()->GetGUID(), packet.GuildGUID, packet.Availability, packet.ClassRoles, packet.PlayStyle, packet.Comment, time(nullptr)));
}

void WorldSession::HandleLFGuildBrowse(WorldPackets::Guild::LFGuildBrowse& packet)
{    
    if (!(packet.ClassRoles & GUILDFINDER_ALL_ROLES) || packet.ClassRoles > GUILDFINDER_ALL_ROLES)
        return;

    if (!(packet.Availability & ALL_WEEK) || packet.Availability > ALL_WEEK)
        return;

    if (!(packet.PlayStyle & ALL_PLAY_STYLES) || packet.PlayStyle > ALL_PLAY_STYLES)
        return;

    if (packet.CharacterLevel > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) || packet.CharacterLevel < 1)
        return;

    Player* player = GetPlayer();

    LFGuildPlayer settings(player->GetGUID(), packet.ClassRoles, packet.Availability, packet.PlayStyle, ANY_FINDER_LEVEL);
    LFGuildStore guildList = sGuildFinderMgr->GetGuildsMatchingSetting(settings, player->GetTeamId());

    if (guildList.empty())
    {
        player->SendDirectMessage(WorldPackets::Guild::LFGuildBrowseResponse().Write());
        return;
    }

    WorldPackets::Guild::LFGuildBrowseResponse browse;
    browse.Browses.reserve(guildList.size());
    for (auto const& x : guildList)
    {
        Guild* guild = sGuildMgr->GetGuildById(x.first.GetCounter());
        WorldPackets::Guild::LFGuildBrowseData data;
        data.GuildGUID = guild->GetGUID();
        data.GuildVirtualRealm = GetVirtualRealmAddress();
        data.GuildMembers = guild->GetMembersCount();
        data.GuildAchievementPoints = guild->GetAchievementMgr().GetAchievementPoints();
        data.PlayStyle = x.second.GetPlayStyle();
        data.Availability = x.second.GetAvailability();
        data.ClassRoles = x.second.GetClassRoles();
        data.LevelRange = guild->GetLevel();
        data.EmblemStyle = guild->GetEmblemInfo().GetStyle();
        data.EmblemColor = guild->GetEmblemInfo().GetColor();
        data.BorderStyle = guild->GetEmblemInfo().GetBorderStyle();
        data.BorderColor = guild->GetEmblemInfo().GetBorderColor();
        data.Background = guild->GetEmblemInfo().GetBackgroundColor();
        data.GuildName = guild->GetName();
        data.Comment = x.second.GetComment();
        data.Cached = 0;
        data.MembershipRequested = sGuildFinderMgr->HasRequest(player->GetGUID(), guild->GetGUID());
        browse.Browses.push_back(data);
    }

    player->SendDirectMessage(browse.Write());
}

void WorldSession::HandleLFGuildDeclineRecruit(WorldPackets::Guild::LFGuildDeclineRecruit& packet)
{
    if (packet.RecruitGUID.IsPlayer())
        sGuildFinderMgr->RemoveMembershipRequest(packet.RecruitGUID, ObjectGuid::Create<HighGuid::Guild>(GetPlayer()->GetGuildId()));
}

void WorldSession::HandleLFGuildGetApplications(WorldPackets::Guild::LFGuildGetApplications& /*packet*/)
{
    std::list<MembershipRequest> applicatedGuilds = sGuildFinderMgr->GetAllMembershipRequestsForPlayer(GetPlayer()->GetGUID());
    WorldPackets::Guild::LFGuildApplication application;
    application.NumRemaining = 10 - sGuildFinderMgr->CountRequestsFromPlayer(GetPlayer()->GetGUID());

    if (!applicatedGuilds.empty())
    {
        application.Applications.reserve(applicatedGuilds.size());
        for (auto const& v : applicatedGuilds)
        {
            Guild* guild = sGuildMgr->GetGuildById(v.GetGuildGuid().GetCounter());
            if (!guild)
                continue;

            LFGuildSettings guildSettings = sGuildFinderMgr->GetGuildSettings(v.GetGuildGuid());
            WorldPackets::Guild::LFGuildApplicationData data;
            data.GuildGUID = guild->GetGUID();
            data.GuildVirtualRealm = GetVirtualRealmAddress();
            data.ClassRoles = guildSettings.GetClassRoles();
            data.PlayStyle = guildSettings.GetPlayStyle();
            data.Availability = guildSettings.GetAvailability();
            data.SecondsSinceCreated = time(nullptr) - v.GetSubmitTime();
            data.GuildName = guild->GetName();
            data.Comment = v.GetComment();
            application.Applications.push_back(data);
        }
    }

    GetPlayer()->SendDirectMessage(application.Write());
}

void WorldSession::HandleLFGuildGetRecruits(WorldPackets::Guild::LFGuildGetRecruits& /*packet*/)
{
    Player* player = GetPlayer();
    std::vector<MembershipRequest> recruitsList = sGuildFinderMgr->GetAllMembershipRequestsForGuild(ObjectGuid::Create<HighGuid::Guild>(player->GetGuildId()));
    
    WorldPackets::Guild::LFGuildRecruits recruits;
    recruits.Recruits.reserve(recruitsList.size());
    for (auto const& x : recruitsList)
    {
        WorldPackets::Guild::LFGuildRecruitData data;
        data.RecruitGUID = x.GetPlayerGUID();
        data.RecruitVirtualRealm = GetVirtualRealmAddress();
        data.CharacterClass = x.GetClass();
        data.CharacterGender = x.GetGender();
        data.CharacterLevel = x.GetLevel();
        data.ClassRoles = x.GetClassRoles();
        data.PlayStyle = x.GetPlayStyle();
        data.Availability = x.GetAvailability();
        data.SecondsSinceCreated = time(nullptr) - x.GetSubmitTime();
        data.SecondsUntilExpiration = x.GetExpiryTime() - time(nullptr);
        data.Name = x.GetName();
        data.Comment = x.GetComment();
        recruits.Recruits.push_back(data);
    }

    player->SendDirectMessage(recruits.Write());
}

void WorldSession::HandleLFGuildGetGuildPost(WorldPackets::Guild::LFGuildGetGuildPost& /*packet*/)
{
    Player* player = GetPlayer();
    if (!player->GetGuildId())
        return;

    bool isGuildMaster = true;
    if (Guild* guild = sGuildMgr->GetGuildById(player->GetGuildId()))
        if (guild->GetLeaderGUID() != player->GetGUID())
            isGuildMaster = false;

    WorldPackets::Guild::LFGuildPost post;
    if (isGuildMaster)
    {
        LFGuildSettings settings = sGuildFinderMgr->GetGuildSettings(ObjectGuid::Create<HighGuid::Guild>(player->GetGuildId()));

        post.Post = boost::in_place();
        post.Post->PlayStyle = settings.GetPlayStyle();
        post.Post->Availability = settings.GetAvailability();
        post.Post->ClassRoles = settings.GetClassRoles();
        post.Post->LevelRange = settings.GetLevel();
        post.Post->SecondsRemaining = 0;
        post.Post->Comment = settings.GetComment();
        post.Post->Active = settings.IsListed();
    }

    player->SendDirectMessage(post.Write());
}

void WorldSession::HandleLFGuildRemoveRecruit(WorldPackets::Guild::LFGuildRemoveRecruit& packet)
{
    if (packet.GuildGUID.IsGuild())
        sGuildFinderMgr->RemoveMembershipRequest(GetPlayer()->GetGUID(), packet.GuildGUID);
}

void WorldSession::HandleLFGuildSetGuildPost(WorldPackets::Guild::LFGuildSetGuildPost& packet)
{
    // Level sent is zero if untouched, force to any (from interface). Idk why
    if (!packet.LevelRange)
        packet.LevelRange = ANY_FINDER_LEVEL;

    if (!(packet.ClassRoles & GUILDFINDER_ALL_ROLES) || packet.ClassRoles > GUILDFINDER_ALL_ROLES)
        return;

    if (!(packet.Availability & ALL_WEEK) || packet.Availability > ALL_WEEK)
        return;

    if (!(packet.PlayStyle & ALL_PLAY_STYLES) || packet.PlayStyle > ALL_PLAY_STYLES)
        return;

    if (!(packet.LevelRange & ALL_GUILDFINDER_LEVELS) || packet.LevelRange > ALL_GUILDFINDER_LEVELS)
        return;

    Player* player = GetPlayer();
    if (!player->GetGuildId()) // Player must be in guild
        return;

    auto const& guild = sGuildMgr->GetGuildById(player->GetGuildId());
    if (!guild)
        return;

    if (guild->GetLeaderGUID() != player->GetGUID())
        return;

    sGuildFinderMgr->SetGuildSettings(guild->GetGUID(), LFGuildSettings(packet.Active, player->GetTeamId(), guild->GetGUID(), packet.ClassRoles, packet.Availability, packet.PlayStyle, packet.LevelRange, packet.Comment));
}
