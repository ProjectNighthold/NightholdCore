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

#ifndef __RASESSION_H__
#define __RASESSION_H__

#include <memory>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>
#include "Common.h"

#include <future>

using boost::asio::ip::tcp;

const size_t bufferSize = 4096;

#define BUFFER_SIZE 4096

class RASession : public std::enable_shared_from_this <RASession>
{
public:
    RASession(tcp::socket&& socket) : _socket(std::move(socket)), _commandExecuting(nullptr)
    {
    }

    void Start();

    const std::string GetRemoteIpAddress() const { return _socket.remote_endpoint().address().to_string(); }
    unsigned short GetRemotePort() const { return _socket.remote_endpoint().port(); }

    boost::asio::streambuf _readBuffer;
    boost::asio::streambuf _writeBuffer;

private:
    int Send(const char* data);
    std::string ReadString();
    bool CheckAccessLevel(const std::string& user);
    bool CheckPassword(const std::string& user, const std::string& pass);
    bool ProcessCommand(std::string& command);

    static void CommandPrint(void* callbackArg, const char* text);
    static void CommandFinished(void* callbackArg, bool);

    tcp::socket _socket;
    std::promise<void>* _commandExecuting;
};

#endif
