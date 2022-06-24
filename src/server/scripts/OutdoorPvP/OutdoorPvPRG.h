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

#ifndef OUTDOOR_PVP_RG_
#define OUTDOOR_PVP_RG_

#include "OutdoorPvP.h"

enum OutdoorPvPRGKillCredit
{
    RG_KILL_CREDIT          = 106650
};

enum OutdoorPvPRGArea
{
    BLACK_ROOK_RUMBLE_AREA  = 8151
};

class OutdoorPvPRG : public OutdoorPvP
{
    public:

        OutdoorPvPRG();

        bool SetupOutdoorPvP() override;

        bool Update(uint32 diff) override;

        void HandleKill(Player* player, Unit* killed) override;

    private:
        int32 m_summonTimer;
        bool m_canSummon;
};

#endif
