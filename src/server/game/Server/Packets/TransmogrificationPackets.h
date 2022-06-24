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

#ifndef TransmogrificationPackets_h__
#define TransmogrificationPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Transmogrification
    {
        struct TransmogrifyItem
        {
            int32 ItemModifiedAppearanceID = 0;
            uint32 Slot = 0;
            int32 SpellItemEnchantmentID = 0;
        };

        class TransmogrifyItems final : public ClientPacket
        {
        public:
            enum
            {
                MAX_TRANSMOGRIFY_ITEMS = 13
            };

            TransmogrifyItems(WorldPacket&& packet) : ClientPacket(CMSG_TRANSMOGRIFY_ITEMS, std::move(packet)) { }

            void Read() override;

            ObjectGuid Npc;
            Array<TransmogrifyItem, MAX_TRANSMOGRIFY_ITEMS> Items;
            bool CurrentSpecOnly = false;
        };

        class TransmogCollectionUpdate final : public ServerPacket
        {
        public:
            TransmogCollectionUpdate() : ServerPacket(SMSG_TRANSMOG_COLLECTION_UPDATE, 6) { }

            WorldPacket const* Write() override;

            std::vector<uint32> FavoriteAppearances;
            bool IsFullUpdate = false;
            bool IsSetFavorite = false;
        };

        class TransmogSetCollectionUpdate final : public ServerPacket
        {
        public:
            TransmogSetCollectionUpdate() : ServerPacket(SMSG_TRANSMOG_SET_COLLECTION_UPDATE, 6) { }

            WorldPacket const* Write() override;

            std::vector<uint32> FavoriteAppearances;
            bool IsFullUpdate = false;
            bool IsSetFavorite = false;
        };

        class OpenTransmogrifier final : public ServerPacket
        {
        public:
            OpenTransmogrifier(ObjectGuid const& guid) : ServerPacket(SMSG_OPEN_TRANSMOGRIFIER, 16), Guid(guid) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
        };
    }
}

#endif // TransmogrificationPackets_h__
