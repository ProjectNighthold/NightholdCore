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

#include "TokenPackets.h"

void WorldPackets::Token::UpdateListedAuctionableTokens::Read()
{
    _worldPacket >> Type;
}

WorldPacket const* WorldPackets::Token::UpdateListedAuctionableTokensResponse::Write()
{
    _worldPacket << UnkInt;
    _worldPacket << Result;
    _worldPacket << static_cast<uint32>(AuctionableTokenAuctionableList.size());
    for (auto const& v : AuctionableTokenAuctionableList)
    {
        _worldPacket << v.DistributionID;
        _worldPacket << v.DateCreated;
        _worldPacket << v.Owner;
        _worldPacket << v.BuyoutPrice;
        _worldPacket << v.EndTime;
    }

    return &_worldPacket;
}

void WorldPackets::Token::RequestWowTokenMarketPrice::Read()
{
    _worldPacket >> UnkInt;
}

WorldPacket const* WorldPackets::Token::WowTokenMarketPriceResponse::Write()
{
    _worldPacket << CurrentMarketPrice;
    _worldPacket << UnkInt;
    _worldPacket << Result;
    _worldPacket << UnkInt2;

    return &_worldPacket;
}

void WorldPackets::Token::CheckVeteranTokenEligibility::Read()
{
    _worldPacket >> UnkInt;
}

WorldPacket const* WorldPackets::Token::WowTokenCanVeteranBuyResult::Write()
{
    _worldPacket << UnkLong;
    _worldPacket << UnkInt;
    _worldPacket << UnkInt2;

    return &_worldPacket;
}
