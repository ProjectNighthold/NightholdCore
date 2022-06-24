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

#ifndef BankPackets_h__
#define BankPackets_h__

#include "ItemPackets.h"
#include "Packet.h"
#include "ObjectGuid.h"
#include "WorldSession.h"

namespace WorldPackets
{
    namespace Bank
    {
        class AutoBankItem final : public ClientPacket
        {
        public:
            AutoBankItem(WorldPacket&& packet) : ClientPacket(CMSG_AUTOBANK_ITEM, std::move(packet)) { }

            void Read() override;

            Item::InvUpdate Inv;
            uint8 Bag = 0;
            uint8 Slot = 0;
        };

        class AutoStoreBankItem final : public ClientPacket
        {
        public:
            AutoStoreBankItem(WorldPacket&& packet) : ClientPacket(CMSG_AUTOSTORE_BANK_ITEM, std::move(packet)) { }

            void Read() override;

            Item::InvUpdate Inv;
            uint8 Bag = 0;
            uint8 Slot = 0;
        };

        class BuyBankSlot final : public ClientPacket
        {
        public:
            BuyBankSlot(WorldPacket&& packet) : ClientPacket(CMSG_BUY_BANK_SLOT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };
        
        class AutostoreBankReagent final : public ClientPacket
        {
        public:
            AutostoreBankReagent(WorldPacket&& packet) : ClientPacket(CMSG_AUTOSTORE_BANK_REAGENT, std::move(packet)) { }

            void Read() override;

            Item::InvUpdate Inv;
            uint8 Bag = 0;
            uint8 Slot = 0;
        };

        class BuyReagentBank final : public ClientPacket
        {
        public:
            BuyReagentBank(WorldPacket&& packet) : ClientPacket(CMSG_BUY_REAGENT_BANK, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
        };

        class DepositReagentBank final : public ClientPacket
        {
        public:
            DepositReagentBank(WorldPacket&& packet) : ClientPacket(CMSG_DEPOSIT_REAGENT_BANK, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
        };
    }
}

#endif // BankPackets_h__
