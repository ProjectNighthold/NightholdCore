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

#ifndef CombatLogPackets_h__
#define CombatLogPackets_h__

#include "Packet.h"
#include "Spell.h"

namespace WorldPackets
{
    namespace Spells
    {
        struct SpellLogPowerData
        {
            SpellLogPowerData(int32 powerType, int32 amount, int32 cost) : PowerType(powerType), Amount(amount), Cost(cost) { }

            int32 PowerType = 0;
            int32 Amount = 0;
            int32 Cost = 0;
        };

        struct SpellCastLogData
        {
            int64 Health = 0;
            int32 AttackPower = 0;
            int32 SpellPower = 0;
            std::vector<SpellLogPowerData> PowerData;

            void Initialize(Unit const* unit);
            void Initialize(Spell const* spell);
        };

        struct SandboxScalingData
        {
            enum SandboxScalingDataType : uint32
            {
                TYPE_PLAYER_TO_PLAYER = 1, // NYI
                TYPE_CREATURE_TO_PLAYER_DAMAGE = 2,
                TYPE_PLAYER_TO_CREATURE_DAMAGE = 3,
                TYPE_CREATURE_TO_CREATURE_DAMAGE = 4
            };

            uint32 Type = 0;
            int16 PlayerLevelDelta = 0;
            uint16 PlayerItemLevel = 0;
            uint8 TargetLevel = 0;
            uint8 Expansion = 0;
            uint8 Class = 0;
            uint8 TargetMinScalingLevel = 0;
            uint8 TargetMaxScalingLevel = 0;
            int8 TargetScalingLevelDelta = 0;

            template<class T, class U>
            bool GenerateDataForUnits(T* attacker, U* target);
        };
    }

    namespace CombatLog
    {
        class CombatLogServerPacket : public ServerPacket
        {
        public:
            CombatLogServerPacket(OpcodeServer opcode, size_t initialSize = 200, ConnectionType connection = CONNECTION_TYPE_DEFAULT) : ServerPacket(opcode, initialSize, connection), _fullLogPacket(opcode, initialSize, connection) { }

            WorldPacket const* GetFullLogPacket() const { return &_fullLogPacket; }
            WorldPacket const* GetBasicLogPacket() const { return &_worldPacket; }

            Spells::SpellCastLogData LogData;

        protected:
            template<typename T>
            void operator<<(T const& val)
            {
                _worldPacket << val;
                _fullLogPacket << val;
            }

            void WriteLogDataBit()
            {
                _worldPacket.WriteBit(false);
                _fullLogPacket.WriteBit(true);
            }

            void FlushBits()
            {
                _worldPacket.FlushBits();
                _fullLogPacket.FlushBits();
            }

            bool WriteBit(bool bit)
            {
                _worldPacket.WriteBit(bit);
                _fullLogPacket.WriteBit(bit);
                return bit;
            }

            void WriteBits(uint32 value, uint32 bitCount)
            {
                _worldPacket.WriteBits(value, bitCount);
                _fullLogPacket.WriteBits(value, bitCount);
            }

            ByteBuffer& WriteLogData();

            WorldPacket _fullLogPacket;
        };

        class SpellNonMeleeDamageLog final : public CombatLogServerPacket
        {
        public:
            SpellNonMeleeDamageLog() : CombatLogServerPacket(SMSG_SPELL_NON_MELEE_DAMAGE_LOG, 16 * 3 + 7 * 4 + 2) { }

            WorldPacket const* Write() override;
            
            ObjectGuid Me;
            ObjectGuid CasterGUID;
            ObjectGuid CastID;
            Optional<Spells::SandboxScalingData> SandboxScaling;
            int32 Absorbed = 0;
            int32 Damage = 0;
            int32 Flags = 0;
            int32 Overkill = -1;
            int32 Resisted = 0;
            int32 ShieldBlock = 0;
            int32 SpellID = 0;
            int32 SpellXSpellVisualID = 0;
            uint8 SchoolMask = 0;
            bool Periodic = false;
            // Optional<SpellNonMeleeDamageLogDebugInfo> DebugInfo;
        };

