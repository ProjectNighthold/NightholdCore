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

#ifndef _GROUPMGR_H
#define _GROUPMGR_H

#include "Group.h"

class GroupMgr
{
private:
    GroupMgr();
    ~GroupMgr();

public:
    static GroupMgr* instance()
    {
        static GroupMgr instance;
        return &instance;
    }

    typedef std::map<ObjectGuid::LowType, Group*> GroupContainer;
    typedef std::vector<Group*>      GroupDbContainer;

    void Update(uint32 diff);

    Group* GetGroupByGUID(ObjectGuid const& guid) const;

    uint32 GenerateNewGroupDbStoreId();
    void   RegisterGroupDbStoreId(uint32 storageId, Group* group);
    void   FreeGroupDbStoreId(Group* group);
    void   SetNextGroupDbStoreId(uint32 storageId) { NextGroupDbStoreId = storageId; };
    Group* GetGroupByDbStoreId(uint32 storageId) const;
    void   SetGroupDbStoreSize(uint32 newSize) { GroupDbStore.resize(newSize); }

    void   LoadGroups();
    ObjectGuid::LowType GenerateGroupId();
    void   AddGroup(Group* group);
    void   RemoveGroup(Group* group);

    void AddDelayedEvent(uint64 timeOffset, std::function<void()>&& function)
    {
        m_Functions.AddDelayedEvent(timeOffset, std::move(function));
    }

protected:
    ObjectGuid::LowType           NextGroupId;
    uint32           NextGroupDbStoreId;
    GroupContainer   GroupStore;
    GroupDbContainer GroupDbStore;
    FunctionProcessor m_Functions;
};

#define sGroupMgr GroupMgr::instance()

#endif
