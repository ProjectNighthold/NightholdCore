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

enum Spells
{
    SPELL_FIERYBURST                                       = 13900,
    SPELL_WARSTOMP                                         = 24375
};

enum eEnums
{
    DATA_THRONE_DOOR                                       = 24 // not id or guid of doors but number of enum in blackrock_depths.h
};

class boss_magmus : public CreatureScript
{
public:
    boss_magmus() : CreatureScript("boss_magmus") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_magmusAI (creature);
    }

    struct boss_magmusAI : public ScriptedAI
    {
        boss_magmusAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 FieryBurst_Timer;
        uint32 WarStomp_Timer;

        void Reset()
        {
            FieryBurst_Timer = 5000;
            WarStomp_Timer =0;
        }

        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //FieryBurst_Timer
            if (FieryBurst_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FIERYBURST);
                FieryBurst_Timer = 6000;
            } else FieryBurst_Timer -= diff;

            //WarStomp_Timer
            if (HealthBelowPct(51))
            {
                if (WarStomp_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_WARSTOMP);
                    WarStomp_Timer = 8000;
                } else WarStomp_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
        // When he die open door to last chamber
        void JustDied(Unit* killer)
        {
            if (InstanceScript* instance = killer->GetInstanceScript())
                instance->HandleGameObject(instance->GetGuidData(DATA_THRONE_DOOR), true);
        }
    };
};

void AddSC_boss_magmus()
{
    new boss_magmus();
}
