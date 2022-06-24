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

#ifndef ClientConfigPackets_h__
#define ClientConfigPackets_h__

#include "Packet.h"
#include "WorldSession.h"

namespace WorldPackets
{
    namespace ClientConfig
    {
        class AccountDataTimes final : public ServerPacket
        {
        public:
            AccountDataTimes() : ServerPacket(SMSG_ACCOUNT_DATA_TIMES, 4 + 4 * NUM_ACCOUNT_DATA_TYPES) { }

            WorldPacket const* Write() override;

            ObjectGuid PlayerGuid;
            uint32 ServerTime = 0;
            uint32 AccountTimes[NUM_ACCOUNT_DATA_TYPES] = { };
        };

        class ClientCacheVersion final : public ServerPacket
        {
        public:
            ClientCacheVersion() : ServerPacket(SMSG_CACHE_VERSION, 4) { }

            WorldPacket const* Write() override;

            uint32 CacheVersion = 0;
        };

        class RequestAccountData final : public ClientPacket
        {
        public:
            RequestAccountData(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_ACCOUNT_DATA, std::move(packet)) { }

            void Read() override;

            ObjectGuid PlayerGuid;
            uint8 DataType = 0;
        };

        class UpdateAccountData final : public ServerPacket
        {
        public:
            UpdateAccountData() : ServerPacket(SMSG_UPDATE_ACCOUNT_DATA) { }

            WorldPacket const* Write() override;

            ObjectGuid Player;
            uint32 Time = 0;
            uint32 Size = 0;
            uint8 DataType = 0;
            ByteBuffer CompressedData;
        };

        class UserClientUpdateAccountData final : public ClientPacket
        {
        public:
            UserClientUpdateAccountData(WorldPacket&& packet) : ClientPacket(CMSG_UPDATE_ACCOUNT_DATA, std::move(packet)) { }

            void Read() override;

            ObjectGuid PlayerGuid;
            uint32 Time = 0;
            uint32 Size = 0;
            uint8 DataType = 0;
            ByteBuffer CompressedData;
        };

        class SetAdvancedCombatLogging final : public ClientPacket
        {
        public:
            SetAdvancedCombatLogging(WorldPacket&& packet) : ClientPacket(CMSG_SET_ADVANCED_COMBAT_LOGGING, std::move(packet)) { }

            void Read() override;

            bool Enable = false;
        };

        class TwitterStatus final : public ServerPacket
        {
        public:
            TwitterStatus() : ServerPacket(SMSG_TWITTER_STATUS, 4) { }

            WorldPacket const* Write() override;

            uint32 StatusInt = 0;
        };
        
        class UpdateClientSettings final : public ClientPacket
        {
        public:
            UpdateClientSettings(WorldPacket&& packet) : ClientPacket(CMSG_UPDATE_CLIENT_SETTINGS, std::move(packet)) { }

            void Read() override;
            
            float FarClip = 0.0f;
        };
        
        class CacheInfo final : public ServerPacket
        {
        public:
            CacheInfo() : ServerPacket(SMSG_CACHE_INFO, 4) { }

            WorldPacket const* Write() override;

            struct Info
            {
                std::string VariableName;
                std::string Value;
            };

            std::vector<Info> Data;
            std::string Signature;
        };
        
        class SaveClientVariables final : public ClientPacket
        {
        public:
            SaveClientVariables(WorldPacket&& packet) : ClientPacket(CMSG_REPORT_CLIENT_VARIABLES, std::move(packet)) { }

            void Read() override;
            
            struct VarablesStruct
            {
                std::string VariableName;
                std::string Value;
            };

            std::list<VarablesStruct> Varables;
        };

        class GetRemainingGameTime  final : public ClientPacket
        {
        public:
            GetRemainingGameTime(WorldPacket&& packet) : ClientPacket(CMSG_GET_REMAINING_GAME_TIME, std::move(packet)) { }

            void Read() override;
            
            uint32 Time = 0;
        };
    }
}

#endif // ClientConfigPackets_h__
