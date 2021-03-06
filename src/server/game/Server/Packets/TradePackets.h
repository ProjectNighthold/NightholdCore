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

#ifndef TradePackets_h__
#define TradePackets_h__

#include "Packet.h"
#include "ItemPackets.h"

namespace WorldPackets
{
    namespace Trade
    {
        class AcceptTrade final : public ClientPacket
        {
        public:
            AcceptTrade(WorldPacket&& packet) : ClientPacket(CMSG_ACCEPT_TRADE, std::move(packet)) { }
            
            void Read() override;

            uint32 StateIndex = 0;
        };

        class ClearTradeItem final : public ClientPacket
        {
        public:
            ClearTradeItem(WorldPacket&& packet) : ClientPacket(CMSG_CLEAR_TRADE_ITEM, std::move(packet)) { }

            void Read() override;

            uint8 TradeSlot = 0;
        };

        class InitiateTrade final : public ClientPacket
        {
        public:
            InitiateTrade(WorldPacket&& packet) : ClientPacket(CMSG_INITIATE_TRADE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };

        class SetTradeCurrency final : public ClientPacket
        {
        public:
            SetTradeCurrency(WorldPacket&& packet) : ClientPacket(CMSG_SET_TRADE_CURRENCY, std::move(packet)) { }

            void Read() override;

            uint32 Type = 0;
            uint32 Quantity = 0;
        };

        class SetTradeGold final : public ClientPacket
        {
        public:
            SetTradeGold(WorldPacket&& packet) : ClientPacket(CMSG_SET_TRADE_GOLD, std::move(packet)) { }

            void Read() override;

            uint64 Coinage = 0;
        };

        //< CMSG_BEGIN_TRADE
        //< CMSG_BUSY_TRADE,
        //< CMSG_CANCEL_TRADE
        //< CMSG_IGNORE_TRADE
        //< CMSG_UNACCEPT_TRADE
        class NullCmsg final : public ClientPacket
        {
        public:
            NullCmsg(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override { }
        };

        class SetTradeItem final : public ClientPacket
        {
        public:
            SetTradeItem(WorldPacket&& packet) : ClientPacket(CMSG_SET_TRADE_ITEM, std::move(packet)) { }

            void Read() override;

            uint8 TradeSlot = 0;
            uint8 PackSlot = 0;
            uint8 ItemSlotInPack = 0;
        };

        class TradeStatus final : public ServerPacket
        {
        public:
            TradeStatus() : ServerPacket(SMSG_TRADE_STATUS, 1 + 1 + 16 + 4 + 4 + 1 + 4 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid PartnerAccount;
            ObjectGuid Partner;
            uint32 ItemID = 0;
            uint32 ID = 0;
            int32 CurrencyType = 0;
            int32 CurrencyQuantity = 0;
            int32 BagResult = 0;
            ::TradeStatus Status = TRADE_STATUS_INITIATED;
            uint8 TradeSlot = 0;
            bool FailureForYou = false;
            bool PartnerIsSameBnetAccount = false;
        };

        class TradeUpdated final : public ServerPacket
        {
        public:
            struct UnwrappedTradeItem
            {
                std::vector<Item::ItemGemData> Gems;
                ObjectGuid Creator;
                int32 EnchantID = 0;
                int32 OnUseEnchantmentID = 0;
                int32 Charges = 0;
                uint32 MaxDurability = 0;
                uint32 Durability = 0;
                bool Lock = false;
            };

            struct TradeItem
            {
                Item::ItemInstance Item;
                Optional<UnwrappedTradeItem> Unwrapped;
                ObjectGuid GiftCreator;
                int32 StackCount = 0;
                uint8 Slot = 0;
            };

            TradeUpdated() : ServerPacket(SMSG_TRADE_UPDATED, 8 + 4 + 1 + 4 + 7 * sizeof(UnwrappedTradeItem) + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            std::vector<TradeItem> Items;
            uint64 Gold = 0;
            uint32 CurrentStateIndex = 0;
            uint32 ClientStateIndex = 0;
            uint32 ID = 0;
            int32 CurrencyType = 0;
            int32 ProposedEnchantment = 0;
            int32 CurrencyQuantity = 0;
            uint8 WhichPlayer = 0;
        };
    }
}

#endif // TradePackets_h__
