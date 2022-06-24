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

#ifndef CollectionPackets_h__
#define CollectionPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Collections
    {
        enum CollectionType : int32
        {
            NONE            = -1,
            TOYBOX          = 1,
            APPEARANCE      = 3,
            TRANSMOG_SET    = 4
        };

        class CollectionItemSetFavorite final : public ClientPacket
        {
        public:
            CollectionItemSetFavorite(WorldPacket&& packet) : ClientPacket(CMSG_COLLECTION_ITEM_SET_FAVORITE, std::move(packet)) { }

            void Read() override;

            CollectionType Type = NONE;
            uint32 ID = 0;
            bool IsFavorite = false;
        };

        class MountClearFanfare final : public ClientPacket
        {
        public:
            MountClearFanfare(WorldPacket&& packet) : ClientPacket(CMSG_MOUNT_CLEAR_FANFARE, std::move(packet)) { }

            void Read() override;
            uint32 spellID = 0;
        };

        class BattlePetClearFanfare final : public ClientPacket
        {
        public:
            BattlePetClearFanfare(WorldPacket&& packet) : ClientPacket(CMSG_BATTLE_PET_CLEAR_FANFARE, std::move(packet)) { }

            void Read() override;
            ObjectGuid BattlePetGUID;
        };
    }
}

#endif // CollectionPackets_h__
