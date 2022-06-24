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
SDName: Boss_Magmadar
SD%Complete: 75
SDComment: Conflag on ground nyi
SDCategory: Molten Core
EndScriptData */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "molten_core.h"

enum Texts
{
    EMOTE_FRENZY        = 0
};

enum Spells
{
    SPELL_FRENZY        = 19451,
    SPELL_MAGMA_SPIT    = 19449,
    SPELL_PANIC         = 19408,
    SPELL_LAVA_BOMB     = 19428
};

enum Events
{
    EVENT_FRENZY        = 1,
    EVENT_PANIC         = 2,
    EVENT_LAVA_BOMB     = 3
};

class boss_magmadar : public CreatureScript
{
    public:
        boss_magmadar() : CreatureScript("boss_magmadar") {}

        struct boss_magmadarAI : public BossAI
        {
            boss_magmadarAI(Creature* creature) : BossAI(creature, BOSS_MAGMADAR) {}

            void Reset() override
            {
                BossAI::Reset();
                DoCast(me, SPELL_MAGMA_SPIT, true);
            }

            void EnterCombat(Unit* victim) override
            {
                BossAI::EnterCombat(victim);
                events.RescheduleEvent(EVENT_FRENZY, 30000);
                events.RescheduleEvent(EVENT_PANIC, 20000);
                events.RescheduleEvent(EVENT_LAVA_BOMB, 12000);
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_FRENZY:
                            Talk(EMOTE_FRENZY);
                            DoCast(SPELL_FRENZY);
                            events.RescheduleEvent(EVENT_FRENZY, 15000);
                            break;
                        case EVENT_PANIC:
                            if (auto victim = me->getVictim())
                                DoCast(victim, SPELL_PANIC, false);

                            events.RescheduleEvent(EVENT_PANIC, 35000);
                            break;
                        case EVENT_LAVA_BOMB:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_LAVA_BOMB))
                                DoCast(target, SPELL_LAVA_BOMB, false);

                            events.RescheduleEvent(EVENT_LAVA_BOMB, 12000);
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
            return new boss_magmadarAI(creature);
        }
};

void AddSC_boss_magmadar()
{
    new boss_magmadar();
}
