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
#include "blackwing_lair.h"

enum Spells
{
    SPELL_SHADOWFLAME           = 22539,
    SPELL_WINGBUFFET            = 23339,
    SPELL_SHADOWOFEBONROC       = 23340
};

enum Events
{
    EVENT_SHADOWFLAME           = 1,
    EVENT_WINGBUFFET            = 2,
    EVENT_SHADOWOFEBONROC       = 3
};

class boss_ebonroc : public CreatureScript
{
public:
    boss_ebonroc() : CreatureScript("boss_ebonroc") { }

    struct boss_ebonrocAI : public BossAI
    {
        boss_ebonrocAI(Creature* creature) : BossAI(creature, BOSS_EBONROC) { }

        void EnterCombat(Unit* /*who*/)
        {
            if (instance->GetBossState(BOSS_BROODLORD) != DONE)
            {
                EnterEvadeMode();
                return;
            }
            _EnterCombat();

            events.RescheduleEvent(EVENT_SHADOWFLAME, urand(10000, 20000));
            events.RescheduleEvent(EVENT_WINGBUFFET, 30000);
            events.RescheduleEvent(EVENT_SHADOWOFEBONROC, urand(8000, 10000));
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
                    case EVENT_SHADOWFLAME:
                        DoCastVictim(SPELL_SHADOWFLAME);
                        events.RescheduleEvent(EVENT_SHADOWFLAME, urand(10000, 20000));
                        break;
                    case EVENT_WINGBUFFET:
                        DoCastVictim(SPELL_WINGBUFFET);
                        events.RescheduleEvent(EVENT_WINGBUFFET, 30000);
                        break;
                    case EVENT_SHADOWOFEBONROC:
                        DoCastVictim(SPELL_SHADOWOFEBONROC);
                        events.RescheduleEvent(EVENT_SHADOWOFEBONROC, urand(8000, 10000));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetInstanceAI<boss_ebonrocAI>(creature);
    }
};

void AddSC_boss_ebonroc()
{
    new boss_ebonroc();
}
