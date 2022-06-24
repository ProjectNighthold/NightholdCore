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

#ifndef PacketBaseWorld_h__
#define PacketBaseWorld_h__

#include "WorldPacket.h"

namespace WorldPackets
{
    class Packet
    {
    public:
        Packet(WorldPacket&& worldPacket);

        virtual ~Packet() = default;

        Packet(Packet const& right) = delete;
        Packet& operator=(Packet const& right) = delete;

        virtual WorldPacket const* Write() = 0;
        virtual void Read() = 0;

        WorldPacket const* GetRawPacket() const;
        size_t GetSize() const;
        ConnectionType GetConnection() const;

    protected:
        WorldPacket _worldPacket;
    };

    class ServerPacket : public Packet
    {
    public:
        ServerPacket(OpcodeServer opcode, size_t initialSize = 200, ConnectionType connection = CONNECTION_TYPE_DEFAULT);

        void Read() override final;

        void Clear();
        WorldPacket&& Move();
        OpcodeServer GetOpcode() const;
    };

    class ClientPacket : public Packet
    {
    public:
        ClientPacket(WorldPacket&& packet);
        ClientPacket(OpcodeClient expectedOpcode, WorldPacket&& packet);

        WorldPacket const* Write() override final;
        OpcodeClient GetOpcode() const;
    };
}

#endif // PacketBaseWorld_h__
