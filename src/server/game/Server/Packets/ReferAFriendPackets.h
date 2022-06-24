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

#ifndef ReferAFriendPackets_h__
#define ReferAFriendPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace ReferAFriend
    {
        class AcceptLevelGrant final : public ClientPacket
        {
        public:
            AcceptLevelGrant(WorldPacket&& packet) : ClientPacket(CMSG_ACCEPT_LEVEL_GRANT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Granter;
        };

        class GrantLevel final : public ClientPacket
        {
        public:
            GrantLevel(WorldPacket&& packet) : ClientPacket(CMSG_GRANT_LEVEL, std::move(packet)) { }

            void Read() override;

            ObjectGuid Target;
        };

        class ProposeLevelGrant final : public ServerPacket
        {
        public:
            ProposeLevelGrant() : ServerPacket(SMSG_PROPOSE_LEVEL_GRANT, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Sender;
        };

        class ReferAFriendFailure final : public ServerPacket
        {
        public:
            ReferAFriendFailure() : ServerPacket(SMSG_REFER_A_FRIEND_FAILURE, 1 + 4) { }

            WorldPacket const* Write() override;

            std::string Str;
            int32 Reason = 0;
        };

        class RecruitAFriendResponse final : public ServerPacket
        {
        public:
            RecruitAFriendResponse() : ServerPacket(SMSG_RECRUIT_A_FRIEND_RESPONSE, 4) { }

            WorldPacket const* Write() override;

            int32 Result = 0;
        };
    }
}

#endif // ReferAFriendPackets_h__
