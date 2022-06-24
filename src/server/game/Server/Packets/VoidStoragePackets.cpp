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

#include "VoidStoragePackets.h"

WorldPacket const* WorldPackets::VoidStorage::VoidTransferResult::Write()
{
    _worldPacket << int32(Result);

    return &_worldPacket;
}

void WorldPackets::VoidStorage::UnlockVoidStorage::Read()
{
    _worldPacket >> Npc;
}

void WorldPackets::VoidStorage::QueryVoidStorage::Read()
{
    _worldPacket >> Npc;
}

WorldPacket const* WorldPackets::VoidStorage::VoidStorageFailed::Write()
{
    _worldPacket << uint8(Reason);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::VoidStorage::VoidItem const& voidItem)
{
    data << voidItem.Guid;
    data << voidItem.Creator;
    data << voidItem.Slot;
    data << voidItem.Item;

    return data;
}

WorldPacket const* WorldPackets::VoidStorage::VoidStorageContents::Write()
{
    _worldPacket.reserve(1 + Items.size() * sizeof(VoidItem));

    _worldPacket.WriteBits(Items.size(), 8);

    for (VoidItem const& voidItem : Items)
        _worldPacket << voidItem;

    return &_worldPacket;
}

void WorldPackets::VoidStorage::VoidStorageTransfer::Read()
{
    _worldPacket >> Npc;
    Deposits.resize(_worldPacket.read<uint32>());
    Withdrawals.resize(_worldPacket.read<uint32>());

    for (ObjectGuid& deposit : Deposits)
        _worldPacket >> deposit;

    for (ObjectGuid& withdrawal : Withdrawals)
        _worldPacket >> withdrawal;
}

WorldPacket const* WorldPackets::VoidStorage::VoidStorageTransferChanges::Write()
{
    _worldPacket.reserve(1 + AddedItems.size() * sizeof(VoidItem) + RemovedItems.size() * 16);

    _worldPacket.WriteBits(AddedItems.size(), 4);
    _worldPacket.WriteBits(RemovedItems.size(), 4);

    for (VoidItem const& addedItem : AddedItems)
        _worldPacket << addedItem;

    for (ObjectGuid const& removedItem : RemovedItems)
        _worldPacket << removedItem;

    return &_worldPacket;
}

void WorldPackets::VoidStorage::SwapVoidItem::Read()
{
    _worldPacket >> Npc;
    _worldPacket >> VoidItemGuid;
    _worldPacket >> DstSlot;
}

WorldPacket const* WorldPackets::VoidStorage::VoidItemSwapResponse::Write()
{
    _worldPacket << VoidItemA;
    _worldPacket << uint32(VoidItemSlotA);
    _worldPacket << VoidItemB;
    _worldPacket << uint32(VoidItemSlotB);

    return &_worldPacket;
}
