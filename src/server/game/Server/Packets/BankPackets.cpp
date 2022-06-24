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

#include "BankPackets.h"
#include "ItemPackets.h"

void WorldPackets::Bank::AutoBankItem::Read()
{
    _worldPacket >> Inv;
    _worldPacket >> Bag;
    _worldPacket >> Slot;
}

void WorldPackets::Bank::AutoStoreBankItem::Read()
{
    _worldPacket >> Inv;
    _worldPacket >> Bag;
    _worldPacket >> Slot;
}

void WorldPackets::Bank::BuyBankSlot::Read()
{
    _worldPacket >> Guid;
}

void WorldPackets::Bank::AutostoreBankReagent::Read()
{
    _worldPacket >> Inv;
    _worldPacket >> Bag;
    _worldPacket >> Slot;
}

void WorldPackets::Bank::BuyReagentBank::Read()
{
    _worldPacket >> Banker;
}

void WorldPackets::Bank::DepositReagentBank::Read()
{
    _worldPacket >> Banker;
}
