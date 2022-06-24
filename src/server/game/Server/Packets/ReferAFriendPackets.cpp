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

#include "ReferAFriendPackets.h"

void WorldPackets::ReferAFriend::AcceptLevelGrant::Read()
{
    _worldPacket >> Granter;
}

void WorldPackets::ReferAFriend::GrantLevel::Read()
{
    _worldPacket >> Target;
}

WorldPacket const* WorldPackets::ReferAFriend::ProposeLevelGrant::Write()
{
    _worldPacket << Sender;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ReferAFriend::ReferAFriendFailure::Write()
{
    _worldPacket << int32(Reason);
    _worldPacket.WriteBits(Str.length(), 6);
    _worldPacket.WriteString(Str);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ReferAFriend::RecruitAFriendResponse::Write()
{
    _worldPacket.WriteBits(Result, 3);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
