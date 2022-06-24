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

enum Say
{
    SAY_AGGRO               = 0,
    SAY_LEASH               = 1
};

enum Spells
{
    SPELL_CLEAVE            = 26350,
    SPELL_BLASTWAVE         = 23331,
    SPELL_MORTALSTRIKE      = 24573,
    SPELL_KNOCKBACK         = 25778
};

enum Events
{
    EVENT_CLEAVE            = 1,
    EVENT_BLASTWAVE         = 2,
    EVENT_MORTALSTRIKE      = 3,
    EVENT_KNOCKBACK         = 4,
    EVENT_CHECK             = 5
};

class boss_broodlord : public CreatureScript
{
public:
    boss_broodlord() : CreatureScript("boss_broodlord") { }

    struct boss_broodlordAI : public BossAI
    {
        boss_broodlordAI(Creature* creature) : BossAI(creature, BOSS_BROODLORD) { }

        void EnterCombat(Unit* /*who*/)
        {
            if (instance->GetBossState(BOSS_VAELASTRAZ) != DONE)
            {
                EnterEvadeMode();
                return;
            }

            _EnterCombat();
            Talk(SAY_AGGRO);

            events.RescheduleEvent(EVENT_CLEAVE, 8000);
            events.RescheduleEvent(EVENT_BLASTWAVE, 12000);
            events.RescheduleEvent(EVENT_MORTALSTRIKE, 20000);
            events.RescheduleEvent(EVENT_KNOCKBACK, 30000);
            events.RescheduleEvent(EVENT_CHECK, 1000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.RescheduleEvent(EVENT_CLEAVE, 7000);
                        break;
                    case EVENT_BLASTWAVE:
                        DoCastVictim(SPELL_BLASTWAVE);
                        events.RescheduleEvent(EVENT_BLASTWAVE, urand(8000, 16000));
                        break;
                    case EVENT_MORTALSTRIKE:
                        DoCastVictim(SPELL_MORTALSTRIKE);
                        events.RescheduleEvent(EVENT_MORTALSTRIKE, urand(25000, 35000));
                        break;
                    case EVENT_KNOCKBACK:
                        DoCastVictim(SPELL_KNOCKBACK);
                        if (DoGetThreat(me->getVictim()))
                            DoModifyThreatPercent(me->getVictim(), -50);
                        events.RescheduleEvent(EVENT_KNOCKBACK, urand(15000, 30000));
                        break;
                    case EVENT_CHECK:
                        if (me->GetDistance(me->GetHomePosition()) > 150.0f)
                        {
                            Talk(SAY_LEASH);
                            EnterEvadeMode();
                        }
                        events.RescheduleEvent(EVENT_CHECK, 1000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return GetInstanceAI<boss_broodlordAI>(creature);
    }
};

void AddSC_boss_broodlord()
{
    new boss_broodlord();
}
