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

#ifndef __BRACKET_H
#define __BRACKET_H

#include "Common.h"
#include "Player.h"

enum BracketState
{
    BRACKET_UNCHANGED   = 0,
    BRACKET_CHANGED     = 1,
    BRACKET_NEW         = 2,
    BRACKET_REMOVED     = 3     //not removed just set count == 0
};

class Bracket
{
public:
    Bracket(ObjectGuid guid, uint8 type);
    ~Bracket() = default;

    void InitStats(uint16 rating, uint16 mmr, uint32 games, uint32 wins, uint32 week_games, uint32 week_wins, uint16 best_week, uint16 best, uint16 bestWeekLast);

    uint16 getRating() const { return m_rating; }
    int16 getRatingLastChange() const { return m_ratingLastChange; }
    uint16 getMMV() const { return m_mmv; }
    int16 getLastMMRChange() const{ return m_mmr_lastChage; }

    void SaveStats(SQLTransaction* trans = nullptr);

    uint16 FinishGame(bool win, uint16 opponents_mmv, bool winnerNone = false);
    uint32 GetBracketInfo(BracketInfoType i) const { return values[i]; }
    uint16 GetSlotByType();

    void SetState(uint8 s) { m_state = s; }

    void ResetWeekly();

private:

    uint32 values[BRACKET_END];                 //used for store data from Player::PLAYER_FIELD_PVP_INFO

    uint16 m_rating;
    int16 m_ratingLastChange;
    uint16 m_mmv;
    int16 m_mmr_lastChage;
    uint8 m_Type;

    ObjectGuid m_owner;
    uint8 m_state;
};

#endif
