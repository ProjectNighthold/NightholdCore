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
SDName: Thunder_Bluff
SD%Complete: 100
SDComment: Quest support: 925
SDCategory: Thunder Bluff
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

/*#####
# npc_cairne_bloodhoof
######*/

enum CairneBloodhoof
{
    SPELL_BERSERKER_CHARGE  = 16636,
    SPELL_CLEAVE            = 16044,
    SPELL_MORTAL_STRIKE     = 16856,
    SPELL_THUNDERCLAP       = 23931,
    SPELL_UPPERCUT          = 22916
};

#define GOSSIP_HCB "I know this is rather silly but a young ward who is a bit shy would like your hoofprint."
//TODO: verify abilities/timers
class npc_cairne_bloodhoof : public CreatureScript
{
public:
    npc_cairne_bloodhoof() : CreatureScript("npc_cairne_bloodhoof") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_cairne_bloodhoofAI (creature);
    }

    struct npc_cairne_bloodhoofAI : public ScriptedAI
    {
        npc_cairne_bloodhoofAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 BerserkerChargeTimer;
        uint32 CleaveTimer;
        uint32 MortalStrikeTimer;
        uint32 ThunderclapTimer;
        uint32 UppercutTimer;

        void Reset()
        {
            BerserkerChargeTimer = 30000;
            CleaveTimer = 5000;
            MortalStrikeTimer = 10000;
            ThunderclapTimer = 15000;
            UppercutTimer = 10000;
        }

        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (BerserkerChargeTimer <= diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                if (target)
                    DoCast(target, SPELL_BERSERKER_CHARGE);
                BerserkerChargeTimer = 25000;
            } else BerserkerChargeTimer -= diff;

            if (UppercutTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_UPPERCUT);
                UppercutTimer = 20000;
            } else UppercutTimer -= diff;

            if (ThunderclapTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_THUNDERCLAP);
                ThunderclapTimer = 15000;
            } else ThunderclapTimer -= diff;

            if (MortalStrikeTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MORTAL_STRIKE);
                MortalStrikeTimer = 15000;
            } else MortalStrikeTimer -= diff;

            if (CleaveTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CLEAVE);
                CleaveTimer = 7000;
            } else CleaveTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_thunder_bluff()
{
    new npc_cairne_bloodhoof();
}
