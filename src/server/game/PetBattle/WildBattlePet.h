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

#pragma once
#ifndef _WILDBATTLEPET_HEADER_
#define _WILDBATTLEPET_HEADER_

#include "Common.h"
#include "Timer.h"
#include "PetBattle.h"

#define WILDBATTLEPETMGR_UPDATE_INTERVAL 6000
#define WILDBATTLEPET_RESPAWN_WHEN_NOT_DEFEATED 10

class Creature;

struct WildBattlePetPool
{
    std::set<Creature*> ToBeReplaced;
    std::set<Creature*> Replaced;
    std::map<ObjectGuid, ObjectGuid> ReplacedRelation;
};

struct WildPetPoolTemplate
{
    uint32 Species{};
    uint32 BattlePetEntry{};
    uint32 CreatureEntry{};
    uint32 Max{};
    uint32 RespawnTime{};
    uint32 MinLevel{};
    uint32 MaxLevel{};
};

class WildBattlePetZonePools
{
public:
    void LoadPoolTemplate(Field* fields);
    std::map<uint32, WildPetPoolTemplate> m_Templates;
};

class WildBattlePetMgr
{
public:
    static WildBattlePetMgr* instance();

    WildBattlePetMgr();

    void Load();

    void Populate(WildPetPoolTemplate* wTemplate, WildBattlePetPool* pTemplate);
    void Depopulate(WildBattlePetPool* pTemplate);

    void ReplaceCreature(Creature* creature, WildPetPoolTemplate* wTemplate, WildBattlePetPool* pTemplate);
    void EnableWildBattle(Creature* creature);
    void UnreplaceCreature(Creature* creature);

    bool IsWildPet(Creature* creature);
    std::shared_ptr<BattlePetInstance> GetWildBattlePet(Creature* creature);

    void EnterInBattle(Creature* creature);
    void LeaveBattle(Creature* creature, bool p_Defeated);

    WildPetPoolTemplate* GetWildPetTemplate(uint32 mapId, uint32 zoneId, uint32 entry);
    bool IsBattlePet(uint32 entry);

private:
    ///        map              zone          pools
    std::vector<std::map<uint32, WildBattlePetZonePools>> m_PoolsByMap;
    std::set<uint32> m_battlePetSetEntry;
};

#define sWildBattlePetMgr WildBattlePetMgr::instance()

#endif
