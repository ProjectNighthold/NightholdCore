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

#include "nexus.h"

enum Spells
{
    SPELL_SPARK                                   = 47751,
    H_SPELL_SPARK                                 = 57062,
    SPELL_RIFT_SHIELD                             = 47748,
    SPELL_CHARGE_RIFT                             = 47747,
};

enum Adds
{
    MOB_CRAZED_MANA_WRAITH                        = 26746,
    MOB_CHAOTIC_RIFT                              = 26918
};

enum Yells
{
    SAY_AGGRO                                     = 0,
    SAY_DEATH                                     = 1,
    SAY_RIFT                                      = 2,
    SAY_SHIELD                                    = 3,
    SAY_SHIELD_A                                  = 4,
    SAY_RIFT_A                                    = 5,
};

enum RiftSpells
{
    SPELL_CHAOTIC_ENERGY_BURST                    = 47688,
    SPELL_CHARGED_CHAOTIC_ENERGY_BURST            = 47737,
    SPELL_ARCANEFORM                              = 48019,
};

Position const RiftLocation[6] =
{
    { 652.64f, -273.70f, -8.75f, 0.0f },
    { 634.45f, -265.94f, -8.44f, 0.0f },
    { 620.73f, -281.17f, -9.02f, 0.0f },
    { 626.10f, -304.67f, -9.44f, 0.0f },
    { 639.87f, -314.11f, -9.49f, 0.0f },
    { 651.72f, -297.44f, -9.37f, 0.0f }
};

#define DATA_CHAOS_THEORY                         1

class boss_anomalus : public CreatureScript
{
    public:
        boss_anomalus() : CreatureScript("boss_anomalus") { }

        struct boss_anomalusAI : public ScriptedAI
        {
            boss_anomalusAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;

            uint8 Phase;
            uint32 uiSparkTimer;
            uint32 uiCreateRiftTimer;
            ObjectGuid uiChaoticRiftGUID;
            bool chaosTheory;

            void Reset() override
            {
                Phase = 0;
                uiSparkTimer = 5000;
                uiChaoticRiftGUID.Clear();
                chaosTheory = true;

                if (instance)
                    instance->SetData(DATA_ANOMALUS_EVENT, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);

                if (instance)
                    instance->SetData(DATA_ANOMALUS_EVENT, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);

                if (instance)
                    instance->SetData(DATA_ANOMALUS_EVENT, DONE);
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_CHAOS_THEORY)
                    return chaosTheory ? 1 : 0;

                return 0;
            }

            void SummonedCreatureDies(Creature* summoned, Unit* /*who*/) override
            {
                if (summoned->GetEntry() == MOB_CHAOTIC_RIFT)
                    chaosTheory = false;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->GetDistance(me->GetHomePosition()) > 60.0f)
                {
                    EnterEvadeMode();
                    return;
                }

                if (me->HasAura(SPELL_RIFT_SHIELD))
                {
                    if (uiChaoticRiftGUID)
                    {
                        Creature* Rift = ObjectAccessor::GetCreature(*me, uiChaoticRiftGUID);
                        if (Rift && Rift->isDead())
                        {
                            me->RemoveAurasDueToSpell(SPELL_RIFT_SHIELD);
                            uiChaoticRiftGUID.Clear();
                        }
                        return;
                    }
                }
                else
                    uiChaoticRiftGUID.Clear();

                if ((Phase == 0) && HealthBelowPct(50))
                {
                    Phase = 1;
                    Talk(SAY_SHIELD);
                    Talk(SAY_SHIELD_A);
                    DoCast(me, SPELL_RIFT_SHIELD);
                    if (Creature* Rift = me->SummonCreature(MOB_CHAOTIC_RIFT, RiftLocation[urand(0, 5)], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1000))
                    {
                        DoCast(Rift, SPELL_CHARGE_RIFT);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            Rift->AI()->AttackStart(target);
                        uiChaoticRiftGUID = Rift->GetGUID();
                        Talk(SAY_RIFT);
                        Talk(SAY_RIFT_A);
                    }
                }

                if (uiSparkTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_SPARK);
                    uiSparkTimer = 5000;
                }
                else
                    uiSparkTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_anomalusAI(creature);
        }
};

class mob_chaotic_rift : public CreatureScript
{
    public:
        mob_chaotic_rift() : CreatureScript("mob_chaotic_rift") { }

        struct mob_chaotic_riftAI : public Scripted_NoMovementAI
        {
            mob_chaotic_riftAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 uiChaoticEnergyBurstTimer;
            uint32 uiSummonCrazedManaWraithTimer;

            void Reset() override
            {
                uiChaoticEnergyBurstTimer = 1000;
                uiSummonCrazedManaWraithTimer = 5000;
                DoCast(me, SPELL_ARCANEFORM, false);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (uiChaoticEnergyBurstTimer <= diff)
                {
                    Creature* Anomalus = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANOMALUS));
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        if (Anomalus && Anomalus->HasAura(SPELL_RIFT_SHIELD))
                            DoCast(target, SPELL_CHARGED_CHAOTIC_ENERGY_BURST);
                        else
                            DoCast(target, SPELL_CHAOTIC_ENERGY_BURST);
                    }
                    uiChaoticEnergyBurstTimer = 1000;
                }
                else
                    uiChaoticEnergyBurstTimer -= diff;

                if (uiSummonCrazedManaWraithTimer <= diff)
                {
                    if (Creature* Wraith = me->SummonCreature(MOB_CRAZED_MANA_WRAITH, me->GetPositionX() + 1, me->GetPositionY() + 1, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1000))
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            Wraith->AI()->AttackStart(target);
                    Creature* Anomalus = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ANOMALUS));
                    if (Anomalus && Anomalus->HasAura(SPELL_RIFT_SHIELD))
                        uiSummonCrazedManaWraithTimer = 5000;
                    else
                        uiSummonCrazedManaWraithTimer = 10000;
                }
                else
                    uiSummonCrazedManaWraithTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_chaotic_riftAI(creature);
        }
};

class achievement_chaos_theory : public AchievementCriteriaScript
{
    public:
        achievement_chaos_theory() : AchievementCriteriaScript("achievement_chaos_theory")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Anomalus = target->ToCreature())
                if (Anomalus->AI()->GetData(DATA_CHAOS_THEORY))
                    return true;

            return false;
        }
};

void AddSC_boss_anomalus()
{
    new boss_anomalus();
    new mob_chaotic_rift();
    new achievement_chaos_theory();
}
