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

#include "TradePackets.h"

void WorldPackets::Trade::AcceptTrade::Read()
{
    _worldPacket >> StateIndex;
}

void WorldPackets::Trade::ClearTradeItem::Read()
{
    _worldPacket >> TradeSlot;
}

void WorldPackets::Trade::InitiateTrade::Read()
{
    _worldPacket >> Guid;
}

void WorldPackets::Trade::SetTradeCurrency::Read()
{
    _worldPacket >> Type;
    _worldPacket >> Quantity;
}

void WorldPackets::Trade::SetTradeGold::Read()
{
    _worldPacket >> Coinage;
}

void WorldPackets::Trade::SetTradeItem::Read()
{
    _worldPacket >> TradeSlot;
    _worldPacket >> PackSlot;
    _worldPacket >> ItemSlotInPack;
}

WorldPacket const* WorldPackets::Trade::TradeStatus::Write()
{
    _worldPacket.WriteBit(PartnerIsSameBnetAccount);
    _worldPacket.WriteBits(Status, 5);
    switch (Status)
    {
        case TRADE_STATUS_FAILED:
            _worldPacket.WriteBit(FailureForYou);
            _worldPacket << int32(BagResult);
            _worldPacket << int32(ItemID);
            break;
        case TRADE_STATUS_INITIATED:
            _worldPacket << uint32(ID);
            break;
        case TRADE_STATUS_PROPOSED:
            _worldPacket << Partner;
            _worldPacket << PartnerAccount;
            break;
        case TRADE_STATUS_WRONG_REALM:
        case TRADE_STATUS_NOT_ON_TAPLIST:
            _worldPacket << uint8(TradeSlot);
            break;
        case TRADE_STATUS_NOT_ENOUGH_CURRENCY:
        case TRADE_STATUS_CURRENCY_NOT_TRADABLE:
            _worldPacket << int32(CurrencyType);
            _worldPacket << int32(CurrencyQuantity);
            break;
        default:
            _worldPacket.FlushBits();
            break;
    }

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& buffer, WorldPackets::Trade::TradeUpdated::UnwrappedTradeItem const& unwrappedTradeItem)
{
    buffer << int32(unwrappedTradeItem.EnchantID);
    buffer << int32(unwrappedTradeItem.OnUseEnchantmentID);
    buffer << unwrappedTradeItem.Creator;
    buffer << int32(unwrappedTradeItem.Charges);
    buffer << uint32(unwrappedTradeItem.MaxDurability);
    buffer << uint32(unwrappedTradeItem.Durability);
    buffer.WriteBits(unwrappedTradeItem.Gems.size(), 2);
    buffer.WriteBit(unwrappedTradeItem.Lock);
    buffer.FlushBits();

    for (auto const& gem : unwrappedTradeItem.Gems)
        buffer << gem;

    return buffer;
}

ByteBuffer& operator<<(ByteBuffer& buffer, WorldPackets::Trade::TradeUpdated::TradeItem const& tradeItem)
{
    buffer << uint8(tradeItem.Slot);
    buffer << uint32(tradeItem.StackCount);
    buffer << tradeItem.GiftCreator;
    buffer << tradeItem.Item;
    buffer.WriteBit(tradeItem.Unwrapped.is_initialized());
    buffer.FlushBits();
    if (tradeItem.Unwrapped)
        buffer << *tradeItem.Unwrapped;

    return buffer;
}

WorldPacket const* WorldPackets::Trade::TradeUpdated::Write()
{
    _worldPacket << uint8(WhichPlayer);
    _worldPacket << uint32(ID);
    _worldPacket << uint32(CurrentStateIndex);
    _worldPacket << uint32(ClientStateIndex);
    _worldPacket << uint64(Gold);
    _worldPacket << int32(CurrencyType);
    _worldPacket << int32(CurrencyQuantity);
    _worldPacket << int32(ProposedEnchantment);
    _worldPacket << static_cast<uint32>(Items.size());
    for (TradeItem const& item : Items)
        _worldPacket << item;

    return &_worldPacket;
}
