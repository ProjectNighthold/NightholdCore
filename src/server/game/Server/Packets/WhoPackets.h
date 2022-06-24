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

#ifndef WhoPackets_h__
#define WhoPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "QueryPackets.h"

namespace WorldPackets
{
    namespace Who
    {
        class WhoIsRequest final : public ClientPacket
        {
        public:
            WhoIsRequest(WorldPacket&& packet) : ClientPacket(CMSG_WHO_IS, std::move(packet)) { }

            void Read() override;

            std::string CharName;
        };

        class WhoIsResponse final : public ServerPacket
        {
        public:
            WhoIsResponse() : ServerPacket(SMSG_WHO_IS, 2) { }

            WorldPacket const* Write() override;

            std::string AccountName;
        };

        struct WhoWord
        {
            std::string Word;
        };

        struct WhoRequestServerInfo
        {
            int32 FactionGroup = 0;
            int32 Locale = 0;
            uint32 RequesterVirtualRealmAddress = 0;
        };

        struct WhoRequest
        {
            int32 MinLevel = 0;
            int32 MaxLevel = 0;
            std::string Name;
            std::string VirtualRealmName;
            std::string Guild;
            std::string GuildVirtualRealmName;
            int64 RaceFilter = SI64LIT(0);
            int32 ClassFilter = -1;
            std::vector<WhoWord> Words;
            bool ShowEnemies = false;
            bool ShowArenaPlayers = false;
            bool ExactName = false;
            Optional<WhoRequestServerInfo> ServerInfo;
        };

        class WhoRequestPkt final : public ClientPacket
        {
        public:
            WhoRequestPkt(WorldPacket&& packet) : ClientPacket(CMSG_WHO, std::move(packet)) { }

            void Read() override;

            WhoRequest Request;
            std::vector<int32> Areas;
        };

        struct WhoEntry
        {
            Query::PlayerGuidLookupData PlayerData;
            ObjectGuid GuildGUID;
            uint32 GuildVirtualRealmAddress = 0;
            std::string GuildName;
            int32 AreaID = 0;
            bool IsGM = false;
        };

        struct WhoResponse
        {
            std::vector<WhoEntry> Entries;
        };

        class WhoResponsePkt final : public ServerPacket
        {
        public:
            WhoResponsePkt() : ServerPacket(SMSG_WHO, 1) { }

            WorldPacket const* Write() override;

            WhoResponse Response;
        };
    }
}

#endif // WhoPackets_h__
