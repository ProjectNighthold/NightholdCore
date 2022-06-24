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

#include "Common.h"
#include "Map.h"

class Battleground;
enum Difficulty : uint8;

class BattlegroundMap : public Map
{
    Battleground* m_bg;
public:
    BattlegroundMap(uint32 id, time_t, uint32 instanceId, Map* parent, Difficulty difficulty);
    ~BattlegroundMap() override;

    bool AddPlayerToMap(Player*, bool initPlayer = true) override;
    void RemovePlayerFromMap(Player*, bool) override;
    bool CanEnter(Player* player) override;
    void SetUnload();
    void RemoveAllPlayers() override;
    void InitVisibilityDistance() override;
    Battleground* GetBG();
    void SetBG(Battleground* bg);
};
