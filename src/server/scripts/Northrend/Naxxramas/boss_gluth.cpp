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

enum Yells
{
    EMOTE_ZOMBIE                = -1533119,
    EMOTE_DECIMATE              = -1533152
};
#define SPELL_MORTAL_WOUND      25646
#define SPELL_ENRAGE            RAID_MODE(28371, 54427)
#define SPELL_DECIMATE          RAID_MODE(28374, 54426)
#define SPELL_BERSERK           26662
#define SPELL_INFECTED_WOUND    29306
#define SPELL_INFECTED_WOUND_AURA 29307

#define MOB_ZOMBIE  16360

const Position PosSummon[3] =
{
    {3267.9f, -3172.1f, 297.42f, 0.94f},
    {3253.2f, -3132.3f, 297.42f, 0},
    {3308.3f, -3185.8f, 297.42f, 1.58f},
};

enum Events
{
    EVENT_NONE,
    EVENT_WOUND,
    EVENT_ENRAGE,
    EVENT_DECIMATE,
    EVENT_BERSERK,
    EVENT_SUMMON,
};

class boss_gluth : public CreatureScript
{
public:
    boss_gluth() : CreatureScript("boss_gluth") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_gluthAI (creature);
    }

    struct boss_gluthAI : public BossAI
    {
        boss_gluthAI(Creature* c) : BossAI(c, BOSS_GLUTH)
        {
            // Do not let Gluth be affected by zombies' debuff
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_INFECTED_WOUND, true);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetEntry() == MOB_ZOMBIE && me->IsWithinMeleeRange(who))
            {
                DoScriptText(EMOTE_ZOMBIE, me);
                if (Creature* creature = who->ToCreature())
                    creature->DisappearAndDie();
                me->ModifyHealth(me->CountPctFromMaxHealth(5));
            }
            else
                BossAI::MoveInLineOfSight(who);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_WOUND, 10000);
            events.ScheduleEvent(EVENT_ENRAGE, 15000);
            events.ScheduleEvent(EVENT_DECIMATE, 105000);
            events.ScheduleEvent(EVENT_BERSERK, 8*60000);
            events.ScheduleEvent(EVENT_SUMMON, 15000);
        }

        void JustSummoned(Creature* summon) override
        {
            if (summon->GetEntry() == MOB_ZOMBIE)
            {
                summon->AddAura(SPELL_INFECTED_WOUND_AURA, summon);
                summon->AI()->AttackStart(me);
            }
            summons.Summon(summon);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictimWithGaze() || !CheckInRoom())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WOUND:
                        DoCast(me->getVictim(), SPELL_MORTAL_WOUND);
                        events.ScheduleEvent(EVENT_WOUND, 10000);
                        break;
                    case EVENT_ENRAGE:
                        // TODO : Add missing text
                        DoCast(me, SPELL_ENRAGE);
                        events.ScheduleEvent(EVENT_ENRAGE, 15000);
                        break;
                    case EVENT_DECIMATE:
                        {
                            DoScriptText(EMOTE_DECIMATE, me);
                            DoCastAOE(SPELL_DECIMATE);
                            events.ScheduleEvent(EVENT_DECIMATE, 105000);
                        }
                        break;
                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK);
                        events.ScheduleEvent(EVENT_BERSERK, 5*60000);
                        break;
                    case EVENT_SUMMON:
                        for (int32 i = 0; i < RAID_MODE(1, 2); ++i)
                            DoSummon(MOB_ZOMBIE, PosSummon[rand() % RAID_MODE(1, 3)]);
                        events.ScheduleEvent(EVENT_SUMMON, 10000);
                        break;
                }
            }

            DoMeleeAttackIfReady();

            EnterEvadeIfOutOfCombatArea(diff);
        }
    };

};

void AddSC_boss_gluth()
{
    new boss_gluth();
}
