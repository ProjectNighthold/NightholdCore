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

#ifndef _ITEM_ENCHANTMENT_MGR_H
#define _ITEM_ENCHANTMENT_MGR_H

#include "Common.h"

struct ItemTemplate;

enum class ItemRandomEnchantmentType : uint8
{
    Property = 0,
    Suffix = 1,
    BonusList = 2,
    BonusListAddition = 3
};

struct ItemRandomEnchantmentId
{
    ItemRandomEnchantmentId() = default;
    ItemRandomEnchantmentId(ItemRandomEnchantmentType type, uint32 id) : Type(type), Id(id) { }

    ItemRandomEnchantmentType Type = ItemRandomEnchantmentType::Property;
    uint32 Id = 0;
};

void LoadRandomEnchantmentsTable();
ItemRandomEnchantmentId GetItemEnchantMod(int32 entry, ItemRandomEnchantmentType type, uint32 ItemID, uint32 spec_id);
uint32 GetItemThirdStat(uint32 ItemID, bool& sosketSlot1, bool& sosketSlot2, bool& sosketSlot3);
uint32 GenerateEnchSuffixFactor(ItemTemplate const* proto, uint32 level = 0);
uint32 GetRandomPropertyPoints(uint32 itemLevel, uint32 quality, uint32 inventoryType, uint32 subclass);
bool CheckSpecProp(uint32 ench, ItemRandomEnchantmentType type, uint32 SpecID);
bool CheckStatsSpec(uint32 StatType, uint32 SpecID);
#endif

