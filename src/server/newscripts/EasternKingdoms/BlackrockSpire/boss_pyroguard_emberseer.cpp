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

enum Text
{
    EMOTE_ONE_STACK                 = 0,
    EMOTE_TEN_STACK                 = 1,
    EMOTE_FREE_OF_BONDS             = 2,
    YELL_FREE_OF_BONDS              = 3,
};

enum Spells
{
    SPELL_ENCAGED_EMBERSEER         = 15282, // Self on spawn
    SPELL_FIRE_SHIELD_TRIGGER       = 13377, // Self on spawn missing from 335 dbc
    SPELL_FREEZE_ANIM               = 16245, // Self on event start
    SPELL_EMBERSEER_GROWING         = 16048, // Self on event start
    SPELL_EMBERSEER_FULL_STRENGTH   = 16047, // Emberseer Full Strength
    SPELL_FIRENOVA                  = 23462, // Combat
    SPELL_FLAMEBUFFET               = 23341, // Combat
    SPELL_PYROBLAST                 = 17274, // Combat
};

enum Events
{
    EVENT_FIRENOVA                  = 1,
    EVENT_FLAMEBUFFET               = 2,
    EVENT_PYROBLAST                 = 3,
};


class boss_pyroguard_emberseer : public CreatureScript
{
public:
    boss_pyroguard_emberseer() : CreatureScript("boss_pyroguard_emberseer") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_pyroguard_emberseerAI(creature);
    }

    struct boss_pyroguard_emberseerAI : public BossAI
    {
        boss_pyroguard_emberseerAI(Creature* creature) : BossAI(creature, DATA_PYROGAURD_EMBERSEER) {}

        void Reset()
        {
            if (instance->GetBossState(DATA_PYROGAURD_EMBERSEER) == IN_PROGRESS)
                OpenDoors(false);
            instance->SetBossState(DATA_PYROGAURD_EMBERSEER,NOT_STARTED);
            // respawn any dead Blackhand Incarcerators
            DoCast(me, SPELL_ENCAGED_EMBERSEER);
            //DoCast(me, SPELL_FIRE_SHIELD_TRIGGER);
            _Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.RescheduleEvent(EVENT_FIRENOVA,    6 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_FLAMEBUFFET, 3 * IN_MILLISECONDS);
            events.RescheduleEvent(EVENT_PYROBLAST,  14 * IN_MILLISECONDS);
        }

        void JustDied(Unit* /*killer*/)
        {
            instance->SetBossState(DATA_PYROGAURD_EMBERSEER,DONE);
            OpenDoors(true);
            _JustDied();
        }

       void OpenDoors(bool Boss_Killed)
       {
           if (GameObject* door1 = me->GetMap()->GetGameObject(instance->GetGuidData(GO_EMBERSEER_IN)))
               door1->SetGoState(GO_STATE_ACTIVE);
           if (GameObject* door2 = me->GetMap()->GetGameObject(instance->GetGuidData(GO_DOORS)))
               door2->SetGoState(GO_STATE_ACTIVE);
           if (Boss_Killed)
               if (GameObject* door3 = me->GetMap()->GetGameObject(instance->GetGuidData(GO_EMBERSEER_OUT)))
                    door3->SetGoState(GO_STATE_ACTIVE);
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
                    case EVENT_FIRENOVA:
                        DoCast(me->getVictim(), SPELL_FIRENOVA);
                        events.RescheduleEvent(EVENT_FIRENOVA, 6 * IN_MILLISECONDS);
                        break;
                    case EVENT_FLAMEBUFFET:
                        DoCast(me->getVictim(), SPELL_FLAMEBUFFET);
                        events.RescheduleEvent(EVENT_FLAMEBUFFET, 14 * IN_MILLISECONDS);
                        break;
                    case EVENT_PYROBLAST:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_PYROBLAST);
                        events.RescheduleEvent(EVENT_PYROBLAST, 15 * IN_MILLISECONDS);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_pyroguard_emberseer()
{
    new boss_pyroguard_emberseer();
}
