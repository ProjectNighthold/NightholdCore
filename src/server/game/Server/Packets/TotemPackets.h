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

#ifndef TotemPackets_h__
#define TotemPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Totem
    {
        class TotemDestroyed final : public ClientPacket
        {
        public:
            TotemDestroyed(WorldPacket&& packet) : ClientPacket(CMSG_TOTEM_DESTROYED, std::move(packet)) { }

            void Read() override;

            ObjectGuid TotemGUID;
            uint8 Slot = 0;
        };

        class TotemCreated final : public ServerPacket
        {
        public:
            TotemCreated() : ServerPacket(SMSG_TOTEM_CREATED, 25) { }

            WorldPacket const* Write() override;

            ObjectGuid Totem;
            int32 SpellID = 0;
            int32 Duration = 0;
            float TimeMod = 1.0f;
            int8 Slot = 0;
            bool CannotDismiss = false;
        };

        class TotemMoved final : public ServerPacket
        {
        public:
            TotemMoved() : ServerPacket(SMSG_TOTEM_MOVED, 20) { }

            WorldPacket const* Write() override;

            ObjectGuid Totem;
            uint8 Slot = 0;
            uint8 NewSlot = 0;
        };
    }
}

#endif // TotemPackets_h__
