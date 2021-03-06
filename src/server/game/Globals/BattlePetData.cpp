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

#include "BattlePetData.h"
#include <fstream>
#include "DatabaseEnv.h"
#include "Log.h"
#include "Timer.h"
#include "MapManager.h"
#include "DB2Stores.h"

BattlePetDataStoreMgr::BattlePetDataStoreMgr()
{
}

BattlePetDataStoreMgr::~BattlePetDataStoreMgr()
{
}

BattlePetDataStoreMgr* BattlePetDataStoreMgr::instance()
{
    static BattlePetDataStoreMgr instance;
    return &instance;
}

void BattlePetDataStoreMgr::Initialize()
{
    LoadBattlePetTemplate();
    LoadBattlePetNpcTeamMember();
    //ComputeBattlePetSpawns();
}

void BattlePetDataStoreMgr::LoadBattlePetTemplate()
{
    uint32 oldMSTime = getMSTime();

    _battlePetTemplateStore.clear();

    auto result = WorldDatabase.Query("SELECT Specie, breadsMask, minquality, NpcID, minlevel, maxlevel FROM battlepet_info");
    if (!result)
    {
        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 battlepet template. DB table `battlepet_info` is empty.");
        return;
    }

    do
    {
        auto fields = result->Fetch();

        uint32 species = fields[0].GetUInt32();
        BattlePetTemplate& temp = _battlePetTemplateStore[species];
        temp.BreedMask = fields[1].GetUInt32();
        temp.MinQuality = fields[2].GetUInt32();
        temp.CreatureID = fields[3].GetUInt32();
        temp.minlevel = fields[4].GetUInt32();
        temp.maxlevel = fields[5].GetUInt32();
        temp.Species = species;

        if (temp.minlevel == 0)
            temp.minlevel = 1;
        if (temp.maxlevel == 0)
            temp.maxlevel = 1;
        if (temp.maxlevel < temp.minlevel)
            temp.maxlevel = temp.minlevel;

        if (temp.BreedMask == 0)
            temp.BreedMask = 8;

        for (uint8 i = 3; i < 13; ++i)
            if (temp.BreedMask & (1 << i))
                temp.BreedIDs.insert(i);

        _battlePetTemplate[temp.CreatureID] = &temp;

    } while (result->NextRow());

    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded %u battlepet template in %u ms.", _battlePetTemplateStore.size(), GetMSTimeDiffToNow(oldMSTime));
}

void BattlePetDataStoreMgr::LoadBattlePetNpcTeamMember()
{
    uint32 oldMSTime = getMSTime();

    _battlePetNpcTeamMembers.clear();

    auto result = WorldDatabase.Query("SELECT NpcID, Specie, Ability1, Ability2, Ability3, maxlevel, minlevel, minquality, breadsMask FROM battlepet_npc_team_member");
    if (!result)
    {
        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 battlepet npc team member. DB table `battlepet_npc_team_member` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        BattlePetNpcTeamMember npcTeamMember;
        npcTeamMember.Specie = fields[1].GetUInt32();
        npcTeamMember.Ability[0] = fields[2].GetUInt32();
        npcTeamMember.Ability[1] = fields[3].GetUInt32();
        npcTeamMember.Ability[2] = fields[4].GetUInt32();
        npcTeamMember.maxlevel = fields[5].GetUInt32();
        npcTeamMember.minlevel = fields[6].GetUInt32();
        npcTeamMember.minquality = fields[7].GetUInt32();
        npcTeamMember.breadsMask = fields[8].GetUInt32();

        if (npcTeamMember.breadsMask == 0)
            npcTeamMember.breadsMask = 8;

        for (uint8 i = 3; i < 13; ++i)
            if (npcTeamMember.breadsMask & (1 << i))
                npcTeamMember.BreedIDs.insert(i);

        _battlePetNpcTeamMembers[fields[0].GetUInt32()].push_back(npcTeamMember);
    } while (result->NextRow());

    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> Loaded %u battlepet npc team member in %u ms.", static_cast<uint32>(_battlePetNpcTeamMembers.size()), GetMSTimeDiffToNow(oldMSTime));
}

