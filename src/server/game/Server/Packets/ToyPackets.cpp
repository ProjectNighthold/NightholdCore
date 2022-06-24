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

#include "ToyPackets.h"

void WorldPackets::Toy::AddToy::Read()
{
    _worldPacket >> Guid;
}

void WorldPackets::Toy::UseToy::Read()
{
    _worldPacket >> Cast;
}

WorldPacket const* WorldPackets::Toy::AccountToysUpdate::Write()
{
    _worldPacket.WriteBit(IsFullUpdate);
    _worldPacket.FlushBits();

    _worldPacket << static_cast<int32>(Toys->size());
    _worldPacket << static_cast<int32>(Toys->size());

    for (auto const& item : *Toys)
        _worldPacket << uint32(item.first);

    for (auto const& favourite : *Toys)
        _worldPacket.WriteBit(favourite.second.isFavourite);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Toy::AccountHeirloomUpdate::Write()
{
    _worldPacket.WriteBit(IsFullUpdate);
    _worldPacket.FlushBits();

    _worldPacket << int32(Unk);

    // both lists have to have the same size
    _worldPacket << int32(Heirlooms->size());
    _worldPacket << int32(Heirlooms->size());

    for (auto const& item : *Heirlooms)
        _worldPacket << uint32(item.first);

    for (auto const& flags : *Heirlooms)
        _worldPacket << uint32(flags.second.flags);

    return &_worldPacket;
}
