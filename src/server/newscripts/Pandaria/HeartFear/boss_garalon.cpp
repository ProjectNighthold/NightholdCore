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

#include "heart_of_fear.h"

enum eSpells
{
    SPELL_FURIOUS_SWIPE     = 122735, //Cleave
    SPELL_PHEROMONES        = 123100, 
    SPELL_PHEROMONES_B      = 122835,
    SPELL_PHEROMONES_TRAIL  = 123106,
    SPELL_FURY              = 122754,
    SPELL_CRUSH             = 122774,
};

enum eEvents
{
    EVENT_FURIOUS_SWIPE     = 1,
    EVENT_CHECK_HIT_SWIPE   = 2,

    ACHIEVEMENT,
};

class boss_garalon : public CreatureScript
{
    public:
        boss_garalon() : CreatureScript("boss_garalon") {}

        struct boss_garalonAI : public BossAI
        {
            boss_garalonAI(Creature* creature) : BossAI(creature, DATA_GARALON)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            uint8 hitcount;
            bool legnotdied = true;

            void Reset() override
            {
                _Reset();
                hitcount = 0;
                legnotdied = true;
                me->SetReactState(REACT_DEFENSIVE);
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == ACHIEVEMENT)
                    return legnotdied ? 1 : 0;
                return 0;
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
            {
                if (summon->GetEntry() == 63053)
                    legnotdied = false;
            }

            void EnterCombat(Unit* who) override
            {
                _EnterCombat();
                events.RescheduleEvent(EVENT_FURIOUS_SWIPE, urand(20000, 30000));
            }
            
            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                if (target->GetTypeId() == TYPEID_PLAYER && spell->Id == SPELL_FURIOUS_SWIPE)
                    hitcount++;
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_FURIOUS_SWIPE:
                        if (me->getVictim())
                            DoCast(me->getVictim(), SPELL_FURIOUS_SWIPE);
                        events.RescheduleEvent(EVENT_CHECK_HIT_SWIPE, 3000);
                        events.RescheduleEvent(EVENT_FURIOUS_SWIPE, urand(20000, 30000));
                        break;
                    case EVENT_CHECK_HIT_SWIPE:
                        if (hitcount < 2)
                            DoCast(me, SPELL_FURY);
                        hitcount = 0;
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_garalonAI(creature);
        }
};

class achievement_like_an_arrow_to_the_face : public AchievementCriteriaScript
{
public:
    achievement_like_an_arrow_to_the_face() : AchievementCriteriaScript("achievement_like_an_arrow_to_the_face") { }

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        if (!target)
            return false;

        if (Creature* boss = target->ToCreature())
            if (boss->GetAI()->GetData(ACHIEVEMENT))
                return true;

        return false;
    }
};

void AddSC_boss_garalon()
{
    new boss_garalon();
    new achievement_like_an_arrow_to_the_face();
}
