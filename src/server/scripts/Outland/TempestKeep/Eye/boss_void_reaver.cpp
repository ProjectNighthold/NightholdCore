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

#include "the_eye.h"

enum Yells
{
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1,
    SAY_DEATH                   = 2,
    SAY_POUNDING                = 3
};

enum Spells
{
    SPELL_POUNDING              = 34162,
    SPELL_ARCANE_ORB            = 34172,
    SPELL_KNOCK_AWAY            = 25778,
    SPELL_BERSERK               = 27680
};

enum Events
{
    EVENT_POUNDING              = 1,
    EVENT_ARCANE_ORB,
    EVENT_KNOCK_AWAY,
    EVENT_BERSERK
};

struct boss_void_reaver : public BossAI
{
    explicit boss_void_reaver(Creature* creature) : BossAI(creature, DATA_VOID_REAVER)
    {
        Initialize();
    }

    void Initialize()
    {
        Enraged = false;
    }

    void Reset() override
    {
        Initialize();
        _Reset();
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        DoZoneInCombat();
        _JustDied();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        Talk(SAY_AGGRO);
        _EnterCombat();

        events.ScheduleEvent(EVENT_POUNDING, 15000);
        events.ScheduleEvent(EVENT_ARCANE_ORB, 3000);
        events.ScheduleEvent(EVENT_KNOCK_AWAY, 30000);
        events.ScheduleEvent(EVENT_BERSERK, 600000);
    }

    void UpdateAI(uint32 diff) override
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
                case EVENT_POUNDING:
                    DoCastVictim(SPELL_POUNDING);
                    Talk(SAY_POUNDING);
                    events.ScheduleEvent(EVENT_POUNDING, 15000);
                    break;
                case EVENT_ARCANE_ORB:
                {
                    Unit* target = NULL;
                    std::list<HostileReference*> t_list = me->getThreatManager().getThreatList();
                    std::vector<Unit*> target_list;
                    for (std::list<HostileReference*>::const_iterator itr = t_list.begin(); itr != t_list.end(); ++itr)
                    {
                        target = ObjectAccessor::GetUnit(*me, (*itr)->getUnitGuid());
                        if (!target)
                            continue;
                        // exclude pets & totems, 18 yard radius minimum
                        if (target->GetTypeId() == TYPEID_PLAYER && target->isAlive() && !target->IsWithinDist(me, 18, false))
                            target_list.push_back(target);
                        target = NULL;
                    }

                    if (!target_list.empty())
                        target = *(target_list.begin() + rand32() % target_list.size());
                    else
                        target = me->getVictim();

                    if (target)
                        me->CastSpell(target, SPELL_ARCANE_ORB, false, NULL, NULL);

                    events.ScheduleEvent(EVENT_ARCANE_ORB, 3000);
                    break;
                }
                case EVENT_KNOCK_AWAY:
                    DoCastVictim(SPELL_KNOCK_AWAY);
                    // Drop 25% aggro
                    if (DoGetThreat(me->getVictim()))
                        DoModifyThreatPercent(me->getVictim(), -25);

                    events.ScheduleEvent(EVENT_KNOCK_AWAY, 30000);
                    break;
                case EVENT_BERSERK:
                    if (!Enraged)
                    {
                        DoCast(me, SPELL_BERSERK);
                        Enraged = true;
                    }
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
    private:
        bool Enraged;
};

void AddSC_boss_void_reaver()
{
    RegisterCreatureAI(boss_void_reaver);
}

