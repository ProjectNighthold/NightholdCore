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

#ifndef _WARDEN_TIMERS_H
#define _WARDEN_TIMERS_H

class WardenTimer
{
    public:
        WardenTimer(uint32 time, uint32 reqLevel, bool reqPlayerInWorld);
        ~WardenTimer() {}

        void SetCurrentTime(uint32 time) { _currentTime = time; }
        uint32 GetCurrentTime() { return _currentTime; }
        uint32 GetInitTime() { return _initTime; }
        void Reset() { _currentTime = _initTime; }
        void Start() { _enabled = true; }
        void Stop() { _enabled = false; }
        bool Active() { return _enabled; }
        bool Expired(uint32 diff) { return _currentTime <= diff; }
        void Continue(uint32 diff) { _currentTime -= diff; }
        bool CheckConditions(Player* player);

    private:
        uint32 _initTime;
        uint32 _currentTime;
        bool _enabled;
        bool _reqPlayer;
        uint32 _reqLevel;
};

#endif
