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
SDName: Isle_of_Queldanas
SD%Complete: 100
SDComment: Quest support: 11524, 11525, 11532, 11533, 11542, 11543, 11541
SDCategory: Isle Of Quel'Danas
EndScriptData */

/* ContentData
npc_converted_sentry
npc_greengill_slave
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

/*######
## npc_converted_sentry
######*/
class npc_converted_sentry : public CreatureScript
{
public:
    npc_converted_sentry() : CreatureScript("npc_converted_sentry") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_converted_sentryAI (creature);
    }

    struct npc_converted_sentryAI : public ScriptedAI
    {
        npc_converted_sentryAI(Creature* creature) : ScriptedAI(creature) {}

        bool Credit;
        uint32 Timer;

        void Reset()
        {
            Credit = false;
            Timer = 2500;
        }

        void MoveInLineOfSight(Unit* /*who*/) {}
        void EnterCombat(Unit* /*who*/) {}

        void UpdateAI(uint32 diff)
        {
            if (!Credit)
            {
                if (Timer <= diff)
                {
                    uint32 i = urand(1, 2);
                    if (i == 1)
                        Talk(0);
                    else
                        Talk(1);

                    DoCast(me, 45009, false);

                    if (me->isPet())
                        me->ToPet()->SetDuration(7500);
                    Credit = true;
                } else Timer -= diff;
            }
        }
    };
};

/*######
## npc_greengill_slave
######*/

#define ENRAGE  45111
#define ORB     45109
#define QUESTG  11541
#define DM      25060

class npc_greengill_slave : public CreatureScript
{
public:
    npc_greengill_slave() : CreatureScript("npc_greengill_slave") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_greengill_slaveAI(creature);
    }

    struct npc_greengill_slaveAI : public ScriptedAI
    {
        npc_greengill_slaveAI(Creature* creature) : ScriptedAI(creature) {}

        ObjectGuid PlayerGUID;

        void EnterCombat(Unit* /*who*/){}

        void Reset()
        {
            PlayerGUID.Clear();
        }

        void SpellHit(Unit* caster, const SpellInfo* spell)
        {
            if (!caster)
                return;

            if (caster->GetTypeId() == TYPEID_PLAYER && spell->Id == ORB && !me->HasAura(ENRAGE))
            {
                PlayerGUID = caster->GetGUID();
                if (PlayerGUID)
                {
                    Player* player = Unit::GetPlayer(*me, PlayerGUID);
                    if (player && player->GetQuestStatus(QUESTG) == QUEST_STATUS_INCOMPLETE)
                        DoCast(player, 45110, true);
                }
                DoCast(me, ENRAGE);
                Unit* Myrmidon = me->FindNearestCreature(DM, 70);
                if (Myrmidon)
                {
                    me->AddThreat(Myrmidon, 100000.0f);
                    AttackStart(Myrmidon);
                }
            }
        }

        void UpdateAI(uint32 /*diff*/)
        {
            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_isle_of_queldanas()
{
    new npc_converted_sentry();
    new npc_greengill_slave();
}
