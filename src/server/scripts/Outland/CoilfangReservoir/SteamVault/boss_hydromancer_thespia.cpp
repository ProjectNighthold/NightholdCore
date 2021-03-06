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
SDName: Boss_Hydromancer_Thespia
SD%Complete: 80
SDComment: Needs additional adjustments (when instance script is adjusted)
SDCategory: Coilfang Resevoir, The Steamvault
EndScriptData */

/* ContentData
boss_hydromancer_thespia
mob_coilfang_waterelemental
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "steam_vault.h"

enum Says
{
    SAY_SUMMON = 0,
    SAY_AGGRO,
    SAY_SLAY,
    SAY_DEAD
};

#define SPELL_LIGHTNING_CLOUD       25033
#define SPELL_LUNG_BURST            31481
#define SPELL_ENVELOPING_WINDS      31718

#define SPELL_WATER_BOLT_VOLLEY     34449
#define H_SPELL_WATER_BOLT_VOLLEY   37924

class boss_hydromancer_thespia : public CreatureScript
{
public:
    boss_hydromancer_thespia() : CreatureScript("boss_hydromancer_thespia") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_thespiaAI (creature);
    }

    struct boss_thespiaAI : public ScriptedAI
    {
        boss_thespiaAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 LightningCloud_Timer;
        uint32 LungBurst_Timer;
        uint32 EnvelopingWinds_Timer;

        void Reset() override
        {
            LightningCloud_Timer = 15000;
            LungBurst_Timer = 7000;
            EnvelopingWinds_Timer = 9000;

            if (instance)
                instance->SetData(TYPE_HYDROMANCER_THESPIA, NOT_STARTED);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEAD);

            if (instance)
                instance->SetData(TYPE_HYDROMANCER_THESPIA, DONE);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_SLAY);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);

            if (instance)
                instance->SetData(TYPE_HYDROMANCER_THESPIA, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            //LightningCloud_Timer
            if (LightningCloud_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_LIGHTNING_CLOUD, false);

                //cast twice in Heroic mode
                if (IsHeroic())
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_LIGHTNING_CLOUD, false);

                LightningCloud_Timer = 15000+rand()%10000;
            }
            else
                LightningCloud_Timer -=diff;

            //LungBurst_Timer
            if (LungBurst_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_LUNG_BURST, false);

                LungBurst_Timer = 7000+rand()%5000;
            }
            else
                LungBurst_Timer -=diff;

            //EnvelopingWinds_Timer
            if (EnvelopingWinds_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_ENVELOPING_WINDS, false);

                //cast twice in Heroic mode
                if (IsHeroic())
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_ENVELOPING_WINDS, false);

                EnvelopingWinds_Timer = 10000+rand()%5000;
            }
            else
                EnvelopingWinds_Timer -=diff;

            DoMeleeAttackIfReady();
        }
    };

};

class mob_coilfang_waterelemental : public CreatureScript
{
public:
    mob_coilfang_waterelemental() : CreatureScript("mob_coilfang_waterelemental") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_coilfang_waterelementalAI (creature);
    }

    struct mob_coilfang_waterelementalAI : public ScriptedAI
    {
        mob_coilfang_waterelementalAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 WaterBoltVolley_Timer;

        void Reset() override
        {
            WaterBoltVolley_Timer = 3000+rand()%3000;
        }

        void EnterCombat(Unit* /*who*/) override {}

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (WaterBoltVolley_Timer <= diff)
            {
                DoCast(SPELL_WATER_BOLT_VOLLEY);
                WaterBoltVolley_Timer = 7000+rand()%5000;
            }
            else
                WaterBoltVolley_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_hydromancer_thespia()
{
    new boss_hydromancer_thespia();
    new mob_coilfang_waterelemental();
}
