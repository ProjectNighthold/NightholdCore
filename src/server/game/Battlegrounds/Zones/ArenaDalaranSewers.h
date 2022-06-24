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


#ifndef __BATTLEGROUNDDS_H
#define __BATTLEGROUNDDS_H

#include "Arena.h"

class ArenaDalaranSewers : public Arena
{
    uint32 _waterfallTimer;
    uint32 _waterfallKnockbackTimer;
    uint32 _pipeKnockBackTimer;
    uint32 _getOutFromTexturesTimer;
    uint8 _pipeKnockBackCount;
    uint8 _waterfallStatus;

    void PostUpdateImpl(uint32 diff) override;

public:
    ArenaDalaranSewers();
    ~ArenaDalaranSewers();

    void StartingEventCloseDoors() override;
    void StartingEventOpenDoors() override;

    void _CheckPositions(uint32 diff) override;
    bool SetupBattleground() override;
protected:
    uint32 getWaterFallStatus() { return _waterfallStatus; };
    void setWaterFallStatus(uint8 status) { _waterfallStatus = status; };
    uint32 getWaterFallTimer() { return _waterfallTimer; };
    void setWaterFallTimer(uint32 timer) { _waterfallTimer = timer; };
    uint32 getWaterFallKnockbackTimer() { return _waterfallKnockbackTimer; };
    void setWaterFallKnockbackTimer(uint32 timer) { _waterfallKnockbackTimer = timer; };
    uint8 getPipeKnockBackCount() { return _pipeKnockBackCount; };
    void setPipeKnockBackCount(uint8 count) { _pipeKnockBackCount = count; };
    uint32 getPipeKnockBackTimer() { return _pipeKnockBackTimer; };
    void setPipeKnockBackTimer(uint32 timer) { _pipeKnockBackTimer = timer; };
    uint32 getOutFromTexturesTimer() { return _getOutFromTexturesTimer; };
    void setgetOutFromTexturesTimer(uint32 timer) { _getOutFromTexturesTimer = timer; };
};

#endif
