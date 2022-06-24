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

#ifndef TrinityEventMap_H
#define TrinityEventMap_H

#include "Common.h"

enum c_events
{
    EVENT_1 = 1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
    EVENT_5,
    EVENT_6,
    EVENT_7,
    EVENT_8,
    EVENT_9,
    EVENT_10,
    EVENT_11,
    EVENT_12,
    EVENT_13,
    EVENT_14,
    EVENT_15,
    EVENT_16,
    EVENT_17,
    EVENT_18,
    EVENT_19,
    EVENT_20,
    EVENT_21,
    EVENT_22,
    EVENT_23,
    EVENT_24,
    EVENT_25,
    EVENT_26,
    EVENT_27,
    EVENT_28,
    EVENT_29,
    EVENT_30,
    EVENT_31,
    EVENT_32,
    EVENT_33,
    EVENT_34,
    EVENT_35,
    EVENT_36,
    EVENT_37,
    EVENT_38,
    EVENT_39,
    EVENT_40,
    EVENT_41,
    EVENT_42,
    EVENT_43,
    EVENT_44,
    EVENT_45,
    EVENT_46,
    EVENT_47,
    EVENT_48,
    EVENT_49,
    EVENT_50
};

enum c_actions
{
    ACTION_NONE,

    ACTION_1,
    ACTION_2,
    ACTION_3,
    ACTION_4,
    ACTION_5,
    ACTION_6,
    ACTION_7,
    ACTION_8,
    ACTION_9,
    ACTION_10,
    ACTION_11,
    ACTION_12,
    ACTION_13,
    ACTION_14,
    ACTION_15
};

class EventMap : std::map<uint32, uint64>
{
public:
    EventMap();

    // Returns current timer value, does not represent real dates/times
    uint32 GetTimer() const;

    // Removes all events and clears phase
    void Reset();

    void Update(uint32 time);

    uint32 GetPhaseMask() const;
    bool IsInPhase(uint8 phase);
    bool Empty() const;
    // Sets event phase, must be in range 1 - 8
    void SetPhase(uint32 phase);
    void AddPhase(uint8 phase);
    void RemovePhase(uint8 phase);

    void ScheduleEvent(uint32 eventId, Seconds time, uint32 group = 0, uint32 phase = 0);
    void ScheduleEvent(uint32 eventId, Minutes time, uint32 group = 0, uint32 phase = 0);
    void ScheduleEvent(uint32 eventId, uint32 time, uint32 group = 0, uint32 phase = 0);
    void RescheduleEvent(uint32 eventId, uint32 time, uint32 groupId = 0, uint32 phase = 0);

    bool HasEvent(uint32 eventId) const;
    uint32 GetEventTime(uint32 eventId) const;

    void RepeatEvent(uint32 time);
    void PopEvent();
    uint32 ExecuteEvent();
    uint32 GetEvent();

    void DelayEvent(uint32 eventID, uint32 delay);
    void DelayEvents(uint32 delay);
    void DelayEvents(uint32 delay, uint32 groupId);

    void RecalcEventTimer(uint32 event, int32 minTime, bool dopTime = false);

    void CancelEvent(uint32 eventId);
    void CancelEventGroup(uint32 groupId);

    uint32 GetNextEventTime(uint32 eventId) const;

private:
    uint32 _time;
    uint32 _phase;
};

#endif // TrinityEventMap_H
