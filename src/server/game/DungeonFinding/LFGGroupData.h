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

#ifndef _LFGGROUPDATA_H
#define _LFGGROUPDATA_H

#include "LFG.h"

namespace lfg
{

enum LfgGroupEnum
{
    LFG_GROUP_MAX_KICKS                           = 3,
};

/**
    Stores all lfg data needed about a group.
*/
class LfgGroupData
{
    public:
        LfgGroupData();
        ~LfgGroupData();

        bool IsLfgGroup();

        // General
        void SetState(LfgState state);
        void RestoreState();
        void AddPlayer(ObjectGuid guid);
        uint8 RemovePlayer(ObjectGuid guid);
        void RemoveAllPlayers();
        void SetLeader(ObjectGuid guid);

        // Dungeon
        void SetDungeon(uint32 dungeon);
        void SetQueueId(uint32 queueId);

        // VoteKick
        void DecreaseKicksLeft();

        // General
        LfgState GetState() const;
        LfgState GetOldState() const;
        GuidSet const& GetPlayers() const;
        uint8 GetPlayerCount() const;
        ObjectGuid GetLeader() const;

        // Dungeon
        uint32 GetDungeon(bool asId = true) const;
        uint32 GetQueueId() const;

        // VoteKick
        uint8 GetKicksLeft() const;

    private:
        // General
        LfgState m_State;                                  ///< State if group in LFG
        LfgState m_OldState;                               ///< Old State
        ObjectGuid m_Leader;                               ///< Leader GUID
        GuidSet m_Players;                                 ///< Players in group
        // Dungeon
        uint32 m_Dungeon;                                  ///< Dungeon entry
        uint32 m_QueueId;                                  ///< Queue Id
        // Vote Kick
        uint8 m_KicksLeft;                                 ///< Number of kicks left
};

} // namespace lfg

#endif
