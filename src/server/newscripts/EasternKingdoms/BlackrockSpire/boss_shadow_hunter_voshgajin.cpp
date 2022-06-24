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
    SPELL_CURSEOFBLOOD              = 24673,
    SPELL_HEX                       = 16708,
    SPELL_CLEAVE                    = 20691,
};

enum Events
{
    EVENT_CURSE_OF_BLOOD            = 1,
    EVENT_HEX                       = 2,
    EVENT_CLEAVE                    = 3,
};

class boss_shadow_hunter_voshgajin : public CreatureScript
{
public:
    boss_shadow_hunter_voshgajin() : CreatureScript("boss_shadow_hunter_voshgajin") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_shadowvoshAI(creature);
    }

    struct boss_shadowvoshAI : public BossAI
    {
        boss_shadowvoshAI(Creature* creature) : BossAI(creature, DATA_SHADOW_HUNTER_VOSHGAJIN) {}

        void Reset()
        {
            _Reset();
            //DoCast(me, SPELL_ICEARMOR, true);
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.RescheduleEvent(EVENT_CURSE_OF_BLOOD, 2 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_HEX,     8 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_CLEAVE, 14 * IN_MILLISECONDS);
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
                    case EVENT_CURSE_OF_BLOOD:
                        DoCast(me->getVictim(), SPELL_CURSEOFBLOOD);
                        events.RescheduleEvent(EVENT_CURSE_OF_BLOOD, 45 * IN_MILLISECONDS);
                        break;
                    case EVENT_HEX:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_HEX);
                        events.RescheduleEvent(EVENT_HEX, 15 * IN_MILLISECONDS);
                        break;
                    case EVENT_CLEAVE:
                        DoCast(me->getVictim(), SPELL_CLEAVE);
                        events.RescheduleEvent(EVENT_CLEAVE, 7 * IN_MILLISECONDS);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_shadowvosh()
{
    new boss_shadow_hunter_voshgajin();
}
