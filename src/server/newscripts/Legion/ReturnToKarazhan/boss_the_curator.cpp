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

#include "return_to_karazhan.h"

enum Says
{
    SAY_AGGRO           = 0,
    SAY_EVOCATION       = 1,
    SAY_DEATH           = 2,
};

enum Spells
{
    SPELL_COSMETIC_MANA_DRAIN       = 228840,
    SPELL_VOLATILE_ENERGY_FILTER    = 234416,
    SPELL_VOLATILE_ENERGY           = 227267,
    SPELL_POWER_DISCHARGE_FILTER    = 227278,
    SPELL_EVOCATION                 = 227254,
    SPELL_OVERLOAD                  = 227257,

    //Volatile Energy
    SPELL_VOLATILE_ENERGY_PASSIVE   = 227268,
    SPELL_ARC_LIGHTNING             = 227270,
    SPELL_STATIC_CHARGE             = 228735,
};

enum eEvents
{
    EVENT_SUM_VOLATILE_ENERGY       = 1,
    EVENT_POWER_DISCHARGE           = 2,
    EVENT_MANA_CHECK                = 3,
};

//114247
class boss_the_curator : public CreatureScript
{
public:
    boss_the_curator() : CreatureScript("boss_the_curator") {}

    struct boss_the_curatorAI : public BossAI
    {
        boss_the_curatorAI(Creature* creature) : BossAI(creature, DATA_CURATOR)
        {
            me->GetMotionMaster()->MovePath(me->GetEntry() * 100, true);
        }

        bool phaseRegenMana;

        void Reset() override
        {
            _Reset();
            phaseRegenMana = false;
            me->SetReactState(REACT_AGGRESSIVE);
            me->SetPower(POWER_MANA, me->GetMaxPower(POWER_MANA));
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _EnterCombat();
            DoCast(me, SPELL_COSMETIC_MANA_DRAIN, true);
            DefaultEvent();

            events.RescheduleEvent(EVENT_MANA_CHECK, 500);
        }

        void DefaultEvent()
        {
            events.RescheduleEvent(EVENT_SUM_VOLATILE_ENERGY, 6000);
            events.RescheduleEvent(EVENT_POWER_DISCHARGE, 13000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            
            Map::PlayerList const& players = me->GetMap()->GetPlayers();
            if (!players.isEmpty())
            {
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (Player* pPlayer = itr->getSource())
                        pPlayer->CastSpell(pPlayer, 232563);
                }
            }
            
            if (Creature* mediv = me->FindNearestCreature(115491, 300.0f, true))
            {
                mediv->AddDelayedEvent(5000, [mediv] () -> void
                {
                    mediv->AI()->ZoneTalk(0);
                    mediv->RemoveAura(229485);
                });
                
                mediv->AddDelayedEvent(15000, [mediv] () -> void
                {
                    mediv->AI()->ZoneTalk(1);
                    mediv->DespawnOrUnsummon(9000);
                });
            }
            if (Creature* golem = me->FindNearestCreature(114462, 300.0f, true))
            {
                golem->AddDelayedEvent(9000, [golem] () -> void
                {
                    golem->RemoveAura(229606);
                });
                
                golem->AddDelayedEvent(11000, [golem] () -> void
                {
                    golem->AI()->ZoneTalk(0);
                    golem->DespawnOrUnsummon(11000);
                });
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (CheckHomeDistToEvade(diff, 64.0f, -11096.19f, -1850.77f, 165.76f))
                return;

            if (CheckHomeDistToEvade(diff, 4.0f, -11096.19f, -1850.77f, 165.76f, true))
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SUM_VOLATILE_ENERGY:
                        DoCast(me, SPELL_VOLATILE_ENERGY_FILTER, true);
                        events.RescheduleEvent(EVENT_SUM_VOLATILE_ENERGY, 10000);
                        break;
                    case EVENT_POWER_DISCHARGE:
                        DoCast(me, SPELL_POWER_DISCHARGE_FILTER, true);
                        events.RescheduleEvent(EVENT_POWER_DISCHARGE, 14000);
                        break;
                    case EVENT_MANA_CHECK:
                        if (me->GetPowerPct(POWER_MANA) < 1.0f && !phaseRegenMana)
                        {
                            phaseRegenMana = true;
                            events.CancelEvent(EVENT_SUM_VOLATILE_ENERGY);
                            events.CancelEvent(EVENT_POWER_DISCHARGE);
                            me->StopAttack();
                            me->RemoveAurasDueToSpell(SPELL_COSMETIC_MANA_DRAIN);
                            DoCast(me, SPELL_EVOCATION, true);
                            Talk(SAY_EVOCATION);
                        }
                        else if (me->GetPowerPct(POWER_MANA) > 99.0f && phaseRegenMana)
                        {
                            phaseRegenMana = false;
                            DefaultEvent();
                            DoCast(me, SPELL_OVERLOAD, true);
                            DoCast(me, SPELL_COSMETIC_MANA_DRAIN, true);
                            me->SetReactState(REACT_AGGRESSIVE);
                        }
                        events.RescheduleEvent(EVENT_MANA_CHECK, 500);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_the_curatorAI (creature);
    }
};

//114249
class npc_curator_volatile_energy : public CreatureScript
{
public:
    npc_curator_volatile_energy() : CreatureScript("npc_curator_volatile_energy") {}

    struct npc_curator_volatile_energyAI : public ScriptedAI
    {
        npc_curator_volatile_energyAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void IsSummonedBy(Unit* summoner) override
        //47:50
        {
            DoCast(me, SPELL_VOLATILE_ENERGY_PASSIVE, true);
            events.RescheduleEvent(EVENT_1, 7000); //47:57
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_1:
                        DoCast(me, SPELL_STATIC_CHARGE, true);
                        events.RescheduleEvent(EVENT_1, 12000);
                        break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_curator_volatile_energyAI(creature);
    }
};

//227270, 227257
class spell_curator_arc_lightning : public SpellScriptLoader
{
    public:
        spell_curator_arc_lightning() : SpellScriptLoader("spell_curator_arc_lightning") {}

        class spell_curator_arc_lightning_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_curator_arc_lightning_SpellScript);

            void DealDamage()
            {
                if (!GetCaster())
                    return;

                if (Aura* aura = GetCaster()->GetAura(GetSpellInfo()->Id))
                    SetHitDamage(GetHitDamage() * (aura->GetStackAmount() + 1));
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_curator_arc_lightning_SpellScript::DealDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_curator_arc_lightning_SpellScript();
        }
};

//50
class eventobject_karazhan_library : public EventObjectScript
{
public:
    eventobject_karazhan_library() : EventObjectScript("eventobject_karazhan_library")
    {}

    bool IsTriggerMeets(Player* player, EventObject* eo) override
    {
        if (InstanceScript* instance = eo->GetInstanceScript())
            if (instance->GetBossState(DATA_CURATOR) == DONE)
                return true;

        return false;
    }
};

void AddSC_boss_the_curator()
{
    new boss_the_curator();
    new npc_curator_volatile_energy();
    new spell_curator_arc_lightning();
    new eventobject_karazhan_library();
}
