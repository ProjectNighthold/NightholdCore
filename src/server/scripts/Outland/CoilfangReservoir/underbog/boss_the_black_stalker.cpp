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
SDName: Boss_the_black_stalker
SD%Complete: 95
SDComment: Timers may be incorrect
SDCategory: Coilfang Resevoir, Underbog
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

#define SPELL_LEVITATE             31704
#define SPELL_SUSPENSION           31719
#define SPELL_LEVITATION_PULSE     31701
#define SPELL_MAGNETIC_PULL        31705
#define SPELL_CHAIN_LIGHTNING      31717
#define SPELL_STATIC_CHARGE        31715
#define SPELL_SUMMON_SPORE_STRIDER 38755

#define ENTRY_SPORE_STRIDER        22299

class boss_the_black_stalker : public CreatureScript
{
public:
    boss_the_black_stalker() : CreatureScript("boss_the_black_stalker") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_the_black_stalkerAI (creature);
    }

    struct boss_the_black_stalkerAI : public ScriptedAI
    {
        boss_the_black_stalkerAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 SporeStriders_Timer;
        uint32 Levitate_Timer;
        uint32 ChainLightning_Timer;
        uint32 StaticCharge_Timer;
        ObjectGuid LevitatedTarget;
        uint32 LevitatedTarget_Timer;
        bool InAir;
        uint32 check_Timer;
        GuidList Striders;

        void Reset()
        {
            Levitate_Timer = 12000;
            ChainLightning_Timer = 6000;
            StaticCharge_Timer = 10000;
            SporeStriders_Timer = 10000+rand()%5000;
            check_Timer = 5000;
            LevitatedTarget.Clear();
            LevitatedTarget_Timer = 0;
            Striders.clear();
        }

        void EnterCombat(Unit* /*who*/) {}

        void JustSummoned(Creature* summon)
        {
            if (summon && summon->GetEntry() == ENTRY_SPORE_STRIDER)
            {
                Striders.push_back(summon->GetGUID());
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    summon->AI()->AttackStart(target);
                else
                    if (me->getVictim())
                        summon->AI()->AttackStart(me->getVictim());
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            for (GuidList::const_iterator i = Striders.begin(); i != Striders.end(); ++i)
                if (Creature* strider = Unit::GetCreature(*me, *i))
                    strider->DisappearAndDie();
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            // Evade if too far
            if (check_Timer <= diff)
            {
                float x, y, z, o;
                me->GetHomePosition(x, y, z, o);
                if (!me->IsWithinDist3d(x, y, z, 60))
                {
                    EnterEvadeMode();
                    return;
                }
                check_Timer = 1000;
            } else check_Timer -= diff;

            // Spore Striders
            if (IsHeroic() && SporeStriders_Timer <= diff)
            {
                DoCast(me, SPELL_SUMMON_SPORE_STRIDER);
                SporeStriders_Timer = 10000+rand()%5000;
            } else SporeStriders_Timer -= diff;

            // Levitate
            if (LevitatedTarget)
            {
                if (LevitatedTarget_Timer <= diff)
                {
                    if (Unit* target = Unit::GetUnit(*me, LevitatedTarget))
                    {
                        if (!target->HasAura(SPELL_LEVITATE))
                        {
                            LevitatedTarget.Clear();
                            return;
                        }
                        if (InAir)
                        {
                            target->AddAura(SPELL_SUSPENSION, target);
                            LevitatedTarget.Clear();
                        }
                        else
                        {
                            target->CastSpell(target, SPELL_MAGNETIC_PULL, true);
                            InAir = true;
                            LevitatedTarget_Timer = 1500;
                        }
                    }
                    else
                        LevitatedTarget.Clear();
                } else LevitatedTarget_Timer -= diff;
            }
            if (Levitate_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                {
                    DoCast(target, SPELL_LEVITATE);
                    LevitatedTarget = target->GetGUID();
                    LevitatedTarget_Timer = 2000;
                    InAir = false;
                }
                Levitate_Timer = 12000+rand()%3000;
            } else Levitate_Timer -= diff;

            // Chain Lightning
            if (ChainLightning_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_CHAIN_LIGHTNING);
                ChainLightning_Timer = 7000;
            } else ChainLightning_Timer -= diff;

            // Static Charge
            if (StaticCharge_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30, true))
                    DoCast(target, SPELL_STATIC_CHARGE);
                StaticCharge_Timer = 10000;
            } else StaticCharge_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_the_black_stalker()
{
    new boss_the_black_stalker();
}
