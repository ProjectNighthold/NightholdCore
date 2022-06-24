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

#include "LFGMgr.h"
#include "Group.h"
#include "QuestData.h"
#include "LFGPackets.h"

void WorldSession::HandleLfgJoin(WorldPackets::LFG::LfgJoin& packet)
{
    if (packet.Slot.empty())
        return;

    if (!sLFGMgr->isOptionEnabled(lfg::LFG_OPTION_ENABLE_DUNGEON_FINDER | lfg::LFG_OPTION_ENABLE_RAID_BROWSER))
        return;

    sLFGMgr->JoinLfg(GetPlayer(), packet.Roles, packet.Slot);
}

void WorldSession::HandleLfgLeave(WorldPackets::LFG::LfgLeave& packet)
{
    sLFGMgr->LeaveLfg(GetPlayer()->GetGUID(), packet.Ticket.Id);
}

void WorldSession::HandleLfgProposalResponse(WorldPackets::LFG::LfgProposalResponse& packet)
{
    sLFGMgr->UpdateProposal(packet.Data, GetPlayer()->GetGUID());
}

void WorldSession::HandleLfgCompleteRoleCheck(WorldPackets::LFG::LfgCompleteRoleCheck& packet)
{
    if (Group* group = GetPlayer()->GetGroup())
        sLFGMgr->UpdateRoleCheck(group->GetGUID(), GetPlayer()->GetGUID(), packet.RolesDesired, packet.PartyIndex);
}

void WorldSession::HandleLfgBootPlayerVote(WorldPackets::LFG::LfgBootPlayerVote& packet)
{
    if (Group* group = GetPlayer()->GetGroup())
        sLFGMgr->UpdateBoot(group->GetGUID(), GetPlayer()->GetGUID(), packet.Vote);
}

void WorldSession::HandleLfgCompleteReadyCheck(WorldPackets::LFG::CompleteReadyCheck& /*packet*/)
{ }

void WorldSession::HandleLfgTeleport(WorldPackets::LFG::LfgTeleport& packet)
{
    sLFGMgr->TeleportPlayer(GetPlayer(), packet.TeleportOut, true);
}

void WorldSession::HandleLockInfoRequest(WorldPackets::LFG::LockInfoRequest& packet)
{
    Player* player = GetPlayer();
    if (!player->IsInWorld() || !player->GetSession())
        return;

    if (packet.Player)
        sLFGMgr->SendLfgPlayerLockInfo(player);
    else
        sLFGMgr->SendLfgPartyLockInfo(player);
}

void WorldSession::HandleDfGetJoinStatus(WorldPackets::LFG::NullCmsg& /*packet*/)
{
    if (!sLFGMgr->HasQueue(GetPlayer()->GetGUID()))
        return;

    if (GetPlayer()->IsInWorld())
        sLFGMgr->SendLfgUpdateQueue(GetPlayer()->GetGUID());
}

void WorldSession::HandleBonusFactionID(WorldPackets::LFG::BonusFactionID& packet)
{
    GetPlayer()->SetLfgBonusFaction(packet.FactionID);
}
