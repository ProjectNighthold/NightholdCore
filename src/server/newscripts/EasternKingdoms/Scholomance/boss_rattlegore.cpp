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
SDName: Boss_the_ravenian
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "scholomance.h"

enum Spells
{
    SPELL_BONE_ARMOR  = 113996,
    SPELL_BONE_SPIKE  = 113999, 
    SPELL_RUSTING     = 113763,
};

class boss_rattlegore : public CreatureScript
{
public:
    boss_rattlegore() : CreatureScript("boss_rattlegore") { }

    struct boss_rattlegoreAI : public BossAI
    {
        boss_rattlegoreAI(Creature* creature) : BossAI(creature, DATA_RATTLEGORE)
        {
            InstanceScript* instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 spiketimer;

        void Reset()
        {
           _Reset();
           spiketimer = 0;
        }

        void JustDied(Unit* /*killer*/)
        {
            _JustDied();
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            spiketimer = 5000;
            if (!me->HasAura(SPELL_RUSTING))
                me->AddAura(SPELL_RUSTING, me);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (spiketimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                    DoCast(target, SPELL_BONE_SPIKE, false);
                spiketimer = 8000;
            }
            else 
                spiketimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_rattlegoreAI (creature);
    }

};

class npc_bone_pile : public CreatureScript
{
    public:
        npc_bone_pile() : CreatureScript("npc_bone_pile") {}

        struct npc_bone_pileAI : public CreatureAI
        {
            npc_bone_pileAI(Creature* creature) : CreatureAI(creature)
            {
                instance = creature->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            InstanceScript* instance;

            void Reset(){}
            
            void OnSpellClick(Unit* clicker)
            {
                if (instance)
                {
                    if (clicker->GetTypeId() == TYPEID_PLAYER && !clicker->HasAura(SPELL_BONE_ARMOR))
                        clicker->AddAura(SPELL_BONE_ARMOR, clicker);
                }
            }
            
            void EnterEvadeMode(){}

            void EnterCombat(Unit* who){}

            void UpdateAI(uint32 diff){}
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_bone_pileAI(creature);
        }
};

class spell_bone_spike : public SpellScriptLoader
{
    public:
        spell_bone_spike() : SpellScriptLoader("spell_bone_spike") { }

        class spell_bone_spike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_bone_spike_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (GetHitUnit()->HasAura(SPELL_BONE_ARMOR))
                {
                    SetHitDamage(0);
                    GetHitUnit()->RemoveAurasDueToSpell(SPELL_BONE_ARMOR);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_bone_spike_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_bone_spike_SpellScript();
        }
};

void AddSC_boss_rattlegore()
{
    new boss_rattlegore();
    new npc_bone_pile();
    new spell_bone_spike();
}
