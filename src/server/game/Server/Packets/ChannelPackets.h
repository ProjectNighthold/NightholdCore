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

#ifndef ChannelPackets_h__
#define ChannelPackets_h__

#include "Packet.h"
#include "Channel.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Channel
    {
        class ChannelListResponse final : public ServerPacket
        {
        public:
            struct ChannelPlayer
            {
                ChannelPlayer(ObjectGuid const& guid, uint32 realm, uint8 flags) : Guid(guid), VirtualRealmAddress(realm), Flags(flags) { }

                ObjectGuid Guid;
                uint32 VirtualRealmAddress;
                uint8 Flags;
            };

            ChannelListResponse() : ServerPacket(SMSG_CHANNEL_LIST, 4 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            std::vector<ChannelPlayer> _Members;
            std::string _Channel;
            uint32 _ChannelFlags = 0;
            bool _Display = false;
        };

        class ChannelNotify final : public ServerPacket
        {
        public:
            ChannelNotify() : ServerPacket(SMSG_CHANNEL_NOTIFY, 16 * 3 + 4 * 3 + 4 * 2 + 1 * 3) { }

            WorldPacket const* Write() override;
            
            ObjectGuid SenderGuid;
            ObjectGuid SenderAccountID;
            ObjectGuid TargetGuid;
            uint32 SenderVirtualRealm = 0;
            uint32 TargetVirtualRealm = 0;
            int32 ChatChannelID = 0;
            std::string Sender;
            std::string _Channel;
            uint8 Type = 0;
            uint8 OldFlags = 0;
            uint8 NewFlags = 0;
        };

        class ChannelNotifyJoined final : public ServerPacket
        {
        public:
            ChannelNotifyJoined() : ServerPacket(SMSG_CHANNEL_NOTIFY_JOINED, 50) { }

            WorldPacket const* Write() override;

            std::string ChannelWelcomeMsg;
            int32 ChatChannelID = 0;
            int32 InstanceID = 0;
            uint32 _ChannelFlags = 0;
            std::string _Channel;
        };

        class ChannelNotifyLeft final : public ServerPacket
        {
        public:
            ChannelNotifyLeft() : ServerPacket(SMSG_CHANNEL_NOTIFY_LEFT, 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            std::string Channel;
            int32 ChatChannelID = 0;
            bool Suspended = false;
        };

        class UserlistAdd final : public ServerPacket
        {
        public:
            UserlistAdd() : ServerPacket(SMSG_USERLIST_ADD, 30) { }

            WorldPacket const* Write() override;

            ObjectGuid AddedUserGUID;
            uint32 _ChannelFlags = CHANNEL_FLAG_NONE; ///< @see enum ChannelFlags
            uint8 UserFlags = MEMBER_FLAG_NONE;
            int32 ChannelID = 0;
            std::string ChannelName;
        };

        class UserlistRemove final : public ServerPacket
        {
        public:
            UserlistRemove() : ServerPacket(SMSG_USERLIST_REMOVE, 30) { }

            WorldPacket const* Write() override;

            ObjectGuid RemovedUserGUID;
            uint32 _ChannelFlags = CHANNEL_FLAG_NONE; ///< @see enum ChannelFlags
            uint32 ChannelID = 0;
            std::string ChannelName;
        };

        class UserlistUpdate final : public ServerPacket
        {
        public:
            UserlistUpdate() : ServerPacket(SMSG_USERLIST_UPDATE, 30) { }

            WorldPacket const* Write() override;

            ObjectGuid UpdatedUserGUID;
            uint32 _ChannelFlags = CHANNEL_FLAG_NONE; ///< @see enum ChannelFlags
            uint8 UserFlags = MEMBER_FLAG_NONE;
            int32 ChannelID = 0;
            std::string ChannelName;
        };

        class ChannelPlayerCommand final : public ClientPacket
        {
        public:
            ChannelPlayerCommand(WorldPacket&& packet);

            void Read() override;

            std::string ChannelName;
            std::string Name;
        };

        class JoinChannel final : public ClientPacket
        {
        public:
            JoinChannel(WorldPacket&& packet) : ClientPacket(CMSG_CHAT_JOIN_CHANNEL, std::move(packet)) { }

            void Read() override;

            std::string Password;
            std::string ChannelName;
            bool CreateVoiceSession = false;
            int32 ChatChannelId = 0;
            bool Internal = false;
        };

        class LeaveChannel final : public ClientPacket
        {
        public:
            LeaveChannel(WorldPacket&& packet) : ClientPacket(CMSG_CHAT_LEAVE_CHANNEL, std::move(packet)) { }

            void Read() override;

            int32 ZoneChannelID = 0;
            std::string ChannelName;
        };
    }
}

#endif // ChannelPackets_h__
