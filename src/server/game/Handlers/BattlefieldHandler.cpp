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


#include "BattlegroundPackets.h"

void WorldSession::SendBfInvitePlayerToWar(uint64 const& queueID, uint32 areaID, uint32 pTime)
{
}

void WorldSession::SendBfInvitePlayerToQueue(uint64 queueId, int8 battleState)
{
}

void WorldSession::SendBfQueueInviteResponse(uint64 queueId, uint32 zoneId, int8 battleStatus, bool canQueue /*= true*/, bool loggingIn /*= false*/)
{
}

void WorldSession::SendBfEntered(uint64 queueID, bool relocated, bool onOffense)
{
}

void WorldSession::HandleReportPvPPlayerAFK(WorldPackets::Battleground::ReportPvPPlayerAFK& packet)
{
    if (Player* reportedPlayer = ObjectAccessor::FindPlayer(packet.Offender))
        reportedPlayer->ReportedAfkBy(_player);
}

void WorldSession::HandleSetCemetryPreferrence(WorldPackets::Battleground::SetCemetryPreferrence& /*packet*/)
{ }
