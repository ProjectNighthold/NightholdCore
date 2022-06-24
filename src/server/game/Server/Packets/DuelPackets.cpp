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

#include "DuelPackets.h"

void WorldPackets::Duel::CanDuel::Read()
{
    _worldPacket >> TargetGUID;
}

WorldPacket const* WorldPackets::Duel::CanDuelResult::Write()
{
    _worldPacket << TargetGUID;
    _worldPacket.WriteBit(Result);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Duel::DuelComplete::Write()
{
    _worldPacket.WriteBit(Started);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Duel::DuelCountdown::Write()
{
    _worldPacket << Countdown;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Duel::DuelRequested::Write()
{
    _worldPacket << ArbiterGUID;
    _worldPacket << RequestedByGUID;
    _worldPacket << RequestedByWowAccount;

    return &_worldPacket;
}

void WorldPackets::Duel::DuelResponse::Read()
{
    _worldPacket >> ArbiterGUID;
    Accepted = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Duel::DuelWinner::Write()
{
    _worldPacket.WriteBits(WinnerName.size(), 6);
    _worldPacket.WriteBits(BeatenName.size(), 6);
    _worldPacket.WriteBit(Fled);
    _worldPacket << BeatenVirtualRealmAddress;
    _worldPacket << WinnerVirtualRealmAddress;
    _worldPacket.WriteString(WinnerName);
    _worldPacket.WriteString(BeatenName);

    return &_worldPacket;
}
