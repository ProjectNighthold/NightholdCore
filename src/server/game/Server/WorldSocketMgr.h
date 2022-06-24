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

/** \addtogroup u2w User to World Communication
 *  @{
 *  \file WorldSocketMgr.h
 *  \author Derex <derex101@gmail.com>
 */

#ifndef __WORLDSOCKETMGR_H
#define __WORLDSOCKETMGR_H

#include "SocketMgr.h"

class WorldSocket;

/// Manages all sockets connected to peers and network threads
class WorldSocketMgr : public SocketMgr<WorldSocket>
{
    typedef SocketMgr<WorldSocket> BaseSocketMgr;

public:
    ~WorldSocketMgr();

    static WorldSocketMgr& Instance();

    /// Start network, listen at address:port .
    bool StartNetwork(boost::asio::io_service& service, std::string const& bindIp, uint16 port, int networkThreads) override;

    /// Stops all network threads, It will wait for all running threads .
    void StopNetwork() override;

    void OnSocketOpen(tcp::socket&& sock, uint32 threadIndex) override;

protected:
    WorldSocketMgr();

    NetworkThread<WorldSocket>* CreateThreads() const override;

private:
    AsyncAcceptor* _instanceAcceptor;
    int32 _socketSendBufferSize;
    int32 m_SockOutUBuff;
    bool _tcpNoDelay;
};

#define sWorldSocketMgr WorldSocketMgr::Instance()

#endif
/// @}
