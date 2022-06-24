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

/* ScriptData
SDName: Boss_Gatewatcher_Ironhand
SD%Complete: 75
SDComment:
SDCategory: Tempest Keep, The Mechanar
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mechanar.h"

enum Says
{
    SAY_AGGRO                      = 0,
    SAY_HAMMER                     = 1,
    SAY_SLAY                       = 2,
    SAY_DEATH                      = 3,
    EMOTE_HAMMER                   = 4
};

enum Spells
{
    SPELL_SHADOW_POWER             = 35322,
    H_SPELL_SHADOW_POWER           = 39193,
    SPELL_HAMMER_PUNCH             = 35326,
    SPELL_JACKHAMMER               = 35327,
    H_SPELL_JACKHAMMER             = 39194,
    SPELL_STREAM_OF_MACHINE_FLUID  = 35311
};

enum Events
{
    EVENT_STREAM_OF_MACHINE_FLUID   = 1,
    EVENT_JACKHAMMER                = 2,
    EVENT_SHADOW_POWER              = 3
};

class boss_gatewatcher_iron_hand : public CreatureScript
{
    public:
        boss_gatewatcher_iron_hand(): CreatureScript("boss_gatewatcher_iron_hand") { }

        struct boss_gatewatcher_iron_handAI : public BossAI
        {
            boss_gatewatcher_iron_handAI(Creature* creature) : BossAI(creature, DATA_GATEWATCHER_IRON_HAND) { }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_STREAM_OF_MACHINE_FLUID, 55000);
                events.ScheduleEvent(EVENT_JACKHAMMER, 45000);
                events.ScheduleEvent(EVENT_SHADOW_POWER, 25000);
                Talk(SAY_AGGRO);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                if (roll_chance_i(50))
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STREAM_OF_MACHINE_FLUID:
                            DoCastVictim(SPELL_STREAM_OF_MACHINE_FLUID, true);
                            events.ScheduleEvent(EVENT_STREAM_OF_MACHINE_FLUID, urand(35000, 50000));
                            break;
                        case EVENT_JACKHAMMER:
                            Talk(EMOTE_HAMMER);
                            /// @todo expect cast this about 5 times in a row (?), announce it by emote only once
                            DoCastVictim(SPELL_JACKHAMMER, true);
                            if (roll_chance_i(50))
                                Talk(SAY_HAMMER);
                            events.ScheduleEvent(EVENT_JACKHAMMER, 30000);
                            break;
                        case EVENT_SHADOW_POWER:
                            DoCast(me, SPELL_SHADOW_POWER);
                            events.ScheduleEvent(EVENT_SHADOW_POWER, urand(20000, 28000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_gatewatcher_iron_handAI(creature);
        }
};

void AddSC_boss_gatewatcher_iron_hand()
{
    new boss_gatewatcher_iron_hand();
}
