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

#include "TaxiPackets.h"

void WorldPackets::Taxi::TaxiNodeStatusQuery::Read()
{
    _worldPacket >> UnitGUID;
}

WorldPacket const* WorldPackets::Taxi::TaxiNodeStatus::Write()
{
    _worldPacket << Unit;
    _worldPacket.WriteBits(Status, 2);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Taxi::ShowTaxiNodes::Write()
{
    _worldPacket.WriteBit(WindowInfo.is_initialized());
    _worldPacket.FlushBits();

    _worldPacket << uint32(CanLandNodes.size());
    _worldPacket << uint32(CanUseNodes.size());

    if (WindowInfo.is_initialized())
    {
        _worldPacket << WindowInfo->UnitGUID;
        _worldPacket << uint32(WindowInfo->CurrentNode);
    }

    if (!CanLandNodes.empty())
        _worldPacket.append(CanLandNodes.data(), CanLandNodes.size());
    if (!CanUseNodes.empty())
        _worldPacket.append(CanUseNodes.data(), CanUseNodes.size());

    return &_worldPacket;
}

void WorldPackets::Taxi::EnableTaxiNode::Read()
{
    _worldPacket >> Unit;
}

void WorldPackets::Taxi::TaxiQueryAvailableNodes::Read()
{
    _worldPacket >> Unit;
}

void WorldPackets::Taxi::ActivateTaxi::Read()
{
    _worldPacket >> Vendor;
    _worldPacket >> Node;
    _worldPacket >> GroundMountID;
    _worldPacket >> FlyingMountID;
}

WorldPacket const* WorldPackets::Taxi::ActivateTaxiReply::Write()
{
    _worldPacket.WriteBits(Reply, 4);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Taxi::SetTaxiBenchmarkMode::Read()
{
    Enable = _worldPacket.ReadBit();
}
