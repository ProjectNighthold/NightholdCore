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

#include "BlackMarketPackets.h"
#include "BlackMarketMgr.h"
#include "Player.h"

void WorldPackets::BlackMarket::BlackMarketItem::Initialize(BlackMarketEntry* const entry, Player* player)
{
    BlackMarketTemplate* templ = entry->GetTemplate();

    MarketID = entry->GetMarketId();
    SellerNPC = templ->SellerNPC;
    Item = templ->Item;
    Quantity = templ->Quantity;

    if (!entry->GetNumBids())
    {
        MinBid = templ->MinBid;
        MinIncrement = 1;
    }
    else
    {
        MinIncrement = entry->GetMinIncrement();
        MinBid = entry->GetCurrentBid() + MinIncrement;
    }

    CurrentBid = entry->GetCurrentBid();
    SecondsRemaining = entry->GetSecondsRemaining();
    HighBid = (entry->GetBidder() == player->GetGUIDLow());
    NumBids = entry->GetNumBids();
}

void WorldPackets::BlackMarket::BlackMarketOpen::Read()
{
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::BlackMarket::BlackMarketOpenResult::Write()
{
    _worldPacket << Guid;
    _worldPacket.WriteBit(Enable);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::BlackMarket::BlackMarketRequestItems::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> LastUpdateID;
}

WorldPacket const* WorldPackets::BlackMarket::BlackMarketRequestItemsResult::Write()
{
    _worldPacket << int32(LastUpdateID);
    _worldPacket << uint32(Items.size());

    for (auto const&  item : Items)
        _worldPacket << item;

    return &_worldPacket;
}

void WorldPackets::BlackMarket::BlackMarketBidOnItem::Read()
{
    _worldPacket >> Guid;
    _worldPacket >> MarketID;
    _worldPacket >> BidAmount;
    _worldPacket >> Item;
}

WorldPacket const* WorldPackets::BlackMarket::BlackMarketBidOnItemResult::Write()
{
    _worldPacket << int32(MarketID);
    _worldPacket << int32(Result);
    _worldPacket << Item;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::BlackMarket::BlackMarketOutbid::Write()
{
    _worldPacket << int32(MarketID);
    _worldPacket << int32(RandomPropertiesID);
    _worldPacket << Item;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::BlackMarket::BlackMarketWon::Write()
{
    _worldPacket << int32(MarketID);
    _worldPacket << int32(RandomPropertiesID);
    _worldPacket << Item;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BlackMarket::BlackMarketItem const& blackMarketItem)
{
    data << int32(blackMarketItem.MarketID);
    data << int32(blackMarketItem.SellerNPC);
    data << int32(blackMarketItem.Quantity);
    data << uint64(blackMarketItem.MinBid);
    data << uint64(blackMarketItem.MinIncrement);
    data << uint64(blackMarketItem.CurrentBid);
    data << int32(blackMarketItem.SecondsRemaining);
    data << int32(blackMarketItem.NumBids);
    data << blackMarketItem.Item;
    data.WriteBit(blackMarketItem.HighBid);
    data.FlushBits();

    return data;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::BlackMarket::BlackMarketItem& blackMarketItem)
{
    data >> blackMarketItem.MarketID;
    data >> blackMarketItem.SellerNPC;
    data >> blackMarketItem.Item;
    data >> blackMarketItem.Quantity;
    data >> blackMarketItem.MinBid;
    data >> blackMarketItem.MinIncrement;
    data >> blackMarketItem.CurrentBid;
    data >> blackMarketItem.SecondsRemaining;
    data >> blackMarketItem.NumBids;
    blackMarketItem.HighBid = data.ReadBit();

    return data;
}