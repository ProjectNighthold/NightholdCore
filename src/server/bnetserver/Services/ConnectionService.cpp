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

#include "ConnectionService.h"
#include "Duration.h"
#include "Log.h"
#include "Session.h"
#include "Util.h"
#include "BattlenetRpcErrorCodes.h"

Battlenet::Services::Connection::Connection(Session* session) : ConnectionService(session)
{
}

uint32 Battlenet::Services::Connection::HandleConnect(connection::v1::ConnectRequest const* request, connection::v1::ConnectResponse* response)
{
    if (request->has_client_id())
        response->mutable_client_id()->CopyFrom(request->client_id());

    std::chrono::system_clock::duration now = std::chrono::system_clock::now().time_since_epoch();

    response->mutable_server_id()->set_label(GetPID());
    response->mutable_server_id()->set_epoch(std::chrono::duration_cast<Seconds>(now).count());
    response->set_server_time(std::chrono::duration_cast<Milliseconds>(now).count());

    response->set_use_bindless_rpc(request->use_bindless_rpc());
    return ERROR_OK;
}

uint32 Battlenet::Services::Connection::HandleKeepAlive(NoData const* /*request*/)
{
    return ERROR_OK;
}

uint32 Battlenet::Services::Connection::HandleRequestDisconnect(connection::v1::DisconnectRequest const* request)
{
    connection::v1::DisconnectNotification disconnectNotification;
    disconnectNotification.set_error_code(request->error_code());
    ForceDisconnect(&disconnectNotification);

    _session->DelayedCloseSocket();
    return ERROR_OK;
}
