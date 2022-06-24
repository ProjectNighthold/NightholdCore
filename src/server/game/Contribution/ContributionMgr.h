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

#ifndef ContributionMgr_h__
#define ContributionMgr_h__

namespace ContributionData
{
    enum ContributionState : uint8
    {
        CONTRIBUTION_STATE_NONE = 0,
        CONTRIBUTION_STATE_BUILDING = 1,
        CONTRIBUTION_STATE_ACTIVE = 2,
        CONTRIBUTION_STATE_UNDERATTACK = 3,
        CONTRIBUTION_STATE_DESTROYED = 4
    };

    enum ContributionResult : uint8
    {
        CONTRIBUTUIN_RESULT_SUCCESS = 0,
        CONTRIBUTUIN_RESULT_MUST_BE_NEAR = 1,
        CONTRIBUTUIN_RESULT_INCORRECT_STATE = 2,
        CONTRIBUTUIN_RESULT_INVALID_ID = 3,
        CONTRIBUTUIN_RESULT_QUEST_DATA_MISSING = 4,
        CONTRIBUTUIN_RESULT_FAILED_CONDITION_CHECK = 5,
        CONTRIBUTUIN_RESULT_UNABLE_TO_COMPLETE_TURN_IN = 6,
        CONTRIBUTUIN_RESULT_INTERNAL_ERROR = 7
    };

    enum Contribution : uint8
    {
        CONTRIBUTION_MAGE_TOWER = 1,
        CONTRIBUTION_COMMAND_CENTER = 3,
        CONTRIBUTION_NETHER_DISRUPTOR = 4,
    };
}

struct ContributionLifeData
{
    uint32 WorldStateVareables[3];
    ContributionData::ContributionState State;
    uint32 UpTimeSecs;
    uint32 CurrentLifeTimer;
    uint32 DownTimeSecs;
    uint32 CurrentUnderAtackTimer;
};

class ContributionMgr
{
public:
    static ContributionMgr& Instance();

    ContributionMgr();

    void Update(uint32 diff);

    void Initialize();
    void OnChangeContributionState(uint32 contribuiontID, ContributionData::ContributionState newState);
    void Contribute(Player* player, uint8 contributuinID);
    void ContributionGetState(Player* player, uint32 contributionID, uint32 contributionGuid);

private:
    std::map<uint32, ContributionLifeData> _contributionObjects;
    uint32 m_nextUpdate;
};

#define sContributionMgr ContributionMgr::Instance()

#endif // ContributionMgr_h__
