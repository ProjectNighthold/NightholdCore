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

#ifndef _LFGPLAYERDATA_H
#define _LFGPLAYERDATA_H

#include "LFG.h"
#include "Packets/LFGPacketsCommon.h"

namespace lfg
{
class LfgPlayerData
{
public:
    LfgPlayerData();
    ~LfgPlayerData();

    void SetTicket(WorldPackets::LFG::RideTicket const& ticket);
    WorldPackets::LFG::RideTicket const& GetTicket() const;
    void SetState(LfgState state);
    void RestoreState();
    void SetTeam(uint8 team);
    void SetGroup(ObjectGuid group);
    void SetLfgGroup(ObjectGuid group);
    void ClearState();
    void SetRoles(uint8 roles);
    void SetSelectedDungeons(const LfgDungeonSet& dungeons);
    LfgState GetState() const;
    LfgState GetOldState() const;
    uint8 GetTeam() const;
    ObjectGuid GetGroup() const;
    ObjectGuid GetLfgGroup() const;
    uint8 GetRoles() const;
    LfgDungeonSet const& GetSelectedDungeons() const;

private:
    WorldPackets::LFG::RideTicket m_Ticket;            ///< Join ticket
    LfgDungeonSet m_SelectedDungeons;                  ///< Selected Dungeons when joined LFG
    ObjectGuid m_Group;                                ///< Original group of player when joined LFG
    ObjectGuid m_LfgGroup;
    LfgState m_State;                                  ///< State if group in LFG
    LfgState m_OldState;                               ///< Old State - Used to restore state after failed Rolecheck/Proposal
    uint8 m_Team;                                      ///< Player team - determines the queue to join
    uint8 m_Roles;                                     ///< Roles the player selected when joined LFG
    std::recursive_mutex m_lock;
};

} // namespace lfg

#endif
