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

#include "Battleground.h"
#include "Player.h"
#include "ArenaAll.h"

ArenaAll::ArenaAll() = default;

ArenaAll::~ArenaAll() = default;

void ArenaAll::StartingEventCloseDoors()
{ }

void ArenaAll::StartingEventOpenDoors()
{ }

void ArenaAll::AddPlayer(Player* player)
{
    Battleground::AddPlayer(player);
}

void ArenaAll::RemovePlayer(Player* /*player*/, ObjectGuid /*guid*/, uint32 /*team*/)
{ }

void ArenaAll::HandleKillPlayer(Player* player, Player* killer)
{
    Battleground::HandleKillPlayer(player, killer);
}

bool ArenaAll::SetupBattleground()
{
    return true;
}
