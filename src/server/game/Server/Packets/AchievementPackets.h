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

#ifndef game_AchievementPackets_h__
#define game_AchievementPackets_h__

#include "ObjectGuid.h"
#include "Packet.h"

namespace WorldPackets
{
    namespace Achievement
    {
        struct EarnedAchievement
        {
            uint32 Id = 0;
            time_t Date = time_t(0);
            ObjectGuid Owner;
            uint32 VirtualRealmAddress = 0;
            uint32 NativeRealmAddress = 0;
        };

        struct CriteriaTreeProgress
        {
            uint32 Id = 0;
            uint64 Quantity = 0;
            ObjectGuid Player;
            uint32 Flags = 0;
            time_t Date = time_t(0);
            uint32 TimeFromStart = 0;
            uint32 TimeFromCreate = 0;
        };

        class AllAchievements final : public ServerPacket
        {
        public:
            AllAchievements() : ServerPacket(SMSG_ALL_ACHIEVEMENT_DATA) { }

            WorldPacket const* Write() override;

            std::vector<EarnedAchievement> Earned;
            std::vector<CriteriaTreeProgress> Progress;
        };

        class CriteriaUpdate final : public ServerPacket
        {
        public:
            CriteriaUpdate() : ServerPacket(SMSG_CRITERIA_UPDATE, 4 + 8 + 16 + 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint32 CriteriaID = 0;
            uint64 Quantity = 0;
            ObjectGuid PlayerGUID;
            uint32 Flags = 0;
            time_t CurrentTime = time_t(0);
            uint32 ElapsedTime = 0;
            uint32 CreationTime = 0;
        };

        class CriteriaDeleted final : public ServerPacket
        {
        public:
            CriteriaDeleted(uint32 ID) : ServerPacket(SMSG_CRITERIA_DELETED, 4), CriteriaID(ID) { }

            WorldPacket const* Write() override;

            uint32 CriteriaID = 0;
        };

        class AchievementDeleted final : public ServerPacket
        {
        public:
            AchievementDeleted() : ServerPacket(SMSG_ACHIEVEMENT_DELETED, 4) { }

            WorldPacket const* Write() override;

            uint32 AchievementID = 0;
            uint32 Immunities = 0; // this is just garbage, not used by client
        };

        class AchievementEarned final : public ServerPacket
        {
        public:
            AchievementEarned() : ServerPacket(SMSG_ACHIEVEMENT_EARNED, 16 + 4 + 4 + 4 + 4 + 1 + 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Earner;
            uint32 EarnerNativeRealm = 0;
            uint32 EarnerVirtualRealm = 0;
            uint32 AchievementID = 0;
            time_t Time = time_t(0);
            bool Initial = false;
            ObjectGuid Sender;
        };

        class ServerFirstAchievement final : public ServerPacket
        {
        public:
            ServerFirstAchievement() : ServerPacket(SMSG_SERVER_FIRST_ACHIEVEMENT) { }

            WorldPacket const* Write() override;

            ObjectGuid PlayerGUID;
            std::string Name;
            uint32 AchievementID = 0;
            bool GuildAchievement = false;
        };

        struct GuildCriteriaProgress
        {
            int32 CriteriaID = 0;
            uint32 DateCreated = 0;
            uint32 DateStarted = 0;
            time_t DateUpdated = 0;
            uint64 Quantity = 0;
            ObjectGuid PlayerGUID;
            int32 Flags = 0;
        };

        class GuildCriteriaUpdate final : public ServerPacket
        {
        public:
            GuildCriteriaUpdate() : ServerPacket(SMSG_GUILD_CRITERIA_UPDATE) { }

            WorldPacket const* Write() override;

            std::vector<GuildCriteriaProgress> Progress;
        };

        class GuildCriteriaDeleted final : public ServerPacket
        {
        public:
            GuildCriteriaDeleted() : ServerPacket(SMSG_GUILD_CRITERIA_DELETED, 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid GuildGUID;
            int32 CriteriaID = 0;
        };

        class GuildSetFocusedAchievement final : public ClientPacket
        {
        public:
            GuildSetFocusedAchievement(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_SET_FOCUSED_ACHIEVEMENT, std::move(packet)) { }

            void Read() override;

            uint32 AchievementID = 0;
        };

        class GuildAchievementDeleted final : public ServerPacket
        {
        public:
            GuildAchievementDeleted() : ServerPacket(SMSG_GUILD_ACHIEVEMENT_DELETED, 16 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid GuildGUID;
            uint32 AchievementID = 0;
            time_t TimeDeleted = time_t(0);
        };

        class GuildAchievementEarned final : public ServerPacket
        {
        public:
            GuildAchievementEarned() : ServerPacket(SMSG_GUILD_ACHIEVEMENT_EARNED, 16 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint32 AchievementID = 0;
            ObjectGuid GuildGUID;
            time_t TimeEarned = time_t(0);
        };

        class AllGuildAchievements final : public ServerPacket
        {
        public:
            AllGuildAchievements() : ServerPacket(SMSG_ALL_GUILD_ACHIEVEMENTS) { }

            WorldPacket const* Write() override;

            std::vector<EarnedAchievement> Earned;
        };

        class CriteriaUpdateAccount final : public ServerPacket
        {
        public:
            CriteriaUpdateAccount() : ServerPacket(SMSG_ACCOUNT_CRITERIA_UPDATE, 44) { }

            WorldPacket const* Write() override;

            CriteriaTreeProgress Data;
        };

        class AllAchievementCriteriaDataAccount final : public ServerPacket
        {
        public:
            AllAchievementCriteriaDataAccount() : ServerPacket(SMSG_ALL_ACCOUNT_CRITERIA, 4) { }

            WorldPacket const* Write() override;

            std::vector<CriteriaTreeProgress> Data;
        };

        class GuildGetAchievementMembers final : public ClientPacket
        {
        public:
            GuildGetAchievementMembers(WorldPacket&& packet) : ClientPacket(CMSG_GUILD_GET_ACHIEVEMENT_MEMBERS, std::move(packet)) { }

            void Read() override;

            uint32 AchievementID = 0;
        };

        class SetAchievementsHidden final : public ClientPacket
        {
        public:
            SetAchievementsHidden(WorldPacket&& packet) : ClientPacket(CMSG_SET_ACHIEVEMENTS_HIDDEN, std::move(packet)) { }

            void Read() override;

            bool Hidden = false;
        };
        
        class RespondInspectAchievements final : public ServerPacket
        {
        public:
            RespondInspectAchievements() : ServerPacket(SMSG_RESPOND_INSPECT_ACHIEVEMENTS, 16 + 8) { }

            WorldPacket const* Write() override;

            ObjectGuid Player;
            AllAchievements Data;
        };

    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Achievement::AllAchievements const& achieve);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Achievement::CriteriaTreeProgress const& achieve);

#endif // game_AchievementPackets_h__
