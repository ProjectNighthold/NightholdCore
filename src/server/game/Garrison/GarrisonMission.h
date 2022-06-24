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

#ifndef GarrisonMission_h__
#define GarrisonMission_h__

#include "GarrisonGlobal.h"
#include "Packets/GarrisonPackets.h"

struct Follower;

struct Mission
{
    WorldPackets::Garrison::GarrisonMission PacketInfo;
    std::list<uint64> CurrentFollowerDBIDs;
    ObjectDBState DbState = DB_STATE_NEW;

    void Start(Player* owner, std::vector<uint64> const &followers);
    void BonusRoll(Player* onwer);
    void Complete(Player* owner);
    bool HasBonusRoll();
    float ComputeSuccessChance();
    float CalcChance(float a, float b, float c);
    uint32 GetDuration(Player* owner);
    std::vector<Follower*> GetMissionFollowers(Garrison* garrison);
};

#endif // GarrisonMission_h__
