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

#include "BattlenetPackets.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Battlenet::MethodCall const& method)
{
    data << uint64(method.Type);
    data << uint64(method.ObjectId);
    data << uint32(method.Token);
    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Battlenet::MethodCall& method)
{
    data >> method.Type;
    data >> method.ObjectId;
    data >> method.Token;
    return data;
}

WorldPacket const* WorldPackets::Battlenet::Notification::Write()
{
    _worldPacket << Method;
    _worldPacket << uint32(Data.size());
    _worldPacket.append(Data);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battlenet::Response::Write()
{
    _worldPacket << uint32(BnetStatus);
    _worldPacket << Method;
    _worldPacket << uint32(Data.size());
    _worldPacket.append(Data);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battlenet::SetSessionState::Write()
{
    _worldPacket.WriteBits(State, 2);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Battlenet::RealmListTicket::Write()
{
    _worldPacket << uint32(Token);
    _worldPacket.WriteBit(Allow);
    _worldPacket << uint32(Ticket.size());
    _worldPacket.append(Ticket);

    return &_worldPacket;
}

void WorldPackets::Battlenet::Request::Read()
{
    uint32 protoSize;

    _worldPacket >> Method;
    _worldPacket >> protoSize;

    Data.Resize(protoSize);
    _worldPacket.read(Data.GetWritePointer(), Data.GetRemainingSpace());
    Data.WriteCompleted(protoSize);
}

void WorldPackets::Battlenet::RequestRealmListTicket::Read()
{
    _worldPacket >> Token;
    _worldPacket.read(Secret.data(), Secret.size());
}
