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

#ifndef TRINITY_BATTLEGROUND_SCORE_H
#define TRINITY_BATTLEGROUND_SCORE_H

enum ScoreType
{
    SCORE_KILLING_BLOWS         = 1,
    SCORE_DEATHS                = 2,
    SCORE_HONORABLE_KILLS       = 3,
    SCORE_BONUS_HONOR           = 4,

    SCORE_DAMAGE_DONE           = 5,
    SCORE_HEALING_DONE          = 6,

    // WS, EY and TP
    SCORE_FLAG_CAPTURES         = 7,
    SCORE_FLAG_RETURNS          = 8,

    // AB and IC
    SCORE_BASES_ASSAULTED       = 9,
    SCORE_BASES_DEFENDED        = 10,

    // AV
    SCORE_GRAVEYARDS_ASSAULTED  = 11,
    SCORE_GRAVEYARDS_DEFENDED   = 12,
    SCORE_TOWERS_ASSAULTED      = 13,
    SCORE_TOWERS_DEFENDED       = 14,
    SCORE_MINES_CAPTURED        = 15,
    SCORE_LEADERS_KILLED        = 16,
    SCORE_SECONDARY_OBJECTIVES  = 17,

    // SOTA
    SCORE_DESTROYED_DEMOLISHER  = 18,
    SCORE_DESTROYED_WALL        = 19,

    // SM
    SCORE_CARTS_HELPED          = 20,
    // TK
    SCORE_ORB_HANDLES           = 21,
    SCORE_ORB_SCORE             = 22,

    // DG
    SCORE_CARTS_CAPTURED        = 25,
    SCORE_CARTS_DEFENDED        = 26,
    SCORE_POINTS_CAPTURED       = 27,
    SCORE_POINTS_DEFENDED       = 28,
};

struct BattlegroundScore
{
    friend class Battleground;
    virtual uint32 GetScore(uint32 type) const;

protected:
    BattlegroundScore(ObjectGuid playerGuid, TeamId team);
    virtual ~BattlegroundScore() = default;
    virtual void UpdateScore(uint32 type, uint32 value);
    virtual void BuildObjectivesBlock(std::vector<int32>& /*stats*/) = 0;

    ObjectGuid PlayerGuid;
    TeamId TeamID;
    uint32 KillingBlows;
    uint32 Deaths;
    uint32 HonorableKills;
    uint32 BonusHonor;
    uint32 DamageDone;
    uint32 HealingDone;
};

#endif // TRINITY_BATTLEGROUND_SCORE_H
