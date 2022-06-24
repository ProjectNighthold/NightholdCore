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

#include "Common.h"
#include "WorldSession.h"
#include "ObjectAccessor.h"
#include "Vehicle.h"
#include "CombatPackets.h"

void WorldSession::HandleAttackSwing(WorldPackets::Combat::AttackSwing& packet)
{
    Unit* pEnemy = ObjectAccessor::GetUnit(*_player, packet.Victim);

    if (!pEnemy)
    {
        // stop attack state at client
        GetPlayer()->SendMeleeAttackStop(nullptr);
        return;
    }

    if (!_player->IsValidAttackTarget(pEnemy))
    {
        // stop attack state at client
        GetPlayer()->SendMeleeAttackStop(pEnemy);
        return;
    }

    //! Client explicitly checks the following before sending CMSG_ATTACK_SWING packet,
    //! so we'll place the same check here. Note that it might be possible to reuse this snippet
    //! in other places as well.
    if (Vehicle* vehicle = _player->GetVehicle())
    {
        VehicleSeatEntry const* seat = vehicle->GetSeatForPassenger(_player);
        if (!seat)
            return;
        if (!(seat->Flags & VEHICLE_SEAT_FLAG_CAN_ATTACK))
        {
            GetPlayer()->SendMeleeAttackStop(pEnemy);
            return;
        }
    }

    _player->Attack(pEnemy, true);
}

void WorldSession::HandleAttackStop(WorldPackets::Combat::AttackStop& /*recvData*/)
{
    GetPlayer()->AttackStop();
}

void WorldSession::HandleSetSheathed(WorldPackets::Combat::SetSheathed& packet)
{
    if (packet.CurrentSheathState >= MAX_SHEATH_STATE)
        return;

    GetPlayer()->SetSheath(SheathState(packet.CurrentSheathState));
}