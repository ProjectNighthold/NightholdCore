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
#include "old_hillsbrad.h"

enum Says
{
    SAY_AGGRO = 3,
    SAY_SLAY,
    SAY_BREATH,
    SAY_DEATH
};

#define SPELL_SAND_BREATH           31914
#define SPELL_IMPENDING_DEATH       31916
#define SPELL_MAGIC_DISRUPTION_AURA 33834
#define SPELL_WING_BUFFET           31475

class boss_epoch_hunter : public CreatureScript
{
public:
    boss_epoch_hunter() : CreatureScript("boss_epoch_hunter") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_epoch_hunterAI (creature);
    }

    struct boss_epoch_hunterAI : public ScriptedAI
    {
        boss_epoch_hunterAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 SandBreath_Timer;
        uint32 ImpendingDeath_Timer;
        uint32 WingBuffet_Timer;
        uint32 Mda_Timer;

        void Reset()
        {
            SandBreath_Timer = urand(8000, 16000);
            ImpendingDeath_Timer = urand(25000, 30000);
            WingBuffet_Timer = 35000;
            Mda_Timer = 40000;
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);

            if (instance && instance->GetData(TYPE_THRALL_EVENT) == IN_PROGRESS)
                instance->SetData(TYPE_THRALL_PART4, DONE);
        }

        void UpdateAI(uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Sand Breath
            if (SandBreath_Timer <= diff)
            {
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);

                DoCast(me->getVictim(), SPELL_SAND_BREATH);

                Talk(SAY_BREATH);

                SandBreath_Timer = urand(10000, 20000);
            } else SandBreath_Timer -= diff;

            if (ImpendingDeath_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_IMPENDING_DEATH);
                ImpendingDeath_Timer = 25000+rand()%5000;
            } else ImpendingDeath_Timer -= diff;

            if (WingBuffet_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_WING_BUFFET);
                WingBuffet_Timer = 25000+rand()%10000;
            } else WingBuffet_Timer -= diff;

            if (Mda_Timer <= diff)
            {
                DoCast(me, SPELL_MAGIC_DISRUPTION_AURA);
                Mda_Timer = 15000;
            } else Mda_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_epoch_hunter()
{
    new boss_epoch_hunter();
}
