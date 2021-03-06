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

#include "culling_of_stratholme.h"

enum corruptorData
{
    SPELL_VOID_STIKE        = 60590,
    SPELL_CORRUPTING_BLIGHT = 60588,
    SPELL_CHANNEL_VISUAL    = 31387,

    SAY_CORRUPTOR_AGGRO     = -1595045,
    SAY_CORRUPTOR_DEAD      = -1595046,
    SAY_CORRUPTOR_DESPAWN   = -1595047,

    NPC_TIME_RIFT           = 28409
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_DEATH                                   = 1,
    SAY_FAIL                                    = 2
};

class boss_infinite_corruptor : public CreatureScript
{
public:
    boss_infinite_corruptor() : CreatureScript("boss_infinite_corruptor") { }

    struct boss_infinite_corruptorAI : public ScriptedAI
    {
        boss_infinite_corruptorAI(Creature *creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            timeRift = NULL;
        }

        InstanceScript* instance;
        uint32 uiStrikeTimer;
        uint32 uiBlightTimer;
        Creature* timeRift;

        void JustReachedHome()
        {
            // Data for visual
            if (timeRift)
                timeRift->DisappearAndDie();
            timeRift = me->SummonCreature(NPC_TIME_RIFT, me->GetPositionX() - 10.0f, me->GetPositionY(), me->GetPositionZ());

            // Visual Channeling
            if(timeRift)
                me->CastSpell(timeRift, SPELL_CHANNEL_VISUAL, true);
        }

        void Reset()
        {
            JustReachedHome();

            // Starting Timers
            uiStrikeTimer = urand(1000,3000);
            uiBlightTimer = urand(5000,8000);
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->Yell(SAY_CORRUPTOR_AGGRO, LANG_UNIVERSAL, ObjectGuid::Empty);
        }

        void JustDied(Unit* /*p_Killer*/)
        {
            me->Yell(SAY_CORRUPTOR_DEAD, LANG_UNIVERSAL, ObjectGuid::Empty);
            if (instance)
                instance->SetData(DATA_INFINITE_EVENT, DONE);
        }

        void DoAction(int32 const id)
        {
            if(id == 0) // Called from InstanceScript
            {
                me->YellToZone(SAY_CORRUPTOR_DESPAWN, LANG_UNIVERSAL, ObjectGuid::Empty);
                me->DespawnOrUnsummon(1000);
            }
        }
        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if(uiStrikeTimer < uiDiff)
            {
                if(Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                   DoCast(target, SPELL_VOID_STIKE);
                uiStrikeTimer = urand(3000, 8000);
            }
            else uiStrikeTimer -= uiDiff;

            if(uiBlightTimer < uiDiff)
            {
                if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM))
                   DoCast(target, SPELL_CORRUPTING_BLIGHT);
                uiBlightTimer = urand(6000, 9000);
            }
            else uiBlightTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_infinite_corruptorAI(creature);
    }
};

void AddSC_boss_infinite_corruptor()
{
    new boss_infinite_corruptor();
}
