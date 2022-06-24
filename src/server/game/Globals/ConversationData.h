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

#ifndef _ConversationDataStoreh_
#define _ConversationDataStoreh_

#include "Conversation.h"

struct ConversationActor
{
    uint32 entry;
    uint32 id;
    uint32 actorId;
    uint32 creatureId;
    uint32 displayId;
    uint32 unk1;
    uint32 unk2;
    uint32 unk3;
    uint32 duration;
};

struct ConversationCreature
{
    uint32 entry;
    uint32 id;
    uint32 creatureId;
    uint32 creatureGuid;
    uint32 unk1;
    uint32 unk2;
    uint32 duration;
};

struct ConversationData
{
    uint32 entry;
    uint32 id;
    uint32 idx;
    uint32 textId;
    uint32 unk1;
    uint32 unk2;
};

typedef std::unordered_map<uint32/*entry*/, std::vector<ConversationData> > ConversationDataMap;
typedef std::unordered_map<uint32/*entry*/, std::vector<ConversationCreature> > ConversationCreatureMap;
typedef std::unordered_map<uint32/*entry*/, std::vector<ConversationActor> > ConversationActorMap;
typedef std::unordered_map<ObjectGuid::LowType, ConversationSpawnData> ConversationDataContainer;

class ConversationDataStoreMgr
{
    ConversationDataStoreMgr();
    ~ConversationDataStoreMgr();

public:
    static ConversationDataStoreMgr* instance();

    void LoadConversations();
    void LoadConversationData();

    ConversationSpawnData const* GetConversationData(ObjectGuid::LowType const& guid) const;
    ConversationSpawnData& NewOrExistConversationData(ObjectGuid::LowType const& guid);

    std::vector<ConversationData> const* GetConversationData(uint32 entry) const;
    std::vector<ConversationCreature> const* GetConversationCreature(uint32 entry) const;
    std::vector<ConversationActor> const* GetConversationActor(uint32 entry) const;
private:
    ConversationDataContainer _conversationDataStore;
    ConversationDataMap _conversationDataList;
    ConversationCreatureMap _conversationCreatureList;
    ConversationActorMap _conversationActorList;
};

#define sConversationDataStore ConversationDataStoreMgr::instance()

#endif
