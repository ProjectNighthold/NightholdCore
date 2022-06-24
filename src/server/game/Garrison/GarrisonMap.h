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

#ifndef GarrisonMap_h__
#define GarrisonMap_h__

#include "Map.h"

class Garrison;
class Player;

class GarrisonMap : public InstanceMap
{
public:
    GarrisonMap(uint32 id, time_t, uint32 instanceId, Map* parent, ObjectGuid const& owner);

    Garrison* GetGarrison();

    void InitVisibilityDistance() override;

    bool AddPlayerToMap(Player* player, bool initPlayer = true) override;

private:
    bool onEnsureGridLoaded(NGrid* grid, Cell const& cell) override;
    Garrison* _garrison;
    ObjectGuid _owner;
};

#endif // GarrisonMap_h__
