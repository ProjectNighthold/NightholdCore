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

#include "VehiclePackets.h"

WorldPacket const* WorldPackets::Vehicle::MoveSetVehicleRecID::Write()
{
    _worldPacket << MoverGUID;
    _worldPacket << uint32(SequenceIndex);
    _worldPacket << int32(VehicleRecID);

    return &_worldPacket;
}

void WorldPackets::Vehicle::MoveSetVehicleRecIdAck::Read()
{
    _worldPacket >> Data;
    _worldPacket >> VehicleRecID;
}

WorldPacket const* WorldPackets::Vehicle::SetVehicleRecID::Write()
{
    _worldPacket << VehicleGUID;
    _worldPacket << int32(VehicleRecID);

    return &_worldPacket;
}

void WorldPackets::Vehicle::MoveDismissVehicle::Read()
{
    _worldPacket >> Status;
}

void WorldPackets::Vehicle::MoveChangeVehicleSeats::Read()
{
    _worldPacket >> Status;
    _worldPacket >> DstVehicle;
    _worldPacket >> DstSeatIndex;
}

void WorldPackets::Vehicle::RequestVehicleSwitchSeat::Read()
{
    _worldPacket >> Vehicle;
    _worldPacket >> SeatIndex;
}

void WorldPackets::Vehicle::RideVehicleInteract::Read()
{
    _worldPacket >> Vehicle;
}

void WorldPackets::Vehicle::EjectPassenger::Read()
{
    _worldPacket >> Passenger;
}
