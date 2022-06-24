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

#ifndef UpdatePackets_h__
#define UpdatePackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Update
    {
        class DestroyArenaUnit final : public ServerPacket
        {
        public:
            DestroyArenaUnit() : ServerPacket(SMSG_DESTROY_ARENA_UNIT, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
        };

        class MapObjEvents final : public ServerPacket
        {
        public:
            MapObjEvents() : ServerPacket(SMSG_MAP_OBJ_EVENTS, 12) { }

            WorldPacket const* Write() override;

            uint32 UniqueID = 0;
            uint32 DataSize = 0;
            std::vector<uint8> Unk2;
        };

        class SetAnimTimer final : public ServerPacket
        {
        public:
            SetAnimTimer() : ServerPacket(SMSG_SET_ANIM_TIER, 16 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
            uint8 Tier = 0;
        };

        struct VignetteInstanceIDList
        {
            GuidVector IDs;
        };

        struct VignetteClientData
        {
            VignetteClientData(ObjectGuid guid, Position pos, int32 vignetteID, int32 zoneID) : ObjGUID(guid), Pos(pos), VignetteID(vignetteID), ZoneID(zoneID) { }

            ObjectGuid ObjGUID;
            TaggedPosition<Position::XYZ> Pos;
            int32 VignetteID = 0;
            int32 ZoneID = 0;
        };

        struct VignetteClientDataSet
        {
            VignetteInstanceIDList IdList;
            std::vector<VignetteClientData> Data;
        };

        class VignetteUpdate  final : public ServerPacket
        {
        public:
            VignetteUpdate() : ServerPacket(SMSG_VIGNETTE_UPDATE, 20 + 1) { }
            VignetteUpdate(bool update) : ServerPacket(SMSG_VIGNETTE_UPDATE, 20 + 1), ForceUpdate(update) { }

            WorldPacket const* Write() override;

            VignetteClientDataSet Updated;
            VignetteClientDataSet Added;
            VignetteInstanceIDList Removed;
            bool ForceUpdate = false;
        };
    }
}

#endif // UpdatePackets_h__
