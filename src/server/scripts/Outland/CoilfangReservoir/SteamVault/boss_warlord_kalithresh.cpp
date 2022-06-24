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
SDName: Boss_Warlord_Kalithres
SD%Complete: 65
SDComment: Contains workarounds regarding warlord's rage spells not acting as expected. Both scripts here require review and fine tuning.
SDCategory: Coilfang Resevoir, The Steamvault
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "steam_vault.h"

#define SPELL_SPELL_REFLECTION      31534
#define SPELL_IMPALE                39061
#define SPELL_WARLORDS_RAGE         37081
#define SPELL_WARLORDS_RAGE_NAGA    31543

#define SPELL_WARLORDS_RAGE_PROC    36453

class mob_naga_distiller : public CreatureScript
{
public:
    mob_naga_distiller() : CreatureScript("mob_naga_distiller") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_naga_distillerAI (creature);
    }

    struct mob_naga_distillerAI : public ScriptedAI
    {
        mob_naga_distillerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset() override
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            //hack, due to really weird spell behaviour :(
            if (instance)
            {
                if (instance->GetData(TYPE_DISTILLER) == IN_PROGRESS)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                }
            }
        }

        void EnterCombat(Unit* /*who*/) override {}

        void StartRageGen(Unit* /*caster*/)
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            DoCast(me, SPELL_WARLORDS_RAGE_NAGA, true);

            if (instance)
                instance->SetData(TYPE_DISTILLER, IN_PROGRESS);
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage, DamageEffectType /*dmgType*/) override
        {
            if (me->GetHealth() <= damage)
                if (instance)
                    instance->SetData(TYPE_DISTILLER, DONE);
        }
    };
};

class boss_warlord_kalithresh : public CreatureScript
{
public:
    boss_warlord_kalithresh() : CreatureScript("boss_warlord_kalithresh") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_warlord_kalithreshAI (creature);
    }

    struct boss_warlord_kalithreshAI : public ScriptedAI
    {
        boss_warlord_kalithreshAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 Reflection_Timer;
        uint32 Impale_Timer;
        uint32 Rage_Timer;
        bool CanRage;

        void Reset() override
        {
            Reflection_Timer = 10000;
            Impale_Timer = 7000+rand()%7000;
            Rage_Timer = 45000;
            CanRage = false;

            if (instance)
                instance->SetData(TYPE_WARLORD_KALITHRESH, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(2);

            if (instance)
                instance->SetData(TYPE_WARLORD_KALITHRESH, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(3);
        }

        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            //hack :(
            if (spell->Id == SPELL_WARLORDS_RAGE_PROC)
                if (instance)
                    if (instance->GetData(TYPE_DISTILLER) == DONE)
                        me->RemoveAurasDueToSpell(SPELL_WARLORDS_RAGE_PROC);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(4);

            if (instance)
                instance->SetData(TYPE_WARLORD_KALITHRESH, DONE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (Rage_Timer <= diff)
            {
                if (Creature* distiller = me->FindNearestCreature(17954, 100.0f))
                {
                    Talk(1);
                    DoCast(SPELL_WARLORDS_RAGE);
                    CAST_AI(mob_naga_distiller::mob_naga_distillerAI, distiller->AI())->StartRageGen(me);
                }
                Rage_Timer = 3000+rand()%15000;
            }
            else
                Rage_Timer -= diff;

            //Reflection_Timer
            if (Reflection_Timer <= diff)
            {
                DoCast(SPELL_SPELL_REFLECTION);
                Reflection_Timer = 15000+rand()%10000;
            }
            else
                Reflection_Timer -= diff;

            //Impale_Timer
            if (Impale_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_IMPALE, false);

                Impale_Timer = 7500+rand()%5000;
            }
            else
                Impale_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_warlord_kalithresh()
{
    new mob_naga_distiller();
    new boss_warlord_kalithresh();
}
