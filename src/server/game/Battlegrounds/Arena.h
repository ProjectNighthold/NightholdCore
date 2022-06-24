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

#ifndef ARENA_H
#define ARENA_H

#include "Battleground.h"
#include "Timer.h"
#include "LogsSystem.h"

class Arena : public Battleground
{
protected:
    Arena();
    
    void PostUpdateImpl(uint32 diff) override;
    void _ProcessJoin(uint32 diff) override;

    void AddPlayer(Player* player) override;
    void RemovePlayer(Player* /*player*/, ObjectGuid /*guid*/, uint32 /*team*/) override;

    void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;
    void UpdateArenaWorldState();

    void HandleKillPlayer(Player* player, Player* killer) override;
    void StartingEventCloseDoors() override;
    void StartingEventOpenDoors() override;
    void SendOpponentSpecialization(uint32 team);

private:
    void RemovePlayerAtLeave(ObjectGuid guid, bool transport, bool sendPacket) override;
    void EndBattleground(uint32 winner) override;
    void CheckWinConditions() override;
    void ApplyDampeningIfNeeded();
    IntervalTimer _dampeningTimer;
    IntervalTimer _winConditionCheckTimer;
    LogsSystem::MainData _logData;
};

#endif // ARENA_H
