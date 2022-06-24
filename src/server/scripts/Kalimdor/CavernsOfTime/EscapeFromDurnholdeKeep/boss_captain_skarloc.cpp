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
SDName: Boss_Captain_Skarloc
SD%Complete: 75
SDComment: Missing adds, missing waypoints to move up to Thrall once spawned + speech before enter combat.
SDCategory: Caverns of Time, Old Hillsbrad Foothills
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "old_hillsbrad.h"

enum Says
{
    SAY_ENTER   = 0,
    SAY_TAUNT,
    SAY_SLAY,
    SAY_DEATH
};

#define SPELL_HOLY_LIGHT            29427
#define SPELL_CLEANSE               29380
#define SPELL_HAMMER_OF_JUSTICE     13005
#define SPELL_HOLY_SHIELD           31904
#define SPELL_DEVOTION_AURA         8258
#define SPELL_CONSECRATION          38385

class boss_captain_skarloc : public CreatureScript
{
public:
    boss_captain_skarloc() : CreatureScript("boss_captain_skarloc") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_captain_skarlocAI (creature);
    }

    struct boss_captain_skarlocAI : public ScriptedAI
    {
        boss_captain_skarlocAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 Holy_Light_Timer;
        uint32 Cleanse_Timer;
        uint32 HammerOfJustice_Timer;
        uint32 HolyShield_Timer;
        uint32 DevotionAura_Timer;
        uint32 Consecration_Timer;

        void Reset()
        {
            Holy_Light_Timer = urand(20000, 30000);
            Cleanse_Timer = 10000;
            HammerOfJustice_Timer = urand(20000, 35000);
            HolyShield_Timer = 240000;
            DevotionAura_Timer = 3000;
            Consecration_Timer = 8000;
        }

        void EnterCombat(Unit* /*who*/)
        {
            //This is not correct. Should taunt Thrall before engage in combat
            Talk(SAY_TAUNT);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);

            if (instance && instance->GetData(TYPE_THRALL_EVENT) == IN_PROGRESS)
                instance->SetData(TYPE_THRALL_PART1, DONE);
        }

        void UpdateAI(uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Holy_Light
            if (Holy_Light_Timer <= diff)
            {
                DoCast(me, SPELL_HOLY_LIGHT);
                Holy_Light_Timer = 30000;
            } else Holy_Light_Timer -= diff;

            //Cleanse
            if (Cleanse_Timer <= diff)
            {
                DoCast(me, SPELL_CLEANSE);
                Cleanse_Timer = 10000;
            } else Cleanse_Timer -= diff;

            //Hammer of Justice
            if (HammerOfJustice_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_HAMMER_OF_JUSTICE);
                HammerOfJustice_Timer = 60000;
            } else HammerOfJustice_Timer -= diff;

            //Holy Shield
            if (HolyShield_Timer <= diff)
            {
                DoCast(me, SPELL_HOLY_SHIELD);
                HolyShield_Timer = 240000;
            } else HolyShield_Timer -= diff;

            //Devotion_Aura
            if (DevotionAura_Timer <= diff)
            {
                DoCast(me, SPELL_DEVOTION_AURA);
                DevotionAura_Timer = urand(45000, 55000);
            } else DevotionAura_Timer -= diff;

            //Consecration
            if (Consecration_Timer <= diff)
            {
                //DoCast(me->getVictim(), SPELL_CONSECRATION);
                Consecration_Timer = urand(5000, 10000);
            } else Consecration_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_captain_skarloc()
{
    new boss_captain_skarloc();
}
