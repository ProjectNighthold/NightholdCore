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

#include "Packet.h"
#include "Errors.h"

WorldPackets::Packet::Packet(WorldPacket&& worldPacket)
    : _worldPacket(std::move(worldPacket))
{
}

WorldPacket const* WorldPackets::Packet::GetRawPacket() const
{
    return &_worldPacket;
}

size_t WorldPackets::Packet::GetSize() const
{
    return _worldPacket.size();
}

ConnectionType WorldPackets::Packet::GetConnection() const
{
    return _worldPacket.GetConnection();
}

WorldPackets::ServerPacket::ServerPacket(OpcodeServer opcode, size_t initialSize /*= 200*/, ConnectionType connection /*= CONNECTION_TYPE_DEFAULT*/)
    : Packet(WorldPacket(opcode, initialSize, connection))
{
}

void WorldPackets::ServerPacket::Read()
{
    ASSERT(!"Read not implemented for server packets.");
}

void WorldPackets::ServerPacket::Clear()
{
    _worldPacket.clear();
}

WorldPacket&& WorldPackets::ServerPacket::Move()
{
    return std::move(_worldPacket);
}

OpcodeServer WorldPackets::ServerPacket::GetOpcode() const
{
    return OpcodeServer(_worldPacket.GetOpcode());
}

WorldPackets::ClientPacket::ClientPacket(OpcodeClient expectedOpcode, WorldPacket&& packet)
    : Packet(std::move(packet))
{
    ASSERT(GetOpcode() == expectedOpcode);
}

WorldPackets::ClientPacket::ClientPacket(WorldPacket&& packet)
    : Packet(std::move(packet))
{
}

WorldPacket const* WorldPackets::ClientPacket::Write()
{
    ASSERT(!"Write not allowed for client packets.");
    // Shut up some compilers
    return nullptr;
}

OpcodeClient WorldPackets::ClientPacket::GetOpcode() const
{
    return OpcodeClient(_worldPacket.GetOpcode());
}