void BattlePetDataStoreMgr::ComputeBattlePetSpawns()
{
    uint32 oldMSTime = getMSTime();

    auto result = WorldDatabase.Query("SELECT CritterEntry, BattlePetEntry FROM temp_battlepet_spawn_relation a");
    if (!result)
    {
        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> ComputeBattlePetSpawns No battlepet relation");
        return;
    }

    std::map<uint32, uint32> battlePetToCritter;
    do
    {
        Field* fields = result->Fetch();
        battlePetToCritter[fields[1].GetUInt32()] = fields[0].GetUInt32();
    } while (result->NextRow());

    result = WorldDatabase.Query("SELECT MapID, a.Zone, BattlePetNPCID, XPos, YPos, MinLevel, MaxLevel FROM temp_battlepet_tocompute a");

    if (!result)
    {
        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> ComputeBattlePetSpawns No data");
        return;
    }

    struct PoolInfo
    {
        uint32 ZoneID;
        std::map<uint32, uint32> CountPerBattlePetTemplateEntry;
        uint32 MinLevel;
        uint32 MaxLevel;
    };

    std::map<uint32, PoolInfo> poolInfosPerZoneID;
    std::map<uint32, uint32> missingCorelations;

    std::ofstream outSpawns;
    outSpawns.open("BattlePetSpawns.sql");

    do
    {
        auto fields = result->Fetch();
        auto mapID = fields[0].GetUInt32();
        auto zoneID = fields[1].GetUInt32();
        auto battlePetNpcID = fields[2].GetUInt32();
        auto xPos = fields[3].GetDouble();
        auto yPos = fields[4].GetDouble();
        auto minLevel = fields[5].GetUInt32();
        auto maxLevel = fields[6].GetUInt32();

        if (battlePetToCritter.find(battlePetNpcID) == battlePetToCritter.end())
        {
            missingCorelations[battlePetNpcID] = 1;
            continue;
        }

        if (!MapManager::IsValidMapCoord(mapID, xPos, yPos))
        {
            printf("Map %u Zone %u Npc %u X %f Y %F invalid map coord\n", mapID, zoneID, battlePetNpcID, xPos, yPos);
            continue;
        }

        auto mapEntry = sMapMgr->CreateBaseMap(mapID);
        auto zPos = mapEntry->GetHeight(xPos, yPos, MAX_HEIGHT) + 0.5f;

        std::string query = "INSERT INTO creature(id, map, zoneID, spawnMask, phaseMask, position_x, position_y, position_z, spawntimesecs) VALUES (";
        query += std::to_string(battlePetToCritter[battlePetNpcID]) + ", " + std::to_string(mapID) + ", " + std::to_string(zoneID) + ", 1, 1, " + std::to_string(xPos) + ", " + std::to_string(yPos) + ", " + std::to_string(zPos) + ", 120);\n";

        outSpawns << query << std::flush;

        poolInfosPerZoneID[zoneID].ZoneID = zoneID;
        poolInfosPerZoneID[zoneID].MinLevel = minLevel;
        poolInfosPerZoneID[zoneID].MaxLevel = maxLevel;

        if (poolInfosPerZoneID[zoneID].CountPerBattlePetTemplateEntry.find(battlePetNpcID) == poolInfosPerZoneID[zoneID].CountPerBattlePetTemplateEntry.end())
            poolInfosPerZoneID[zoneID].CountPerBattlePetTemplateEntry[battlePetNpcID] = 1;
        else
            poolInfosPerZoneID[zoneID].CountPerBattlePetTemplateEntry[battlePetNpcID] = 1 + poolInfosPerZoneID[zoneID].CountPerBattlePetTemplateEntry[battlePetNpcID];
    } while (result->NextRow());

    for (auto itr = missingCorelations.begin(); itr != missingCorelations.end(); ++itr)
        printf("Npc %u no critter npc found\n", itr->first);

    outSpawns.close();

    std::ofstream outPools;
    outPools.open("BattlePetPools.sql");

    for (auto itrX = poolInfosPerZoneID.begin(); itrX != poolInfosPerZoneID.end(); ++itrX)
    {
        PoolInfo& poolInfo = itrX->second;

        for (auto itr = poolInfo.CountPerBattlePetTemplateEntry.begin(); itr != poolInfo.CountPerBattlePetTemplateEntry.end(); ++itr)
        {
            uint32 respawnTime = 60;
            uint32 replace = battlePetToCritter[itr->first];
            uint32 max = float(itr->second) > 1 ? (float(itr->second) * 0.95f) : 1;

            if (battlePetToCritter[itr->first] == itr->first)
                max = itr->second;

            uint32 speciesID = 0;

            if (auto speciesInfo = sDB2Manager.GetSpeciesByCreatureID(itr->first))
                speciesID = speciesInfo->ID;

            if (speciesID == 0 || replace == 0)
            {
                printf("No species or replacement for npc %u found\n", itr->first);
                continue;
            }

            std::string query = "INSERT INTO `wild_battlepet_zone_pool` (`Zone`, `Species`, `Replace`, `Max`, `RespawnTime`, `MinLevel`, `MaxLevel`) VALUES (";
            query += std::to_string(poolInfo.ZoneID) + ", " + std::to_string(speciesID) + ", " + std::to_string(replace) + ", " + std::to_string(max) + ", " + std::to_string(respawnTime) + ", " + std::to_string(poolInfo.MinLevel) + ", " + std::to_string(poolInfo.MaxLevel) + ");\n";

            outPools << query << std::flush;
        }
    }

    outPools.close();

    TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, ">> ComputeBattlePetSpawns %u ms.", GetMSTimeDiffToNow(oldMSTime));
}