        class EnvironmentalDamageLog final : public CombatLogServerPacket
        {
        public:
            EnvironmentalDamageLog() : CombatLogServerPacket(SMSG_ENVIRONMENTAL_DAMAGE_LOG, 23) { }

            WorldPacket const* Write() override;

            ObjectGuid Victim;
            uint8 Type = 0;
            int32 Amount = 0;
            int32 Resisted = 0;
            int32 Absorbed = 0;
        };

        class SpellExecuteLog final : public CombatLogServerPacket
        {
        public:
            struct SpellLogEffect
            {
                int32 Effect = 0;

                std::vector<SpellLogEffectPowerDrainParams> PowerDrainTargets;
                std::vector<SpellLogEffectExtraAttacksParams> ExtraAttacksTargets;
                std::vector<SpellLogEffectDurabilityDamageParams> DurabilityDamageTargets;
                std::vector<SpellLogEffectGenericVictimParams> GenericVictimTargets;
                std::vector<SpellLogEffectTradeSkillItemParams> TradeSkillTargets;
                std::vector<SpellLogEffectFeedPetParams> FeedPetTargets;
            };

            SpellExecuteLog() : CombatLogServerPacket(SMSG_SPELL_EXECUTE_LOG, 16 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Caster;
            int32 SpellID = 0;
            std::vector<SpellLogEffect> Effects;
        };

        class SpellHealLog final : public CombatLogServerPacket
        {
        public:
            SpellHealLog() : CombatLogServerPacket(SMSG_SPELL_HEAL_LOG, 16 + 16 + 4 * 4 + 1) { }

            WorldPacket const* Write() override;

            Optional<Spells::SandboxScalingData> SandboxScaling;
            Optional<float> CritRollMade;
            Optional<float> CritRollNeeded;
            ObjectGuid CasterGUID;
            ObjectGuid TargetGUID;
            int32 SpellID = 0;
            int32 Health = 0;
            int32 OverHeal = 0;
            int32 Absorbed = 0;
            bool Crit = false;
        };

        class SpellPeriodicAuraLog final : public CombatLogServerPacket
        {
        public:
            struct PeriodicalAuraLogEffectDebugInfo
            {
                float CritRollMade = 0.0f;
                float CritRollNeeded = 0.0f;
            };

            struct SpellLogEffect
            {
                int32 Effect = 0;
                int32 Amount = 0;
                int32 OverHealOrKill = 0;
                int32 SchoolMaskOrPower = 0;
                int32 AbsorbedOrAmplitude = 0;
                int32 Resisted = 0;
                bool Crit = false;
                Optional<PeriodicalAuraLogEffectDebugInfo> DebugInfo;
                Optional<Spells::SandboxScalingData> SandboxScaling;
            };

            SpellPeriodicAuraLog() : CombatLogServerPacket(SMSG_SPELL_PERIODIC_AURA_LOG, 16 + 16 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid TargetGUID;
            ObjectGuid CasterGUID;
            int32 SpellID = 0;
            std::vector<SpellLogEffect> Effects;
        };

        class SpellInterruptLog final : public ServerPacket
        {
        public:
            SpellInterruptLog() : ServerPacket(SMSG_SPELL_INTERRUPT_LOG, 16 + 16 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Caster;
            ObjectGuid Victim;
            int32 InterruptedSpellID = 0;
            int32 SpellID = 0;
        };

        class SpellEnergizeLog final : public CombatLogServerPacket
        {
        public:
            SpellEnergizeLog() : CombatLogServerPacket(SMSG_SPELL_ENERGIZE_LOG, 16 + 16 + 4 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterGUID;
            ObjectGuid TargetGUID;
            int32 SpellID = 0;
            int32 Type = 0;
            int32 Amount = 0;
            int32 OverEnergize = 0;
        };

        class SpellInstakillLog final : public ServerPacket
        {
        public:
            SpellInstakillLog() : ServerPacket(SMSG_SPELL_INSTAKILL_LOG, 16 + 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Target;
            ObjectGuid Caster;
            int32 SpellID = 0;
        };

