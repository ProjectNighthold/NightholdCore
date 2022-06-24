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

#include "TotemPackets.h"

void WorldPackets::Totem::TotemDestroyed::Read()
{
    _worldPacket >> Slot;
    _worldPacket >> TotemGUID;
}

WorldPacket const* WorldPackets::Totem::TotemCreated::Write()
{
    _worldPacket << Slot;
    _worldPacket << Totem;
    _worldPacket << int32(Duration);
    _worldPacket << int32(SpellID);
    _worldPacket << float(TimeMod);
    _worldPacket.WriteBit(CannotDismiss);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Totem::TotemMoved::Write()
{
    _worldPacket << uint8(Slot);
    _worldPacket << uint8(NewSlot);
    _worldPacket << Totem;

    return &_worldPacket;
}
