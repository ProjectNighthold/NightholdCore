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
    SPELL_MIGHTYBLOW                                       = 14099,
    SPELL_HAMSTRING                                        = 9080,
    SPELL_CLEAVE                                           = 20691
};

class boss_general_angerforge : public CreatureScript
{
public:
    boss_general_angerforge() : CreatureScript("boss_general_angerforge") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_general_angerforgeAI (creature);
    }

    struct boss_general_angerforgeAI : public ScriptedAI
    {
        boss_general_angerforgeAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 MightyBlow_Timer;
        uint32 HamString_Timer;
        uint32 Cleave_Timer;
        uint32 Adds_Timer;
        bool Medics;

        void Reset()
        {
            MightyBlow_Timer = 8000;
            HamString_Timer = 12000;
            Cleave_Timer = 16000;
            Adds_Timer = 0;
            Medics = false;
        }

        void EnterCombat(Unit* /*who*/) {}

        void SummonAdds(Unit* victim)
        {
            if (Creature* SummonedAdd = DoSpawnCreature(8901, float(irand(-14, 14)), float(irand(-14, 14)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120000))
                SummonedAdd->AI()->AttackStart(victim);
        }

        void SummonMedics(Unit* victim)
        {
            if (Creature* SummonedMedic = DoSpawnCreature(8894, float(irand(-9, 9)), float(irand(-9, 9)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120000))
                SummonedMedic->AI()->AttackStart(victim);
        }

        void UpdateAI(uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //MightyBlow_Timer
            if (MightyBlow_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MIGHTYBLOW);
                MightyBlow_Timer = 18000;
            } else MightyBlow_Timer -= diff;

            //HamString_Timer
            if (HamString_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_HAMSTRING);
                HamString_Timer = 15000;
            } else HamString_Timer -= diff;

            //Cleave_Timer
            if (Cleave_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CLEAVE);
                Cleave_Timer = 9000;
            } else Cleave_Timer -= diff;

            //Adds_Timer
            if (HealthBelowPct(21))
            {
                if (Adds_Timer <= diff)
                {
                    // summon 3 Adds every 25s
                    SummonAdds(me->getVictim());
                    SummonAdds(me->getVictim());
                    SummonAdds(me->getVictim());

                    Adds_Timer = 25000;
                } else Adds_Timer -= diff;
            }

            //Summon Medics
            if (!Medics && HealthBelowPct(21))
            {
                SummonMedics(me->getVictim());
                SummonMedics(me->getVictim());
                Medics = true;
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_general_angerforge()
{
    new boss_general_angerforge();
}
