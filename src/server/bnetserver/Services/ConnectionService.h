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

#ifndef ConnectionService_h__
#define ConnectionService_h__

#include "Common.h"
#include "Service.h"
#include "connection_service.pb.h"

namespace Battlenet
{
    class Session;

    namespace Services
    {
        class Connection : public Service<connection::v1::ConnectionService>
        {
            typedef Service<connection::v1::ConnectionService> ConnectionService;

        public:
            Connection(Session* session);

            uint32 HandleConnect(connection::v1::ConnectRequest const* request, connection::v1::ConnectResponse* respons) override;
            uint32 HandleKeepAlive(NoData const* request) override;
            uint32 HandleRequestDisconnect(connection::v1::DisconnectRequest const* request) override;

        };
    }
}

#endif // ConnectionService_h__
