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
#include "blackrock_spire.h"

enum Spells
{
    SPELL_CRYSTALIZE                = 16104,
    SPELL_MOTHERSMILK               = 16468,
    SPELL_SUMMON_SPIRE_SPIDERLING   = 16103,
};

enum Events
{
    EVENT_CRYSTALIZE                = 1,
    EVENT_MOTHERS_MILK              = 2,
};

class boss_mother_smolderweb : public CreatureScript
{
public:
    boss_mother_smolderweb() : CreatureScript("boss_mother_smolderweb") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_mothersmolderwebAI(creature);
    }

    struct boss_mothersmolderwebAI : public BossAI
    {
        boss_mothersmolderwebAI(Creature* creature) : BossAI(creature, DATA_MOTHER_SMOLDERWEB) {}

        void Reset()
        {
            _Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.RescheduleEvent(EVENT_CRYSTALIZE,   20 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_MOTHERS_MILK, 10 * IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/)
        {
            _JustDied();
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage, DamageEffectType dmgType)
        {
            if (me->GetHealth() <= damage)
                DoCast(me, SPELL_SUMMON_SPIRE_SPIDERLING, true);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CRYSTALIZE:
                        DoCast(me, SPELL_CRYSTALIZE);
                        events.RescheduleEvent(EVENT_CRYSTALIZE, 15 * IN_MILLISECONDS);
                        break;
                    case EVENT_MOTHERS_MILK:
                        DoCast(me, SPELL_MOTHERSMILK);
                        events.RescheduleEvent(EVENT_MOTHERS_MILK, urand(5 * IN_MILLISECONDS, 12500));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_mothersmolderweb()
{
    new boss_mother_smolderweb();
}
