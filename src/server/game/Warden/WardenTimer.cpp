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

#include "Warden.h"
#include "WardenTimer.h"

WardenTimer::WardenTimer(uint32 time, uint32 reqLevel, bool reqPlayerInWorld) : _initTime(time), _enabled(false), _reqPlayer(reqPlayerInWorld), _reqLevel(reqLevel) 
{
    _currentTime = _initTime;
}

bool WardenTimer::CheckConditions(Player* player)
{
    if (!_reqPlayer)
        return true;

    if (!player || !player->IsInWorld() || player->isBeingLoaded() || player->IsBeingTeleported())
        return false;

    if (_reqLevel && player->getLevel() < _reqLevel)
        return false;

    return true;
}