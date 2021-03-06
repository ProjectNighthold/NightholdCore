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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ahnkahet.h"

enum Yells
{
    SAY_AGGRO       = 0,
    SAY_SLAY        = 1,
    SAY_DEATH       = 2,
    SAY_EGG_SAC     = 3,
    EMOTE_HATCHES   = 4 
};

enum Spells
{
    SPELL_BROOD_PLAGUE                            = 56130,
    H_SPELL_BROOD_PLAGUE                          = 59467,
    H_SPELL_BROOD_RAGE                            = 59465,
    SPELL_ENRAGE                                  = 26662, // Enraged if too far away from home
    SPELL_SUMMON_SWARMERS                         = 56119, //2x 30178  -- 2x every 10secs
    SPELL_SUMMON_SWARM_GUARD                      = 56120, //1x 30176  -- every 25secs
};

enum Creatures
{
    MOB_AHNKAHAR_SWARMER                          = 30178,
    MOB_AHNKAHAR_GUARDIAN_ENTRY                   = 30176
};

#define ACTION_AHNKAHAR_GUARDIAN_DEAD             1
#define DATA_RESPECT_YOUR_ELDERS                  2

class boss_elder_nadox : public CreatureScript
{
    public:
        boss_elder_nadox() : CreatureScript("boss_elder_nadox") { }

        struct boss_elder_nadoxAI : public ScriptedAI
        {
            boss_elder_nadoxAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            uint32 uiPlagueTimer;
            uint32 uiRagueTimer;

            uint32 uiSwarmerSpawnTimer;
            uint32 uiGuardSpawnTimer;
            uint32 uiEnrageTimer;

            bool bGuardSpawned;
            bool respectYourElders;

            InstanceScript* instance;

            void Reset() override
            {
                uiPlagueTimer           = 13000;
                uiRagueTimer            = 20000;

                uiSwarmerSpawnTimer     = 10000;
                uiGuardSpawnTimer       = 25000;

                uiEnrageTimer           = 5000;

                bGuardSpawned           = false;
                respectYourElders       = true;

                if (instance)
                    instance->SetData(DATA_ELDER_NADOX_EVENT, NOT_STARTED);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);

                if (instance)
                    instance->SetData(DATA_ELDER_NADOX_EVENT, IN_PROGRESS);
            }

            void KilledUnit(Unit* /*who*/) override
            {
                Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);

                if (instance)
                    instance->SetData(DATA_ELDER_NADOX_EVENT, DONE);
            }

            void DoAction(int32 const action) override
            {
                if (action == ACTION_AHNKAHAR_GUARDIAN_DEAD)
                    respectYourElders = false;
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_RESPECT_YOUR_ELDERS)
                    return respectYourElders ? 1 : 0;

                return 0;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (uiPlagueTimer <= diff)
                {
                    DoCastVictim(SPELL_BROOD_PLAGUE);
                    uiPlagueTimer = 15000;
                }
                else
                    uiPlagueTimer -= diff;

                if (IsHeroic())
                {
                    if (uiRagueTimer <= diff)
                    {
                        if (Creature* Swarmer = me->FindNearestCreature(MOB_AHNKAHAR_SWARMER, 35.0f))
                        {
                            DoCast(Swarmer, H_SPELL_BROOD_RAGE, true);
                            uiRagueTimer = 15000;
                        }
                    }
                    else
                        uiRagueTimer -= diff;
                }

                if (uiSwarmerSpawnTimer <= diff)
                {
                    DoCast(me, SPELL_SUMMON_SWARMERS, true);
                    DoCast(me, SPELL_SUMMON_SWARMERS);
                    if (urand(1, 3) == 3) // 33% chance of dialog
                        Talk(SAY_EGG_SAC);

                    uiSwarmerSpawnTimer = 10000;
                }
                else
                    uiSwarmerSpawnTimer -= diff;

                if (!bGuardSpawned && uiGuardSpawnTimer <= diff)
                {
                    Talk(EMOTE_HATCHES, me->GetGUID());
                    DoCast(me, SPELL_SUMMON_SWARM_GUARD);
                    bGuardSpawned = true;
                }
                else
                    uiGuardSpawnTimer -= diff;

                if (uiEnrageTimer <= diff)
                {
                    if (me->HasAura(SPELL_ENRAGE, ObjectGuid::Empty))
                        return;

                    float x, y, z, o;
                    me->GetHomePosition(x, y, z, o);
                    if (z < 24)
                        if (!me->IsNonMeleeSpellCast(false))
                            DoCast(me, SPELL_ENRAGE, true);

                    uiEnrageTimer = 5000;
                }
                else
                    uiEnrageTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_elder_nadoxAI(creature);
        }
};

enum AddSpells
{
    SPELL_SPRINT                                  = 56354,
    SPELL_GUARDIAN_AURA                           = 56151
};

class mob_ahnkahar_nerubian : public CreatureScript
{
    public:
        mob_ahnkahar_nerubian() : CreatureScript("mob_ahnkahar_nerubian") { }

        struct mob_ahnkahar_nerubianAI : public ScriptedAI
        {
            mob_ahnkahar_nerubianAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            uint32 uiSprintTimer;

            void Reset() override
            {
                if (me->GetEntry() == MOB_AHNKAHAR_GUARDIAN_ENTRY)
                    DoCast(me, SPELL_GUARDIAN_AURA, true);
                uiSprintTimer = 10000;
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (me->GetEntry() == MOB_AHNKAHAR_GUARDIAN_ENTRY)
                    if (Creature* Nadox = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_ELDER_NADOX)))
                        Nadox->AI()->DoAction(ACTION_AHNKAHAR_GUARDIAN_DEAD);
            }

            void EnterCombat(Unit* /*who*/) override {}

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->GetEntry() == MOB_AHNKAHAR_GUARDIAN_ENTRY)
                    me->RemoveAurasDueToSpell(SPELL_GUARDIAN_AURA);

                if (instance)
                    if (instance->GetData(DATA_ELDER_NADOX_EVENT) != IN_PROGRESS)
                        me->DespawnOrUnsummon();

                if (uiSprintTimer <= diff)
                {
                    DoCast(me, SPELL_SPRINT);
                    uiSprintTimer = 25000;
                }
                else
                    uiSprintTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_ahnkahar_nerubianAI(creature);
        }
};

//HACK: No, AI. Replace with proper db content?
class mob_nadox_eggs : public CreatureScript
{
public:
    mob_nadox_eggs() : CreatureScript("mob_nadox_eggs") { }

    struct mob_nadox_eggsAI : public Scripted_NoMovementAI
    {
        mob_nadox_eggsAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
            creature->UpdateAllStats();
        }
        void Reset() override {}
        void EnterCombat(Unit* /*who*/) override {}
        void AttackStart(Unit* /*victim*/) override {}
        void MoveInLineOfSight(Unit* /*who*/) override {}
        void UpdateAI(uint32 /*diff*/) override {}
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_nadox_eggsAI(creature);
    }
};

class achievement_respect_your_elders : public AchievementCriteriaScript
{
    public:
        achievement_respect_your_elders() : AchievementCriteriaScript("achievement_respect_your_elders") {}

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Nadox = target->ToCreature())
                if (Nadox->AI()->GetData(DATA_RESPECT_YOUR_ELDERS))
                    return true;

            return false;
        }
};

void AddSC_boss_elder_nadox()
{
    new boss_elder_nadox;
    new mob_ahnkahar_nerubian;
    new mob_nadox_eggs;
    new achievement_respect_your_elders();
}
