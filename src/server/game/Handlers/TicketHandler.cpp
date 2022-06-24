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
#include "Language.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "TicketMgr.h"
#include "TicketPackets.h"
#include "Util.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "DatabaseEnv.h"
#include "WordFilterMgr.h"

void WorldSession::HandleComplaint(WorldPackets::Ticket::Complaint& packet)
{
    uint64 complaintId = sObjectMgr->GenerateReportComplaintID();
    if (sWordFilterMgr->AddComplaintForUser(packet.Offender.PlayerGuid, GetPlayer()->GetGUID(), complaintId, packet.Chat.MessageLog))
    {
        uint8 index = 0;
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_COMPLAINTS);
        stmt->setUInt64(index++, complaintId);
        stmt->setUInt64(index++, GetPlayer()->GetGUIDLow());
        stmt->setUInt32(index++, GetAccountId());
        stmt->setUInt32(index++, time(NULL));
        stmt->setUInt64(index++, packet.Offender.PlayerGuid.GetGUIDLow());
        stmt->setUInt8(index++, packet.ComplaintType);
        stmt->setUInt32(index++, packet.MailID);
        stmt->setUInt32(index++, packet.Offender.TimeSinceOffence);
        stmt->setString(index++, packet.Chat.MessageLog);
        CharacterDatabase.Execute(stmt);
    }

    WorldPackets::Ticket::ComplaintResult result;
    result.ComplaintType = packet.ComplaintType;
    result.Result = 0;
    SendPacket(result.Write());
}

void WorldSession::HandleSupportTicketSubmitBug(WorldPackets::Ticket::SupportTicketSubmitBug& packet)
{
    // Don't accept tickets if the ticket queue is disabled. (Ticket UI is greyed out but not fully dependable)
    if (!sTicketMgr->GetStatus())
        return;

    if (GetPlayer()->getLevel() < sWorld->getIntConfig(CONFIG_TICKET_LEVEL_REQ))
    {
        SendNotification(GetTrinityString(LANG_TICKET_REQ), sWorld->getIntConfig(CONFIG_TICKET_LEVEL_REQ));
        return;
    }

    // Player must not have ticket
    if (!sTicketMgr->GetTicketByPlayer(GetPlayer()->GetGUID()))
    {
        GmTicket* ticket = new GmTicket(GetPlayer(), packet);
        sTicketMgr->AddTicket(ticket);
        sTicketMgr->UpdateLastChange();

        sWorld->SendGMText(LANG_COMMAND_TICKETNEW, GetPlayer()->GetName(), ticket->GetId());
    }
}

void WorldSession::HandleGMTicketGetSystemStatus(WorldPackets::Ticket::GMTicketGetSystemStatus& /*packet*/)
{
    // Note: This only disables the ticket UI at client side and is not fully reliable
    WorldPackets::Ticket::GMTicketSystemStatus response;
    response.Status = sTicketMgr->GetStatus() ? GMTICKET_QUEUE_STATUS_ENABLED : GMTICKET_QUEUE_STATUS_DISABLED;
    SendPacket(response.Write());
}

void WorldSession::HandleGMTicketAcknowledgeSurvey(WorldPackets::Ticket::GMTicketAcknowledgeSurvey& /*packet*/)
{ }

void WorldSession::HandleGMTicketGetCaseStatus(WorldPackets::Ticket::GMTicketGetCaseStatus& /*packet*/)
{
    // TODO: Implement GmCase and handle this packet properly
    WorldPackets::Ticket::GMTicketCaseStatus status;
    SendPacket(status.Write());
}

void WorldSession::HandleSupportTicketSubmitComplaint(WorldPackets::Ticket::SupportTicketSubmitComplaint& /*packet*/)
{ }

void WorldSession::HandleSupportTicketSubmitSuggestion(WorldPackets::Ticket::SupportTicketSubmitSuggestion& /*packet*/)
{ }
