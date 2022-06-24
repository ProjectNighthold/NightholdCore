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

#include "WorldSession.h"
#include "CollectionMgr.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "TransmogrificationPackets.h"
#include "GameEventMgr.h"

void WorldSession::HandleTransmogrifyItems(WorldPackets::Transmogrification::TransmogrifyItems& packet)
{
    Player* player = GetPlayer();
    if (!player->GetNPCIfCanInteractWith(packet.Npc, UNIT_NPC_FLAG_TRANSMOGRIFIER))
        return;

    int64 cost = 0;
    std::unordered_map<Item*, uint32> transmogItems;
    std::unordered_map<Item*, uint32> illusionItems;

    std::vector<Item*> resetAppearanceItems;
    std::vector<Item*> resetIllusionItems;

    for (WorldPackets::Transmogrification::TransmogrifyItem const& transmogItem : packet.Items)
    {
        if (transmogItem.Slot >= EQUIPMENT_SLOT_END)
            return;

        Item* itemTransmogrified = player->GetItemByPos(INVENTORY_SLOT_BAG_0, transmogItem.Slot);
        if (!itemTransmogrified)
            return;

        if (transmogItem.ItemModifiedAppearanceID)
        {
            ItemModifiedAppearanceEntry const* itemModifiedAppearance = sItemModifiedAppearanceStore.LookupEntry(transmogItem.ItemModifiedAppearanceID);
            if (!itemModifiedAppearance)
                return;

            if (player->CanUseItem(sObjectMgr->GetItemTemplate(itemModifiedAppearance->ItemID)) != EQUIP_ERR_OK)
                return;

            if (!Item::CanTransmogrifyItemWithItem(itemTransmogrified, itemModifiedAppearance))
                return;

            transmogItems[itemTransmogrified] = transmogItem.ItemModifiedAppearanceID;

            cost += itemTransmogrified->GetSellPrice();
        }
        else
            resetAppearanceItems.push_back(itemTransmogrified);

        if (transmogItem.SpellItemEnchantmentID)
        {
            if (transmogItem.Slot != EQUIPMENT_SLOT_MAINHAND && transmogItem.Slot != EQUIPMENT_SLOT_OFFHAND)
                return;

            SpellItemEnchantmentEntry const* illusion = sSpellItemEnchantmentStore.LookupEntry(transmogItem.SpellItemEnchantmentID);
            if (!illusion)
                return;

            if (!illusion->ItemVisual || !(illusion->Flags & ENCHANTMENT_COLLECTABLE))
                return;

            if (!sConditionMgr->IsPlayerMeetingCondition(player, illusion->TransmogPlayerConditionID))
            {
                resetIllusionItems.push_back(itemTransmogrified);
                continue;
            }

            if (illusion->ScalingClassRestricted > 0 && uint8(illusion->ScalingClassRestricted) != player->getClass())
                return;

            illusionItems[itemTransmogrified] = transmogItem.SpellItemEnchantmentID;
            cost += illusion->TransmogCost;
        }
        else
            resetIllusionItems.push_back(itemTransmogrified);
    }

    if (!IsHolidayActive(HOLIDAY_TRIAL_OF_STYLE))
    {
        if (cost)
        {
            if (!player->HasEnoughMoney(cost))
                return;

            player->ModifyMoney(-cost);
        }
    }

    for (auto& transmogPair : transmogItems)
    {
        Item* transmogrified = transmogPair.first;

        if (!packet.CurrentSpecOnly)
        {
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, transmogPair.second);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, 0);
        }
        else
        {
            if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4))
                transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, transmogrified->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            transmogrified->SetModifier(AppearanceModifierSlotBySpec[player->GetActiveTalentGroup()], transmogPair.second);
        }

        player->SetVisibleItemSlot(transmogrified->GetSlot(), transmogrified);

        transmogrified->SetNotRefundable(player);
        transmogrified->ClearSoulboundTradeable(player);
        transmogrified->SetState(ITEM_CHANGED, player);
    }

    for (auto& illusionPair : illusionItems)
    {
        Item* transmogrified = illusionPair.first;

        if (!packet.CurrentSpecOnly)
        {
            transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS, illusionPair.second);
            transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3, 0);
            transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4, 0);
        }
        else
        {
            if (!transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1))
                transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1, transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2))
                transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2, transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3))
                transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3, transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            if (!transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4))
                transmogrified->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4, transmogrified->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            transmogrified->SetModifier(IllusionModifierSlotBySpec[player->GetActiveTalentGroup()], illusionPair.second);
        }

        player->SetVisibleItemSlot(transmogrified->GetSlot(), transmogrified);

        transmogrified->SetNotRefundable(player);
        transmogrified->ClearSoulboundTradeable(player);
        transmogrified->SetState(ITEM_CHANGED, player);
    }

    for (Item* item : resetAppearanceItems)
    {
        if (!packet.CurrentSpecOnly)
        {
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, 0);
        }
        else
        {
            if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4))
                item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, item->GetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS));
            item->SetModifier(AppearanceModifierSlotBySpec[player->GetActiveTalentGroup()], 0);
            item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS, 0);
        }

        item->SetState(ITEM_CHANGED, player);
        player->SetVisibleItemSlot(item->GetSlot(), item);
    }

    for (Item* item : resetIllusionItems)
    {
        if (!packet.CurrentSpecOnly)
        {
            item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS, 0);
            item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1, 0);
            item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2, 0);
            item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3, 0);
            item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4, 0);
        }
        else
        {
            if (!item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1))
                item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_1, item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2))
                item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_2, item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3))
                item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_3, item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            if (!item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4))
                item->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_SPEC_4, item->GetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS));
            item->SetModifier(IllusionModifierSlotBySpec[player->GetActiveTalentGroup()], 0);
            item->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, 0);
        }

        item->SetState(ITEM_CHANGED, player);
        player->SetVisibleItemSlot(item->GetSlot(), item);
    }
}

void WorldSession::SendOpenTransmogrifier(ObjectGuid const& guid)
{
    SendPacket(WorldPackets::Transmogrification::OpenTransmogrifier(guid).Write());
}
