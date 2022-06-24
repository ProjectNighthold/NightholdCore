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

struct npc_great_gnomeregan_race_gate : ScriptedAI
{
    npc_great_gnomeregan_race_gate(Creature* creature) : ScriptedAI(creature) {}

    std::set<ObjectGuid> PlayerList;

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsPlayer())
            return;

        if (me->GetDistance(who) > 7.0f)
            return;

        if (who->ToPlayer()->GetQuestStatus(47709) == QUEST_STATUS_NONE)
            return;

        if (who->ToPlayer()->GetQuestStatus(47709) == QUEST_STATUS_COMPLETE)
            return;

        if (PlayerList.find(who->GetGUID()) == PlayerList.end())
        {
            PlayerList.insert(who->GetGUID());
            DoCast(246069);
            me->CastSpell(who, 245989, true);
        }
    }
};

struct npc_great_gnomeregan_race_gate_start : ScriptedAI
{
    npc_great_gnomeregan_race_gate_start(Creature* creature) : ScriptedAI(creature) {}

    std::set<ObjectGuid> PlayerList;

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsPlayer())
            return;

        if (me->GetDistance(who) > 7.0f)
            return;

        if (who->ToPlayer()->GetQuestStatus(47709) == QUEST_STATUS_NONE)
            return;

        if (who->ToPlayer()->GetQuestStatus(47709) == QUEST_STATUS_COMPLETE)
            return;

        if (PlayerList.find(who->GetGUID()) == PlayerList.end())
        {
            PlayerList.insert(who->GetGUID());
            DoCast(246070);
            me->CastSpell(who, 245999, true);
        }
    }
};

struct npc_great_gnomeregan_race_gate_finish : ScriptedAI
{
    npc_great_gnomeregan_race_gate_finish(Creature* creature) : ScriptedAI(creature) {}

    std::set<ObjectGuid> PlayerList;

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsPlayer())
            return;

        if (me->GetDistance(who) > 7.0f)
            return;

        if (who->ToPlayer()->GetQuestStatus(47709) == QUEST_STATUS_NONE)
            return;

        if (who->ToPlayer()->GetQuestStatus(47709) == QUEST_STATUS_COMPLETE)
            return;

        if (PlayerList.find(who->GetGUID()) == PlayerList.end())
        {
            PlayerList.insert(who->GetGUID());
            DoCast(246070);
            me->CastSpell(who, 246000, true);
        }
    }
};

void AddSC_TheGreatGromereganRun()
{
    RegisterCreatureAI(npc_great_gnomeregan_race_gate);
    RegisterCreatureAI(npc_great_gnomeregan_race_gate_start);
    RegisterCreatureAI(npc_great_gnomeregan_race_gate_finish);
}