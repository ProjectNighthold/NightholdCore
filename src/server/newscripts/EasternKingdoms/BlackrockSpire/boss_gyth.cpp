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
    SPELL_CORROSIVE_ACID            = 20667,
    SPELL_FREEZE                    = 18763,
    SPELL_FLAMEBREATH               = 20712,
    SPELL_SELF_ROOT_FOREVER         = 33356,
};

enum Adds
{
    MODEL_REND_ON_DRAKE             = 9723, // TODO: use creature_template 10459 instead of its modelid
    NPC_RAGE_TALON_FIRE_TONG        = 10372,
    NPC_CHROMATIC_WHELP             = 10442,
    NPC_CHROMATIC_DRAGONSPAWN       = 10447,
    NPC_BLACKHAND_ELITE             = 10317,
};

enum Events
{
    EVENT_SUMMON_REND               = 1,
    EVENT_AGGRO                     = 2,
    EVENT_SUMMON_DRAGON_PACK        = 3,
    EVENT_SUMMON_ORC_PACK           = 4,
    EVENT_CORROSIVE_ACID            = 5,
    EVENT_FREEZE                    = 6,
    EVENT_FLAME_BREATH              = 7,
};

class boss_gyth : public CreatureScript
{
public:
    boss_gyth() : CreatureScript("boss_gyth") { }

    struct boss_gythAI : public BossAI
    {
        boss_gythAI(Creature* creature) : BossAI(creature, DATA_GYTH)
        {
            DoCast(me, SPELL_SELF_ROOT_FOREVER);
        }

        bool SummonedRend;

        void Reset()
        {
            _Reset();
            SummonedRend = false;
            //Invisible for event start
            me->SetVisible(false);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.RescheduleEvent(EVENT_SUMMON_DRAGON_PACK, 3 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_SUMMON_ORC_PACK, 60 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_AGGRO, 60 * IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/)
        {
            _JustDied();
        }

        void SummonCreatureWithRandomTarget(uint32 creatureId, uint8 count)
        {
            for (uint8 n = 0; n < count; n++)
                if (Unit* Summoned = me->SummonCreature(creatureId, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 240 * IN_MILLISECONDS))
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                        Summoned->AddThreat(target, 250.0f);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (!SummonedRend && HealthBelowPct(11))
            {
                events.RescheduleEvent(EVENT_SUMMON_REND, 8 * IN_MILLISECONDS);
                SummonedRend = true;
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SUMMON_REND:
                        // Summon Rend and Change model to normal Gyth
                        // Interrupt any spell casting
                        me->InterruptNonMeleeSpells(false);
                        // Gyth model
                        me->SetDisplayId(me->GetCreatureTemplate()->Modelid[0]);
                        me->SummonCreature(NPC_WARCHIEF_REND_BLACKHAND, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 900 * IN_MILLISECONDS);
                        events.RescheduleEvent(EVENT_CORROSIVE_ACID, 8 * IN_MILLISECONDS);
                        events.RescheduleEvent(EVENT_FREEZE, 11 * IN_MILLISECONDS);
                        events.RescheduleEvent(EVENT_FLAME_BREATH, 4 * IN_MILLISECONDS);
                        events.CancelEvent(EVENT_SUMMON_REND);
                        break;
                    case EVENT_AGGRO:
                        me->SetVisible(true);
                        me->SetDisplayId(MODEL_REND_ON_DRAKE);
                        me->setFaction(14);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        events.CancelEvent(EVENT_AGGRO);
                        break;
                    // Summon Dragon pack. 2 Dragons and 3 Whelps
                    case EVENT_SUMMON_DRAGON_PACK:
                        for (uint8 i = 0; i < urand(0, 3) + 2; ++i)
                        {
                            SummonCreatureWithRandomTarget(NPC_RAGE_TALON_FIRE_TONG, 2);
                            SummonCreatureWithRandomTarget(NPC_CHROMATIC_WHELP, 3);
                        }
                        events.CancelEvent(EVENT_SUMMON_DRAGON_PACK);
                        break;
                    // Summon Orc pack. 1 Orc Handler 1 Elite Dragonkin and 3 Whelps
                    case EVENT_SUMMON_ORC_PACK:
                        for (uint8 i = 0; i < urand (0, 5) + 2; ++i)
                        {
                            SummonCreatureWithRandomTarget(NPC_CHROMATIC_DRAGONSPAWN, 1);
                            SummonCreatureWithRandomTarget(NPC_BLACKHAND_ELITE, 1);
                            SummonCreatureWithRandomTarget(NPC_CHROMATIC_WHELP, 3);
                        }
                        events.CancelEvent(EVENT_SUMMON_ORC_PACK);
                        break;
                    case EVENT_CORROSIVE_ACID:
                        DoCast(me->getVictim(), SPELL_CORROSIVE_ACID);
                        events.RescheduleEvent(EVENT_CORROSIVE_ACID, 7 * IN_MILLISECONDS);
                        break;
                    case EVENT_FREEZE:
                        DoCast(me->getVictim(), SPELL_FREEZE);
                        events.RescheduleEvent(EVENT_FREEZE, 16 * IN_MILLISECONDS);
                        break;
                    case EVENT_FLAME_BREATH:
                        DoCast(me->getVictim(), SPELL_FLAMEBREATH);
                        events.RescheduleEvent(EVENT_FLAME_BREATH, 10500);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_gythAI(creature);
    }
};

void AddSC_boss_gyth()
{
    new boss_gyth();
}
