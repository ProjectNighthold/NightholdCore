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

#include "LFGPlayerData.h"

namespace lfg
{

LfgPlayerData::LfgPlayerData() : m_State(LFG_STATE_NONE), m_OldState(LFG_STATE_NONE), m_Team(0), m_Roles(0)
{ }

LfgPlayerData::~LfgPlayerData() { }

void LfgPlayerData::SetTicket(WorldPackets::LFG::RideTicket const& ticket)
{
    m_Ticket = ticket;
}

WorldPackets::LFG::RideTicket const& LfgPlayerData::GetTicket() const
{
    return m_Ticket;
}

void LfgPlayerData::SetState(LfgState state)
{
    switch (state)
    {
        case LFG_STATE_NONE:
        case LFG_STATE_FINISHED_DUNGEON:
        {
            std::lock_guard<std::recursive_mutex> _lock(m_lock);
            m_Roles = 0;
            m_SelectedDungeons.clear();
            // No break on purpose
        }
        case LFG_STATE_DUNGEON:
            m_OldState = state;
            // No break on purpose
        default:
            m_State = state;
    }
}

void LfgPlayerData::ClearState()
{
    std::lock_guard<std::recursive_mutex> _lock(m_lock);
    m_SelectedDungeons.clear();
    m_Roles = 0;
    m_State = m_OldState;
}

void LfgPlayerData::RestoreState()
{
    if (m_OldState == LFG_STATE_NONE)
    {
        std::lock_guard<std::recursive_mutex> _lock(m_lock);
        m_SelectedDungeons.clear();
        m_Roles = 0;
    }
    m_State = m_OldState;
}

void LfgPlayerData::SetTeam(uint8 team)
{
    m_Team = team;
}

void LfgPlayerData::SetGroup(ObjectGuid group)
{
    m_Group = group;
}

void LfgPlayerData::SetLfgGroup(ObjectGuid group)
{
    m_LfgGroup = group;
}

void LfgPlayerData::SetRoles(uint8 roles)
{
    m_Roles = roles;
}

void LfgPlayerData::SetSelectedDungeons(LfgDungeonSet const& dungeons)
{
    std::lock_guard<std::recursive_mutex> _lock(m_lock);
    m_SelectedDungeons = dungeons;
}

LfgState LfgPlayerData::GetState() const
{
    return m_State;
}

LfgState LfgPlayerData::GetOldState() const
{
    return m_OldState;
}

uint8 LfgPlayerData::GetTeam() const
{
    return m_Team;
}

ObjectGuid LfgPlayerData::GetGroup() const
{
    return m_Group;
}

ObjectGuid LfgPlayerData::GetLfgGroup() const
{
    return m_LfgGroup;
}

uint8 LfgPlayerData::GetRoles() const
{
    return m_Roles;
}

LfgDungeonSet const& LfgPlayerData::GetSelectedDungeons() const
{
    return m_SelectedDungeons;
}

} // namespace lfg
