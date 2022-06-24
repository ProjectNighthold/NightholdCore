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

#include "ScenarioMgr.h"
#include "LFGMgr.h"
#include "WorldSession.h"

ScenarioMgr::ScenarioMgr()
{
    m_stepVector.assign(sScenarioStore.GetNumRows() + 1, nullptr);

    for (ScenarioStepEntry const* entry : sScenarioStepStore)
    {
        if (!sScenarioStore.LookupEntry(entry->ScenarioID))
            continue;

        if (HasAffixesTeeming(entry->Criteriatreeid)) // Affixes::Teeming
        {
            uint8 orderIndex = 0/*entry->OrderIndex*/; // allways step 0
            if (m_stepTeemingMap[entry->ScenarioID].size() <= orderIndex)
                m_stepTeemingMap[entry->ScenarioID].resize(orderIndex + 1);

            m_stepTeemingMap[entry->ScenarioID][orderIndex] = entry;
            continue;
        }

        if (m_stepMap[entry->ScenarioID].size() <= entry->OrderIndex)
            m_stepMap[entry->ScenarioID].resize(entry->OrderIndex + 1);

        m_stepMap[entry->ScenarioID][entry->OrderIndex] = entry;
        m_stepVector[entry->ScenarioID] = &m_stepMap[entry->ScenarioID];
    }
}

ScenarioMgr::~ScenarioMgr()
{
    for (auto v : _scenarioStore)
        delete v.second;
}

void ScenarioMgr::UnloadAll()
{
    for (auto v : _scenarioStore)
        v.second->GetAchievementMgr().ClearMap();
}

ScenarioMgr* ScenarioMgr::instance()
{
    static ScenarioMgr instance;
    return &instance;
}

void ScenarioMgr::RemoveScenario(uint32 instanceId)
{
    ScenarioMap::iterator itr = _scenarioStore.find(instanceId);
    if (itr == _scenarioStore.end())
        return;

    delete itr->second;
    _scenarioStore.erase(itr);
}

ScenarioSteps const* ScenarioMgr::GetScenarioSteps(uint32 scenarioId, bool Teeming)
{
    if (Teeming)
        if (ScenarioSteps const* steps = Trinity::Containers::MapGetValuePtr(m_stepTeemingMap, scenarioId))
            return steps;
    return m_stepVector[scenarioId];
}

Scenario* ScenarioMgr::AddScenario(Map* map, lfg::LFGDungeonData const* dungeonData, Player* player, bool find)
{
    if (_scenarioStore.find(map->GetInstanceId()) != _scenarioStore.end())
        return nullptr;

    Scenario* scenario = new Scenario(map, dungeonData, player, find);
    _scenarioStore[map->GetInstanceId()] = scenario;
    map->m_scenarios.insert(scenario);
    return scenario;
}

Scenario* ScenarioMgr::GetScenario(uint32 instanceId)
{
    return Trinity::Containers::MapGetValuePtr(_scenarioStore, instanceId);
}

bool ScenarioMgr::HasScenarioStep(lfg::LFGDungeonData const* _dungeonData, Player* player)
{
    uint32 scenarioId = 0;
    if (player->GetScenarioId())
        scenarioId = player->GetScenarioId();
    else if (ScenarioData const* scenarioData = sObjectMgr->GetScenarioOnMap(_dungeonData->map, _dungeonData->difficulty, player->GetTeam(), player->getClass(), _dungeonData->id))
        scenarioId = scenarioData->ScenarioID;
    else if (_dungeonData->dbc->ScenarioID)
        scenarioId = _dungeonData->dbc->ScenarioID;

    if (!scenarioId)
        return false;

    return m_stepVector[scenarioId] != nullptr;
}

bool ScenarioMgr::HasAffixesTeeming(uint16 CriteriaTreeID)
{
    switch (CriteriaTreeID)
    {
        case 47415:
        case 50599:
        case 51246:
        case 51710:
        case 51880:
        case 52278:
        case 52327:
        case 52427:
        case 52471:
        case 57810:
        case 57866:
        case 58715:
        case 60933:
            return true;
    }

    return false;
}
