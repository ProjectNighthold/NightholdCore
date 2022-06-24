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

#ifndef SessionManager_h__
#define SessionManager_h__

#include "SocketMgr.h"
#include "Session.h"

namespace Battlenet
{
    class SessionManager : public SocketMgr<Session>
    {
        typedef SocketMgr<Session> BaseSocketMgr;

    public:
        static SessionManager& Instance();

        bool StartNetwork(boost::asio::io_service& service, std::string const& bindIp, uint16 port, int threadCount = 1) override;

    protected:
        NetworkThread<Session>* CreateThreads() const override;

    private:
        static void OnSocketAccept(tcp::socket&& sock, uint32 threadIndex);
    };
}

#define sSessionMgr Battlenet::SessionManager::Instance()

#endif // SessionManager_h__
