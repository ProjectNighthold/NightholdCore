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

#include "EventMap.h"

EventMap::EventMap() : _time(0), _phase(0) { }

uint32 EventMap::GetTimer() const
{
    return _time;
}

void EventMap::Reset()
{
    clear();
    _time = 0;
    _phase = 0;
}

void EventMap::Update(uint32 time)
{
    _time += time;
}

uint32 EventMap::GetPhaseMask() const
{
    return _phase;
}

bool EventMap::IsInPhase(uint8 phase)
{
    return phase <= 8 && (!phase || _phase & (1 << (phase - 1)));
}

bool EventMap::Empty() const
{
    return empty();
}

void EventMap::SetPhase(uint32 phase)
{
    if (!phase)
        _phase = 0;
    else if (phase <= 8)
        _phase = (1 << (phase - 1));
}

void EventMap::AddPhase(uint8 phase)
{
    if (phase && phase <= 8)
        _phase |= (1 << (phase - 1));
}

void EventMap::RemovePhase(uint8 phase)
{
    if (phase && phase <= 8)
        _phase &= ~(1 << (phase - 1));
}

void EventMap::ScheduleEvent(uint32 eventId, Seconds time, uint32 group, uint32 phase)
{
    ScheduleEvent(eventId, time.count(), group, phase);
}

void EventMap::ScheduleEvent(uint32 eventId, Minutes time, uint32 group, uint32 phase)
{
    ScheduleEvent(eventId, time.count(), group, phase);
}

void EventMap::ScheduleEvent(uint32 eventId, uint32 time, uint32 group, uint32 phase)
{
    uint32 data = 0;
    if (group && group <= 8)
        data |= (1 << (group + 15));
    if (phase && phase <= 8)
        data |= (1 << (phase + 23));
    time += _time;
    const_iterator itr = find(time);
    while (itr != end())
    {
        ++time;
        itr = find(time);
    }

    insert(std::make_pair(time, MAKE_PAIR64(eventId, data)));
}

void EventMap::RescheduleEvent(uint32 eventId, uint32 time, uint32 groupId, uint32 phase)
{
    CancelEvent(eventId);
    ScheduleEvent(eventId, time, groupId, phase);
}

bool EventMap::HasEvent(uint32 eventId) const
{
    for (auto itr = cbegin(); itr != cend(); ++itr)
        if ((itr->second & 0x0000FFFF) == eventId)
            return true;

    return false;
}

uint32 EventMap::GetEventTime(uint32 eventId) const
{
    for (auto itr = cbegin(); itr != cend(); ++itr)
        if ((itr->second & 0x0000FFFF) == eventId)
            return itr->first;

    return 0;
}

void EventMap::RepeatEvent(uint32 time)
{
    if (empty())
        return;

    auto eventData = begin()->second;
    erase(begin());
    time += _time;
    const_iterator itr = find(time);
    while (itr != end())
    {
        ++time;
        itr = find(time);
    }
    insert(std::make_pair(time, eventData));
}

void EventMap::PopEvent()
{
    erase(begin());
}

uint32 EventMap::ExecuteEvent()
{
    while (!empty())
    {
        if (begin()->first > _time)
            return 0;

        auto data = PAIR64_HIPART(begin()->second);
        if (_phase && (data & 0xFF000000) && !((data >> 24) & _phase))
            erase(begin());
        else
        {
            auto eventId = PAIR64_LOPART(begin()->second);
            erase(begin());
            return eventId;
        }
    }
    return 0;
}

uint32 EventMap::GetEvent()
{
    while (!empty())
    {
        if (begin()->first > _time)
            return 0;

        auto data = PAIR64_HIPART(begin()->second);
        if (_phase && (data & 0xFF000000) && !((data >> 24) & _phase))
            erase(begin());
        else
            return PAIR64_LOPART(begin()->second);
    }
    return 0;
}

void EventMap::DelayEvent(uint32 eventID, uint32 delay)
{
    auto nextTime = _time + delay;
    for (auto itr = begin(); itr != end() && itr->first < nextTime;)
    {
        if (PAIR64_LOPART(itr->second) == eventID)
        {
            auto data = PAIR64_HIPART(begin()->second);
            ScheduleEvent(eventID, itr->first - _time + delay, data >> 24, data >> 16);
            erase(itr);
            itr = begin();
        }
        else
            ++itr;
    }
}

void EventMap::DelayEvents(uint32 delay)
{
    if (delay < _time)
        _time -= delay;
    else
        _time = 0;
}

void EventMap::DelayEvents(uint32 delay, uint32 groupId)
{
    auto nextTime = _time + delay;
    uint32 groupMask = (1 << (groupId + 16));
    for (auto itr = begin(); itr != end() && itr->first < nextTime;)
    {
        auto data = PAIR64_HIPART(itr->second);
        if (data & groupMask)
        {
            ScheduleEvent(PAIR64_LOPART(itr->second), itr->first - _time + delay, data >> 24, data >> 16);
            erase(itr);
            itr = begin();
        }
        else
            ++itr;
    }
}

void EventMap::RecalcEventTimer(uint32 event, int32 minTime, bool dopTime)
{
    if (HasEvent(event))
    {
        int32 timer = GetNextEventTime(event) - GetTimer();
        if (timer < minTime)
            RescheduleEvent(event, dopTime ? minTime + timer : minTime);
    }
}

void EventMap::CancelEvent(uint32 eventId)
{
    for (auto itr = begin(); itr != end();)
    {
        if (eventId == PAIR64_LOPART(itr->second))
        {
            erase(itr);
            itr = begin();
        }
        else
            ++itr;
    }
}

void EventMap::CancelEventGroup(uint32 groupId)
{
    uint32 groupMask = (1 << (groupId + 16));
    for (auto itr = begin(); itr != end();)
    {
        auto data = PAIR64_HIPART(itr->second);
        if (data & groupMask)
        {
            erase(itr);
            itr = begin();
        }
        else
            ++itr;
    }
}

uint32 EventMap::GetNextEventTime(uint32 eventId) const
{
    for (auto itr = cbegin(); itr != cend(); ++itr)
        if (eventId == PAIR64_LOPART(itr->second))
            return itr->first;
    return 0;
}

