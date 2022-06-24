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

#include "HotfixPackets.h"
#include "PacketUtilities.h"

void WorldPackets::Hotfix::DBQueryBulk::Read()
{
    _worldPacket >> TableHash;

    uint32 count = _worldPacket.ReadBits(13);

    Queries.resize(count);
    for (uint32 i = 0; i < count; ++i)
    {
        _worldPacket >> Queries[i].GUID;
        _worldPacket >> Queries[i].RecordID;
    }
}

WorldPacket const* WorldPackets::Hotfix::DBReply::Write()
{
    _worldPacket << TableHash;
    _worldPacket << RecordID;
    _worldPacket << Timestamp;

    _worldPacket.WriteBit(Allow);
    _worldPacket << static_cast<uint32>(Data.size());
    _worldPacket.append(Data);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Hotfix::AvailableHotfixes::Write()
{
    _worldPacket << int32(HotfixCacheVersion);
    _worldPacket << static_cast<uint32>(Hotfixes.size());
    for (auto const& hotfixEntry : Hotfixes)
        _worldPacket << uint64(hotfixEntry.first);

    return &_worldPacket;
}

void WorldPackets::Hotfix::HotfixRequest::Read()
{
    auto hotfixCount = _worldPacket.read<uint32>();
    if (hotfixCount > sDB2Manager.GetHotfixData().size())
        throw PacketArrayMaxCapacityException(hotfixCount, sDB2Manager.GetHotfixData().size());

    Hotfixes.resize(hotfixCount);
    for (auto& hotfixId : Hotfixes)
        _worldPacket >> hotfixId;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Hotfix::HotfixData const& hotfixData)
{
    data << uint64(hotfixData.ID);
    data << int32(hotfixData.RecordID);
    data.WriteBit(hotfixData.Data.is_initialized());
    if (hotfixData.Data.is_initialized())
    {
        data << uint32(hotfixData.Data->size());
        data.append(*hotfixData.Data);
    }
    else
        data << uint32(0);

    return data;
}

WorldPacket const* WorldPackets::Hotfix::HotfixResponse::Write()
{
    _worldPacket << uint32(Hotfixes.size());
    for (auto const& hotfix : Hotfixes)
        _worldPacket << hotfix;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Hotfix::HotfixMessage::Write()
{
    _worldPacket << uint32(Hotfixes.size());
    for (auto const& hotfix : Hotfixes)
        _worldPacket << hotfix;

    return &_worldPacket;
}
