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
SDName: Boss_Landslide
SD%Complete: 100
SDComment:
SDCategory: Maraudon
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_KNOCKAWAY         = 18670,
    SPELL_TRAMPLE           = 5568,
    SPELL_LANDSLIDE         = 21808
};

class boss_landslide : public CreatureScript
{
public:
    boss_landslide() : CreatureScript("boss_landslide") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_landslideAI(creature);
    }

    struct boss_landslideAI : public ScriptedAI
    {
        boss_landslideAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            KnockAwayTimer = 8000;
            TrampleTimer = 2000;
            LandslideTimer = 0;
        }

        uint32 KnockAwayTimer;
        uint32 TrampleTimer;
        uint32 LandslideTimer;

        void Reset()
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //KnockAwayTimer
            if (KnockAwayTimer <= diff)
            {
                DoCastVictim(SPELL_KNOCKAWAY);
                KnockAwayTimer = 15000;
            }
            else KnockAwayTimer -= diff;

            //TrampleTimer
            if (TrampleTimer <= diff)
            {
                DoCast(me, SPELL_TRAMPLE);
                TrampleTimer = 8000;
            }
            else TrampleTimer -= diff;

            //Landslide
            if (HealthBelowPct(50))
            {
                if (LandslideTimer <= diff)
                {
                    me->InterruptNonMeleeSpells(false);
                    DoCast(me, SPELL_LANDSLIDE);
                    LandslideTimer = 60000;
                }
                else LandslideTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_landslide()
{
    new boss_landslide();
}
