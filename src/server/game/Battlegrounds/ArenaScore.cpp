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

#include "ArenaScore.h"

ArenaScore::ArenaScore(ObjectGuid playerGuid, TeamId team) : BattlegroundScore(playerGuid, team), TeamID(team)
{
}

ArenaTeamScore::ArenaTeamScore() : OldRating(0), NewRating(0), MatchmakerRating(0)
{
}

void ArenaTeamScore::Reset()
{
    OldRating = 0;
    NewRating = 0;
    MatchmakerRating = 0;
}

void ArenaTeamScore::Assign(int32 oldRating, int32 newRating, uint32 matchMakerRating)
{
    OldRating = oldRating;
    NewRating = newRating;
    MatchmakerRating = matchMakerRating;
}
