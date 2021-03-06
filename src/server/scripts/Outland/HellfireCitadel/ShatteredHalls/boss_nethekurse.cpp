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

/* ScriptData
SDName: Boss_Grand_Warlock_Nethekurse
SD%Complete: 75
SDComment: encounter not fully completed. missing part where boss kill minions.
SDCategory: Hellfire Citadel, Shattered Halls
EndScriptData */

/* ContentData
boss_grand_warlock_nethekurse
mob_fel_orc_convert
mob_lesser_shadow_fissure
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "shattered_halls.h"

enum eSays
{
    SAY_INTRO                   = 0,
    SAY_PEON_ATTACK             = 1,
    SAY_PEON_DIE                = 2,
    SAY_TAUNT                   = 3,
    SAY_AGGRO                   = 4,
    SAY_SLAY                    = 5,
    SAY_DIE                     = 6,
};

enum eSpells
{
    SPELL_DEATH_COIL            = 30500,
    SPELL_DARK_SPIN             = 30502,
    SPELL_SHADOW_FISSURE        = 30496,
    SPELL_SHADOW_CLEAVE         = 30495,
    H_SPELL_SHADOW_SLAM         = 35953,
    SPELL_HEMORRHAGE            = 30478,
    SPELL_CONSUMPTION           = 30497,
    SPELL_TEMPORARY_VISUAL      = 39312,
};

class boss_grand_warlock_nethekurse : public CreatureScript
{
    public:

        boss_grand_warlock_nethekurse()
            : CreatureScript("boss_grand_warlock_nethekurse")
        {
        }

        struct boss_grand_warlock_nethekurseAI : public ScriptedAI
        {
            boss_grand_warlock_nethekurseAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            bool IntroOnce;
            bool IsIntroEvent;
            bool IsMainEvent;
            bool SpinOnce;
            bool Phase;

            uint32 PeonEngagedCount;
            uint32 PeonKilledCount;

            uint32 IntroEvent_Timer;
            uint32 DeathCoil_Timer;
            uint32 ShadowFissure_Timer;
            uint32 Cleave_Timer;

            void Reset()
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                IsIntroEvent = false;
                IntroOnce = false;
                IsMainEvent = false;
                SpinOnce = false;
                Phase = false;

                PeonEngagedCount = 0;
                PeonKilledCount = 0;

                IntroEvent_Timer = 90000;
                DeathCoil_Timer = 20000;
                ShadowFissure_Timer = 8000;
                Cleave_Timer = 5000;
            }

            void DoYellForPeonAggro()
            {
                if (PeonEngagedCount >= 4)
                    return;

                Talk(SAY_PEON_ATTACK);
                ++PeonEngagedCount;
            }

            void DoYellForPeonDeath()
            {
                if (PeonKilledCount >= 4)
                    return;

                Talk(SAY_PEON_DIE);
                ++PeonKilledCount;

                if (PeonKilledCount == 4)
                {
                    IsIntroEvent = false;
                    IsMainEvent = true;
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
            }

            void DoTauntPeons()
            {
                Talk(SAY_TAUNT);

                IsIntroEvent = false;
                PeonEngagedCount = 4;
                PeonKilledCount = 4;
                IsMainEvent = true;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            void AttackStart(Unit* who)
            {
                if (IsIntroEvent || !IsMainEvent)
                    return;

                if (me->Attack(who, true))
                {
                    if (Phase)
                        DoStartNoMovement(who);
                    else
                        DoStartMovement(who);
                }
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!IntroOnce && me->IsWithinDistInMap(who, 50.0f))
                    {
                    if (who->GetTypeId() != TYPEID_PLAYER)
                        return;

                        Talk(SAY_INTRO);
                        IntroOnce = true;
                        IsIntroEvent = true;

                        if (instance)
                            instance->SetData(TYPE_NETHEKURSE, IN_PROGRESS);
                    }

                    if (IsIntroEvent || !IsMainEvent)
                        return;

                    ScriptedAI::MoveInLineOfSight(who);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);
            }

            void JustSummoned(Creature* summoned)
            {
                summoned->setFaction(16);
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                summoned->CastSpell(summoned, SPELL_TEMPORARY_VISUAL, true);
                summoned->CastSpell(summoned, SPELL_CONSUMPTION, false, 0, NULL, me->GetGUID());
            }

            void KilledUnit(Unit* /*victim*/)
            {
                Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_DIE);

                if (!instance)
                    return;

                instance->SetData(TYPE_NETHEKURSE, DONE);
                instance->HandleGameObject(instance->GetGuidData(DATA_NETHEKURSE_DOOR), true);
            }

            void UpdateAI(uint32 diff)
            {
                if (IsIntroEvent)
                {
                    if (!instance)
                        return;

                    if (instance->GetData(TYPE_NETHEKURSE) == IN_PROGRESS)
                    {
                        if (IntroEvent_Timer <= diff)
                            DoTauntPeons();
                        else
                            IntroEvent_Timer -= diff;
                    }
                }

                if (!UpdateVictim())
                    return;

                if (!IsMainEvent)
                    return;

                if (Phase)
                {
                    if (!SpinOnce)
                    {
                        DoCast(me->getVictim(), SPELL_DARK_SPIN);
                        SpinOnce = true;
                    }

                    if (Cleave_Timer <= diff)
                    {
                        DoCast(me->getVictim(), SPELL_SHADOW_CLEAVE);
                        Cleave_Timer = 6000+rand()%2500;
                    }
                    else
                        Cleave_Timer -= diff;
                }
                else
                {
                    if (ShadowFissure_Timer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SHADOW_FISSURE);
                        ShadowFissure_Timer = urand(7500, 15000);
                    }
                    else
                        ShadowFissure_Timer -= diff;

                    if (DeathCoil_Timer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_DEATH_COIL);
                        DeathCoil_Timer = urand(15000, 20000);
                    }
                    else
                        DeathCoil_Timer -= diff;

                    if (!HealthAbovePct(20))
                        Phase = true;

                    DoMeleeAttackIfReady();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_grand_warlock_nethekurseAI(creature);
        }
};

