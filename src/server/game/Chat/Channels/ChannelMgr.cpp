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

#include "ChannelMgr.h"
#include "ChannelPackets.h"
#include "World.h"

ChannelMgr* channelMgr(uint32 team)
{
    static ChannelMgr allianceChannelMgr;
    static ChannelMgr hordeChannelMgr;
    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL))
        return &allianceChannelMgr;        // cross-faction

    if (team == ALLIANCE)
        return &allianceChannelMgr;

    if (team == HORDE)
        return &hordeChannelMgr;

    return nullptr;
}

ChannelMgr::~ChannelMgr()
{
    for (auto const& v : channels)
        delete v.second;

    channels.clear();
}

Channel* ChannelMgr::GetJoinChannel(std::string name, uint32 channel_id)
{
    std::wstring wname;
    if (!Utf8toWStr(name, wname))
        return nullptr;

    wstrToLower(wname);

    if (channels.find(wname) == channels.end())
    {
        auto nchan = new Channel(name, channel_id, team);
        channels[wname] = nchan;
        return nchan;
    }

    return channels[wname];
}

Channel* ChannelMgr::GetChannel(std::string const& name, Player* player, bool notify /*= true*/)
{
    std::wstring wname;
    if (!Utf8toWStr(name, wname))
        return nullptr;

    wstrToLower(wname);

    ChannelMap::const_iterator i = channels.find(wname);
    if (i == channels.end())
    {
        if (notify)
            SendNotOnChannelNotify(player, name);

        return nullptr;
    }

    return i->second;
}

void ChannelMgr::LeftChannel(std::string name)
{
    std::wstring wname;
    Utf8toWStr(name, wname);
    wstrToLower(wname);

    ChannelMap::const_iterator i = channels.find(wname);
    if (i == channels.end())
        return;

    Channel* channel = i->second;

    if (channel->GetNumPlayers() == 0 && !channel->IsConstant())
    {
        channels.erase(wname);
        delete channel;
    }
}

void ChannelMgr::SendNotOnChannelNotify(Player const* player, std::string const& name)
{
    WorldPackets::Channel::ChannelNotify notify;
    notify.Type = CHAT_NOT_MEMBER_NOTICE;
    notify._Channel = name;
    player->SendDirectMessage(notify.Write());
}
