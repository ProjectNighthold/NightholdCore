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

#include "Common.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "ClientConfigPackets.h"
#include "zlib.h"

void WorldSession::HandleRequestAccountData(WorldPackets::ClientConfig::RequestAccountData& request)
{
    if (request.DataType >= NUM_ACCOUNT_DATA_TYPES)
        return;

    AccountData const* adata = GetAccountData(AccountDataType(request.DataType));

    WorldPackets::ClientConfig::UpdateAccountData data;
    data.Player = _player ? _player->GetGUID() : ObjectGuid::Empty;
    data.Time = adata->Time;
    data.Size = adata->Data.size();
    data.DataType = request.DataType;

    if (data.Size)
    {
        auto destSize = compressBound(data.Size);
        data.CompressedData.resize(destSize);
        if (compress(data.CompressedData.contents(), &destSize, reinterpret_cast<uint8 const*>(adata->Data.c_str()), data.Size) != Z_OK)
        {
            TC_LOG_ERROR(LOG_FILTER_NETWORKIO, "RAD: Failed to compress account data");
            return;
        }

        data.CompressedData.resize(destSize);
    }

    SendPacket(data.Write());
}

void WorldSession::HandleUpdateAccountData(WorldPackets::ClientConfig::UserClientUpdateAccountData& packet)
{
    if (packet.DataType > NUM_ACCOUNT_DATA_TYPES)
        return;

    if (packet.Size == 0)
    {
        SetAccountData(AccountDataType(packet.DataType));
        return;
    }

    if (packet.Size > 0xFFFF)
    {
        TC_LOG_ERROR(LOG_FILTER_NETWORKIO, "UAD: Account data packet too big, size %u", packet.Size);
        return;
    }

    ByteBuffer dest;
    dest.resize(packet.Size);

    uLongf realSize = packet.Size;
    if (uncompress(dest.contents(), &realSize, packet.CompressedData.contents(), packet.CompressedData.size()) != Z_OK)
    {
        TC_LOG_ERROR(LOG_FILTER_NETWORKIO, "UAD: Failed to decompress account data");
        return;
    }

    std::string adata;
    dest >> adata;

    SetAccountData(AccountDataType(packet.DataType), packet.Time, adata);
}

void WorldSession::HandleUpdateClientSettings(WorldPackets::ClientConfig::UpdateClientSettings& /*packet*/)
{ }

void WorldSession::HandleSaveClientVariables(WorldPackets::ClientConfig::SaveClientVariables& /*packet*/)
{ }

void WorldSession::HandleGetRemainingGameTime(WorldPackets::ClientConfig::GetRemainingGameTime& /*packet*/)
{ }
