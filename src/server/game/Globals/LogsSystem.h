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

#pragma once

namespace LogsSystem
{
    struct KillCreatureData
    {
        uint32 Entry = 0;
        uint32 Counter = 0;
        float Points = 0;
        bool NeedUpdate = false;
        bool NeedSave = false;
    };

    struct RosterData
    {
        uint32 GuidLow = 0;
        uint32 SpecID = 0;
        uint32 Role = 0;
        uint32 ItemLevel = 0;
        std::string Name;
        uint8 Level = 0;
        uint8 Class = 0;
        uint8 TeamId = 0;
    };

    struct GuildData
    {
        uint32 GuildID = 0;
        uint32 GuildFaction = 0;
        std::string GuildName;
    };

    struct EncounterData
    {
        uint32 Expansion = 0;
        uint32 EncounterID = 0;
        uint32 DifficultyID = 0;
        uint32 StartTime = 0;
        uint32 CombatDuration = 0;
        uint32 EndTime = 0;
        uint32 DeadCount = 0;
        bool Success = false;
        bool EncounterStarded = false;
    };

    struct ArenaData
    {
        uint32 WinnerTeamId = 0;
        uint32 Duration = 0;
        uint32 WinnerOldRating = 0;
        uint32 WinnerNewRating = 0;
        uint32 LooserOldRating = 0;
        uint32 LooserNewRating = 0;
        uint8 JoinType = 0;
    };

    struct MainData
    {
        std::string const& Serealize() const;

        std::vector<RosterData> Rosters;
        Optional<EncounterData> Encounter;
        Optional<ArenaData> Arena;
        Optional<GuildData> Guild;
        uint32 RealmID = 0;
        uint32 MapID = 0;
    };
}
