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

enum Says
{
    SAY_AGGRO,
    SAY_SUMMON60,
    SAY_SUMMON30,
    SAY_HP,
    SAY_KILL
};

#define SPELL_AMNENNARSWRATH    13009
#define SPELL_FROSTBOLT         15530
#define SPELL_FROST_NOVA        15531
#define SPELL_FROST_SPECTRES    12642

class boss_amnennar_the_coldbringer : public CreatureScript
{
public:
    boss_amnennar_the_coldbringer() : CreatureScript("boss_amnennar_the_coldbringer") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_amnennar_the_coldbringerAI (creature);
    }

    struct boss_amnennar_the_coldbringerAI : public ScriptedAI
    {
        boss_amnennar_the_coldbringerAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 AmnenarsWrath_Timer;
        uint32 FrostBolt_Timer;
        uint32 FrostNova_Timer;
        bool Spectrals60;
        bool Spectrals30;
        bool Hp;

        void Reset()
        {
            AmnenarsWrath_Timer = 8000;
            FrostBolt_Timer = 1000;
            FrostNova_Timer = urand(10000, 15000);
            Spectrals30 = false;
            Spectrals60 = false;
            Hp = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_KILL);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //AmnenarsWrath_Timer
            if (AmnenarsWrath_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_AMNENNARSWRATH);
                AmnenarsWrath_Timer = 12000;
            } else AmnenarsWrath_Timer -= diff;

            //FrostBolt_Timer
            if (FrostBolt_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FROSTBOLT);
                FrostBolt_Timer = 8000;
            } else FrostBolt_Timer -= diff;

            if (FrostNova_Timer <= diff)
            {
                DoCast(me, SPELL_FROST_NOVA);
                FrostNova_Timer = 15000;
            } else FrostNova_Timer -= diff;

            if (!Spectrals60 && HealthBelowPct(60))
            {
                DoScriptText(SAY_SUMMON60, me);
                DoCast(me->getVictim(), SPELL_FROST_SPECTRES);
                Spectrals60 = true;
            }

            if (!Hp && HealthBelowPct(50))
            {
                Talk(SAY_HP);
                Hp = true;
            }

            if (!Spectrals30 && HealthBelowPct(30))
            {
                Talk(SAY_SUMMON30);
                DoCast(me->getVictim(), SPELL_FROST_SPECTRES);
                Spectrals30 = true;
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_amnennar_the_coldbringer()
{
    new boss_amnennar_the_coldbringer();
}
