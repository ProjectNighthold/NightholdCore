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

#include <EasyJSon.hpp>
#include "LogsSystem.h"

using namespace LogsSystem;

std::string const& MainData::Serealize() const
{
    EasyJSon::Node<std::string> data;

    data["RealmID"] = RealmID;
    data["MapID"] = MapID;

    if (Guild.is_initialized())
    {
        data["Guild"]["GuildID"] = Guild->GuildID;
        data["Guild"]["GuildName"] = Guild->GuildName;
        data["Guild"]["GuildFaction"] = Guild->GuildFaction;
    }

    if (Encounter.is_initialized())
    {
        data["Encounter"]["Expansion"] = Encounter->Expansion;
        data["Encounter"]["EncounterID"] = Encounter->EncounterID;
        data["Encounter"]["DifficultyID"] = Encounter->DifficultyID;
        data["Encounter"]["StartTime"] = Encounter->StartTime;
        data["Encounter"]["CombatDuration"] = Encounter->CombatDuration;
        data["Encounter"]["EndTime"] = Encounter->EndTime;
        data["Encounter"]["Success"] = Encounter->Success;
        data["Encounter"]["DeadCount"] = Encounter->DeadCount;
    }

    if (Arena.is_initialized())
    {
        data["Arena"]["WinnerTeamId"] = Arena->WinnerTeamId;
        data["Arena"]["Duration"] = Arena->Duration;
        data["Arena"]["WinnerOldRating"] = Arena->WinnerOldRating;
        data["Arena"]["WinnerNewRating"] = Arena->WinnerNewRating;
        data["Arena"]["LooserOldRating"] = Arena->LooserOldRating;
        data["Arena"]["LooserNewRating"] = Arena->LooserNewRating;
        data["Arena"]["JoinType"] = Arena->JoinType;
    }

    for (auto i = 0; i < Rosters.size(); ++i)
    {
        auto const& rooster = Rosters[i];

        data["Rooster"][i]["Name"] = rooster.Name;
        data["Rooster"][i]["GuidLow"] = rooster.GuidLow;
        data["Rooster"][i]["Level"] = rooster.Level;
        data["Rooster"][i]["Class"] = rooster.Class;
        data["Rooster"][i]["SpecID"] = rooster.SpecID;
        data["Rooster"][i]["Role"] = rooster.Role;
        data["Rooster"][i]["ItemLevel"] = rooster.ItemLevel;
        data["Rooster"][i]["TeamId"] = rooster.TeamId;
    }

    return data.Serialize<std::ostringstream>(true);
}
