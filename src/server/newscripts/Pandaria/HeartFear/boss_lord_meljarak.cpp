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

#include "heart_of_fear.h"

enum eSpells
{
    //Lord Meljarak
    SPELL_RECKLESSNESS    = 122354,
    SPELL_RAIN_OF_BLADES  = 122406,

    //Zarthik spells
    SPELL_HEAL            = 122193,
    SPELL_HEAL_TR_EF      = 122147,
    SPELL_HASTE           = 122149,

    //Korthik spells
    SPELL_KORTHIK_STRIKE  = 122409, //not work 
};

enum eEvents
{
    //Lord Meljarak
    EVENT_RAIN_BLADES     = 1,

    //Soldiers
    EVENT_HEAL            = 2,
    EVENT_HASTE           = 3,
};

const AuraType auratype[6] = 
{
    SPELL_AURA_MOD_STUN,
    SPELL_AURA_MOD_FEAR,
    SPELL_AURA_MOD_CHARM,
    SPELL_AURA_MOD_CONFUSE,
    SPELL_AURA_MOD_SILENCE,
    SPELL_AURA_TRANSFORM,
};

class boss_lord_meljarak : public CreatureScript
{
    public:
        boss_lord_meljarak() : CreatureScript("boss_lord_meljarak") {}

        struct boss_lord_meljarakAI : public BossAI
        {
            boss_lord_meljarakAI(Creature* creature) : BossAI(creature, DATA_MELJARAK)
            {
                instance = creature->GetInstanceScript();
                me->SetReactState(REACT_AGGRESSIVE);
            }

            InstanceScript* instance;

            void Reset() override
            {
                _Reset();
                me->RemoveAurasDueToSpell(SPELL_RECKLESSNESS);
                me->RemoveAurasDueToSpell(SPELL_HASTE);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.RescheduleEvent(EVENT_RAIN_BLADES, 30000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_RAIN_BLADES:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            DoCast(target, SPELL_RAIN_OF_BLADES);
                        events.RescheduleEvent(EVENT_RAIN_BLADES, urand(30000, 90000));
                        break;
                    //In future must be more events
                    }
                }
                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_lord_meljarakAI(creature);
        }
};

void SendDamageSoldiers(InstanceScript* instance, Creature* caller, uint32 callerEntry, ObjectGuid callerGuid, uint32 damage)
{
    if (caller && instance)
    {
        switch (callerEntry)
        {
        case NPC_SRATHIK:
            for (uint32 n = NPC_SRATHIK_1; n <= NPC_SRATHIK_3; n++)
            {
                if (Creature* soldier = caller->GetCreature(*caller, instance->GetGuidData(n)))
                {
                    if (soldier->GetGUID() != callerGuid && soldier->isAlive())
                        soldier->SetHealth(soldier->GetHealth() - damage);
                }
            }
            break;
        case NPC_ZARTHIK:
            for (uint32 n = NPC_ZARTHIK_1; n <= NPC_ZARTHIK_3; n++)
            {
                if (Creature* soldier = caller->GetCreature(*caller, instance->GetGuidData(n)))
                {
                    if (soldier->GetGUID() != callerGuid && soldier->isAlive())
                        soldier->SetHealth(soldier->GetHealth() - damage);
                }
            }
            break;
        case NPC_KORTHIK:
            for (uint32 n = NPC_KORTHIK_1; n <= NPC_KORTHIK_3; n++)
            {
                if (Creature* soldier = caller->GetCreature(*caller, instance->GetGuidData(n)))
                {
                    if (soldier->GetGUID() != callerGuid && soldier->isAlive())
                        soldier->SetHealth(soldier->GetHealth() - damage);
                }
            }
            break;
        }
    }
}

void SendDiedSoldiers(InstanceScript* instance, Creature* caller, uint32 callerEntry, ObjectGuid callerGuid)
{
    if (caller && instance)
    {
        switch (callerEntry)
        {
        case NPC_SRATHIK:
            for (uint32 n = NPC_SRATHIK_1; n <= NPC_SRATHIK_3; n++)
            {
                if (Creature* soldier = caller->GetCreature(*caller, instance->GetGuidData(n)))
                {
                    if (soldier->GetGUID() != callerGuid && soldier->isAlive())
                        soldier->Kill(soldier, true);
                }
            }
            break;
        case NPC_ZARTHIK:
            for (uint32 n = NPC_ZARTHIK_1; n <= NPC_ZARTHIK_3; n++)
            {
                if (Creature* soldier = caller->GetCreature(*caller, instance->GetGuidData(n)))
                {
                    if (soldier->GetGUID() != callerGuid && soldier->isAlive())
                        soldier->Kill(soldier, true);
                }
            }
            break;
        case NPC_KORTHIK:
            for (uint32 n = NPC_KORTHIK_1; n <= NPC_KORTHIK_3; n++)
            {
                if (Creature* soldier = caller->GetCreature(*caller, instance->GetGuidData(n)))
                {
                    if (soldier->GetGUID() != callerGuid && soldier->isAlive())
                        soldier->Kill(soldier, true);
                }
            }
            break;
        }

        if (Creature* meljarak = caller->GetCreature(*caller, instance->GetGuidData(NPC_MELJARAK)))
        {
            if (meljarak->isAlive())
                meljarak->AddAura(SPELL_RECKLESSNESS, meljarak);
        }
    }
}

