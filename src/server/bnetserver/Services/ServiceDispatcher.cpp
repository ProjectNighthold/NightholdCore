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

#include "ServiceDispatcher.h"

Battlenet::ServiceDispatcher::ServiceDispatcher()
{
    AddService<Services::Account>();
    AddService<Services::Authentication>();
    AddService<Service<challenge::v1::ChallengeService>>();
    AddService<Service<channel::v1::ChannelService>>();
    AddService<Services::Connection>();
    AddService<Service<friends::v1::FriendsService>>();
    AddService<Services::GameUtilities>();
    AddService<Service<presence::v1::PresenceService>>();
    AddService<Service<report::v1::ReportService>>();
    AddService<Service<resources::v1::ResourcesService>>();
    AddService<Service<user_manager::v1::UserManagerService>>();
}

void Battlenet::ServiceDispatcher::Dispatch(Session* session, uint32 serviceHash, uint32 token, uint32 methodId, MessageBuffer buffer)
{
    auto itr = _dispatchers.find(serviceHash);
    if (itr != _dispatchers.end())
        itr->second(session, token, methodId, std::forward<MessageBuffer>(buffer));
    else
        TC_LOG_ERROR(LOG_FILTER_BNET_SESSION, "%s tried to call invalid service 0x%X", session->GetClientInfo().c_str(), serviceHash);
}

Battlenet::ServiceDispatcher& Battlenet::ServiceDispatcher::Instance()
{
    static ServiceDispatcher instance;
    return instance;
}
