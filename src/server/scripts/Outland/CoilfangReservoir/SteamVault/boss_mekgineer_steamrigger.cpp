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
SDName: Boss_Mekgineer_Steamrigger
SD%Complete: 60
SDComment: Mechanics' interrrupt heal doesn't work very well, also a proper movement needs to be implemented -> summon further away and move towards target to repair.
SDCategory: Coilfang Resevoir, The Steamvault
EndScriptData */

/* ContentData
boss_mekgineer_steamrigger
mob_steamrigger_mechanic
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "steam_vault.h"

#define SPELL_SUPER_SHRINK_RAY      31485
#define SPELL_SAW_BLADE             31486
#define SPELL_ELECTRIFIED_NET       35107
#define H_SPELL_ENRAGE              1                       //corrent enrage spell not known

#define ENTRY_STREAMRIGGER_MECHANIC 17951

class boss_mekgineer_steamrigger : public CreatureScript
{
public:
    boss_mekgineer_steamrigger() : CreatureScript("boss_mekgineer_steamrigger") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_mekgineer_steamriggerAI (creature);
    }

    struct boss_mekgineer_steamriggerAI : public ScriptedAI
    {
        boss_mekgineer_steamriggerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 Shrink_Timer;
        uint32 Saw_Blade_Timer;
        uint32 Electrified_Net_Timer;
        bool Summon75;
        bool Summon50;
        bool Summon25;

        void Reset() override
        {
            Shrink_Timer = 20000;
            Saw_Blade_Timer = 15000;
            Electrified_Net_Timer = 10000;

            Summon75 = false;
            Summon50 = false;
            Summon25 = false;

            if (instance)
                instance->SetData(TYPE_MEKGINEER_STEAMRIGGER, NOT_STARTED);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(3);

            if (instance)
                instance->SetData(TYPE_MEKGINEER_STEAMRIGGER, DONE);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(2);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(1);

            if (instance)
                instance->SetData(TYPE_MEKGINEER_STEAMRIGGER, IN_PROGRESS);
        }

        //no known summon spells exist
        void SummonMechanichs()
        {
            Talk(0);

            DoSpawnCreature(ENTRY_STREAMRIGGER_MECHANIC, 5, 5, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 240000);
            DoSpawnCreature(ENTRY_STREAMRIGGER_MECHANIC, -5, 5, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 240000);
            DoSpawnCreature(ENTRY_STREAMRIGGER_MECHANIC, -5, -5, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 240000);

            if (rand()%2)
                DoSpawnCreature(ENTRY_STREAMRIGGER_MECHANIC, 5, -7, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 240000);
            if (rand()%2)
                DoSpawnCreature(ENTRY_STREAMRIGGER_MECHANIC, 7, -5, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 240000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (Shrink_Timer <= diff)
            {
                if (auto victim = me->getVictim())
                    DoCast(victim, SPELL_SUPER_SHRINK_RAY, false);

                Shrink_Timer = 20000;
            }
            else
                Shrink_Timer -= diff;

            if (Saw_Blade_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    DoCast(target, SPELL_SAW_BLADE);
                else
                    DoCast(me->getVictim(), SPELL_SAW_BLADE, false);

                Saw_Blade_Timer = 15000;
            }
            else
                Saw_Blade_Timer -= diff;

            if (Electrified_Net_Timer <= diff)
            {
                if (auto victim = me->getVictim())
                    DoCast(victim, SPELL_ELECTRIFIED_NET, false);

                Electrified_Net_Timer = 10000;
            }
            else
                Electrified_Net_Timer -= diff;

            if (!Summon75)
            {
                if (HealthBelowPct(75))
                {
                    SummonMechanichs();
                    Summon75 = true;
                }
            }

            if (!Summon50)
            {
                if (HealthBelowPct(50))
                {
                    SummonMechanichs();
                    Summon50 = true;
                }
            }

            if (!Summon25)
            {
                if (HealthBelowPct(25))
                {
                    SummonMechanichs();
                    Summon25 = true;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

#define SPELL_DISPEL_MAGIC          17201
#define SPELL_REPAIR                31532
#define H_SPELL_REPAIR              37936

#define MAX_REPAIR_RANGE            (13.0f)                 //we should be at least at this range for repair
#define MIN_REPAIR_RANGE            (7.0f)                  //we can stop movement at this range to repair but not required

class mob_steamrigger_mechanic : public CreatureScript
{
public:
    mob_steamrigger_mechanic() : CreatureScript("mob_steamrigger_mechanic") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_steamrigger_mechanicAI (creature);
    }

    struct mob_steamrigger_mechanicAI : public ScriptedAI
    {
        mob_steamrigger_mechanicAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 Repair_Timer;

        void Reset() override
        {
            Repair_Timer = 2000;
        }

        void MoveInLineOfSight(Unit* /*who*/) override
        {
            //react only if attacked
        }

        void EnterCombat(Unit* /*who*/) override {}

        void UpdateAI(uint32 diff) override
        {
            if (Repair_Timer <= diff)
            {
                if (instance && instance->GetGuidData(DATA_MEKGINEERSTEAMRIGGER) && instance->GetData(TYPE_MEKGINEER_STEAMRIGGER) == IN_PROGRESS)
                {
                    if (Unit* pMekgineer = Unit::GetUnit(*me, instance->GetGuidData(DATA_MEKGINEERSTEAMRIGGER)))
                    {
                        if (me->IsWithinDistInMap(pMekgineer, MAX_REPAIR_RANGE))
                        {
                            //are we already channeling? Doesn't work very well, find better check?
                            if (!me->GetUInt32Value(UNIT_FIELD_CHANNEL_SPELL))
                            {
                                //me->GetMotionMaster()->MovementExpired();
                                //me->GetMotionMaster()->MoveIdle();

                                DoCast(me, SPELL_REPAIR, true);
                            }
                            Repair_Timer = 5000;
                        }
                        else
                        {
                            //me->GetMotionMaster()->MovementExpired();
                            //me->GetMotionMaster()->MoveFollow(pMekgineer, 0, 0);
                        }
                    }
                }
                else
                    Repair_Timer = 5000;
            }
            else
                Repair_Timer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_mekgineer_steamrigger()
{
    new boss_mekgineer_steamrigger();
    new mob_steamrigger_mechanic();
}
