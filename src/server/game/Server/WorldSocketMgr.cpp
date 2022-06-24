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

#include "Config.h"
#include "NetworkThread.h"
#include "ScriptMgr.h"
#include "WorldSocket.h"
#include "WorldSocketMgr.h"
#include <boost/system/error_code.hpp>

static void OnSocketAccept(tcp::socket&& sock, uint32 threadIndex)
{
    sWorldSocketMgr.OnSocketOpen(std::forward<tcp::socket>(sock), threadIndex);
}

class WorldSocketThread : public NetworkThread<WorldSocket>
{
public:
    void SocketAdded(std::shared_ptr<WorldSocket> sock) override
    {
    }

    void SocketRemoved(std::shared_ptr<WorldSocket> sock) override
    {
    }
};

WorldSocketMgr::WorldSocketMgr() : BaseSocketMgr(), _instanceAcceptor(nullptr), _socketSendBufferSize(-1), m_SockOutUBuff(65536), _tcpNoDelay(true)
{
}

WorldSocketMgr::~WorldSocketMgr()
{
    ASSERT(!_instanceAcceptor, "StopNetwork must be called prior to WorldSocketMgr destruction");
}

WorldSocketMgr& WorldSocketMgr::Instance()
{
    static WorldSocketMgr instance;
    return instance;
}

bool WorldSocketMgr::StartNetwork(boost::asio::io_service& service, std::string const& bindIp, uint16 port, int threadCount)
{
    _tcpNoDelay = sConfigMgr->GetBoolDefault("Network.TcpNodelay", true);

    TC_LOG_DEBUG(LOG_FILTER_NETWORKIO, "Max allowed socket connections %d", boost::asio::socket_base::max_connections);

    // -1 means use default
    _socketSendBufferSize = sConfigMgr->GetIntDefault("Network.OutKBuff", -1);

    m_SockOutUBuff = sConfigMgr->GetIntDefault("Network.OutUBuff", 65536);

    if (m_SockOutUBuff <= 0)
    {
        TC_LOG_ERROR(LOG_FILTER_NETWORKIO, "Network.OutUBuff is wrong in your config file");
        return false;
    }

    BaseSocketMgr::StartNetwork(service, bindIp, port, threadCount);
    _instanceAcceptor = new AsyncAcceptor(service, bindIp, uint16(sWorld->getIntConfig(CONFIG_PORT_INSTANCE)));

    _acceptor->SetSocketFactory(std::bind(&BaseSocketMgr::GetSocketForAccept, this));
    _instanceAcceptor->SetSocketFactory(std::bind(&BaseSocketMgr::GetSocketForAccept, this));

    _acceptor->AsyncAcceptWithCallback<&OnSocketAccept>();
    _instanceAcceptor->AsyncAcceptWithCallback<&OnSocketAccept>();

    return true;
}

void WorldSocketMgr::StopNetwork()
{
    _instanceAcceptor->Close();
    BaseSocketMgr::StopNetwork();

    delete _instanceAcceptor;
    _instanceAcceptor = nullptr;
}

void WorldSocketMgr::OnSocketOpen(tcp::socket&& sock, uint32 threadIndex)
{
    // set some options here
    if (_socketSendBufferSize >= 0)
    {
        boost::system::error_code err;
        sock.set_option(boost::asio::socket_base::send_buffer_size(_socketSendBufferSize), err);
        if (err && err != boost::system::errc::not_supported)
        {
            TC_LOG_ERROR(LOG_FILTER_NETWORKIO, "WorldSocketMgr::OnSocketOpen sock.set_option(boost::asio::socket_base::send_buffer_size) err = %s", err.message().c_str());
            return;
        }
    }

    // Set TCP_NODELAY.
    if (_tcpNoDelay)
    {
        boost::system::error_code err;
        sock.set_option(boost::asio::ip::tcp::no_delay(true), err);
        if (err)
        {
            TC_LOG_ERROR(LOG_FILTER_NETWORKIO, "WorldSocketMgr::OnSocketOpen sock.set_option(boost::asio::ip::tcp::no_delay) err = %s", err.message().c_str());
            return;
        }
    }

    //sock->m_OutBufferSize = static_cast<size_t> (m_SockOutUBuff);

    BaseSocketMgr::OnSocketOpen(std::forward<tcp::socket>(sock), threadIndex);
}

NetworkThread<WorldSocket>* WorldSocketMgr::CreateThreads() const
{
    return new WorldSocketThread[GetNetworkThreadCount()];
}
