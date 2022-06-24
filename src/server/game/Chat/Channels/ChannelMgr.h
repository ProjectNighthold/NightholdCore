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

#ifndef __TRINITY_CHANNELMGR_H
#define __TRINITY_CHANNELMGR_H

#include "Common.h"
#include "Channel.h"

#include "World.h"

#define MAX_CHANNEL_NAME_STR 31
#define MAX_CHANNEL_PASS_STR 31

class ChannelMgr
{
    public:
        ChannelMgr() { team = 0; }
        ~ChannelMgr();

        uint32 team;
        typedef std::map<std::wstring, Channel*> ChannelMap;

        Channel* GetJoinChannel(std::string name, uint32 channel_id);
        Channel* GetChannel(std::string const& name, Player* player, bool notify = true);
        void LeftChannel(std::string name);

    private:
        ChannelMap channels;
        static void SendNotOnChannelNotify(Player const* player, std::string const& name);
};

ChannelMgr* channelMgr(uint32 team);

#endif
