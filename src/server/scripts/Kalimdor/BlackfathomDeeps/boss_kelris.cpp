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
    SPELL_MIND_BLAST                                       = 15587,
    SPELL_SLEEP                                            = 8399,
};

//Id's from ACID
enum Yells
{
    SAY_AGGRO                                              = 2,
    SAY_SLEEP                                              = 1,
    SAY_DEATH                                              = 0
};

class boss_kelris : public CreatureScript
{
public:
    boss_kelris() : CreatureScript("boss_kelris") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_kelrisAI (creature);
    }

    struct boss_kelrisAI : public ScriptedAI
    {
        boss_kelrisAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 mindBlastTimer;
        uint32 sleepTimer;

        InstanceScript* instance;

        void Reset()
        {
            mindBlastTimer = urand(2000, 5000);
            sleepTimer = urand(9000, 12000);

            if (instance)
                instance->SetData(TYPE_KELRIS, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);

            if (instance)
                instance->SetData(TYPE_KELRIS, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(TYPE_KELRIS, DONE);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (mindBlastTimer < diff)
            {
                DoCastVictim(SPELL_MIND_BLAST);
                mindBlastTimer = urand(7000, 9000);
            } else mindBlastTimer -= diff;

            if (sleepTimer < diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                {
                    Talk(SAY_SLEEP);
                    DoCast(target, SPELL_SLEEP);
                }
                sleepTimer = urand(15000, 20000);
            } else sleepTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_kelris()
{
    new boss_kelris();
}