class mob_fel_orc_convert : public CreatureScript
{
    public:

        mob_fel_orc_convert()
            : CreatureScript("mob_fel_orc_convert")
        {
        }

        struct mob_fel_orc_convertAI : public ScriptedAI
        {
            mob_fel_orc_convertAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            uint32 Hemorrhage_Timer;

            void Reset()
            {
                me->SetNoCallAssistance(true);
                Hemorrhage_Timer = 3000;
            }

            void MoveInLineOfSight(Unit* /*who*/)
            {
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (instance)
                {
                    if (instance->GetGuidData(DATA_NETHEKURSE))
                    {
                        Creature* pKurse = Unit::GetCreature(*me, instance->GetGuidData(DATA_NETHEKURSE));
                        if (pKurse && me->IsWithinDist(pKurse, 45.0f))
                        {
                            CAST_AI(boss_grand_warlock_nethekurse::boss_grand_warlock_nethekurseAI, pKurse->AI())->DoYellForPeonAggro();

                            if (instance->GetData(TYPE_NETHEKURSE) == IN_PROGRESS)
                                return;
                            else
                                instance->SetData(TYPE_NETHEKURSE, IN_PROGRESS);
                        }
                    }
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                if (instance)
                {
                    if (instance->GetData(TYPE_NETHEKURSE) != IN_PROGRESS)
                        return;
                    if (instance->GetGuidData(DATA_NETHEKURSE))
                        if (Creature* pKurse = Unit::GetCreature(*me, instance->GetGuidData(DATA_NETHEKURSE)))
                            CAST_AI(boss_grand_warlock_nethekurse::boss_grand_warlock_nethekurseAI, pKurse->AI())->DoYellForPeonDeath();
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (Hemorrhage_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_HEMORRHAGE);
                    Hemorrhage_Timer = 15000;
                } else Hemorrhage_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_fel_orc_convertAI(creature);
        }
};

//NOTE: this Creature are also summoned by other spells, for different creatures
class mob_lesser_shadow_fissure : public CreatureScript
{
    public:

        mob_lesser_shadow_fissure()
            : CreatureScript("mob_lesser_shadow_fissure")
        {
        }

        struct mob_lesser_shadow_fissureAI : public ScriptedAI
        {
            mob_lesser_shadow_fissureAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset() { }
            void MoveInLineOfSight(Unit* /*who*/) {}
            void AttackStart(Unit* /*who*/) {}
            void EnterCombat(Unit* /*who*/) {}
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_lesser_shadow_fissureAI (creature);
        }
};

void AddSC_boss_grand_warlock_nethekurse()
{
    new boss_grand_warlock_nethekurse();
    new mob_fel_orc_convert();
    new mob_lesser_shadow_fissure();
}

