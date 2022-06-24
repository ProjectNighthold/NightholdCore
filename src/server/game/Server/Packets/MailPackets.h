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

#ifndef MailPackets_h__
#define MailPackets_h__

#include "ItemPackets.h"
#include "Packet.h"
#include "ObjectGuid.h"

struct Mail;

namespace WorldPackets
{
    namespace Mail
    {
        struct MailAttachedItem
        {
            MailAttachedItem(::Item const* item, uint8 pos);

            uint8 Position = 0;
            int32 AttachID = 0;
            Item::ItemInstance Item;
            int32 Count = 0;
            int32 Charges = 0;
            int32 MaxDurability = 0;
            int32 Durability = 0;
            bool Unlocked = false;
            std::vector<Item::ItemEnchantData> Enchants;
            std::vector<Item::ItemGemData> Gems;
        };

        struct MailListEntry
        {
            MailListEntry(::Mail const* mail, Player* player);
            
            std::vector<MailAttachedItem> Attachments;
            Optional<ObjectGuid> SenderCharacter;
            Optional<uint32> AltSenderID;
            int64 Cod = 0;
            int64 SentMoney = 0;
            int32 MailID = 0;
            int32 StationeryID = 0;
            int32 Flags = 0;
            int32 MailTemplateID = 0;
            float DaysLeft = 0.0f;
            std::string Subject;
            std::string Body;
            uint8 SenderType = 0;
        };

        class MailGetList final : public ClientPacket
        {
        public:
            MailGetList(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_GET_LIST, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
        };

        class MailListResult final : public ServerPacket
        {
        public:
            MailListResult() : ServerPacket(SMSG_MAIL_LIST_RESULT, 8) { }

            WorldPacket const* Write() override;

            int32 TotalNumRecords = 0;
            std::vector<MailListEntry> Mails;
        };

        class MailCreateTextItem final : public ClientPacket
        {
        public:
            MailCreateTextItem(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_CREATE_TEXT_ITEM, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            uint32 MailID = 0;
        };

        class SendMail final : public ClientPacket
        {
        public:
            struct StructSendMail
            {
                struct MailAttachment
                {
                    uint8 AttachPosition = 0;
                    ObjectGuid ItemGUID;
                };

                ObjectGuid Mailbox;
                int32 StationeryID = 0;
                int64 SendMoney = 0;
                int64 Cod = 0;
                std::string Target;
                std::string Subject;
                std::string Body;
                std::vector<MailAttachment> Attachments;
            };

            SendMail(WorldPacket&& packet) : ClientPacket(CMSG_SEND_MAIL, std::move(packet)) { }

            void Read() override;

            StructSendMail Info;
        };

        class MailCommandResult final : public ServerPacket
        {
        public:
            MailCommandResult() : ServerPacket(SMSG_MAIL_COMMAND_RESULT, 6 * 4) { }

            WorldPacket const* Write() override;

            uint32 MailID = 0;
            uint32 Command = 0;
            uint32 ErrorCode = 0;
            uint32 BagResult = 0;
            uint32 AttachID = 0;
            uint32 QtyInInventory = 0;
        };

        class MailReturnToSender final : public ClientPacket
        {
        public:
            MailReturnToSender(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_RETURN_TO_SENDER, std::move(packet)) { }

            void Read() override;

            int32 MailID = 0;
            ObjectGuid SenderGUID;
        };

        class MailMarkAsRead final : public ClientPacket
        {
        public:
            MailMarkAsRead(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_MARK_AS_READ, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            int32 MailID = 0;
            bool BiReceipt = false;
        };

        class MailDelete final : public ClientPacket
        {
        public:
            MailDelete(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_DELETE, std::move(packet)) { }

            void Read() override;

            int32 MailID = 0;
            int32 DeleteReason = 0;
        };

        class MailTakeItem final : public ClientPacket
        {
        public:
            MailTakeItem(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_TAKE_ITEM, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            int32 MailID = 0;
            uint32 AttachID = 0;
        };

        class MailTakeMoney final : public ClientPacket
        {
        public:
            MailTakeMoney(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_TAKE_MONEY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            int32 MailID = 0;
            int64 Money = 0;
        };

        class MailQueryNextMailTime final : public ClientPacket
        {
        public:
            MailQueryNextMailTime(WorldPacket&& packet) : ClientPacket(CMSG_QUERY_NEXT_MAIL_TIME, std::move(packet)) { }

            void Read() override { }
        };

        class MailQueryNextTimeResult final : public ServerPacket
        {
        public:
            struct MailNextTimeEntry
            {
                MailNextTimeEntry(::Mail const* mail);

                ObjectGuid SenderGuid;
                float TimeLeft = 0.0f;
                int32 AltSenderID = 0;
                int8 AltSenderType = 0;
                int32 StationeryID = 0;
            };

            MailQueryNextTimeResult() : ServerPacket(SMSG_MAIL_QUERY_NEXT_TIME_RESULT, 8) { }

            WorldPacket const* Write() override;

            float NextMailTime = 0.0f;
            std::vector<MailNextTimeEntry> Next;
        };

        class NotifyRecievedMail : ServerPacket
        {
        public:
            NotifyRecievedMail() : ServerPacket(SMSG_NOTIFY_RECEIVED_MAIL, 4) { }

            WorldPacket const* Write() override;

            float Delay = 0.0f;
        };

        class ShowMailbox final : public ServerPacket
        {
        public:
            ShowMailbox() : ServerPacket(SMSG_SHOW_MAILBOX, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid PostmasterGUID;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Mail::MailAttachedItem const& att);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Mail::MailListEntry const& entry);

#endif // MailPackets_h__
