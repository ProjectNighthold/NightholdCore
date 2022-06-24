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

#include "LFGPacketsCommon.h"

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::RideTicket& ticket)
{
    data >> ticket.RequesterGuid;
    data >> ticket.Id;
    ticket.Type = data.read<WorldPackets::LFG::RideType>();
    data >> ticket.Time;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::RideTicket const& ticket)
{
    data << ticket.RequesterGuid;
    data << uint32(ticket.Id);
    data << uint32(ticket.Type);
    data << int32(ticket.Time);
    return data;
}
