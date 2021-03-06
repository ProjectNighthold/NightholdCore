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

#include "siege_of_the_niuzoa_temple.h"

enum eSpells
{
    SPELL_CAUSTIC_TAR    = 120269,
    SPELL_THOUSED_BLADES = 120759,
    SPELL_DASHING_STRIKE = 120789
};

enum eEvents
{
    EVENT_STRIKE         = 0,
    EVENT_BLADES         = 1
};

struct boss_commander_vojak : public BossAI
{
    explicit boss_commander_vojak(Creature* creature) : BossAI(creature, NPC_VOJAK) {}

    uint32 striketimer;
    uint32 bladetimer;

    void Reset() override
    {
        _Reset();
        striketimer = 0;
        bladetimer = 0;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        striketimer = 3000;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (striketimer <= diff)
        {
            if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                DoCast(target, SPELL_DASHING_STRIKE, false);

            striketimer = urand(8000, 10000);
            bladetimer = 2000;
        }
        else
            striketimer -= diff;

        if (bladetimer)
        {
            if (bladetimer <= diff)
            {
                bladetimer = 0;
                DoCast(SPELL_THOUSED_BLADES);
            }
            else
                bladetimer -= diff;
        }

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
    }
};

void AddSC_boss_commander_vojak()
{
    RegisterCreatureAI(boss_commander_vojak);
}
