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
SDName: Example_Escort
SD%Complete: 100
SDComment: Script used for testing escortAI
SDCategory: Script Examples
EndScriptData */

#include "PrecompiledHeaders/ScriptPCH.h"

#define START            1

enum eEnums
{
    NPC_PATCHWERK               = 31099,

    SAY_AGGRO                  = 0,
    SAY_DEATH
};

class Loskutik : public CreatureScript
{
    public:

        Loskutik()
            : CreatureScript("Loskutik")
        {
        }

        struct LoskutikAI : public ScriptedAI
        {
            LoskutikAI(Creature* pCreature) : ScriptedAI(pCreature) {}

            void EnterCombat(Unit* /*pWho*/) override
            {
                Talk(SAY_AGGRO);
                if(me->getVictim())
                    me->AttackerStateUpdate(me->getVictim());
            }

            void EnterEvadeMode() override
            {
                me->DespawnOrUnsummon();
            }

            void JustDied(Unit* pKiller) override
            {
                Talk(SAY_DEATH);
                me->DespawnOrUnsummon();

                if (pKiller->IsPlayer())
                    pKiller->ToPlayer()->KilledMonsterCredit(31099);
            }

            void UpdateAI(uint32 uiDiff) override
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new LoskutikAI(creature);
        }
};

class Loskutik_Start : public CreatureScript
{
    public:
        Loskutik_Start() : CreatureScript("Loskutik_Start") {}

        struct Loskutik_StartAI : public ScriptedAI
        {
            // CreatureAI functions
            Loskutik_StartAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset() override {}

            void JustDied(Unit* /*who*/) override {}

            void UpdateAI(uint32 uiDiff) override {}
        };

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        player->TalkedToCreature(creature->GetEntry(), creature->GetGUID());
        player->PrepareGossipMenu(creature, 0);
        if (Creature* e = creature->FindNearestCreature(31099, 60.0f))
            return true;

        if ( player->getClass() == CLASS_DEATH_KNIGHT)
            player->ADD_GOSSIP_ITEM(0, "Start event Patchwerk!", GOSSIP_SENDER_MAIN, START);

        player->SendPreparedGossip(creature);

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
    {
        if(sender != GOSSIP_SENDER_MAIN)
        {    
            player->CLOSE_GOSSIP_MENU();
            return true;
        }

        switch(action)
        {
            case START:
                player->CLOSE_GOSSIP_MENU();
                creature->SummonCreature(31099, 2460.29f, -5593.26f, 414.122f, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000);
                break;
            default:
                return false;                                   // nothing defined      -> trinity core handling
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new Loskutik_StartAI(creature);
    }
};

void AddSC_Loskutik()
{
    new Loskutik();
    new Loskutik_Start();
}
