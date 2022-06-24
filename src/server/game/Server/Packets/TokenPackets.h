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

#ifndef TokenPackets_h__
#define TokenPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Token
    {
        class UpdateListedAuctionableTokens final : public ClientPacket
        {
        public:
            UpdateListedAuctionableTokens(WorldPacket&& packet) : ClientPacket(CMSG_UPDATE_WOW_TOKEN_AUCTIONABLE_LIST, std::move(packet)) { }

            void Read() override;

            uint32 Type = 0;
        };

        class UpdateListedAuctionableTokensResponse final : public ServerPacket
        {
        public:
            UpdateListedAuctionableTokensResponse() : ServerPacket(SMSG_WOW_TOKEN_UPDATE_AUCTIONABLE_LIST_RESPONSE, 12) { }

            WorldPacket const* Write() override;

            struct AuctionableTokenAuctionable
            {
                uint64 DistributionID = 0;
                uint32 DateCreated = 0;
                uint32 Owner = 0;
                uint64 BuyoutPrice = 0;
                uint32 EndTime = 0;
            };

            uint32 UnkInt = 0; // send CMSG_UPDATE_WOW_TOKEN_AUCTIONABLE_LIST
            uint32 Result = 0;
            std::vector<AuctionableTokenAuctionable> AuctionableTokenAuctionableList;
        };

        class RequestWowTokenMarketPrice final : public ClientPacket
        {
        public:
            RequestWowTokenMarketPrice(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_WOW_TOKEN_MARKET_PRICE, std::move(packet)) { }

            void Read() override;

            uint32 UnkInt = 0;
        };

        class WowTokenMarketPriceResponse final : public ServerPacket
        {
        public:
            WowTokenMarketPriceResponse() : ServerPacket(SMSG_WOW_TOKEN_MARKET_PRICE_RESPONSE, 8 + 4 * 3) { }

            WorldPacket const* Write() override;

            uint64 CurrentMarketPrice = 0;
            uint32 UnkInt = 0;
            uint32 Result = 0;
            uint32 UnkInt2 = 0;
        };
        
        class CheckVeteranTokenEligibility final : public ClientPacket
        {
        public:
            CheckVeteranTokenEligibility(WorldPacket&& packet) : ClientPacket(CMSG_CHECK_WOW_TOKEN_VETERAN_ELIGIBILITY, std::move(packet)) { }

            void Read() override;

            uint32 UnkInt = 0;
        };

        class WowTokenCanVeteranBuyResult final : public ServerPacket
        {
        public:
            WowTokenCanVeteranBuyResult() : ServerPacket(SMSG_WOW_TOKEN_CAN_VETERAN_BUY_RESULT, 8 + 4 * 2) { }

            WorldPacket const* Write() override;

            uint64 UnkLong = 0;
            uint32 UnkInt = 0;
            uint32 UnkInt2 = 0;
        };
    }
}

#endif // TokenPackets_h__
