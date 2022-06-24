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

#include "Item.h"
#include "ToyPackets.h"
#include "WorldSession.h"
#include "DatabaseEnv.h"

void WorldSession::HandleAddToy(WorldPackets::Toy::AddToy& packet)
{
    if (!packet.Guid)
        return;
    Player* player = GetPlayer();
    if (!player)
        return;

    Item* item = player->GetItemByGuid(packet.Guid);
    if (!item)
    {
        player->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr);
        return;
    }

    if (!sDB2Manager.IsToyItem(item->GetEntry()))
        return;

    InventoryResult msg = player->CanUseItem(item);
    if (msg != EQUIP_ERR_OK)
    {
        player->SendEquipError(msg, item, nullptr);
        return;
    }

    if (player->GetCollectionMgr()->AddToy(item->GetEntry(), false))
    {
        { // donate status
            SQLTransaction transs = LoginDatabase.BeginTransaction();
            TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Status] Status = 3 item guid = %u, entry = %u, %s", item->GetGUID().GetGUIDLow(), item->GetEntry(), player->GetInfoForDonate().c_str());
            uint8 index = 0;
            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_HISTORY_STATUS);
            stmt->setUInt32(  index, 3);
            stmt->setUInt32(  ++index, item->GetGUID().GetGUIDLow()); 
            stmt->setUInt32(  ++index, realm.Id.Realm); 
                    
            transs->Append(stmt);
            LoginDatabase.CommitTransaction(transs); 
        }
        
        player->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);
    }
}

void WorldSession::HandleUseToy(WorldPackets::Toy::UseToy& packet)
{
    uint32 itemId = packet.Cast.Misc[0];
    auto item = sObjectMgr->GetItemTemplate(itemId);
    if (!item)
        return;

    auto spellInfo = sSpellMgr->GetSpellInfo(packet.Cast.SpellID);
    if (!spellInfo)
        return;

    auto player = GetPlayer();
    if (!player)
        return;

    auto effect = std::find_if(item->Effects.begin(), item->Effects.end(), [&packet](ItemEffectEntry const* effect)
    {
        return uint32(packet.Cast.SpellID) == effect->SpellID;
    });

    if (effect == item->Effects.end())
        return;

    if (player->isPossessing())
        return;

    SpellCastTargets targets(player, packet.Cast);

    if (Map* map = _player->GetMap())
    {
        if (map->IsRaid() || map->isChallenge())
        {
            if (Unit * target = targets.GetUnitTarget())
                sLog->outWarden("AnticheatSpecial: Player %s (GUID: %u) used toy %u on target %u on map %u", _player->GetName(), _player->GetGUIDLow(), item->GetId(), target->GetEntry(), map->GetId());
            else
                sLog->outWarden("AnticheatSpecial: Player %s (GUID: %u) used toy %u on map %u", _player->GetName(), _player->GetGUIDLow(), item->GetId(), map->GetId());
        }
    }

    TriggerCastData triggerData;
    triggerData.miscData0 = packet.Cast.Misc[0];
    triggerData.miscData1 = packet.Cast.Misc[1];
    triggerData.spellGuid = packet.Cast.SpellGuid;

    auto spell = new Spell(player, spellInfo, triggerData);
    spell->m_castItemEntry = itemId;
    spell->m_castFlags[1] |= CAST_FLAG_EX_USE_TOY_SPELL;
    spell->prepare(&targets);
}
