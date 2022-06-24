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

#include "MessageBuffer.h"
#include "Log.h"
#include "Common.h"
#include "AccountService.h"
#include "AuthenticationService.h"
#include "challenge_service.pb.h"
#include "channel_service.pb.h"
#include "ConnectionService.h"
#include "friends_service.pb.h"
#include "GameUtilitiesService.h"
#include "presence_service.pb.h"
#include "report_service.pb.h"
#include "resource_service.pb.h"
#include "user_manager_service.pb.h"

namespace Battlenet
{
    class Session;

    class ServiceDispatcher
    {
    public:
        void Dispatch(Session* session, uint32 serviceHash, uint32 token, uint32 methodId, MessageBuffer buffer);

        static ServiceDispatcher& Instance();

    private:
        ServiceDispatcher();

        template<class Service>
        void AddService()
        {
            _dispatchers[Service::OriginalHash::value] = &ServiceDispatcher::Dispatch<Service>;
        }

        template<class Service>
        static void Dispatch(Session* session, uint32 token, uint32 methodId, MessageBuffer buffer)
        {
            Service(session).CallServerMethod(token, methodId, std::forward<MessageBuffer>(buffer));
        }

        std::unordered_map<uint32, std::function<void(Session*, uint32, uint32, MessageBuffer)>> _dispatchers;
    };
}

#define sServiceDispatcher ServiceDispatcher::Instance()

#endif // ServiceRegistry_h__
