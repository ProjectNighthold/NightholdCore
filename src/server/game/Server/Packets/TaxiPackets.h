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

#ifndef TaxiPackets_h__
#define TaxiPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "DB2Structure.h"

namespace WorldPackets
{
    namespace Taxi
    {
        class TaxiNodeStatusQuery final : public ClientPacket
        {
        public:
            TaxiNodeStatusQuery(WorldPacket&& packet) : ClientPacket(CMSG_TAXI_NODE_STATUS_QUERY, std::move(packet)) { }

            void Read() override;

            ObjectGuid UnitGUID;
        };

        class TaxiNodeStatus final : public ServerPacket
        {
        public:
            TaxiNodeStatus() : ServerPacket(SMSG_TAXI_NODE_STATUS, 16 + 1) { }

            WorldPacket const* Write() override;

            uint8 Status = 0; // replace with TaxiStatus enum
            ObjectGuid Unit;
        };

        struct ShowTaxiNodesWindowInfo
        {
            ObjectGuid UnitGUID;
            int32 CurrentNode = 0;
        };

        class ShowTaxiNodes final : public ServerPacket
        {
        public:
            ShowTaxiNodes() : ServerPacket(SMSG_SHOW_TAXI_NODES) { }

            WorldPacket const* Write() override;

            Optional<ShowTaxiNodesWindowInfo> WindowInfo;
            std::vector<uint8> CanLandNodes; // Nodes known by player
            std::vector<uint8> CanUseNodes;  // Nodes available for use - this can temporarily disable a known node
        };

        class EnableTaxiNode final : public ClientPacket
        {
        public:
            EnableTaxiNode(WorldPacket&& packet) : ClientPacket(CMSG_ENABLE_TAXI_NODE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Unit;
        };

        class TaxiQueryAvailableNodes final : public ClientPacket
        {
        public:
            TaxiQueryAvailableNodes(WorldPacket&& packet) : ClientPacket(CMSG_TAXI_QUERY_AVAILABLE_NODES, std::move(packet)) { }

            void Read() override;

            ObjectGuid Unit;
        };

        class ActivateTaxi final : public ClientPacket
        {
        public:
            ActivateTaxi(WorldPacket&& packet) : ClientPacket(CMSG_ACTIVATE_TAXI, std::move(packet)) { }

            void Read() override;

            ObjectGuid Vendor;
            uint32 Node = 0;
            uint32 GroundMountID = 0;
            uint32 FlyingMountID = 0;
        };

        class NewTaxiPath final : public ServerPacket
        {
        public:
            NewTaxiPath() : ServerPacket(SMSG_NEW_TAXI_PATH, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class ActivateTaxiReply final : public ServerPacket
        {
        public:
            ActivateTaxiReply() : ServerPacket(SMSG_ACTIVATE_TAXI_REPLY, 4) { }

            WorldPacket const* Write() override;

            uint8 Reply = 0;
        };

        class TaxiRequestEarlyLanding final : public ClientPacket
        {
        public:
            TaxiRequestEarlyLanding(WorldPacket&& packet) : ClientPacket(CMSG_TAXI_REQUEST_EARLY_LANDING, std::move(packet)) { }

            void Read() override { }
        };

        class SetTaxiBenchmarkMode final : public ClientPacket
        {
        public:
            SetTaxiBenchmarkMode(WorldPacket&& packet) : ClientPacket(CMSG_SET_TAXI_BENCHMARK_MODE, std::move(packet)) { }

            void Read() override;

            bool Enable = false;
        };
    }
}

#endif // TaxiPackets_h__
