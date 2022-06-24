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

#ifndef HotfixPackets_h__
#define HotfixPackets_h__

#include "Packet.h"
#include "Common.h"
#include "DB2Stores.h"

namespace WorldPackets
{
    namespace Hotfix
    {
        class HotfixRequest final : public ClientPacket
        {
        public:
            HotfixRequest(WorldPacket&& packet) : ClientPacket(CMSG_HOTFIX_REQUEST, std::move(packet)) { }

            void Read() override;

            std::vector<uint64> Hotfixes;
        };

        class DBQueryBulk final : public ClientPacket
        {
        public:
            struct DBQueryRecord
            {
                ObjectGuid GUID;
                uint32 RecordID = 0;
            };

            DBQueryBulk(WorldPacket&& packet) : ClientPacket(CMSG_DB_QUERY_BULK, std::move(packet)) { }

            void Read() override;

            std::vector<DBQueryRecord> Queries;
            uint32 TableHash = 0;
        };

        class DBReply final : public ServerPacket
        {
        public:
            DBReply() : ServerPacket(SMSG_DB_REPLY, 12) { }

            WorldPacket const* Write() override;

            ByteBuffer Data;
            uint32 TableHash = 0;
            uint32 Timestamp = 0;
            uint32 RecordID = 0;
            bool Allow = false;
        };

        class AvailableHotfixes final : public ServerPacket
        {
        public:
            AvailableHotfixes(int32 hotfixCacheVersion, std::map<uint64, int32> const& hotfixes) : ServerPacket(SMSG_AVAILABLE_HOTFIXES), Hotfixes(hotfixes), HotfixCacheVersion(hotfixCacheVersion) { }

            WorldPacket const* Write() override;

            std::map<uint64, int32> const& Hotfixes;
            int32 HotfixCacheVersion;
        };

        struct HotfixData
        {
            Optional<ByteBuffer> Data;
            uint64 ID = 0;
            int32 RecordID = 0;
        };

        class HotfixResponse final : public ServerPacket
        {
        public:
            HotfixResponse() : ServerPacket(SMSG_HOTFIX_RESPONSE, 9) { }

            WorldPacket const* Write() override;

            std::vector<HotfixData> Hotfixes;
        };

        class HotfixMessage final : public ServerPacket
        {
        public:
            HotfixMessage() : ServerPacket(SMSG_HOTFIX_MESSAGE, 9) { }

            WorldPacket const* Write() override;

            std::vector<HotfixData> Hotfixes;
        };
    }
}

#endif // HotfixPackets_h__
