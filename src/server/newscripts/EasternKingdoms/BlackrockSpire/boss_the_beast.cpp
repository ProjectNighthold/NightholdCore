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
    SPELL_FLAMEBREAK                = 16785,
    SPELL_IMMOLATE                  = 20294,
    SPELL_TERRIFYINGROAR            = 14100,
};

enum Events
{
    EVENT_FLAME_BREAK              = 1,
    EVENT_IMMOLATE                 = 2,
    EVENT_TERRIFYING_ROAR          = 3,
};

class boss_the_beast : public CreatureScript
{
public:
    boss_the_beast() : CreatureScript("boss_the_beast") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_thebeastAI(creature);
    }

    struct boss_thebeastAI : public BossAI
    {
        boss_thebeastAI(Creature* creature) : BossAI(creature, DATA_THE_BEAST) {}

        void Reset()
        {
            _Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.RescheduleEvent(EVENT_FLAME_BREAK,     12 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_IMMOLATE,         3 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_TERRIFYING_ROAR, 23 * IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/)
        {
            _JustDied();
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
                    case EVENT_FLAME_BREAK:
                        DoCast(me->getVictim(), SPELL_FLAMEBREAK);
                        events.RescheduleEvent(EVENT_FLAME_BREAK, 10 * IN_MILLISECONDS);
                        break;
                    case EVENT_IMMOLATE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_IMMOLATE);
                        events.RescheduleEvent(EVENT_IMMOLATE, 8 * IN_MILLISECONDS);
                        break;
                    case EVENT_TERRIFYING_ROAR:
                        DoCast(me->getVictim(), SPELL_TERRIFYINGROAR);
                        events.RescheduleEvent(EVENT_TERRIFYING_ROAR, 20 * IN_MILLISECONDS);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_thebeast()
{
    new boss_the_beast();
}
