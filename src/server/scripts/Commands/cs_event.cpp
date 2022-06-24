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

/* ScriptData
Name: event_commandscript
%Complete: 100
Comment: All event related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "GameEventMgr.h"
#include "Chat.h"

class event_commandscript : public CommandScript
{
public:
    event_commandscript() : CommandScript("event_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> eventCommandTable =
        {
            { "activelist",     SEC_GAMEMASTER,     true,  &HandleEventActiveListCommand,     ""},
            { "start",          SEC_GAMEMASTER,     true,  &HandleEventStartCommand,          ""},
            { "stop",           SEC_GAMEMASTER,     true,  &HandleEventStopCommand,           ""},
            { "",               SEC_GAMEMASTER,     true,  &HandleEventInfoCommand,           ""}
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "event",          SEC_GAMEMASTER,     false, NULL,                  "", eventCommandTable },
            { "events",         SEC_GAMEMASTER,     false, &HandleEventsListCommand,           ""}
        };
        return commandTable;
    }

    static bool HandleEventActiveListCommand(ChatHandler* handler, char const* /*args*/)
    {
        uint32 counter = 0;

        GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();
        GameEventMgr::ActiveEvents const& activeEvents = sGameEventMgr->GetActiveEventList();

        char const* active = handler->GetTrinityString(LANG_ACTIVE);

        for (GameEventMgr::ActiveEvents::const_iterator itr = activeEvents.begin(); itr != activeEvents.end(); ++itr)
        {
            uint32 eventId = *itr;
            GameEventData const& eventData = events[eventId];

            if (handler->GetSession())
                handler->PSendSysMessage(LANG_EVENT_ENTRY_LIST_CHAT, eventId, eventId, eventData.description.c_str(), active);
            else
                handler->PSendSysMessage(LANG_EVENT_ENTRY_LIST_CONSOLE, eventId, eventData.description.c_str(), active);

            ++counter;
        }

        if (counter == 0)
            handler->SendSysMessage(LANG_NOEVENTFOUND);
        handler->SetSentErrorMessage(true);

        return true;
    }

    static bool HandleEventInfoCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // id or [name] Shift-click form |color|Hgameevent:id|h[name]|h|r
        char* id =  handler->extractKeyFromLink((char*)args, "Hgameevent");
        if (!id)
            return false;

        uint32 eventId = atoi(id);

        GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();

        if (eventId >= events.size())
        {
            handler->SendSysMessage(LANG_EVENT_NOT_EXIST);
            handler->SetSentErrorMessage(true);
            return false;
        }

        GameEventData const& eventData = events[eventId];
        if (!eventData.isValid())
        {
            handler->SendSysMessage(LANG_EVENT_NOT_EXIST);
            handler->SetSentErrorMessage(true);
            return false;
        }

        GameEventMgr::ActiveEvents const& activeEvents = sGameEventMgr->GetActiveEventList();
        bool active = activeEvents.find(eventId) != activeEvents.end();
        char const* activeStr = active ? handler->GetTrinityString(LANG_ACTIVE) : "";

        std::string startTimeStr = TimeToTimestampStr(eventData.start);
        std::string endTimeStr = TimeToTimestampStr(eventData.end);

        uint32 delay = sGameEventMgr->NextCheck(eventId);
        time_t nextTime = time(NULL) + delay;
        std::string nextStr = nextTime >= eventData.start && nextTime < eventData.end ? TimeToTimestampStr(time(NULL) + delay) : "-";

        std::string occurenceStr = secsToTimeString(eventData.occurence * MINUTE);
        std::string lengthStr = secsToTimeString(eventData.length * MINUTE);

        handler->PSendSysMessage(LANG_EVENT_INFO, eventId, eventData.description.c_str(), activeStr,
            startTimeStr.c_str(), endTimeStr.c_str(), occurenceStr.c_str(), lengthStr.c_str(),
            nextStr.c_str());
        return true;
    }

    static bool HandleEventStartCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // id or [name] Shift-click form |color|Hgameevent:id|h[name]|h|r
        char* id =  handler->extractKeyFromLink((char*)args, "Hgameevent");
        if (!id)
            return false;

        int32 eventId = atoi(id);

        GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();

        if (eventId < 1 || uint32(eventId) >= events.size())
        {
            handler->SendSysMessage(LANG_EVENT_NOT_EXIST);
            handler->SetSentErrorMessage(true);
            return false;
        }

        GameEventData const& eventData = events[eventId];
        if (!eventData.isValid())
        {
            handler->SendSysMessage(LANG_EVENT_NOT_EXIST);
            handler->SetSentErrorMessage(true);
            return false;
        }

        GameEventMgr::ActiveEvents const& activeEvents = sGameEventMgr->GetActiveEventList();
        if (activeEvents.find(eventId) != activeEvents.end())
        {
            handler->PSendSysMessage(LANG_EVENT_ALREADY_ACTIVE, eventId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        sGameEventMgr->StartEvent(eventId, true);
        return true;
    }

    static bool HandleEventStopCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // id or [name] Shift-click form |color|Hgameevent:id|h[name]|h|r
        char* id =  handler->extractKeyFromLink((char*)args, "Hgameevent");
        if (!id)
            return false;

        int32 eventId = atoi(id);

        GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();

        if (eventId < 1 || uint32(eventId) >= events.size())
        {
            handler->SendSysMessage(LANG_EVENT_NOT_EXIST);
            handler->SetSentErrorMessage(true);
            return false;
        }

        GameEventData const& eventData = events[eventId];
        if (!eventData.isValid())
        {
            handler->SendSysMessage(LANG_EVENT_NOT_EXIST);
            handler->SetSentErrorMessage(true);
            return false;
        }

        GameEventMgr::ActiveEvents const& activeEvents = sGameEventMgr->GetActiveEventList();

        if (activeEvents.find(eventId) == activeEvents.end())
        {
            handler->PSendSysMessage(LANG_EVENT_NOT_ACTIVE, eventId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        sGameEventMgr->StopEvent(eventId, true);
        return true;
    }

    static bool HandleEventsListCommand(ChatHandler* handler, char const* /*args*/)
    {
        GameEventMgr::GameEventDataMap const& events = sGameEventMgr->GetEventMap();
        GameEventMgr::ActiveEvents const& activeEvents = sGameEventMgr->GetActiveEventList();

        char const* active = handler->GetTrinityString(LANG_ACTIVE);
        static uint32 eventsArray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 26, 29, 32 };
        static const size_t eventsArraySize = sizeof(eventsArray) / sizeof(uint32);

        for (size_t i = 0; i < eventsArraySize; ++i)
        {
            uint32 id = eventsArray[i];
            GameEventData const& eventData = events[id];

            std::string descr = eventData.description;
            if (descr.empty())
                continue;

            char const* active = activeEvents.find(id) != activeEvents.end() ? handler->GetTrinityString(LANG_ACTIVE) : "";

            uint32 delay = sGameEventMgr->NextCheck(id);
            time_t nextTime = time(NULL) + delay;
            std::string nextStr = nextTime >= eventData.start && nextTime < eventData.end ? TimeToTimestampStr(time(NULL) + delay) : "-";

            if (handler->GetSession() && nextStr.length() > 1)
                handler->PSendSysMessage(LANG_EVENTS_INFO, id, id, eventData.description.c_str(), active, nextStr.c_str());
        }

        return true;
    }
};

void AddSC_event_commandscript()
{
    new event_commandscript();
}
