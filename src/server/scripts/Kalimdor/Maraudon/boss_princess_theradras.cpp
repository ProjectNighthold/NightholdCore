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
SDName: Boss_Princess_Theradras
SD%Complete: 100
SDComment:
SDCategory: Maraudon
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_DUSTFIELD             = 21909,
    SPELL_BOULDER               = 21832,
    SPELL_THRASH                = 3391,
    SPELL_REPULSIVEGAZE         = 21869
};

class boss_princess_theradras : public CreatureScript
{
public:
    boss_princess_theradras() : CreatureScript("boss_princess_theradras") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_ptheradrasAI(creature);
    }

    struct boss_ptheradrasAI : public ScriptedAI
    {
        boss_ptheradrasAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            DustfieldTimer = 8000;
            BoulderTimer = 2000;
            ThrashTimer = 5000;
            RepulsiveGazeTimer = 23000;
        }

        uint32 DustfieldTimer;
        uint32 BoulderTimer;
        uint32 ThrashTimer;
        uint32 RepulsiveGazeTimer;

        void Reset()
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) { }

        void JustDied(Unit* /*killer*/)
        {
            me->SummonCreature(12238, 28.067f, 61.875f, -123.405f, 4.67f, TEMPSUMMON_TIMED_DESPAWN, 600000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //DustfieldTimer
            if (DustfieldTimer <= diff)
            {
                DoCast(me, SPELL_DUSTFIELD);
                DustfieldTimer = 14000;
            }
            else DustfieldTimer -= diff;

            //BoulderTimer
            if (BoulderTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_BOULDER);
                BoulderTimer = 10000;
            }
            else BoulderTimer -= diff;

            //RepulsiveGazeTimer
            if (RepulsiveGazeTimer <= diff)
            {
                DoCastVictim(SPELL_REPULSIVEGAZE);
                RepulsiveGazeTimer = 20000;
            }
            else RepulsiveGazeTimer -= diff;

            //ThrashTimer
            if (ThrashTimer <= diff)
            {
                DoCast(me, SPELL_THRASH);
                ThrashTimer = 18000;
            }
            else ThrashTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_ptheradras()
{
    new boss_princess_theradras();
}
