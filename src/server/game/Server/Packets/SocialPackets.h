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

#ifndef SocialPackets_h__
#define SocialPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"
#include "LfgListPackets.h"

struct FriendInfo;
enum FriendsResult : uint8;

namespace WorldPackets
{
    namespace Social
    {
        class SendContactList final : public ClientPacket
        {
        public:
            SendContactList(WorldPacket&& packet) : ClientPacket(CMSG_SEND_CONTACT_LIST, std::move(packet)) { }

            void Read() override;

            uint32 Flags = 0;
        };

        struct ContactInfo
        {
            ObjectGuid Guid;
            ObjectGuid WowAccountGuid;
            uint32 VirtualRealmAddr = 0;
            uint32 NativeRealmAddr = 0;
            uint32 TypeFlags = 0;
            uint32 AreaID = 0;
            uint32 Level = 0;
            uint32 ClassID = CLASS_NONE;
            std::string Notes;
            uint8 Status = 0;
        };

        class ContactList final : public ServerPacket
        {
        public:
            ContactList() : ServerPacket(SMSG_CONTACT_LIST, 8) { }

            WorldPacket const* Write() override;

            std::vector<ContactInfo> Contacts;
            uint32 Flags = 0;
        };

        class FriendStatus final : public ServerPacket
        {
        public:
            FriendStatus() : ServerPacket(SMSG_FRIEND_STATUS, 38) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            ObjectGuid WowAccountGuid;
            uint32 VirtualRealmAddress = 0;
            uint32 ClassID = CLASS_NONE;
            uint32 Level = 0;
            uint32 AreaID = 0;
            std::string Notes;
            uint8 Status = 0;
            uint8 FriendResult = 0;
        };

        struct QualifiedGUID
        {
            ObjectGuid Guid;
            uint32 VirtualRealmAddress = 0;
        };

        class AddFriend final : public ClientPacket
        {
        public:
            AddFriend(WorldPacket&& packet) : ClientPacket(CMSG_ADD_FRIEND, std::move(packet)) { }

            void Read() override;

            std::string Notes;
            std::string Name;
        };

        class DelFriend final : public ClientPacket
        {
        public:
            DelFriend(WorldPacket&& packet) : ClientPacket(CMSG_DEL_FRIEND, std::move(packet)) { }

            void Read() override;

            QualifiedGUID Player;
        };

        class SetContactNotes final : public ClientPacket
        {
        public:
            SetContactNotes(WorldPacket&& packet) : ClientPacket(CMSG_SET_CONTACT_NOTES, std::move(packet)) { }

            void Read() override;

            QualifiedGUID Player;
            std::string Notes;
        };

        class AddIgnore final : public ClientPacket
        {
        public:
            AddIgnore(WorldPacket&& packet) : ClientPacket(CMSG_ADD_IGNORE, std::move(packet)) { }

            void Read() override;

            std::string Name;
        };

        class DelIgnore final : public ClientPacket
        {
        public:
            DelIgnore(WorldPacket&& packet) : ClientPacket(CMSG_DEL_IGNORE, std::move(packet)) { }

            void Read() override;

            QualifiedGUID Player;
        };

        struct SocialQueueUpdateData
        {
            struct UnkDataStruct
            {
                uint32 UnkInt1 = 0;
                uint32 UnkInt2 = 0;
                uint32 UnkInt3 = 0;
                uint32 UnkInt4 = 0;
                uint8 UnkByte = 0;
                bool UnkBit1 = false;
                bool UnkBit2 = false;
            };

            struct UnkDataStruct2
            {
                std::vector<uint32> UnkInts1;
                std::vector<uint32> UnkInts2;
                std::vector<uint8> UnkBytes;
                bool UnkBit1 = false;
                bool UnkBit2 = false;
            };

            LfgList::ListSearchResult SearchResult;
            UnkDataStruct UnkData;
            UnkDataStruct2 UnkData2;
            int8 Type = 0;
            bool UnkBit = false;
        };

        class SocialQueueUpdateNotify final : public ServerPacket
        {
        public:
            SocialQueueUpdateNotify() : ServerPacket(SMSG_SOCIAL_QUEUE_UPDATE_NOTIFY, 4 * 16 + 8 + 1 + 4) { }

            WorldPacket const* Write() override;

            std::vector<SocialQueueUpdateData> SocialQueueUpdates;
            ObjectGuid FriendGuid;
            ObjectGuid ApplicationGuid;
            ObjectGuid ApplicationLeaderGuid;
            uint64 QueueID = 0;
            bool UnkBit = false;
        };

        class QuickJoinAutoAcceptRequests final : public ClientPacket
        {
        public:
            QuickJoinAutoAcceptRequests(WorldPacket&& packet) : ClientPacket(CMSG_QUICK_JOIN_AUTO_ACCEPT_REQUESTS, std::move(packet)) { }

            void Read() override;

            bool EnableAutoAccept = false;
        };

        class QuickJoinRequestInvite final : public ClientPacket
        {
        public:
            QuickJoinRequestInvite(WorldPacket&& packet) : ClientPacket(CMSG_QUICK_JOIN_REQUEST_INVITE, std::move(packet)) { }

            void Read() override;

            ObjectGuid GroupGUID;
            uint32 UnkInt1 = 0;
            uint32 UnkInt2 = 0;
            std::string UnkString1;
            std::string UnkString2;
            bool ApplyAsTank = false;
            bool ApplyAsHealer = false;
            bool ApplyAsDamage = false;
        };

        class QuickJoinRespondToInvite final : public ClientPacket
        {
        public:
            QuickJoinRespondToInvite(WorldPacket&& packet) : ClientPacket(CMSG_QUICK_JOIN_RESPOND_TO_INVITE, std::move(packet)) { }

            void Read() override;

            ObjectGuid GroupGUID;
            ObjectGuid GUID;
            bool Accept = false;
        };

        class QuickJoinSignalToastDisplayed final : public ClientPacket
        {
        public:
            QuickJoinSignalToastDisplayed(WorldPacket&& packet) : ClientPacket(CMSG_QUICK_JOIN_SIGNAL_TOAST_DISPLAYED, std::move(packet)) { }

            void Read() override;

            std::vector<ObjectGuid> UnkGuids;
            ObjectGuid GroupGUID;
            uint32 Priority = 0;
            bool UnkBit1 = false;
            bool UnkBit2 = false;
        };
    }
}

#endif // SocialPackets_h__
