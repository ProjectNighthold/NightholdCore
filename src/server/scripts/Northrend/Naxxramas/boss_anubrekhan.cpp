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

#define SAY_GREET           RAND(-1533000,-1533004,-1533005,-1533006,-1533007)
#define SAY_AGGRO           RAND(-1533001,-1533002,-1533003)
#define SAY_SLAY                -1533008
#define EMOTE_INSECT_SWARM      -1533154
#define EMOTE_CORPSE_SCARABS    -1533155
#define EMOTE_CRYPT_GUARD       -1533153

#define MOB_CRYPT_GUARD     16573

const Position GuardSummonPos = {3333.72f, -3476.30f, 287.1f, 6.2801f};

enum Events
{
    EVENT_NONE,
    EVENT_IMPALE,
    EVENT_LOCUST,
    EVENT_SPAWN_GUARDIAN_NORMAL,
    EVENT_BERSERK,
};

enum Spells
{
    SPELL_IMPALE_10                 = 28783,
    SPELL_IMPALE_25                 = 56090,
    SPELL_LOCUST_SWARM_10           = 28785,
    SPELL_LOCUST_SWARM_25           = 54021,
    SPELL_SUMMON_CORPSE_SCARABS_PLR = 29105,    // This spawns 5 corpse scarabs on top of player
    SPELL_SUMMON_CORPSE_SCARABS_MOB = 28864,   // This spawns 10 corpse scarabs on top of dead guards
    SPELL_BERSERK                   = 27680,
};

enum
{
    ACHIEV_TIMED_START_EVENT                      = 9891,
};

class boss_anubrekhan : public CreatureScript
{
public:
    boss_anubrekhan() : CreatureScript("boss_anubrekhan") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new boss_anubrekhanAI (pCreature);
    }

    struct boss_anubrekhanAI : public BossAI
    {
        boss_anubrekhanAI(Creature *c) : BossAI(c, BOSS_ANUBREKHAN) {}

        bool hasTaunted;

        void Reset() override
        {
            _Reset();

            hasTaunted = false;

            if (GetDifficultyID() == DIFFICULTY_25_N)
            {
                Position pos;

                // respawn guard using home position,
                // otherwise, after a wipe, they respawn where boss was at wipe moment.
                pos = me->GetHomePosition();
                pos.m_positionY -= 10.0f;
                me->SummonCreature(MOB_CRYPT_GUARD, pos, TEMPSUMMON_CORPSE_DESPAWN);

                pos = me->GetHomePosition();
                pos.m_positionY += 10.0f;
                me->SummonCreature(MOB_CRYPT_GUARD, pos, TEMPSUMMON_CORPSE_DESPAWN);
            }
        }

        void KilledUnit(Unit* victim) override
        {
            //Force the player to spawn corpse scarabs via spell, TODO: Check percent chance for scarabs, 20% at the moment
            if (!(rand()%5))
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    victim->CastSpell(victim, SPELL_SUMMON_CORPSE_SCARABS_PLR, true, NULL, NULL, me->GetGUID());

            DoScriptText(SAY_SLAY, me);
        }

        void JustDied(Unit *) override
        {
            _JustDied();

            // start achievement timer (kill Maexna within 20 min)
            if (instance)
                instance->DoStartTimedAchievement(CRITERIA_TIMED_TYPE_EVENT2, ACHIEV_TIMED_START_EVENT);
        }
        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            DoScriptText(SAY_AGGRO, me);
            events.ScheduleEvent(EVENT_IMPALE, 10000 + rand()%10000);
            events.ScheduleEvent(EVENT_LOCUST, 90000);
            events.ScheduleEvent(EVENT_BERSERK, 600000);

            if (GetDifficultyID() == DIFFICULTY_10_N)
                events.ScheduleEvent(EVENT_SPAWN_GUARDIAN_NORMAL, urand(15000,20000));
        }

        void MoveInLineOfSight(Unit *who) override
        {
            if (!hasTaunted && me->IsWithinDistInMap(who, 60.0f) && who->GetTypeId() == TYPEID_PLAYER)
            {
                DoScriptText(SAY_GREET, me);
                hasTaunted = true;
            }
            ScriptedAI::MoveInLineOfSight(who);
        }

        void JustSummoned(Creature* summon) override
        {
            BossAI::JustSummoned(summon);
            if (summon && instance && instance->GetBossState(BOSS_ANUBREKHAN) == IN_PROGRESS)
                DoScriptText(EMOTE_CRYPT_GUARD, summon);
        }

        void SummonedCreatureDespawn(Creature *summon) override
        {
            BossAI::SummonedCreatureDespawn(summon);

            // check if it is an actual killed guard
            if (!me->isAlive() || summon->isAlive() || summon->GetEntry() != MOB_CRYPT_GUARD)
                return;

            summon->CastSpell(summon, SPELL_SUMMON_CORPSE_SCARABS_MOB, true, NULL, NULL, me->GetGUID());
            DoScriptText(EMOTE_CORPSE_SCARABS, me);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || !CheckInRoom())
                return;

            if (me->IsNonMeleeSpellCast(false))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_IMPALE:
                        //Cast Impale on a random target
                        //Do NOT cast it when we are afflicted by locust swarm
                        if (!me->HasAura(RAID_MODE(SPELL_LOCUST_SWARM_10,SPELL_LOCUST_SWARM_25)))
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(pTarget, RAID_MODE(SPELL_IMPALE_10,SPELL_IMPALE_25));
                        events.ScheduleEvent(EVENT_IMPALE, urand(10000,20000));
                        break;
                    case EVENT_LOCUST:
                        DoScriptText(EMOTE_INSECT_SWARM, me);
                        DoCast(me, RAID_MODE(SPELL_LOCUST_SWARM_10,SPELL_LOCUST_SWARM_25));
                        DoSummon(MOB_CRYPT_GUARD, GuardSummonPos, 0, TEMPSUMMON_CORPSE_DESPAWN);
                        events.ScheduleEvent(EVENT_LOCUST, 90000);
                        break;
                    case EVENT_SPAWN_GUARDIAN_NORMAL:
                        DoSummon(MOB_CRYPT_GUARD, GuardSummonPos, 0, TEMPSUMMON_CORPSE_DESPAWN);
                        break;
                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK, true);
                        events.ScheduleEvent(EVENT_BERSERK, 600000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_anubrekhan()
{
    new boss_anubrekhan();
}
