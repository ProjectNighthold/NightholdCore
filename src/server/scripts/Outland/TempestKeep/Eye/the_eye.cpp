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

#include "the_eye.h"

enum Spells
{
    SPELL_COUNTERCHARGE    = 35035,
    SPELL_KNOCKAWAY        = 22893,
};

struct npc_crystalcore_devastator : public ScriptedAI
{
    explicit npc_crystalcore_devastator(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        Countercharge_Timer = 9000;
        Knockaway_Timer = 25000;
    }

    uint32 Knockaway_Timer;
    uint32 Countercharge_Timer;

    void Reset() override
    {
        Initialize();
    }

    void EnterCombat(Unit* /*who*/) override
    {
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        //Check if we have a current target
        //Knockaway_Timer
        if (Knockaway_Timer <= diff)
        {
            DoCastVictim(SPELL_KNOCKAWAY, true);

            // current aggro target is knocked away pick new target
            Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0);

            if (!target || target == me->getVictim())
                target = SelectTarget(SELECT_TARGET_TOPAGGRO, 1);

            if (target)
                me->TauntApply(target);

            Knockaway_Timer = 23000;
        }
        else
            Knockaway_Timer -= diff;

        //Countercharge_Timer
        if (Countercharge_Timer <= diff)
        {
            DoCast(me, SPELL_COUNTERCHARGE);
            Countercharge_Timer = 45000;
        }
        else
            Countercharge_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
void AddSC_the_eye()
{
    RegisterCreatureAI(npc_crystalcore_devastator);
}

