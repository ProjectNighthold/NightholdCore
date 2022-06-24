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
SDName: Silvermoon_City
SD%Complete: 100
SDComment: Quest support: 9685
SDCategory: Silvermoon City
EndScriptData */

/* ContentData
npc_blood_knight_stillblade
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

/*#######
# npc_blood_knight_stillblade
#######*/
enum eStillbladeData
{
    SAY_HEAL                    = 0,

    QUEST_REDEEMING_THE_DEAD    = 9685,
    SPELL_SHIMMERING_VESSEL     = 31225,
    SPELL_REVIVE_SELF           = 32343
};

class npc_blood_knight_stillblade : public CreatureScript
{
public:
    npc_blood_knight_stillblade() : CreatureScript("npc_blood_knight_stillblade") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_blood_knight_stillbladeAI (creature);
    }

    struct npc_blood_knight_stillbladeAI : public ScriptedAI
    {
        npc_blood_knight_stillbladeAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 lifeTimer = 120000;
        bool spellHit = false;

        void Reset() override
        {
            lifeTimer = 120000;
            me->SetStandState(UNIT_STAND_STATE_DEAD);
            me->SetUInt32Value(UNIT_FIELD_BYTES_1, 7);   // lay down
            spellHit = false;
        }

        void EnterCombat(Unit* /*who*/) override {}

        void MoveInLineOfSight(Unit* /*who*/) override {}

        void UpdateAI(uint32 diff) override
        {
            if (me->IsStandState())
            {
                if (lifeTimer <= diff)
                    me->AI()->EnterEvadeMode();
                else
                    lifeTimer -= diff;
            }
        }

        void SpellHit(Unit* Hitter, const SpellInfo* Spellkind) override
        {
            if ((Spellkind->Id == SPELL_SHIMMERING_VESSEL) && !spellHit &&
                (Hitter->IsPlayer()) && (CAST_PLR(Hitter)->GetQuestStatus(QUEST_REDEEMING_THE_DEAD) == QUEST_STATUS_INCOMPLETE))
            {
                CAST_PLR(Hitter)->AreaExploredOrEventHappens(QUEST_REDEEMING_THE_DEAD);
                DoCast(me, SPELL_REVIVE_SELF);
                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->SetUInt32Value(OBJECT_FIELD_DYNAMIC_FLAGS, 0);
                Talk(SAY_HEAL);
                spellHit = true;
            }
        }
    };
};

void AddSC_silvermoon_city()
{
    new npc_blood_knight_stillblade();
}
