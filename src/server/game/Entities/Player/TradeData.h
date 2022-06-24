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

#ifndef TradeData_h__
#define TradeData_h__

#include "ObjectGuid.h"

enum TradeSlots
{
    TRADE_SLOT_COUNT            = 7,
    TRADE_SLOT_TRADED_COUNT     = 6,
    TRADE_SLOT_NONTRADED        = 6,
    TRADE_SLOT_INVALID          = -1,
};

class Item;
class Player;

class TradeData
{
public:
    TradeData(Player* player, Player* trader);

    Player* GetTrader() const;
    TradeData* GetTraderData() const;

    Item* GetItem(TradeSlots slot) const;
    bool HasItem(ObjectGuid itemGuid) const;
    TradeSlots GetTradeSlotForItem(ObjectGuid itemGuid) const;
    void SetItem(TradeSlots slot, Item* item);

    uint32 GetSpell() const;
    void SetSpell(uint32 spell_id, Item* castItem = nullptr);

    Item*  GetSpellCastItem() const;
    bool HasSpellCastItem() const;

    uint64 GetMoney() const;
    void SetMoney(uint64 money);

    bool IsAccepted() const;
    void SetAccepted(bool state, bool crosssend = false);

    bool IsInAcceptProcess() const;
    void SetInAcceptProcess(bool state);

    uint32 GetClientStateIndex() const;
    void UpdateClientStateIndex();

    uint32 GetServerStateIndex() const;
    void UpdateServerStateIndex();
    void Update(bool for_trader = true);

private:
    Player* _player;
    Player* _trader;
    ObjectGuid _spellCastItem;
    ObjectGuid _items[TRADE_SLOT_COUNT];
    uint64 _money;
    uint32 _spell;
    uint32 _clientStateIndex;
    uint32 _serverStateIndex;
    bool _accepted;
    bool _acceptProccess;
};

#endif // TradeData_h__
