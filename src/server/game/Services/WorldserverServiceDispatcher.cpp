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

#include "WorldserverServiceDispatcher.h"
#include "WorldserverService.h"

Battlenet::WorldserverServiceDispatcher::WorldserverServiceDispatcher()
{
    AddService<WorldserverService<account::v1::AccountService>>();
    AddService<WorldserverService<authentication::v1::AuthenticationService>>();
    AddService<WorldserverService<challenge::v1::ChallengeService>>();
    AddService<WorldserverService<channel::v1::ChannelService>>();
    AddService<WorldserverService<connection::v1::ConnectionService>>();
    AddService<WorldserverService<friends::v1::FriendsService>>();
    AddService<GameUtilitiesService>();
    AddService<WorldserverService<presence::v1::PresenceService>>();
    AddService<WorldserverService<report::v1::ReportService>>();
    AddService<WorldserverService<resources::v1::ResourcesService>>();
    AddService<WorldserverService<user_manager::v1::UserManagerService>>();
}

void Battlenet::WorldserverServiceDispatcher::Dispatch(WorldSession* session, uint32 serviceHash, uint32 token, uint32 methodId, MessageBuffer buffer)
{
    auto itr = _dispatchers.find(serviceHash);
    if (itr != _dispatchers.end())
        itr->second(session, token, methodId, std::forward<MessageBuffer>(buffer));
    else
        TC_LOG_DEBUG(LOG_FILTER_BATTLENET, "%s tried to call invalid service 0x%X", session->GetPlayerName().c_str(), serviceHash);
}

Battlenet::WorldserverServiceDispatcher& Battlenet::WorldserverServiceDispatcher::Instance()
{
    static WorldserverServiceDispatcher instance;
    return instance;
}
