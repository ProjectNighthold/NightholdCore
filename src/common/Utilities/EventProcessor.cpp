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

#include "EventProcessor.h"

BasicEvent::BasicEvent()
{
    to_Abort = false;
    m_addTime = 0;
    m_execTime = 0;
}

EventProcessor::EventProcessor()
{
    m_time = 0;
}

EventProcessor::~EventProcessor()
{
    KillAllEvents(true);
}

void EventProcessor::Update(uint32 p_time)
{
    //move from queue
    AddEventsFromQueue();

    // update time
    m_time += p_time;

    // main event loop
    EventList::iterator i;
    while (((i = m_events.begin()) != m_events.end()) && i->first <= m_time)
    {
        // get and remove event from queue
        BasicEvent* Event = i->second;
        m_events.erase(i);

        if (!Event->to_Abort)
        {
            if (Event->Execute(m_time, p_time))
            {
                // completely destroy event if it is not re-added
                delete Event;
            }
        }
        else
        {
            Event->Abort(m_time);
            delete Event;
        }
    }
}

void EventProcessor::KillAllEvents(bool force)
{
    AddEventsFromQueue();
    // first, abort all existing events
    for (EventList::iterator i = m_events.begin(); i != m_events.end();)
    {
        EventList::iterator i_old = i;
        ++i;

        if (i_old->second)
        {
            i_old->second->to_Abort = true;
            i_old->second->Abort(m_time);
        }

        if (force || !i_old->second || i_old->second->IsDeletable())
        {
            delete i_old->second;

            if (!force)                                      // need per-element cleanup
                m_events.erase (i_old);
        }
    }

    // fast clear event list (in force case)
    if (force)
        m_events.clear();
}

void EventProcessor::AddEvent(BasicEvent* Event, uint64 e_time, bool set_addtime)
{
    std::lock_guard<std::recursive_mutex> _queue_lock(m_queue_lock);
    if (set_addtime) Event->m_addTime = m_time;
    Event->m_execTime = e_time;
    m_events_queue.insert(std::pair<uint64, BasicEvent*>(e_time, Event));
}

void EventProcessor::AddEventsFromQueue()
{
    EventList tempEvents;
    {
        std::lock_guard<std::recursive_mutex> _queue_lock(m_queue_lock);
        std::swap(tempEvents, m_events_queue);
    }
    EventList::iterator itr = tempEvents.begin();
    for(; itr != tempEvents.end(); ++itr)
    {
        m_events.insert(std::pair<uint64, BasicEvent*>(itr->first, itr->second));
        itr->second = NULL;
    }
}

uint64 EventProcessor::CalculateTime(uint64 t_offset) const
{
    return(m_time + t_offset);
}

