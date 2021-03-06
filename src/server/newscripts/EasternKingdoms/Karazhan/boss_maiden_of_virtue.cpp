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
SDName: Boss_Maiden_of_Virtue
SD%Complete: 100
SDComment:
SDCategory: Karazhan
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_SLAY,
    SAY_REPENTANCE,
    SAY_DEATH
};

#define SPELL_REPENTANCE        29511
#define SPELL_HOLYFIRE          29522
#define SPELL_HOLYWRATH         32445
#define SPELL_HOLYGROUND        29512
#define SPELL_BERSERK           26662

class boss_maiden_of_virtue : public CreatureScript
{
public:
    boss_maiden_of_virtue() : CreatureScript("boss_maiden_of_virtue") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_maiden_of_virtueAI (creature);
    }

    struct boss_maiden_of_virtueAI : public ScriptedAI
    {
        boss_maiden_of_virtueAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 Repentance_Timer;
        uint32 Holyfire_Timer;
        uint32 Holywrath_Timer;
        uint32 Holyground_Timer;
        uint32 Enrage_Timer;

        bool Enraged;

        void Reset() override
        {
            Repentance_Timer    = 25000+(rand()%15000);
            Holyfire_Timer      = 8000+(rand()%17000);
            Holywrath_Timer     = 15000+(rand()%10000);
            Holyground_Timer    = 3000;
            Enrage_Timer        = 600000;

            Enraged = false;
        }

        void KilledUnit(Unit* /*Victim*/) override
        {
            if (urand(0, 1) == 0)
                Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (Enrage_Timer < diff && !Enraged)
            {
                DoCast(me, SPELL_BERSERK, true);
                Enraged = true;
            }
            else
                Enrage_Timer -= diff;

            if (Holyground_Timer <= diff)
            {
                DoCast(me, SPELL_HOLYGROUND, true);   //Triggered so it doesn't interrupt her at all
                Holyground_Timer = 3000;
            }
            else
                Holyground_Timer -= diff;

            if (Repentance_Timer <= diff)
            {
                if (auto victim = me->getVictim())
                    DoCast(victim, SPELL_REPENTANCE, false);

                Talk(SAY_REPENTANCE);

                Repentance_Timer = urand(25000, 35000);        //A little randomness on that spell
            }
            else
                Repentance_Timer -= diff;

            if (Holyfire_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_HOLYFIRE);

                    Holyfire_Timer = urand(8000, 23000);      //Anywhere from 8 to 23 seconds, good luck having several of those in a row!
            }
            else
                Holyfire_Timer -= diff;

            if (Holywrath_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_HOLYWRATH);

                Holywrath_Timer = urand(20000, 25000);        //20-30 secs sounds nice
            }
            else
                Holywrath_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_maiden_of_virtue()
{
    new boss_maiden_of_virtue();
}
