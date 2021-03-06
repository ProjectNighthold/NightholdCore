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
SDName: Boss_Golemagg
SD%Complete: 90
SDComment: Timers need to be confirmed, Golemagg's Trust need to be checked
SDCategory: Molten Core
EndScriptData */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "molten_core.h"

enum Texts
{
    EMOTE_LOWHP             = 0,
};

enum Spells
{
    // Golemagg
    SPELL_MAGMASPLASH       = 13879,
    SPELL_PYROBLAST         = 20228,
    SPELL_EARTHQUAKE        = 19798,
    SPELL_ENRAGE            = 19953,
    SPELL_GOLEMAGG_TRUST    = 20553,

    // Core Rager
    SPELL_MANGLE            = 19820
};

enum Events
{
    EVENT_PYROBLAST     = 1,
    EVENT_EARTHQUAKE    = 2
};

class boss_golemagg : public CreatureScript
{
    public:
        boss_golemagg() : CreatureScript("boss_golemagg") {}

        struct boss_golemaggAI : public BossAI
        {
            boss_golemaggAI(Creature* creature) : BossAI(creature, BOSS_GOLEMAGG_THE_INCINERATOR) {}

            void Reset() override
            {
                BossAI::Reset();
                DoCast(me, SPELL_MAGMASPLASH, true);
            }

            void EnterCombat(Unit* victim) override
            {
                BossAI::EnterCombat(victim);
                events.RescheduleEvent(EVENT_PYROBLAST, 7000);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*dmgType*/) override
            {
                if (!HealthBelowPct(10) || me->HasAura(SPELL_ENRAGE))
                    return;

                DoCast(me, SPELL_ENRAGE, true);
                events.RescheduleEvent(EVENT_EARTHQUAKE, 3000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PYROBLAST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_PYROBLAST, false);

                            events.RescheduleEvent(EVENT_PYROBLAST, 7000);
                            break;
                        case EVENT_EARTHQUAKE:
                            if (auto victim = me->getVictim())
                                DoCast(victim, SPELL_EARTHQUAKE, false);

                            events.RescheduleEvent(EVENT_EARTHQUAKE, 3000);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_golemaggAI(creature);
        }
};

class mob_core_rager : public CreatureScript
{
    public:
        mob_core_rager() : CreatureScript("mob_core_rager") {}

        struct mob_core_ragerAI : public ScriptedAI
        {
            mob_core_ragerAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                mangleTimer = 7 * IN_MILLISECONDS;                 // These times are probably wrong
            }

            void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*dmgType*/) override
            {
                if (HealthAbovePct(50) || !instance)
                    return;

                if (Creature* pGolemagg = instance->instance->GetCreature(instance->GetGuidData(BOSS_GOLEMAGG_THE_INCINERATOR)))
                {
                    if (pGolemagg->isAlive())
                    {
                        me->AddAura(SPELL_GOLEMAGG_TRUST, me);
                        Talk(EMOTE_LOWHP);
                        me->SetFullHealth();
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                // Mangle
                if (mangleTimer <= diff)
                {
                    if (auto victim = me->getVictim())
                        DoCast(victim, SPELL_MANGLE, false);

                    mangleTimer = 10*IN_MILLISECONDS;
                }
                else
                    mangleTimer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* instance;
            uint32 mangleTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_core_ragerAI(creature);
        }
};

void AddSC_boss_golemagg()
{
    new boss_golemagg();
    new mob_core_rager();
}
