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
#include "arena_of_annihilation.h"

enum Says
{
    SAY_WARN_RAGE   = 0,
};

enum Spells
{
    SPELL_SLAM         = 123934,
    SPELL_HEADBUTT     = 123931,
    SPELL_ANGRY        = 123936,
};

enum Events
{
    EVENT_POINT_HOME    = 1,
    EVENT_SLAM          = 2,
    EVENT_HEADBUTT      = 3,
};

class boss_jolgrum : public CreatureScript
{
public:
    boss_jolgrum() : CreatureScript("boss_jolgrum") { }

    struct boss_jolgrumAI : public BossAI
    {
        boss_jolgrumAI(Creature* creature) : BossAI(creature, DATA_JOLGRUM)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset() override
        {
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
            me->setPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            events.RescheduleEvent(EVENT_POINT_HOME, 2000);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.RescheduleEvent(EVENT_JUMP, 30000);
            events.RescheduleEvent(EVENT_HEADBUTT, 8000);
        }

        void EnterEvadeMode() override
        {
            _Reset();
            me->DespawnOrUnsummon();
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == 1)
            {
                if (GameObject* pGo = instance->instance->GetGameObject(instance->GetGuidData(DATA_DOOR)))
                    pGo->SetGoState(GO_STATE_READY);
                me->HandleEmoteCommand(EMOTE_ONESHOT_BATTLE_ROAR);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->SetReactState(REACT_AGGRESSIVE);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && me->isInCombat())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_POINT_HOME:
                        if (GameObject* pGo = instance->instance->GetGameObject(instance->GetGuidData(DATA_DOOR)))
                            pGo->SetGoState(GO_STATE_ACTIVE);
                        me->GetMotionMaster()->MovePoint(1, centerPos);
                        break;
                    case EVENT_JUMP:
                        me->StopAttack();
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveJump(centerPos.GetPositionX(), centerPos.GetPositionY(), centerPos.GetPositionZ(), 30.f, 15.f);
                        events.RescheduleEvent(EVENT_JUMP, 20000);
                        events.RescheduleEvent(EVENT_SLAM, 2000);
                        break;
                    case EVENT_SLAM:
                        DoCast(SPELL_SLAM);
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    case EVENT_HEADBUTT:
                        if (Unit* target = me->getVictim())
                            DoCast(target, SPELL_HEADBUTT);
                        events.RescheduleEvent(EVENT_HEADBUTT, 17000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_jolgrumAI (creature);
    }
};

class spell_jolgrum_ill_tempered : public SpellScriptLoader
{
    public:
        spell_jolgrum_ill_tempered() : SpellScriptLoader("spell_jolgrum_ill_tempered") { }
 
        class spell_jolgrum_ill_tempered_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_jolgrum_ill_tempered_AuraScript)

            void OnPeriodic(AuraEffect const* aurEff)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                if (caster->isMoving() && caster->isInCombat())
                {
                    uint32 power = caster->GetPower(POWER_ENERGY);
                    caster->SetPower(POWER_ENERGY, power + 5);
                    if (power >= 100)
                    {
                        caster->SetPower(POWER_ENERGY, 0);
                        caster->CastSpell(caster, SPELL_ANGRY);
                        if (caster && caster->ToCreature())
                            caster->ToCreature()->AI()->Talk(SAY_WARN_RAGE);
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_jolgrum_ill_tempered_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_jolgrum_ill_tempered_AuraScript();
        }
};

void AddSC_boss_jolgrum()
{
    new boss_jolgrum();
    new spell_jolgrum_ill_tempered();
}
