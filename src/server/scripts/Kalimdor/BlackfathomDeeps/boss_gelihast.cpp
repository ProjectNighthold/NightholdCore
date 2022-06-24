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
#include "blackfathom_deeps.h"

enum Spells
{
    SPELL_NET                                              = 6533
};

class boss_gelihast : public CreatureScript
{
public:
    boss_gelihast() : CreatureScript("boss_gelihast") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_gelihastAI (creature);
    }

    struct boss_gelihastAI : public ScriptedAI
    {
        boss_gelihastAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 netTimer;

        InstanceScript* instance;

        void Reset()
        {
            netTimer = urand(2000, 4000);
            if (instance)
                instance->SetData(TYPE_GELIHAST, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (instance)
                instance->SetData(TYPE_GELIHAST, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
                instance->SetData(TYPE_GELIHAST, DONE);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (netTimer < diff)
            {
                DoCastVictim(SPELL_NET);
                netTimer = urand(4000, 7000);
            } else netTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_gelihast()
{
    new boss_gelihast();
}
