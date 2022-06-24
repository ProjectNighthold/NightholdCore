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
    SPELL_WARSTOMP                  = 24375,
    SPELL_CLEAVE                    = 15579,
    SPELL_STRIKE                    = 18368,
    SPELL_REND                      = 18106,
    SPELL_SUNDERARMOR               = 24317,
    SPELL_KNOCKAWAY                 = 20686,
    SPELL_SLOW                      = 22356,
};

enum Events
{
    EVENT_WARSTOMP                  = 1,
    EVENT_CLEAVE                    = 2,
    EVENT_STRIKE                    = 3,
    EVENT_REND                      = 4,
    EVENT_SUNDER_ARMOR              = 5,
    EVENT_KNOCK_AWAY                = 6,
    EVENT_SLOW                      = 7,
};

class boss_highlord_omokk : public CreatureScript
{
public:
    boss_highlord_omokk() : CreatureScript("boss_highlord_omokk") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_highlordomokkAI(creature);
    }

    struct boss_highlordomokkAI : public BossAI
    {
        boss_highlordomokkAI(Creature* creature) : BossAI(creature, DATA_OMOKK) {}

        void Reset()
        {
            _Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.RescheduleEvent(EVENT_WARSTOMP, 15 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_CLEAVE,    6 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_STRIKE,   10 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_REND,     14 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_SUNDER_ARMOR, 2 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_KNOCK_AWAY,  18 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_SLOW, 24 * IN_MILLISECONDS);
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
                    case EVENT_WARSTOMP:
                        DoCast(me->getVictim(), SPELL_WARSTOMP);
                        events.RescheduleEvent(EVENT_WARSTOMP, 14 * IN_MILLISECONDS);
                        break;
                    case EVENT_CLEAVE:
                        DoCast(me->getVictim(), SPELL_CLEAVE);
                        events.RescheduleEvent(EVENT_CLEAVE, 8 * IN_MILLISECONDS);
                        break;
                    case EVENT_STRIKE:
                        DoCast(me->getVictim(), SPELL_STRIKE);
                        events.RescheduleEvent(EVENT_STRIKE, 10 * IN_MILLISECONDS);
                        break;
                    case EVENT_REND:
                        DoCast(me->getVictim(), SPELL_REND);
                        events.RescheduleEvent(EVENT_REND, 18 * IN_MILLISECONDS);
                        break;
                    case EVENT_SUNDER_ARMOR:
                        DoCast(me->getVictim(), SPELL_SUNDERARMOR);
                        events.RescheduleEvent(EVENT_SUNDER_ARMOR, 25 * IN_MILLISECONDS);
                        break;
                    case EVENT_KNOCK_AWAY:
                        DoCast(me->getVictim(), SPELL_KNOCKAWAY);
                        events.RescheduleEvent(EVENT_KNOCK_AWAY, 12 * IN_MILLISECONDS);
                        break;
                    case EVENT_SLOW:
                        DoCast(me->getVictim(), SPELL_SLOW);
                        events.RescheduleEvent(EVENT_SLOW, 18 * IN_MILLISECONDS);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_highlordomokk()
{
    new boss_highlord_omokk();
}
