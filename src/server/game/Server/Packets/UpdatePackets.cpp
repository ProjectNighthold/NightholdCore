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

#include "UpdatePackets.h"

WorldPacket const* WorldPackets::Update::DestroyArenaUnit::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Update::MapObjEvents::Write()
{
    _worldPacket << UniqueID;
    _worldPacket << DataSize;
    _worldPacket << static_cast<uint32>(Unk2.size());
    for (auto const& itr : Unk2)
        _worldPacket << itr;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Update::SetAnimTimer::Write()
{
    _worldPacket << Unit;
    _worldPacket.WriteBits(Tier, 3);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Update::VignetteUpdate::Write()
{
    _worldPacket.WriteBit(ForceUpdate);
    _worldPacket.FlushBits();

    _worldPacket << static_cast<uint32>(Removed.IDs.size());
    for (ObjectGuid const& ID : Removed.IDs)
        _worldPacket << ID;

    _worldPacket << static_cast<uint32>(Added.IdList.IDs.size());
    for (ObjectGuid const& ID : Added.IdList.IDs)
        _worldPacket << ID;

    _worldPacket << static_cast<uint32>(Added.Data.size());
    for (auto const& x : Added.Data)
    {
        _worldPacket << x.Pos;
        _worldPacket << x.ObjGUID;
        _worldPacket << x.VignetteID;
        _worldPacket << x.ZoneID;
    }

    _worldPacket << static_cast<uint32>(Updated.IdList.IDs.size());
    for (ObjectGuid const& ID : Updated.IdList.IDs)
        _worldPacket << ID;

    _worldPacket << static_cast<uint32>(Updated.Data.size());
    for (auto const& x : Updated.Data)
    {
        _worldPacket << x.Pos;
        _worldPacket << x.ObjGUID;
        _worldPacket << x.VignetteID;
        _worldPacket << x.ZoneID;
    }

    return &_worldPacket;
}
