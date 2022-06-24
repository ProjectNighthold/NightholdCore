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

#ifndef ReputationPackets_h__
#define ReputationPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Reputation
    {
        static uint16 const FactionCount = 0x12C;

        class InitializeFactions final : public ServerPacket
        {
        public:
            InitializeFactions() : ServerPacket(SMSG_INITIALIZE_FACTIONS, FactionCount * 6)
            {
                for (uint16 i = 0; i < FactionCount; ++i)
                {
                    FactionStandings[i] = 0;
                    FactionHasBonus[i] = false;
                    FactionFlags[i] = 0;
                }
            }

            WorldPacket const* Write() override;

            int32 FactionStandings[FactionCount];
            bool FactionHasBonus[FactionCount];
            uint8 FactionFlags[FactionCount];
        };

        class RequestForcedReactions final : public ClientPacket
        {
        public:
            RequestForcedReactions(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_FORCED_REACTIONS, std::move(packet)) { }

            void Read() override { }
        };

        struct ForcedReaction
        {
            int32 Faction = 0;
            int32 Reaction = 0;
        };

        class SetForcedReactions final : public ServerPacket
        {
        public:
            SetForcedReactions() : ServerPacket(SMSG_SET_FORCED_REACTIONS, 4) { }

            WorldPacket const* Write() override;

            std::vector<ForcedReaction> Reactions;
        };

        class FactionBonusInfo final : public ServerPacket
        {
        public:
            FactionBonusInfo() : ServerPacket(SMSG_FACTION_BONUS_INFO, FactionCount) { }

            WorldPacket const* Write() override;

            bool FactionHasBonus[FactionCount] = { };
        };
        
        struct FactionStandingData
        {
            int32 Index = 0;
            int32 Standing = 0;
        };

        class SetFactionStanding final : public ServerPacket
        {
        public:
            SetFactionStanding() : ServerPacket(SMSG_SET_FACTION_STANDING, 13) { }

            WorldPacket const* Write() override;

            std::vector<FactionStandingData> Faction;
            float BonusFromAchievementSystem = 0.0f;
            float ReferAFriendBonus = 0.0f;
            bool ShowVisual = false;
        };
    }
}

#endif // ReputationPackets_h__
