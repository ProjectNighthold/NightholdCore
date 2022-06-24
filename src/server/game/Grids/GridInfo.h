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

#ifndef TRINITY_GRIDInfo_H
#define TRINITY_GRIDInfo_H

#include "Timer.h"

class GridInfo final
{
public:
    GridInfo();
    explicit GridInfo(time_t expiry, bool unload = true);

    const TimeTracker& getTimeTracker() const;
    bool getUnloadLock() const;
    void setUnloadReferenceLock(bool on);
    void incUnloadActiveLock();
    void decUnloadActiveLock();
    void setTimer(const TimeTracker& pTimer);
    void ResetTimeTracker(time_t interval);

    void UpdateTimeTracker(time_t diff);

private:
    TimeTracker i_timer;

    uint16 i_unloadActiveLockCount;                     // lock from active object spawn points (prevent clone loading)
    uint8 i_unloadReferenceLock;                        // lock from instance map copy
    uint8 i_unloadExplicitLock;                         // explicit config setting
};

#endif
