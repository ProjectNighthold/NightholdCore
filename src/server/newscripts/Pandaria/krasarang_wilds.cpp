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

#include "ScriptedEscortAI.h"

enum eArnessSpells
{
    SPELL_GRAPPLING_HOOK    = 125623,
    SPELL_VANISH            = 125632,
    SPELL_VICIOUS_REND        = 125624,
};

enum eArnessEvents
{
    EVENT_GRAPPLING_HOOK        = 1,
    EVENT_VANISH                = 2,
    EVENT_VICIOUS_REND            = 3,
};

class mob_arness_the_scale : public CreatureScript
{
    public:
        mob_arness_the_scale() : CreatureScript("mob_arness_the_scale")
        { 
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_arness_the_scaleAI(creature);
        }

        struct mob_arness_the_scaleAI : public ScriptedAI
        {
            mob_arness_the_scaleAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();
                
                events.RescheduleEvent(EVENT_GRAPPLING_HOOK,  40000);
                events.RescheduleEvent(EVENT_VANISH,            20000);
                events.RescheduleEvent(EVENT_VICIOUS_REND,    15000);
            }

            void JustDied(Unit* /*killer*/)
            {
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
                

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GRAPPLING_HOOK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_GRAPPLING_HOOK, false);
                            events.RescheduleEvent(EVENT_GRAPPLING_HOOK,      10000);
                            break;
                        case EVENT_VANISH:
                            me->CastSpell(me, SPELL_VANISH, false);
                            events.RescheduleEvent(EVENT_VANISH, 20000);
                            break;
                        case EVENT_VICIOUS_REND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_VICIOUS_REND, false);
                            events.RescheduleEvent(EVENT_VICIOUS_REND, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

void AddSC_krasarang_wilds()
{
    new mob_arness_the_scale();
}