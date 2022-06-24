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
SDName: Boss_Baron_Geddon
SD%Complete: 100
SDComment:
SDCategory: Molten Core
EndScriptData */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "molten_core.h"

enum Spells
{
    SPELL_INFERNO       = 19695,
    SPELL_IGNITE_MANA   = 19659,
    SPELL_LIVING_BOMB   = 20475,
    SPELL_ARMAGEDDON    = 20479
};

enum Events
{
    EVENT_INFERNO       = 1,
    EVENT_IGNITE_MANA   = 2,
    EVENT_LIVING_BOMB   = 3
};

class boss_baron_geddon : public CreatureScript
{
    public:
        boss_baron_geddon() : CreatureScript("boss_baron_geddon") {}

        struct boss_baron_geddonAI : public BossAI
        {
            boss_baron_geddonAI(Creature* creature) : BossAI(creature, BOSS_BARON_GEDDON) {}

            void EnterCombat(Unit* victim) override
            {
                BossAI::EnterCombat(victim);
                events.RescheduleEvent(EVENT_INFERNO, 45000);
                events.RescheduleEvent(EVENT_IGNITE_MANA, 30000);
                events.RescheduleEvent(EVENT_LIVING_BOMB, 35000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                // If we are <2% hp cast Armageddon
                if (!HealthAbovePct(2))
                {
                    me->InterruptNonMeleeSpells(true);
                    DoCast(me, SPELL_ARMAGEDDON);
                    Talk(0);
                    return;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INFERNO:
                            DoCast(SPELL_INFERNO);
                            events.RescheduleEvent(EVENT_INFERNO, 45000);
                            break;
                        case EVENT_IGNITE_MANA:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_IGNITE_MANA))
                                DoCast(target, SPELL_IGNITE_MANA, false);

                            events.RescheduleEvent(EVENT_IGNITE_MANA, 30000);
                            break;
                        case EVENT_LIVING_BOMB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_LIVING_BOMB, false);

                            events.RescheduleEvent(EVENT_LIVING_BOMB, 35000);
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
            return new boss_baron_geddonAI (creature);
        }
};

void AddSC_boss_baron_geddon()
{
    new boss_baron_geddon();
}
