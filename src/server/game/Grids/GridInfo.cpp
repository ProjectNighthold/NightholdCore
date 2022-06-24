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

#include "GridInfo.h"

inline GridInfo::GridInfo() : i_timer(0), i_unloadActiveLockCount(0), i_unloadReferenceLock(0), i_unloadExplicitLock(0)
{
}

GridInfo::GridInfo(time_t expiry, bool unload) : i_timer(expiry), i_unloadActiveLockCount(0), i_unloadReferenceLock(0), i_unloadExplicitLock(unload ? 0 : 1)
{
}

const TimeTracker& GridInfo::getTimeTracker() const
{
    return i_timer;
}

bool GridInfo::getUnloadLock() const
{
    return i_unloadActiveLockCount || i_unloadReferenceLock || i_unloadExplicitLock;
}

void GridInfo::setUnloadReferenceLock(bool on)
{
    if (!this) // https://pastebin.com/7aVfGk6a
        return;

    i_unloadReferenceLock = on ? 1 : 0;
}

void GridInfo::incUnloadActiveLock()
{
    ++i_unloadActiveLockCount;
}

void GridInfo::decUnloadActiveLock()
{
    if (i_unloadActiveLockCount)
        --i_unloadActiveLockCount;
}

void GridInfo::setTimer(const TimeTracker& pTimer)
{
    i_timer = pTimer;
}

void GridInfo::ResetTimeTracker(time_t interval)
{
    i_timer.Reset(interval);
}

void GridInfo::UpdateTimeTracker(time_t diff)
{
    i_timer.Update(diff);
}
