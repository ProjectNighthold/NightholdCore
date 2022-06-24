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
SDName: Stormwind_City
SD%Complete: 0
SDComment:
SDCategory: Stormwind City
EndScriptData */

/* ContentData
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"

class npc_102585_jace_for_dh_questline : public CreatureScript
{
public:
    npc_102585_jace_for_dh_questline() : CreatureScript("npc_102585_jace_for_dh_questline") { }

    struct npc_102585_jace_for_dh_questlineAI : ScriptedAI
    {
        npc_102585_jace_for_dh_questlineAI(Creature* creature) : ScriptedAI(creature) {}

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (events.Empty())
                events.ScheduleEvent(EVENT_1, 2000);

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = who->ToPlayer();

            if (player->GetQuestStatus(39691) != QUEST_STATUS_INCOMPLETE)
                return;

            player->KilledMonsterCredit(102585);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    events.ScheduleEvent(EVENT_1, 2000);

                    std::list<Player*> list;
                    me->GetPlayerListInGrid(list, 20.0f);
                    for (Player* player : list)
                        if (player->HasAura(188501) && player->GetQuestStatus(44471) == QUEST_STATUS_INCOMPLETE)
                            player->KilledMonsterCredit(102563);

                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_102585_jace_for_dh_questlineAI(creature);
    }
};

void AddSC_stormwind_city()
{
	new npc_102585_jace_for_dh_questline();
}
