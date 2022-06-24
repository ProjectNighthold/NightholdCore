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

#ifndef VehiclePackets_h__
#define VehiclePackets_h__

#include "Packet.h"
#include "MovementPackets.h"

namespace WorldPackets
{
    namespace Vehicle
    {
        class MoveSetVehicleRecID final : public ServerPacket
        {
        public:
            MoveSetVehicleRecID() : ServerPacket(SMSG_MOVE_SET_VEHICLE_REC_ID, 16 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid MoverGUID;
            uint32 SequenceIndex = 0;
            int32 VehicleRecID = 0;
        };

        class MoveSetVehicleRecIdAck final : public ClientPacket
        {
        public:
            MoveSetVehicleRecIdAck(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_SET_VEHICLE_REC_ID_ACK, std::move(packet)) { }

            void Read() override;

            Movement::MovementAck Data;
            int32 VehicleRecID = 0;
        };

        class SetVehicleRecID final : public ServerPacket
        {
        public:
            SetVehicleRecID() : ServerPacket(SMSG_SET_VEHICLE_REC_ID, 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid VehicleGUID;
            int32 VehicleRecID = 0;
        };

        class OnCancelExpectedRideVehicleAura final : public ServerPacket
        {
        public:
            OnCancelExpectedRideVehicleAura() : ServerPacket(SMSG_ON_CANCEL_EXPECTED_RIDE_VEHICLE_AURA, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class MoveDismissVehicle final : public ClientPacket
        {
        public:
            MoveDismissVehicle(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_DISMISS_VEHICLE, std::move(packet)) { }

            void Read() override;

            MovementInfo Status;
        };

        class RequestVehiclePrevSeat final : public ClientPacket
        {
        public:
            RequestVehiclePrevSeat(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_VEHICLE_PREV_SEAT, std::move(packet)) { }

            void Read() override { }
        };

        class RequestVehicleNextSeat final : public ClientPacket
        {
        public:
            RequestVehicleNextSeat(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_VEHICLE_NEXT_SEAT, std::move(packet)) { }

            void Read() override { }
        };

        class MoveChangeVehicleSeats final : public ClientPacket
        {
        public:
            MoveChangeVehicleSeats(WorldPacket&& packet) : ClientPacket(CMSG_MOVE_CHANGE_VEHICLE_SEATS, std::move(packet)) { }

            void Read() override;

            ObjectGuid DstVehicle;
            MovementInfo Status;
            uint8 DstSeatIndex = 255;
        };

        class RequestVehicleSwitchSeat final : public ClientPacket
        {
        public:
            RequestVehicleSwitchSeat(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_VEHICLE_SWITCH_SEAT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Vehicle;
            uint8 SeatIndex = 255;
        };

        class RideVehicleInteract final : public ClientPacket
        {
        public:
            RideVehicleInteract(WorldPacket&& packet) : ClientPacket(CMSG_RIDE_VEHICLE_INTERACT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Vehicle;
        };

        class EjectPassenger final : public ClientPacket
        {
        public:
            EjectPassenger(WorldPacket&& packet) : ClientPacket(CMSG_EJECT_PASSENGER, std::move(packet)) { }

            void Read() override;

            ObjectGuid Passenger;
        };

        class RequestVehicleExit final : public ClientPacket
        {
        public:
            RequestVehicleExit(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_VEHICLE_EXIT, std::move(packet)) { }

            void Read() override { }
        };
    }
}

#endif // VehiclePackets_h__
