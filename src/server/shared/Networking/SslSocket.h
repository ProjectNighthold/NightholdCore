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

#ifndef SslSocket_h__
#define SslSocket_h__

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/system/error_code.hpp>

using boost::asio::ip::tcp;
namespace boostssl = boost::asio::ssl;

template<class SslContext>
class SslSocket
{
public:
    explicit SslSocket(tcp::socket&& socket) : _socket(std::move(socket)), _sslSocket(_socket, SslContext::instance())
    {
        _sslSocket.set_verify_mode(boostssl::verify_none);
    }

    // adapting tcp::socket api
    void close(boost::system::error_code& error)
    {
        _socket.close(error);
    }

    void shutdown(boost::asio::socket_base::shutdown_type what, boost::system::error_code& shutdownError)
    {
        _sslSocket.shutdown(shutdownError);
        _socket.shutdown(what, shutdownError);
    }

    template<typename MutableBufferSequence, typename ReadHandlerType>
    void async_read_some(MutableBufferSequence const& buffers, ReadHandlerType&& handler)
    {
        _sslSocket.async_read_some(buffers, std::move(handler));
    }

    template<typename ConstBufferSequence, typename WriteHandlerType>
    void async_write_some(ConstBufferSequence const& buffers, WriteHandlerType&& handler)
    {
        _sslSocket.async_write_some(buffers, std::move(handler));
    }

    template<typename ConstBufferSequence>
    std::size_t write_some(ConstBufferSequence const& buffers, boost::system::error_code& error)
    {
        return _sslSocket.write_some(buffers, error);
    }

    template<typename SettableSocketOption>
    void set_option(SettableSocketOption const& option, boost::system::error_code& error)
    {
        _socket.set_option(option, error);
    }

    tcp::socket::endpoint_type remote_endpoint() const
    {
        return _socket.remote_endpoint();
    }

    // ssl api
    template<typename HandshakeHandlerType>
    void async_handshake(boostssl::stream_base::handshake_type type, HandshakeHandlerType&& handler)
    {
        _sslSocket.async_handshake(type, std::move(handler));
    }

private:
    tcp::socket _socket;
    boostssl::stream<tcp::socket&> _sslSocket;
};

#endif // SslSocket_h__
