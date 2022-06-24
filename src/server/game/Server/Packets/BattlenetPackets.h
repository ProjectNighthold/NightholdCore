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

#ifndef BattlenetPackets_h__
#define BattlenetPackets_h__

#include "Packet.h"
#include "MessageBuffer.h"
#include "BattlenetRpcErrorCodes.h"

namespace WorldPackets
{
    namespace Battlenet
    {
        struct MethodCall
        {
            uint64 Type = 0;
            uint64 ObjectId = 0;
            uint32 Token = 0;

            uint32 GetServiceHash() const { return uint32(Type >> 32); }
            uint32 GetMethodId() const { return uint32(Type & 0xFFFFFFFF); }
        };

        class Notification final : public ServerPacket
        {
        public:
            Notification() : ServerPacket(SMSG_BATTLENET_NOTIFICATION, 8 + 8 + 4 + 4) { }

            WorldPacket const* Write() override;

            MethodCall Method;
            ByteBuffer Data;
        };

        class Response final : public ServerPacket
        {
        public:
            Response() : ServerPacket(SMSG_BATTLENET_RESPONSE, 4 + 8 + 8 + 4 + 4) { }

            WorldPacket const* Write() override;

            BattlenetRpcErrorCode BnetStatus = ERROR_OK;
            MethodCall Method;
            ByteBuffer Data;
        };

        class SetSessionState final : public ServerPacket
        {
        public:
            SetSessionState(uint8 state) : ServerPacket(SMSG_BATTLENET_SET_SESSION_STATE, 1), State(state) { }

            WorldPacket const* Write() override;

            uint8 State = 0;
        };

        class RealmListTicket final : public ServerPacket
        {
        public:
            RealmListTicket() : ServerPacket(SMSG_BATTLENET_REALM_LIST_TICKET) { }

            WorldPacket const* Write() override;

            uint32 Token = 0;
            bool Allow = false;
            ByteBuffer Ticket;
        };

        class Request final : public ClientPacket
        {
        public:
            Request(WorldPacket&& packet) : ClientPacket(CMSG_BATTLENET_REQUEST, std::move(packet)) { }

            void Read() override;

            MethodCall Method;
            MessageBuffer Data;
        };

        class RequestRealmListTicket final : public ClientPacket
        {
        public:
            RequestRealmListTicket(WorldPacket&& packet) : ClientPacket(CMSG_BATTLENET_REQUEST_REALM_LIST_TICKET, std::move(packet)) { }

            void Read() override;

            uint32 Token = 0;
            std::array<uint8, 32> Secret;
        };
    }
}

#endif // BattlenetPackets_h__
