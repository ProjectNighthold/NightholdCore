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

#include "TransmogrificationPackets.h"

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Transmogrification::TransmogrifyItem& transmogItem)
{
    data >> transmogItem.ItemModifiedAppearanceID;
    data >> transmogItem.Slot;
    data >> transmogItem.SpellItemEnchantmentID;

    return data;
}

void WorldPackets::Transmogrification::TransmogrifyItems::Read()
{
    Items.resize(_worldPacket.read<uint32>());
    _worldPacket >> Npc;
    for (TransmogrifyItem& item : Items)
        _worldPacket >> item;

    CurrentSpecOnly = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Transmogrification::TransmogCollectionUpdate::Write()
{
    _worldPacket.WriteBit(IsFullUpdate);
    _worldPacket.WriteBit(IsSetFavorite);
    _worldPacket.FlushBits();

    _worldPacket << uint32(FavoriteAppearances.size());
    for (uint32 itemModifiedAppearanceId : FavoriteAppearances)
        _worldPacket << uint32(itemModifiedAppearanceId);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Transmogrification::TransmogSetCollectionUpdate::Write()
{
    _worldPacket.WriteBit(IsFullUpdate);
    _worldPacket.WriteBit(IsSetFavorite);
    _worldPacket.FlushBits();

    _worldPacket << uint32(FavoriteAppearances.size());
    for (uint32 itemModifiedAppearanceId : FavoriteAppearances)
        _worldPacket << uint32(itemModifiedAppearanceId);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Transmogrification::OpenTransmogrifier::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}
