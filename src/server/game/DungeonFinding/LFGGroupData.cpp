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

#include "LFG.h"
#include "LFGGroupData.h"

namespace lfg
{

LfgGroupData::LfgGroupData(): m_State(LFG_STATE_NONE), m_OldState(LFG_STATE_NONE), m_Dungeon(0), m_QueueId(0), m_KicksLeft(LFG_GROUP_MAX_KICKS)
{ }

LfgGroupData::~LfgGroupData() = default;

bool LfgGroupData::IsLfgGroup()
{
    return m_OldState != LFG_STATE_NONE;
}

void LfgGroupData::SetState(LfgState state)
{
    switch (state)
    {
        case LFG_STATE_NONE:
            m_Dungeon = 0;
            m_KicksLeft = LFG_GROUP_MAX_KICKS;
        case LFG_STATE_FINISHED_DUNGEON:
        case LFG_STATE_DUNGEON:
            m_OldState = state;
            // No break on purpose
        default:
            m_State = state;
    }
}

void LfgGroupData::RestoreState()
{
    m_State = m_OldState;
}

void LfgGroupData::AddPlayer(ObjectGuid guid)
{
    m_Players.insert(guid);
}

uint8 LfgGroupData::RemovePlayer(ObjectGuid guid)
{
    auto it = m_Players.find(guid);
    if (it != m_Players.end())
        m_Players.erase(it);
    return uint8(m_Players.size());
}

void LfgGroupData::RemoveAllPlayers()
{
    m_Players.clear();
}

void LfgGroupData::SetLeader(ObjectGuid guid)
{
    m_Leader = guid;
}

void LfgGroupData::SetDungeon(uint32 dungeon)
{
    m_Dungeon = dungeon;
}

void LfgGroupData::SetQueueId(uint32 queueId)
{
    m_QueueId = queueId;
}

void LfgGroupData::DecreaseKicksLeft()
{
    if (m_KicksLeft)
      --m_KicksLeft;
}

LfgState LfgGroupData::GetState() const
{
    return m_State;
}

LfgState LfgGroupData::GetOldState() const
{
    return m_OldState;
}

GuidSet const& LfgGroupData::GetPlayers() const
{
    return m_Players;
}

uint8 LfgGroupData::GetPlayerCount() const
{
    return m_Players.size();
}

ObjectGuid LfgGroupData::GetLeader() const
{
    return m_Leader;
}

uint32 LfgGroupData::GetDungeon(bool asId /* = true */) const
{
    if (asId)
        return m_Dungeon & 0xFFFFF;

    return m_Dungeon;
}

uint32 LfgGroupData::GetQueueId() const
{
    return m_QueueId;
}

uint8 LfgGroupData::GetKicksLeft() const
{
    return m_KicksLeft;
}

} // namespace lfg
