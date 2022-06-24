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

#include "BattlegroundScore.h"

uint32 BattlegroundScore::GetScore(uint32 type) const
{
    switch (type)
    {
        case SCORE_KILLING_BLOWS:
            return KillingBlows;
        case SCORE_DEATHS:
            return Deaths;
        case SCORE_HONORABLE_KILLS:
            return HonorableKills;
        case SCORE_BONUS_HONOR:
            return BonusHonor;
        case SCORE_DAMAGE_DONE:
            return DamageDone;
        case SCORE_HEALING_DONE:
            return HealingDone;
    }
    return 0;
}

BattlegroundScore::BattlegroundScore(ObjectGuid playerGuid, TeamId team) : PlayerGuid(playerGuid), TeamID(MS::Battlegrounds::GetOtherTeamID(team)), KillingBlows(0), Deaths(0), HonorableKills(0), BonusHonor(0), DamageDone(0), HealingDone(0)
{
}

void BattlegroundScore::UpdateScore(uint32 type, uint32 value)
{
    switch (type)
    {
        case SCORE_KILLING_BLOWS:
            KillingBlows += value;
            break;
        case SCORE_DEATHS:
            Deaths += value;
            break;
        case SCORE_HONORABLE_KILLS:
            HonorableKills += value;
            break;
        case SCORE_BONUS_HONOR:
            BonusHonor += value;
            break;
        case SCORE_DAMAGE_DONE:
            DamageDone += value;
            break;
        case SCORE_HEALING_DONE:
            HealingDone += value;
            break;
        default:
            ASSERT(false && "Not implemented Battleground score type!");
            break;
    }
}
