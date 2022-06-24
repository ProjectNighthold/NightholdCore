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

#ifndef CombatPackets_h__
#define CombatPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Player.h"
#include "SpellPackets.h"

namespace WorldPackets
{
    namespace Combat
    {
        class AttackSwingError final : public ServerPacket
        {
        public:
            AttackSwingError(AttackSwingReason reason) : ServerPacket(SMSG_ATTACK_SWING_ERROR, 4), Reason(reason) { }

            WorldPacket const* Write() override;

            AttackSwingReason Reason = ATTACK_SWING_ERROR_CANT_ATTACK;
        };

        class AttackSwing final : public ClientPacket
        {
        public:
            AttackSwing(WorldPacket&& packet) : ClientPacket(CMSG_ATTACK_SWING, std::move(packet)) { }

            void Read() override;

            ObjectGuid Victim;
        };

        class AttackStop final : public ClientPacket
        {
        public:
            AttackStop(WorldPacket&& packet) : ClientPacket(CMSG_ATTACK_STOP, std::move(packet)) { }

            void Read() override { }
        };

        class AttackStart final : public ServerPacket
        {
        public:
            AttackStart() : ServerPacket(SMSG_ATTACK_START, 16 * 2) { }

            WorldPacket const* Write() override;

            ObjectGuid Attacker;
            ObjectGuid Victim;
        };

        class SAttackStop final : public ServerPacket
        {
        public:
            SAttackStop() : ServerPacket(SMSG_ATTACK_STOP, 16 * 2 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Attacker;
            ObjectGuid Victim;
            bool Dead = false;
        };

        struct ThreatInfo
        {
            ObjectGuid UnitGUID;
            int64 Threat = 0;
        };

        class ThreatUpdate final : public ServerPacket
        {
        public:
            ThreatUpdate() : ServerPacket(SMSG_THREAT_UPDATE, 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            std::vector<ThreatInfo> ThreatList;
        };

        class HighestThreatUpdate final : public ServerPacket
        {
        public:
            HighestThreatUpdate() : ServerPacket(SMSG_HIGHEST_THREAT_UPDATE, 16 * 2 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            std::vector<ThreatInfo> ThreatList;
            ObjectGuid HighestThreatGUID;
        };

        class ThreatRemove final : public ServerPacket
        {
        public:
            ThreatRemove() : ServerPacket(SMSG_THREAT_REMOVE, 32) { }

            WorldPacket const* Write() override;

            ObjectGuid AboutGUID;
            ObjectGuid UnitGUID;
        };

        class AIReaction final : public ServerPacket
        {
        public:
            AIReaction() : ServerPacket(SMSG_AI_REACTION, 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            uint32 Reaction = 0;
        };

        class CancelCombat final : public ServerPacket
        {
        public:
            CancelCombat() : ServerPacket(SMSG_CANCEL_COMBAT, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        struct PowerUpdatePower
        {
            PowerUpdatePower(int32 power, uint8 powerType) : Power(power), PowerType(powerType) { }

            int32 Power = 0;
            uint8 PowerType = 0;
        };

        class PowerUpdate final : public ServerPacket
        {
        public:
            PowerUpdate() : ServerPacket(SMSG_POWER_UPDATE, 16 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            std::vector<PowerUpdatePower> Powers;
        };

        class SetSheathed final : public ClientPacket
        {
        public:
            SetSheathed(WorldPacket&& packet) : ClientPacket(CMSG_SET_SHEATHED, std::move(packet)) { }

            void Read() override;

            int32 CurrentSheathState = 0;
            bool Animate = true;
        };

        class CancelAutoRepeat final : public ServerPacket
        {
        public:
            CancelAutoRepeat() : ServerPacket(SMSG_CANCEL_AUTO_REPEAT, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
        };

        class HealthUpdate final : public ServerPacket
        {
        public:
            HealthUpdate() : ServerPacket(SMSG_HEALTH_UPDATE, 16 + 8) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            int64 Health = 0;
        };

        class ThreatClear final : public ServerPacket
        {
        public:
            ThreatClear() : ServerPacket(SMSG_THREAT_CLEAR, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
        };

        class PvPCredit final : public ServerPacket
        {
        public:
            PvPCredit() : ServerPacket(SMSG_PVP_CREDIT, 4 + 4 + 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Target;
            int32 Honor = 0;
            int32 Rank = 0;
        };

        class BreakTarget final : public ServerPacket
        {
        public:
            BreakTarget() : ServerPacket(SMSG_BREAK_TARGET, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
        };
        
        class ResetRangedCombatTimer final : public ServerPacket
        {
        public:
            ResetRangedCombatTimer() : ServerPacket(SMSG_RESET_RANGED_COMBAT_TIMER, 4) { }

            WorldPacket const* Write() override;

            int32 Delay = 0;
        };
    }
}

#endif // CombatPackets_h__
