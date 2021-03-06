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
SDName: Boss_jandicebarov
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "scholomance.h"



//NPC_ILLUSION  = 59220, 

enum Spells
{
    SPELL_GRAVITY_FLUX       = 114059,
    SPELL_WONDROUS_RAPIDITY  = 114062,
};


class boss_jandice_barov : public CreatureScript
{
public:
    boss_jandice_barov() : CreatureScript("boss_jandice_barov") { }

    struct boss_jandice_barovAI : public BossAI
    {
        boss_jandice_barovAI(Creature* creature) : BossAI(creature, DATA_BAROV)
        {
            InstanceScript* instance = creature->GetInstanceScript();
            me->SetReactState(REACT_DEFENSIVE);
        }

        InstanceScript* instance;
        uint32 gravitytimer;
        uint32 rapiditytimer;

        void Reset()
        {
            _Reset();
            rapiditytimer = 0;
            gravitytimer = 0;
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            rapiditytimer = 5000;
            gravitytimer = 12000; 
        }

        void JustDied(Unit* killer)
        {
            _JustDied();
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (gravitytimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                    DoCast(target, SPELL_GRAVITY_FLUX);
                gravitytimer = 20000;
            }
            else
                gravitytimer -= diff;

            if (rapiditytimer <= diff)
            {
                if (me->getVictim())
                    DoCast(me->getVictim(), SPELL_WONDROUS_RAPIDITY);
                rapiditytimer = 10000;
            }
            else
                rapiditytimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
    
    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_jandice_barovAI (creature);
    }

};

class spell_gravity_flux : public SpellScriptLoader
{
    public:
        spell_gravity_flux() :  SpellScriptLoader("spell_gravity_flux") { }

        class spell_gravity_flux_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gravity_flux_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;
               
                if (GetTarget()->GetTypeId() == TYPEID_PLAYER)
                    GetTarget()->CastSpell(GetTarget(), 114038, true);
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_gravity_flux_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_gravity_flux_AuraScript();
        }
};

void AddSC_boss_jandice_barov()
{
    new boss_jandice_barov();
    new spell_gravity_flux();
}
