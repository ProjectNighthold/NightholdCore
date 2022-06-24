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

#include "naxxramas.h"

enum Spells
{
    SPELL_HATEFUL_STRIKE                        = 41926,
    H_SPELL_HATEFUL_STRIKE                      = 59192,
    SPELL_FRENZY                                = 28131,
    SPELL_BERSERK                               = 26662,
    SPELL_SLIME_BOLT                            = 32309,
};

enum Yells
{
    SAY_AGGRO_1                                 = -1533017,
    SAY_AGGRO_2                                 = -1533018,
    SAY_SLAY                                    = -1533019,
    SAY_DEATH                                   = -1533020,
    EMOTE_BERSERK                               = -1533021,
    EMOTE_ENRAGE                                = -1533022,
};

enum Events
{
    EVENT_NONE,
    EVENT_BERSERK,
    EVENT_HATEFUL,
    EVENT_SLIME
};

enum
{
    ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT  = 10286,
};

class boss_patchwerk : public CreatureScript
{
public:
    boss_patchwerk() : CreatureScript("boss_patchwerk") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_patchwerkAI (creature);
    }

    struct boss_patchwerkAI : public BossAI
    {
        boss_patchwerkAI(Creature* c) : BossAI(c, BOSS_PATCHWERK) {}

        bool Enraged;

        void Reset() override
        {
            _Reset();

            if (instance)
                instance->DoStopTimedAchievement(CRITERIA_TIMED_TYPE_EVENT2, ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT);
        }

        void KilledUnit(Unit* /*Victim*/) override
        {
            if (!(rand()%5))
                DoScriptText(SAY_SLAY, me);
        }

        void JustDied(Unit* /*Killer*/) override
        {
            _JustDied();
            DoScriptText(SAY_DEATH, me);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Enraged = false;
            DoScriptText(RAND(SAY_AGGRO_1, SAY_AGGRO_2), me);
            events.ScheduleEvent(EVENT_HATEFUL, 1200);
            events.ScheduleEvent(EVENT_BERSERK, 360000);

            if (instance)
                instance->DoStartTimedAchievement(CRITERIA_TIMED_TYPE_EVENT2, ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_HATEFUL:
                    {
                        //Cast Hateful strike on the player with the highest
                        //amount of HP within melee distance
                        // uint32 MostHP = 0;
                        // Unit* pMostHPTarget = NULL;
                        // std::list<HostileReference*>::const_iterator i = me->getThreatManager().getThreatList().begin();
                        // for (; i != me->getThreatManager().getThreatList().end(); ++i)
                        // {
                            // Unit* target = (*i)->getTarget();
                            // if (target->isAlive() && target != me->getVictim() && target->GetHealth() > MostHP && me->IsWithinMeleeRange(target))
                            // {
                                // MostHP = target->GetHealth();
                                // pMostHPTarget = target;
                            // }
                        // }

                        Unit* pMostHPTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                        if (!pMostHPTarget)
                            pMostHPTarget = me->getVictim();

                        DoCast(pMostHPTarget, RAID_MODE(SPELL_HATEFUL_STRIKE, H_SPELL_HATEFUL_STRIKE), true);

                        events.ScheduleEvent(EVENT_HATEFUL, 1200);
                        break;
                    }
                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK, true);
                        DoScriptText(EMOTE_BERSERK, me);
                        events.ScheduleEvent(EVENT_SLIME, 2000);
                        break;
                    case EVENT_SLIME:
                        DoCast(me->getVictim(), SPELL_SLIME_BOLT);
                        events.ScheduleEvent(EVENT_SLIME, 2000);
                        break;
                }
            }

            if (!Enraged && HealthBelowPct(5))
            {
                DoCast(me, SPELL_FRENZY, true);
                DoScriptText(EMOTE_ENRAGE, me);
                Enraged = true;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_patchwerk()
{
    new boss_patchwerk();
}