        struct SpellLogMissDebug
        {
            float HitRoll = 0.0f;
            float HitRollNeeded = 0.0f;
        };

        struct SpellLogMissEntry
        {
            SpellLogMissEntry(ObjectGuid const& victim, uint8 missReason) : Victim(victim), MissReason(missReason) { }

            ObjectGuid Victim;
            uint8 MissReason = 0;
            Optional<SpellLogMissDebug> Debug;
        };

        class SpellMissLog final : public ServerPacket
        {
        public:
            SpellMissLog() : ServerPacket(SMSG_SPELL_MISS_LOG, 4 + 16 + 4) { }

            WorldPacket const* Write() override;

            int32 SpellID = 0;
            ObjectGuid Caster;
            std::vector<SpellLogMissEntry> Entries;
        };

        class ProcResist final : public ServerPacket
        {
        public:
            ProcResist() : ServerPacket(SMSG_PROC_RESIST, 16 + 4 + 4 + 4 + 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Caster;
            ObjectGuid Target;
            int32 SpellID = 0;
            Optional<float> Rolled;
            Optional<float> Needed;
        };

        class SpellOrDamageImmune final : public ServerPacket
        {
        public:
            SpellOrDamageImmune() : ServerPacket(SMSG_SPELL_OR_DAMAGE_IMMUNE, 16 + 1 + 4 + 16) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterGUID;
            ObjectGuid VictimGUID;
            uint32 SpellID = 0;
            bool IsPeriodic = false;
        };

        class SpellDamageShield final : public CombatLogServerPacket
        {
        public:
            SpellDamageShield() : CombatLogServerPacket(SMSG_SPELL_DAMAGE_SHIELD, 4 + 16 + 4 + 4 + 16 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Attacker;
            ObjectGuid Defender;
            int32 SpellID = 0;
            int32 TotalDamage = 0;
            int32 OverKill = 0;
            int32 SchoolMask = 0;
            int32 LogAbsorbed = 0;
        };

        struct SubDamage
        {
            int32 SchoolMask = 0;
            float FDamage = 0.0f; // Float damage (Most of the time equals to Damage)
            int32 Damage = 0;
            int32 Absorbed = 0;
            int32 Resisted = 0;
        };

        struct UnkAttackerState
        {
            int32 State1 = 0;
            float State2 = 0.0f;
            float State3 = 0.0f;
            float State4 = 0.0f;
            float State5 = 0.0f;
            float State6 = 0.0f;
            float State7 = 0.0f;
            float State8 = 0.0f;
            float State9 = 0.0f;
            float State10 = 0.0f;
            float State11 = 0.0f;
            int32 State12 = 0;
        };

        class AttackerStateUpdate final : public CombatLogServerPacket
        {
        public:
            AttackerStateUpdate() : CombatLogServerPacket(SMSG_ATTACKER_STATE_UPDATE, 70) { }

            WorldPacket const* Write() override;
            
            UnkAttackerState UnkState;
            Optional<SubDamage> SubDmg;
            ObjectGuid AttackerGUID;
            ObjectGuid VictimGUID;
            uint32 HitInfo = 0; // Flags
            int32 Damage = 0;
            int32 OverDamage = -1; // (damage - health) or -1 if unit is still alive
            int32 AttackerState = -1;
            int32 MeleeSpellID = 0;
            int32 BlockAmount = 0;
            int32 RageGained = 0;
            float Unk = 0.0f;
            uint8 VictimState = 0;
            Spells::SandboxScalingData SandboxScaling;
        };

        class AttackEventFailed final : public CombatLogServerPacket
        {
        public:
            AttackEventFailed() : CombatLogServerPacket(SMSG_COMBAT_EVENT_FAILED, 32) { }

            WorldPacket const* Write() override;

            ObjectGuid Attacker;
            ObjectGuid Victim;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellCastLogData const& spellCastLogData);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SandboxScalingData const& sandboxScalingData);

#endif // CombatLogPackets_h__
