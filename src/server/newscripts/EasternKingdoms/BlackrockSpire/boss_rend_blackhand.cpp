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
    SPELL_WHIRLWIND                 = 26038,
    SPELL_CLEAVE                    = 20691,
    SPELL_THUNDERCLAP               = 23931, //Not sure if he cast this spell
};

enum Events
{
    EVENT_WHIRLWIND                 = 1,
    EVENT_CLEAVE                    = 2,
    EVENT_THUNDERCLAP               = 3,
};

class boss_rend_blackhand : public CreatureScript
{
public:
    boss_rend_blackhand() : CreatureScript("boss_rend_blackhand") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_rend_blackhandAI(creature);
    }

    struct boss_rend_blackhandAI : public BossAI
    {
        boss_rend_blackhandAI(Creature* creature) : BossAI(creature, DATA_WARCHIEF_REND_BLACKHAND) {}

        void Reset()
        {
            _Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.RescheduleEvent(EVENT_WHIRLWIND,  20 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_CLEAVE,      5 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_THUNDERCLAP, 9 * IN_MILLISECONDS);
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
                    case EVENT_WHIRLWIND:
                        DoCast(me->getVictim(), SPELL_WHIRLWIND);
                        events.RescheduleEvent(EVENT_WHIRLWIND, 18 * IN_MILLISECONDS);
                        break;
                    case EVENT_CLEAVE:
                        DoCast(me->getVictim(), SPELL_CLEAVE);
                        events.RescheduleEvent(EVENT_CLEAVE, 10 * IN_MILLISECONDS);
                        break;
                    case EVENT_THUNDERCLAP:
                        DoCast(me->getVictim(), SPELL_THUNDERCLAP);
                        events.RescheduleEvent(EVENT_THUNDERCLAP, 16 * IN_MILLISECONDS);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_rend_blackhand()
{
    new boss_rend_blackhand();
}
