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

#ifndef TRINITY_ARENA_SCORE_H
#define TRINITY_ARENA_SCORE_H

#include "BattlegroundScore.h"
#include "ObjectGuid.h"
#include "SharedDefines.h"

struct ArenaScore : BattlegroundScore
{
    friend class Arena;

protected:
    ArenaScore(ObjectGuid playerGuid, TeamId team);

    void BuildObjectivesBlock(std::vector<int32>& /*stats*/) override { }

    TeamId TeamID;
};

struct ArenaTeamScore
{
    friend class Arena;
    friend class Battleground;

protected:
    ArenaTeamScore();

    virtual ~ArenaTeamScore() = default;

    void Reset();

    void Assign(int32 oldRating, int32 newRating, uint32 matchMakerRating);

    int32 OldRating;
    int32 NewRating;
    uint32 MatchmakerRating;
};

#endif // TRINITY_ARENA_SCORE_H
