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

#include "CombatPackets.h"

WorldPacket const* WorldPackets::Combat::AttackSwingError::Write()
{
    _worldPacket.WriteBits(Reason, 2);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Combat::AttackSwing::Read()
{
    _worldPacket >> Victim;
}

WorldPacket const* WorldPackets::Combat::AttackStart::Write()
{
    _worldPacket << Attacker;
    _worldPacket << Victim;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::SAttackStop::Write()
{
    _worldPacket << Attacker;
    _worldPacket << Victim;
    _worldPacket.WriteBit(Dead);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::ThreatUpdate::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << static_cast<int32>(ThreatList.size());
    for (ThreatInfo const& threatInfo : ThreatList)
    {
        _worldPacket << threatInfo.UnitGUID;
        _worldPacket << threatInfo.Threat;
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::HighestThreatUpdate::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << HighestThreatGUID;
    _worldPacket << static_cast<int32>(ThreatList.size());
    for (ThreatInfo const& threatInfo : ThreatList)
    {
        _worldPacket << threatInfo.UnitGUID;
        _worldPacket << threatInfo.Threat;
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::ThreatRemove::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << AboutGUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::AIReaction::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << Reaction;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::PowerUpdate::Write()
{
    _worldPacket << Guid;
    _worldPacket << static_cast<uint32>(Powers.size());
    for (PowerUpdatePower const& power : Powers)
    {
        _worldPacket << power.Power;
        _worldPacket << power.PowerType;
    }

    return &_worldPacket;
}

void WorldPackets::Combat::SetSheathed::Read()
{
    _worldPacket >> CurrentSheathState;
    Animate = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Combat::CancelAutoRepeat::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::HealthUpdate::Write()
{
    _worldPacket << Guid;
    _worldPacket << Health;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::ThreatClear::Write()
{
    _worldPacket << UnitGUID;
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::PvPCredit::Write()
{
    _worldPacket << int32(Honor);
    _worldPacket << int32(Honor);
    _worldPacket << Target;
    _worldPacket << int32(Rank);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::BreakTarget::Write()
{
    _worldPacket << UnitGUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Combat::ResetRangedCombatTimer::Write()
{
    _worldPacket << Delay;

    return &_worldPacket;
}
