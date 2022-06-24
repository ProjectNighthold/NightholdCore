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
    SPELL_SNAPKICK                  = 15618,
    SPELL_CLEAVE                    = 15579,
    SPELL_UPPERCUT                  = 10966,
    SPELL_MORTALSTRIKE              = 16856,
    SPELL_PUMMEL                    = 15615,
    SPELL_THROWAXE                  = 16075,
};

enum Events
{
    EVENT_SNAP_KICK                 = 1,
    EVENT_CLEAVE                    = 2,
    EVENT_UPPERCUT                  = 3,
    EVENT_MORTAL_STRIKE             = 4,
    EVENT_PUMMEL                    = 5,
    EVENT_THROW_AXE                 = 6,
};

class boss_warmaster_voone : public CreatureScript
{
public:
    boss_warmaster_voone() : CreatureScript("boss_warmaster_voone") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_warmastervooneAI(creature);
    }

    struct boss_warmastervooneAI : public BossAI
    {
        boss_warmastervooneAI(Creature* creature) : BossAI(creature, DATA_WARMASTER_VOONE) {}

        void Reset()
        {
            _Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.RescheduleEvent(EVENT_SNAP_KICK, 8 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_CLEAVE,   14 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_UPPERCUT, 20 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_MORTAL_STRIKE, 12 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_PUMMEL,   32 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_THROW_AXE, 1 * IN_MILLISECONDS);
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
                    case EVENT_SNAP_KICK:
                        DoCast(me->getVictim(), SPELL_SNAPKICK);
                        events.RescheduleEvent(EVENT_SNAP_KICK, 6 * IN_MILLISECONDS);
                        break;
                    case EVENT_CLEAVE:
                        DoCast(me->getVictim(), SPELL_CLEAVE);
                        events.RescheduleEvent(EVENT_CLEAVE, 12 * IN_MILLISECONDS);
                        break;
                    case EVENT_UPPERCUT:
                        DoCast(me->getVictim(), SPELL_UPPERCUT);
                        events.RescheduleEvent(EVENT_UPPERCUT, 14 * IN_MILLISECONDS);
                        break;
                    case EVENT_MORTAL_STRIKE:
                        DoCast(me->getVictim(), SPELL_MORTALSTRIKE);
                        events.RescheduleEvent(EVENT_MORTAL_STRIKE, 10 * IN_MILLISECONDS);
                        break;
                    case EVENT_PUMMEL:
                        DoCast(me->getVictim(), SPELL_PUMMEL);
                        events.RescheduleEvent(EVENT_MORTAL_STRIKE, 16 * IN_MILLISECONDS);
                        break;
                    case EVENT_THROW_AXE:
                        DoCast(me->getVictim(), SPELL_THROWAXE);
                        events.RescheduleEvent(EVENT_THROW_AXE, 8 * IN_MILLISECONDS);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_warmastervoone()
{
    new boss_warmaster_voone();
}