void SendHealSoldiers(InstanceScript* instance, Creature* caller, uint32 callerEntry, ObjectGuid callerGuid, uint32 modhealth)
{
    if (caller && instance)
    {
        switch (callerEntry)
        {
        case NPC_SRATHIK:
            for (uint32 n = NPC_SRATHIK_1; n <= NPC_SRATHIK_3; n++)
            {
                if (Creature* soldier = caller->GetCreature(*caller, instance->GetGuidData(n)))
                {
                    if (soldier->GetGUID() != callerGuid && soldier->isAlive())
                        soldier->SetHealth(soldier->GetHealth() + modhealth);
                }
            }
            break;
        case NPC_ZARTHIK:
            for (uint32 n = NPC_ZARTHIK_1; n <= NPC_ZARTHIK_3; n++)
            {
                if (Creature* soldier = caller->GetCreature(*caller, instance->GetGuidData(n)))
                {
                    if (soldier->GetGUID() != callerGuid && soldier->isAlive())
                        soldier->SetHealth(soldier->GetHealth() + modhealth);
                }
            }
            break;
        case NPC_KORTHIK:
            for (uint32 n = NPC_KORTHIK_1; n <= NPC_KORTHIK_3; n++)
            {
                if (Creature* soldier = caller->GetCreature(*caller, instance->GetGuidData(n)))
                {
                    if (soldier->GetGUID() != callerGuid && soldier->isAlive())
                        soldier->SetHealth(soldier->GetHealth() + modhealth);
                }
            }
            break;
        }
    }
}

class npc_generic_soldier : public CreatureScript
{
    public:
        npc_generic_soldier() : CreatureScript("npc_generic_soldier") {}

        struct npc_generic_soldierAI : public ScriptedAI
        {
            npc_generic_soldierAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                me->SetReactState(REACT_AGGRESSIVE);
            }

            InstanceScript* instance;
            EventMap events;

            void Reset() override
            {
                me->RemoveAurasDueToSpell(SPELL_HASTE);
            }
            
            void EnterCombat(Unit* attacker) override
            {
                if (instance)
                {
                    if (Creature* meljarak = me->GetCreature(*me, instance->GetGuidData(NPC_MELJARAK)))
                    {
                        if (meljarak->isAlive() && !meljarak->isInCombat())
                            meljarak->AI()->AttackStart(attacker);
                    }
                }

                switch (me->GetEntry())
                {
                case NPC_SRATHIK:
                    break;
                case NPC_ZARTHIK:
                    events.RescheduleEvent(EVENT_HEAL, urand(60000,  120000));
                    events.RescheduleEvent(EVENT_HASTE, urand(50000, 110000));
                    break;
                case NPC_KORTHIK:
                    break;
                }
            }

            void DamageTaken(Unit* attacker, uint32 &damage, DamageEffectType dmgType) override
            {
                if (damage >= me->GetHealth())
                    SendDiedSoldiers(instance, me, me->GetEntry(), me->GetGUID());
                else
                    SendDamageSoldiers(instance, me, me->GetEntry(), me->GetGUID(), damage);
            }

            bool CheckMeIsInControl()
            {
                for (uint8 n = 0; n < 6; n++)
                {
                    if (me->HasAuraType(auratype[n]))
                        return true;
                }
                return false;
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_HEAL_TR_EF)
                {
                    uint32 modhealth = me->GetMaxHealth()/4;
                    SendHealSoldiers(instance, me, me->GetEntry(), me->GetGUID(), modhealth);
                }
            }

            void FindSoldierWithLowHealt()
            {
                if (!CheckMeIsInControl())
                {
                    for (uint32 n = NPC_SRATHIK_1; n <= NPC_KORTHIK_3; n++)
                    {
                        if (Creature* soldier = me->GetCreature(*me, instance->GetGuidData(n)))
                        {
                            if (soldier->GetGUID() != me->GetGUID())
                            {
                                if (soldier->isAlive() && soldier->HealthBelowPct(75))
                                {
                                    DoCast(soldier, SPELL_HEAL);
                                    break;
                                }
                            }
                        }
                    }
                }
                events.RescheduleEvent(EVENT_HEAL, urand(60000, 120000));
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_HEAL:
                        if (instance)
                            FindSoldierWithLowHealt();
                        break;
                    case EVENT_HASTE:
                        if (!CheckMeIsInControl())
                            DoCast(me, SPELL_HASTE);
                        events.RescheduleEvent(EVENT_HASTE, urand(50000, 110000));
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_generic_soldierAI(creature);
        }
};

void AddSC_boss_lord_meljarak()
{
    new boss_lord_meljarak();
    new npc_generic_soldier();
}
