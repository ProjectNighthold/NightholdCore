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

#ifndef __BrawlBattlegroundSouthshoreVsTarrenMill
#define __BrawlBattlegroundSouthshoreVsTarrenMill

#include "Battleground.h"

class BrawlBattlegroundSouthshoreVsTarrenMill : public Battleground
{
    std::unordered_map<ObjectGuid, uint8> m_playerPointsCounter;
    std::unordered_map<ObjectGuid, uint8> _playerRank;
public:
    BrawlBattlegroundSouthshoreVsTarrenMill();
    ~BrawlBattlegroundSouthshoreVsTarrenMill();

    void Reset() override;
    bool SetupBattleground() override;
    void PostUpdateImpl(uint32 diff) override;
    void AddPlayer(Player* player) override;
    void OnPlayerEnter(Player* player) override;
    WorldSafeLocsEntry const* GetClosestGraveYard(Player* player) override;
    void HandleKillPlayer(Player* player, Player* killer) override;
    bool UpdatePlayerScore(Player* player, uint32 type, uint32 value, bool doAddHonor = true) override;
    void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;
};

#endif
