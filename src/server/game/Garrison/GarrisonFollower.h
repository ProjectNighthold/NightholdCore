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

#ifndef GarrisonFollower_h__
#define GarrisonFollower_h__

#include "GarrisonGlobal.h"
#include "Packets/GarrisonPackets.h"

struct Follower
{
    WorldPackets::Garrison::GarrisonFollower PacketInfo;

    uint32 GetItemLevel() const;
    void ModAssistant(SpellInfo const* spellInfo, Player* caster);
    void IncreaseFollowerExperience(SpellInfo const* spellInfo, Player* caster);
    uint8 RollQuality(uint32 baseQuality);
    void GiveLevel(uint32 level);
    void SetQuality(uint32 quality);
    uint32 GiveXP(uint32 xp);

    uint8 TypeID = GarrisonConst::FollowerType::Garrison;
    uint32 Faction = 0;
    std::unordered_map<uint32, uint32> ItemTraits;
    ObjectDBState DbState = DB_STATE_UNCHANGED;
    ObjectDBState db_state_ability = DB_STATE_UNCHANGED;
};

#endif // GarrisonFollower_h__
