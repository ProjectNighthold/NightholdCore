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

#ifndef ToyPackets_h__
#define ToyPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "SpellPackets.h"
#include "CollectionMgr.h"

namespace WorldPackets
{
    namespace Toy
    {
        class AddToy final : public ClientPacket
        {
        public:
            AddToy(WorldPacket&& packet) : ClientPacket(CMSG_ADD_TOY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };

        class UseToy final : public ClientPacket
        {
        public:
            UseToy(WorldPacket&& packet) : ClientPacket(CMSG_USE_TOY, std::move(packet)) { }

            void Read() override;

            Spells::SpellCastRequest Cast;
        };

        class AccountToysUpdate final : public ServerPacket
        {
        public:
            AccountToysUpdate() : ServerPacket(SMSG_ACCOUNT_TOYS_UPDATE, 1 + 4 + 4) { }

            WorldPacket const* Write() override;

            ToyBoxContainer const* Toys = nullptr;
            bool IsFullUpdate = false;
        };

        class AccountHeirloomUpdate final : public ServerPacket
        {
        public:
            AccountHeirloomUpdate() : ServerPacket(SMSG_ACCOUNT_HEIRLOOM_UPDATE) { }

            WorldPacket const* Write() override;

            bool IsFullUpdate = false;
            HeirloomContainer const* Heirlooms = nullptr;
            int32 Unk = 0;
        };
    }
}

#endif // ToyPackets_h__
