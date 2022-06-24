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
#include "CollectionPackets.h"
#include "PetBattle.h"

void WorldSession::HandleCollectionItemSetFavorite(WorldPackets::Collections::CollectionItemSetFavorite& collectionItemSetFavorite)
{
    switch (collectionItemSetFavorite.Type)
    {
        case WorldPackets::Collections::TOYBOX:
            _player->GetCollectionMgr()->ToySetFavorite(collectionItemSetFavorite.ID, collectionItemSetFavorite.IsFavorite);
            break;
        case WorldPackets::Collections::APPEARANCE:
            if (_player->GetCollectionMgr()->HasItemAppearance(collectionItemSetFavorite.ID))
                _player->GetCollectionMgr()->SetAppearanceIsFavorite(collectionItemSetFavorite.ID, collectionItemSetFavorite.IsFavorite);
            break;
        case WorldPackets::Collections::TRANSMOG_SET:
            break;
        default:
            break;
    }
}

void WorldSession::HandleMountClearFanfare(WorldPackets::Collections::MountClearFanfare& packet)
{
    if (_player->GetCollectionMgr()->HasMount(packet.spellID))
        _player->GetCollectionMgr()->UpdateAccountMounts(packet.spellID, MOUNT_FLAG_NONE);
}

void WorldSession::HandleBattlePetClearFanfare(WorldPackets::Collections::BattlePetClearFanfare& packet)
{
    if (auto battlePet = _player->GetBattlePet(packet.BattlePetGUID))
    {
        battlePet->Flags = battlePet->Flags & ~BATTLEPET_FLAG_GIFT;;
        battlePet->needSave = true;
    }
}
