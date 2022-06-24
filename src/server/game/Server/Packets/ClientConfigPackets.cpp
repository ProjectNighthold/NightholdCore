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

#include "ClientConfigPackets.h"

WorldPacket const* WorldPackets::ClientConfig::AccountDataTimes::Write()
{
    _worldPacket << PlayerGuid;
    _worldPacket << uint32(ServerTime);
    _worldPacket.append(AccountTimes, NUM_ACCOUNT_DATA_TYPES);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ClientConfig::ClientCacheVersion::Write()
{
    _worldPacket << uint32(CacheVersion);

    return &_worldPacket;
}

void WorldPackets::ClientConfig::RequestAccountData::Read()
{
    _worldPacket >> PlayerGuid;
    DataType = _worldPacket.ReadBits(3);
}

WorldPacket const* WorldPackets::ClientConfig::UpdateAccountData::Write()
{
    _worldPacket << Player;
    _worldPacket << uint32(Time);
    _worldPacket << uint32(Size);
    _worldPacket.WriteBits(DataType, 3);
    _worldPacket << static_cast<uint32>(CompressedData.size());
    _worldPacket.append(CompressedData);

    return &_worldPacket;
}

void WorldPackets::ClientConfig::UserClientUpdateAccountData::Read()
{
    _worldPacket >> PlayerGuid;
    _worldPacket >> Time;
    _worldPacket >> Size;
    DataType = _worldPacket.ReadBits(3);

    uint32 compressedSize = _worldPacket.read<uint32>();
    if (compressedSize)
    {
        CompressedData.resize(compressedSize);
        _worldPacket.read(CompressedData.contents(), compressedSize);
    }
}

void WorldPackets::ClientConfig::SetAdvancedCombatLogging::Read()
{
    Enable = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::ClientConfig::TwitterStatus::Write()
{
    _worldPacket << StatusInt;

    return &_worldPacket;
}

void WorldPackets::ClientConfig::UpdateClientSettings::Read()
{
    _worldPacket >> FarClip;
}

WorldPacket const* WorldPackets::ClientConfig::CacheInfo::Write()
{
    _worldPacket << static_cast<uint32>(Data.size());
    _worldPacket.WriteBits(Signature.length(), 6);
    for (auto const& v : Data)
    {
        _worldPacket.WriteBits(v.VariableName.length(), 6);
        _worldPacket.WriteBits(v.Value.length(), 6);
        _worldPacket << v.VariableName;
        _worldPacket << v.Value;
    }

    _worldPacket << Signature;

    return &_worldPacket;
}

void WorldPackets::ClientConfig::SaveClientVariables::Read()
{
    Varables.resize(_worldPacket.read<uint32>());
    for (auto &v : Varables)
    {
        uint32 len1 = _worldPacket.ReadBits(6);
        uint32 len2 = _worldPacket.ReadBits(10);
        v.VariableName = _worldPacket.ReadString(len1);
        v.Value = _worldPacket.ReadString(len2);
    }
}

void WorldPackets::ClientConfig::GetRemainingGameTime::Read()
{
    _worldPacket >> Time;
}
