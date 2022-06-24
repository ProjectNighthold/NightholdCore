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

#ifndef _EventObjectDataStoreh_
#define _EventObjectDataStoreh_

#include "EventObject.h"

typedef std::unordered_map<ObjectGuid::LowType, EventObjectData> EventObjectDataContainer;

class EventObjectDataStoreMgr
{
    EventObjectDataStoreMgr();
    ~EventObjectDataStoreMgr();

public:
    static EventObjectDataStoreMgr* instance();

    void LoadEventObjectTemplates();
    void LoadEventObjects();

    EventObjectTemplate const* GetEventObjectTemplate(uint32 entry);
    EventObjectTemplate const* AddEventObjectTemplate(uint32 entry, float radius, uint32 spell, uint32 worldsafe);
    EventObjectData const* GetEventObjectData(ObjectGuid::LowType const& guid) const;
    EventObjectData& NewOrExistEventObjectData(ObjectGuid::LowType const& guid);
private:
    EventObjectTemplateContainer _eventObjectTemplateMap;
    EventObjectDataContainer _eventObjectData;
};

#define sEventObjectDataStore EventObjectDataStoreMgr::instance()

#endif
