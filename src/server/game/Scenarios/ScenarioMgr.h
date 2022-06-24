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

#ifndef TRINITY_SCENARIOMGR_H
#define TRINITY_SCENARIOMGR_H

#include "Common.h"
#include "Scenario.h"

class Scenario;
struct ScenarioStepEntry;

typedef std::vector<ScenarioStepEntry const*> ScenarioSteps;
typedef std::map<uint32 /*instance_id*/, Scenario*> ScenarioMap;
typedef std::map<uint32, ScenarioSteps> ScenarioStepsByScenarioMap;
typedef std::vector<ScenarioSteps*> ScenarioStepsByScenarioVector;

class ScenarioMgr
{
public:
    ScenarioMgr();
    ~ScenarioMgr();

    void UnloadAll();
    static ScenarioMgr* instance();

    Scenario* AddScenario(Map* map, lfg::LFGDungeonData const* _dungeonData, Player* player, bool find = false);
    void RemoveScenario(uint32 instanceId);
    Scenario* GetScenario(uint32 instanceId);

    ScenarioSteps const* GetScenarioSteps(uint32 scenarioId, bool Teeming = false);
    bool HasScenarioStep(lfg::LFGDungeonData const* _dungeonData, Player* player);
    bool HasAffixesTeeming(uint16 CriteriaTreeID);

private:
    ScenarioMap _scenarioStore;

    ScenarioStepsByScenarioMap m_stepMap;
    ScenarioStepsByScenarioMap m_stepTeemingMap;
    ScenarioStepsByScenarioVector m_stepVector;
};

#define sScenarioMgr ScenarioMgr::instance()

#endif
