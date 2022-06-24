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

#include "WorldStatePackets.h"

WorldPacket const* WorldPackets::WorldState::InitWorldStates::Write()
{
    std::sort(Worldstates.begin(), Worldstates.end(), [](WorldStateInfo const& a, WorldStateInfo const& b) -> bool
    {
        return a.VariableID < b.VariableID;
    });

    _worldPacket.reserve(16 + Worldstates.size() * 8);

    _worldPacket << uint32(MapID);
    _worldPacket << uint32(AreaID);
    _worldPacket << uint32(SubareaID);

    _worldPacket << uint32(Worldstates.size());
    for (auto const& wsi : Worldstates)
    {
        _worldPacket << uint32(wsi.VariableID);
        _worldPacket << int32(wsi.Value);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::WorldState::UpdateWorldState::Write()
{
    _worldPacket << uint32(VariableID);
    _worldPacket << int32(Value);
    _worldPacket.WriteBit(Hidden);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::WorldState::StartElapsedTimer::Write()
{
    _worldPacket << Timer.TimerID;
    _worldPacket << uint32(Timer.CurrentDuration);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::WorldState::StartElapsedTimers::Write()
{
    _worldPacket << static_cast<uint32>(Timers.size());
    for (auto const& v : Timers)
    {
        _worldPacket << v.TimerID;
        _worldPacket << uint32(v.CurrentDuration);
    }

    return &_worldPacket;
}
