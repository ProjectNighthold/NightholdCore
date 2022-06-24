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

#ifndef TRINITY_PACKETLOG_H
#define TRINITY_PACKETLOG_H

#include <mutex>

#include "Common.h"

namespace boost
{
    namespace asio
    {
        namespace ip
        {
            class address;
        }
    }
}

enum Direction
{
    CLIENT_TO_SERVER,
    SERVER_TO_CLIENT
};

class WorldPacket;
enum ConnectionType;

class PacketLog
{
public:
    static PacketLog* instance();

    void Initialize();
    void LogPacket(WorldPacket const& packet, Direction direction, boost::asio::ip::address const& addr, uint16 port, ConnectionType connectionType);

private:
    PacketLog();
    ~PacketLog();

    std::mutex _logPacketLock;
    std::once_flag _initializeFlag;
    FILE* _file;
};

#define sPacketLog PacketLog::instance()
#endif
