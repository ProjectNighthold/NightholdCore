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

#ifndef TalentPackets_h__
#define TalentPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Talent
    {
        struct TalentGroupInfo
        {
            uint32 SpecID = 0;
            std::vector<uint16> TalentIDs;
            std::vector<uint16> PvPTalentIDs;
        };

        struct TalentInfoUpdate
        {
            std::vector<TalentGroupInfo> TalentGroups;
            uint32 ActiveSpecID = 0;
            uint8 ActiveGroup = 0;
        };

        class UpdateTalentData final : public ServerPacket
        {
        public:
            UpdateTalentData() : ServerPacket(SMSG_UPDATE_TALENT_DATA, 2 + 4 + 4 + 4 + 12) { }

            WorldPacket const* Write() override;

            TalentInfoUpdate Info;
        };

        class LearnTalent final : public ClientPacket
        {
        public:
            LearnTalent(WorldPacket&& packet) : ClientPacket(CMSG_LEARN_TALENTS, std::move(packet)) { }

            void Read() override;

            Array<uint16, MAX_TALENT_TIERS> Talents;
        };

        class LearnPvpTalents final : public ClientPacket
        {
        public:
            LearnPvpTalents(WorldPacket&& packet) : ClientPacket(CMSG_LEARN_PVP_TALENTS, std::move(packet)) { }

            void Read() override;

            Array<uint16, 2> TalentIDs;
        };

        enum class LearnTalentReasons : uint8
        {
            None                            = 0,
            Unknown                         = 1,
            NotEnoughTalentInPrimaryTree    = 2,
            NoPrimaryTreeSelected           = 3,
            CantDoThatRightNow              = 4,
            AffectingCombat                 = 5,
            CantRemoveTalent                = 6,
            ChallengeModeActive             = 7,
            RestArea                        = 8,
        };

        struct LearnTalentFailedData
        {
            std::vector<uint16> TalentIDs;
            LearnTalentReasons Reason = LearnTalentReasons::None;
            uint32 SpecID = 0;
        };

        class LearnTalentFailed final : public ServerPacket
        {
        public:
            LearnTalentFailed() : ServerPacket(SMSG_LEARN_TALENTS_FAILED, 16) { }

            WorldPacket const* Write() override;

            LearnTalentFailedData Talent;
        };

        class LearnPvPTalentFailed final : public ServerPacket
        {
        public:
            LearnPvPTalentFailed() : ServerPacket(SMSG_LEARN_PVP_TALENTS_FAILED, 16) { }

            WorldPacket const* Write() override;

            LearnTalentFailedData PvPTalent;
        };

        struct GlyphBinding
        {
            GlyphBinding(uint32 spellId = 0, uint16 glyphId = 0) : SpellID(spellId), GlyphID(glyphId) { }

            uint32 SpellID;
            uint16 GlyphID;
        };

        class ActiveGlyphs final : public ServerPacket
        {
        public:
            ActiveGlyphs() : ServerPacket(SMSG_ACTIVE_GLYPHS, 4 + 1) { }

            WorldPacket const* Write() override;

            std::vector<GlyphBinding> Glyphs;
            bool IsFullUpdate = false;
        };
    }
}

#endif // TalentPackets_h__
