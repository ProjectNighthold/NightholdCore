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

#include "ChannelPackets.h"
#include "ChannelMgr.h"
#include "Chat.h"
#include "GlobalFunctional.h"

void WorldSession::HandleJoinChannel(WorldPackets::Channel::JoinChannel& packet)
{
    Player* player = GetPlayer();
    if (!player)
        return;

    if (packet.ChatChannelId)
    {
        ChatChannelsEntry const* channel = sChatChannelsStore.LookupEntry(packet.ChatChannelId);
        if (!channel)
            return;

        AreaTableEntry const* zone = sAreaTableStore.LookupEntry(player->GetCurrentZoneID());
        if (!zone || !player->CanJoinConstantChannelInZone(channel, zone))
            return;
    }

    if (packet.ChannelName.empty())
        return;

    if (isdigit(packet.ChannelName[0]))
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        cMgr->team = player->GetTeam();
        if (Channel* channel = cMgr->GetJoinChannel(packet.ChannelName, packet.ChatChannelId))
            channel->JoinChannel(player, packet.Password, true);
    }
}

void WorldSession::HandleLeaveChannel(WorldPackets::Channel::LeaveChannel& packet)
{
    Player* player = GetPlayer();
    if (packet.ChannelName.empty() || !player)
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
    {
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->LeaveChannel(player, true, true);

        cMgr->LeftChannel(packet.ChannelName);
    }
}

void WorldSession::HandleChannelCommandAnnounce(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->Announce(player);
}

void WorldSession::HandleChannelCommandDeclineInvite(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->DeclineInvite(player);
}

void WorldSession::HandleChannelCommandList(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->List(player);
}

void WorldSession::HandleChannelCommandSendWhoOwner(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->SendWhoOwner(player);
}

void WorldSession::HandleChannelPlayerCommandBan(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->Ban(player, packet.Name);
}

void WorldSession::HandleChannelPlayerCommandInvite(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->Invite(player, packet.Name);
}

void WorldSession::HandleChannelPlayerCommandKick(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->Kick(player, packet.Name);
}

void WorldSession::HandleChannelPlayerCommandSetModerator(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->_SetModerator(player, packet.Name);
}

void WorldSession::HandleChannelPlayerCommandSetMute(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->_SetMute(player, packet.Name);
}

void WorldSession::HandleChannelPlayerCommandSetOwner(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->_SetOwner(player, packet.Name);
}

void WorldSession::HandleChannelPlayerCommandSilenceAll(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->SilenceAll(player, packet.Name);
}

void WorldSession::HandleChannelPlayerCommandUnBan(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->UnBan(player, packet.Name);
}

void WorldSession::HandleChannelPlayerCommandUnsetModerator(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->UnsetModerator(player, packet.Name);
}

void WorldSession::HandleChannelPlayerCommandUnsetMute(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->UnsetMute(player, packet.Name);
}

void WorldSession::HandleChannelPlayerCommandUnsilenceAll(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() >= MAX_CHANNEL_NAME_STR || !player)
        return;

    if (!normalizePlayerName(packet.Name))
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->UnsilenceAll(player, packet.Name);
}

void WorldSession::HandleChannelPlayerCommandPassword(WorldPackets::Channel::ChannelPlayerCommand& packet)
{
    Player* player = GetPlayer();
    if (packet.Name.length() > MAX_CHANNEL_PASS_STR || !player)
        return;

    if (packet.ChannelName.empty())
        return;

    if (!ChatHandler(this).isValidChatMessage(packet.ChannelName.c_str()))
        return;

    if (ChannelMgr* cMgr = channelMgr(player->GetTeam()))
        if (Channel* channel = cMgr->GetChannel(packet.ChannelName, player))
            channel->Password(player, packet.Name);
}