BattlePetTemplate const* BattlePetDataStoreMgr::GetBattlePetTemplate(uint32 species) const
{
    return Trinity::Containers::MapGetValuePtr(_battlePetTemplateStore, species);
}

BattlePetTemplate const* BattlePetDataStoreMgr::GetBattlePetTemplateByEntry(uint32 CreatureID) const
{
    return Trinity::Containers::MapGetValuePtr(_battlePetTemplate, CreatureID);
}

uint16 BattlePetDataStoreMgr::GetRandomBreedID(std::set<uint32> BreedIDs)
{
    if (BreedIDs.empty())
        return 0;

    uint32 sum = 0;
    for (auto itr : BreedIDs)
        sum += GetWeightForBreed(itr);

    uint32 r = urand(0, sum);
    uint32 current_sum = 0;

    for (auto itr : BreedIDs)
    {
        uint16 breedID = itr;
        if (current_sum <= r && r < current_sum + GetWeightForBreed(breedID))
            return breedID;

        current_sum += GetWeightForBreed(breedID);
    }

    return 0;
}

uint8 BattlePetDataStoreMgr::GetWeightForBreed(uint16 breedID)
{
    uint8 weight = 0;
    switch (breedID)
    {
        case 3:
            weight = 60;
            break;
        case 4:
        case 5:
        case 6:
            weight = 10;
            break;
        case 7:
        case 8:
        case 9:
            weight = 20;
            break;
        case 10:
        case 11:
        case 12:
            weight = 30;
            break;
        default:
            break;
    }
    return weight;
}

uint8 BattlePetDataStoreMgr::GetRandomQuailty()
{
    // 42% - grey, 33% - white, 19% - green, 6% - rare
    uint32 r = urand(0, 1000);

    uint8 quality = 0;
    if (r >= 420 && r < 750)
        quality = 1;
    else if (r >= 750 && r < 940)
        quality = 2;
    else if (r >= 940 && r <= 1000)
        quality = 3;

    return quality;
}

std::vector<BattlePetNpcTeamMember> BattlePetDataStoreMgr::GetPetBattleTrainerTeam(uint32 npcID)
{
    return _battlePetNpcTeamMembers[npcID];
}
