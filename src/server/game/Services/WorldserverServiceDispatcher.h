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

#ifndef ServiceRegistry_h__
#define ServiceRegistry_h__

#include "WorldSession.h"
#include "MessageBuffer.h"
#include "Common.h"
#include "account_service.pb.h"
#include "authentication_service.pb.h"
#include "challenge_service.pb.h"
#include "channel_service.pb.h"
#include "connection_service.pb.h"
#include "friends_service.pb.h"
#include "game_utilities_service.pb.h"
#include "presence_service.pb.h"
#include "report_service.pb.h"
#include "resource_service.pb.h"
#include "user_manager_service.pb.h"

namespace Battlenet
{
    class WorldserverServiceDispatcher
    {
    public:
        void Dispatch(WorldSession* session, uint32 serviceHash, uint32 token, uint32 methodId, MessageBuffer buffer);

        static WorldserverServiceDispatcher& Instance();

    private:
        WorldserverServiceDispatcher();

        template<class Service>
        void AddService()
        {
            _dispatchers[Service::NameHash::value] = &WorldserverServiceDispatcher::Dispatch<Service>;
        }

        template<class Service>
        static void Dispatch(WorldSession* session, uint32 token, uint32 methodId, MessageBuffer buffer)
        {
            Service(session).CallServerMethod(token, methodId, std::forward<MessageBuffer>(buffer));
        }

        std::unordered_map<uint32, std::function<void(WorldSession*, uint32, uint32, MessageBuffer)>> _dispatchers;
    };
}

#define sServiceDispatcher Battlenet::WorldserverServiceDispatcher::Instance()

#endif // ServiceRegistry_h__
