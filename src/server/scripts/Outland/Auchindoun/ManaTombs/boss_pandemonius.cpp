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
SDName: Boss_Pandemonius
SD%Complete: 75
SDComment: Not known how void blast is done (amount of rapid cast seems to be related to players in party). All mobs remaining in surrounding area should aggro when engaged.
SDCategory: Auchindoun, Mana Tombs
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Texts
{
    SAY_AGGRO                           = 0,
    SAY_KILL                            = 2,
    SAY_DEATH                           = 3,
    EMOTE_DARK_SHELL                    = 4,
};

#define SPELL_VOID_BLAST                32325
#define H_SPELL_VOID_BLAST              38760
#define SPELL_DARK_SHELL                32358
#define H_SPELL_DARK_SHELL              38759

class boss_pandemonius : public CreatureScript
{
public:
    boss_pandemonius() : CreatureScript("boss_pandemonius") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_pandemoniusAI (creature);
    }

    struct boss_pandemoniusAI : public ScriptedAI
    {
        boss_pandemoniusAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        uint32 VoidBlast_Timer;
        uint32 DarkShell_Timer;
        uint32 VoidBlast_Counter;

        void Reset()
        {
            VoidBlast_Timer = 8000+rand()%15000;
            DarkShell_Timer = 20000;
            VoidBlast_Counter = 0;
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_KILL);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (VoidBlast_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    DoCast(target, SPELL_VOID_BLAST);
                    VoidBlast_Timer = 500;
                    ++VoidBlast_Counter;
                }

                if (VoidBlast_Counter == 5)
                {
                    VoidBlast_Timer = 15000+rand()%10000;
                    VoidBlast_Counter = 0;
                }
            } else VoidBlast_Timer -= diff;

            if (!VoidBlast_Counter)
            {
                if (DarkShell_Timer <= diff)
                {
                    if (me->IsNonMeleeSpellCast(false))
                        me->InterruptNonMeleeSpells(true);

                    Talk(EMOTE_DARK_SHELL);

                    DoCast(me, SPELL_DARK_SHELL);
                    DarkShell_Timer = 20000;
                } else DarkShell_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_pandemonius()
{
    new boss_pandemonius();
}
