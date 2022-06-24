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

#pragma once

#include "Packet.h"
#include "ItemPackets.h"
#include "ObjectGuid.h"

class Item;

namespace WorldPackets
{
    namespace Inspect
    {
        class Inspect final : public ClientPacket
        {
        public:
            Inspect(WorldPacket&& packet) : ClientPacket(CMSG_INSPECT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Target;
        };

        struct InspectEnchantData
        {
            InspectEnchantData(uint32 id, uint8 index) : Id(id), Index(index) { }

            uint32 Id = 0;
            uint8 Index = 0;
        };

        struct InspectItemData
        {
            InspectItemData(::Item const* item, uint8 index);

            std::vector<InspectEnchantData> Enchants;
            std::vector<Item::ItemGemData> Gems;
            ObjectGuid CreatorGUID;
            Item::ItemInstance Item;
            uint8 Index = 0;
            bool Usable = false;
        };

        struct InspectGuildData
        {
            ObjectGuid GuildGUID;
            int32 NumGuildMembers = 0;
            int32 AchievementPoints = 0;
        };

        class InspectResult final : public ServerPacket
        {
        public:
            InspectResult() : ServerPacket(SMSG_INSPECT_RESULT, 28 + 16 + 1) { }

            WorldPacket const* Write() override;

            Optional<InspectGuildData> GuildData;
            std::vector<InspectItemData> Items;
            std::vector<uint16> Glyphs;
            std::vector<uint16> Talents;
            std::vector<uint16> PvPTalents;
            ObjectGuid InspecteeGUID;
            int32 ClassID = CLASS_NONE;
            int32 SpecializationID = 0;
            int32 GenderID = GENDER_NONE;
        };

        class RequestHonorStats final : public ClientPacket
        {
        public:
            RequestHonorStats(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_HONOR_STATS, std::move(packet)) { }

            void Read() override;

            ObjectGuid TargetGUID;
        };

        class InspectHonorStats final : public ServerPacket
        {
        public:
            InspectHonorStats() : ServerPacket(SMSG_INSPECT_HONOR_STATS, 25) { }

            WorldPacket const* Write() override;

            ObjectGuid PlayerGUID;
            uint32 LifetimeHK = 0;
            uint16 YesterdayHK = 0;
            uint16 TodayHK = 0;
            uint8 LifetimeMaxRank = 0;
        };

        class InspectPVPRequest final : public ClientPacket
        {
        public:
            InspectPVPRequest(WorldPacket&& packet) : ClientPacket(CMSG_INSPECT_PVP, std::move(packet)) { }

            void Read() override;

            ObjectGuid InspectTarget;
            uint32 InspectRealmAddress = 0;
        };

        struct PVPBracketData
        {
            int32 Rating = 0;
            int32 Rank = 0;
            int32 WeeklyPlayed = 0;
            int32 WeeklyWon = 0;
            int32 SeasonPlayed = 0;
            int32 SeasonWon = 0;
            int32 WeeklyBestRating = 0;
            int32 Unk710 = 0;
            uint8 Bracket = 0;
        };

        class InspectPVPResponse final : public ServerPacket
        {
        public:
            InspectPVPResponse() : ServerPacket(SMSG_INSPECT_PVP, 17) { }

            WorldPacket const* Write() override;

            std::vector<PVPBracketData> Bracket;
            ObjectGuid ClientGUID;
        };

        class QueryInspectAchievements final : public ClientPacket
        {
        public:
            QueryInspectAchievements(WorldPacket&& packet) : ClientPacket(CMSG_QUERY_INSPECT_ACHIEVEMENTS, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };
    }
}
