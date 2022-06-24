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
SDName: Boss_Majordomo_Executus
SD%Complete: 30
SDComment: Correct spawning and Event NYI
SDCategory: Molten Core
EndScriptData */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "molten_core.h"

enum Texts
{
    SAY_AGGRO           = 0,
    SAY_SPAWN           = 1,
    SAY_SLAY            = 2,
    SAY_SPECIAL         = 3,
    SAY_DEFEAT          = 4,
    SAY_SUMMON_MAJ      = 5,
    SAY_ARRIVAL2_MAJ    = 6

    //SAY_ARRIVAL1_RAG    = -1409009,
    //SAY_ARRIVAL3_RAG    = -1409011,
    //SAY_ARRIVAL5_RAG    = -1409012,
};

enum Spells
{
    SPELL_MAGIC_REFLECTION  = 20619,
    SPELL_DAMAGE_REFLECTION = 21075,
    SPELL_BLAST_WAVE        = 20229,
    SPELL_AEGIS_OF_RAGNAROS = 20620,
    SPELL_TELEPORT          = 20618,
    SPELL_SUMMON_RAGNAROS   = 19774,
};

#define GOSSIP_HELLO 4995
#define GOSSIP_SELECT "Tell me more."

enum Events
{
    EVENT_MAGIC_REFLECTION  = 1,
    EVENT_DAMAGE_REFLECTION = 2,
    EVENT_BLAST_WAVE        = 3,
    EVENT_TELEPORT          = 4,

    EVENT_OUTRO_1           = 5,
    EVENT_OUTRO_2           = 6,
    EVENT_OUTRO_3           = 7
};

class boss_majordomo : public CreatureScript
{
    public:
        boss_majordomo() : CreatureScript("boss_majordomo") {}

        struct boss_majordomoAI : public BossAI
        {
            boss_majordomoAI(Creature* creature) : BossAI(creature, BOSS_MAJORDOMO_EXECUTUS) {}

            void KilledUnit(Unit* /*victim*/) override
            {
                if (urand(0, 99) < 25)
                    Talk(SAY_SLAY);
            }

            void EnterCombat(Unit* who) override
            {
                BossAI::EnterCombat(who);
                Talk(SAY_AGGRO);
                events.RescheduleEvent(EVENT_MAGIC_REFLECTION, 30000);
                events.RescheduleEvent(EVENT_DAMAGE_REFLECTION, 15000);
                events.RescheduleEvent(EVENT_BLAST_WAVE, 10000);
                events.RescheduleEvent(EVENT_TELEPORT, 20000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (instance && instance->GetBossState(BOSS_MAJORDOMO_EXECUTUS) != DONE)
                {
                    if (!UpdateVictim())
                        return;

                    events.Update(diff);

                    if (!me->FindNearestCreature(NPC_FLAMEWAKER_HEALER, 100.0f) && !me->FindNearestCreature(NPC_FLAMEWAKER_ELITE, 100.0f))
                    {
                        me->GetMap()->UpdateEncounterState(ENCOUNTER_CREDIT_KILL_CREATURE, me->GetEntry(), me, me);
                        me->setFaction(35);
                        me->AI()->EnterEvadeMode();
                        Talk(SAY_DEFEAT);
                        _JustDied();
                        events.RescheduleEvent(EVENT_OUTRO_1, 32000);
                        return;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    if (HealthBelowPct(50))
                        DoCast(me, SPELL_AEGIS_OF_RAGNAROS, true);

                    if (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_MAGIC_REFLECTION:
                                DoCast(SPELL_MAGIC_REFLECTION);
                                events.RescheduleEvent(EVENT_MAGIC_REFLECTION, 30000);
                                break;
                            case EVENT_DAMAGE_REFLECTION:
                                DoCast(SPELL_DAMAGE_REFLECTION);
                                events.RescheduleEvent(EVENT_DAMAGE_REFLECTION, 30000);
                                break;
                            case EVENT_BLAST_WAVE:
                                if (auto victim = me->getVictim())
                                    DoCast(victim, SPELL_BLAST_WAVE, false);

                                events.RescheduleEvent(EVENT_BLAST_WAVE, 10000);
                                break;
                            case EVENT_TELEPORT:
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                                    DoCast(target, SPELL_TELEPORT, false);

                                events.RescheduleEvent(EVENT_TELEPORT, 20000);
                                break;
                            default:
                                break;
                        }
                    }
                    DoMeleeAttackIfReady();
                }
                else
                {
                    events.Update(diff);

                    if (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_OUTRO_1:
                                me->NearTeleportTo(RagnarosTelePos.GetPositionX(), RagnarosTelePos.GetPositionY(), RagnarosTelePos.GetPositionZ(), RagnarosTelePos.GetOrientation());
                                me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                                break;
                            case EVENT_OUTRO_2:
                                if (instance)
                                    instance->instance->SummonCreature(NPC_RAGNAROS, RagnarosSummonPos);
                                break;
                            case EVENT_OUTRO_3:
                                Talk(SAY_ARRIVAL2_MAJ);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }

            void DoAction(int32 const action) override
            {
                if (action == ACTION_START_RAGNAROS)
                {
                    me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    Talk(SAY_SUMMON_MAJ);
                    events.RescheduleEvent(EVENT_OUTRO_2, 8000);
                    events.RescheduleEvent(EVENT_OUTRO_3, 24000);
                }
                else if (action == ACTION_START_RAGNAROS_ALT)
                {
                    me->setFaction(35);
                    me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                }
            }
        };

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(GOSSIP_HELLO, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
        {
            player->CLOSE_GOSSIP_MENU();
            creature->AI()->DoAction(ACTION_START_RAGNAROS);
            return true;
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_majordomoAI(creature);
        }
};

void AddSC_boss_majordomo()
{
    new boss_majordomo();
}
