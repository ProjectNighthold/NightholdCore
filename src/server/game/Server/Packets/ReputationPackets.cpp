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

#include "ReputationPackets.h"

WorldPacket const* WorldPackets::Reputation::InitializeFactions::Write()
{
    for (uint16 i = 0; i < FactionCount; ++i)
    {
        _worldPacket << uint8(FactionFlags[i]);
        _worldPacket << int32(FactionStandings[i]);
    }

    for (auto factionHasBonus : FactionHasBonus)
        _worldPacket.WriteBit(factionHasBonus);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Reputation::ForcedReaction const& forcedReaction)
{
    data << int32(forcedReaction.Faction);
    data << int32(forcedReaction.Reaction);

    return data;
}

WorldPacket const* WorldPackets::Reputation::SetForcedReactions::Write()
{
    _worldPacket << static_cast<uint32>(Reactions.size());
    for (ForcedReaction const& reaction : Reactions)
        _worldPacket << reaction;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Reputation::FactionBonusInfo::Write()
{
    for (auto factionHasBonus : FactionHasBonus)
        _worldPacket.WriteBit(factionHasBonus);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Reputation::SetFactionStanding::Write()
{
    _worldPacket << BonusFromAchievementSystem;
    _worldPacket << ReferAFriendBonus;
    _worldPacket << static_cast<uint32>(Faction.size());
    for (auto const& v : Faction)
    {
        _worldPacket << v.Index;
        _worldPacket << v.Standing;
    }

    _worldPacket.WriteBit(ShowVisual);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
