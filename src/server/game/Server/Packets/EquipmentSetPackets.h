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
#include "EquipementSet.h"
#include "ItemPackets.h"

namespace WorldPackets
{
    namespace EquipmentSet
    {
        class EquipmentSetID final : public ServerPacket
        {
        public:
            EquipmentSetID() : ServerPacket(SMSG_EQUIPMENT_SET_ID, 8 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint64 GUID = 0;
            uint32 SetID = 0;
            int32 Type = 0;
        };

        class LoadEquipmentSet final : public ServerPacket
        {
        public:
            LoadEquipmentSet() : ServerPacket(SMSG_LOAD_EQUIPMENT_SET, 4) { }

            WorldPacket const* Write() override;

            std::vector<EquipmentSetInfo::EquipmentSetData const*> SetData;
        };

        class SaveEquipmentSet final : public ClientPacket
        {
        public:
            SaveEquipmentSet(WorldPacket&& packet) : ClientPacket(CMSG_SAVE_EQUIPMENT_SET, std::move(packet)) { }

            void Read() override;

            EquipmentSetInfo::EquipmentSetData Set{};
        };

        class DeleteEquipmentSet final : public ClientPacket
        {
        public:
            DeleteEquipmentSet(WorldPacket&& packet) : ClientPacket(CMSG_DELETE_EQUIPMENT_SET, std::move(packet)) { }

            void Read() override;

            uint64 ID = 0;
        };

        class UseEquipmentSet final : public ClientPacket
        {
        public:
            UseEquipmentSet(WorldPacket&& packet) : ClientPacket(CMSG_USE_EQUIPMENT_SET, std::move(packet)) { }

            void Read() override;

            struct EquipmentSetItem
            {
                ObjectGuid Item;
                uint8 ContainerSlot     = 0;
                uint8 Slot              = 0;
            };

            Item::InvUpdate Inv;
            EquipmentSetItem Items[EQUIPEMENT_SET_SLOTS] = { };
            uint64 GUID = 0;
        };

        class UseEquipmentSetResult final : public ServerPacket
        {
        public:
            UseEquipmentSetResult() : ServerPacket(SMSG_USE_EQUIPMENT_SET_RESULT, 8 + 1) { }

            WorldPacket const* Write() override;

            uint64 GUID = 0;
            uint8 Reason = 0;
        };

        class AssignEquipmentSetSpec final : public ClientPacket
        {
        public:
            AssignEquipmentSetSpec(WorldPacket&& packet) : ClientPacket(CMSG_ASSIGN_EQUIPMENT_SET_SPEC, std::move(packet)) { }

            void Read() override;

            uint64 GUID = 0;
            uint32 SpecID = 0;
        };
    }
}
