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
 
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Chat.h"
#include <stdlib.h>
#include "ObjectMgr.h"
#include "DatabaseEnv.h"
#include "BracketMgr.h"
#include "QuestData.h"
#include "PetBattle.h"
#include "CollectionMgr.h"
#include "Configuration/Config.h"
#include "Player.h"
#include "Creature.h"
#include "AccountMgr.h"
#include "Define.h"
#include "GossipDef.h"
#include "WorldSession.h"
#include "AppenderConsole.h"
#include "AreaTrigger.h"
#include "AchievementMgr.h"
#include "Bag.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "BattlefieldTB.h"
#include "BattlefieldWG.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "BattlegroundPackets.h"
#include "BattlegroundScore.h"
#include "CellImpl.h"
#include "Channel.h"
#include "ChannelMgr.h"
#include "CharacterDatabaseCleaner.h"
#include "CharacterPackets.h"
#include "Chat.h"
#include "ChatPackets.h"
#include "CombatLogPackets.h"
#include "CombatPackets.h"
#include "Common.h"
#include "ConditionMgr.h"
#include "CreatureAI.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "DisableMgr.h"
#include "DuelPackets.h"
#include "EquipmentSetPackets.h"
#include "Formulas.h"
#include "GameEventMgr.h"
#include "GameObjectAI.h"
#include "Garrison.h"
#include "GitRevision.h"
#include "GossipDef.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "GroupMgr.h"
#include "GameTables.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "InstancePackets.h"
#include "InstanceSaveMgr.h"
#include "InstanceScript.h"
#include "ItemPackets.h"
#include "KillRewarder.h"
#include "LFGMgr.h"
#include "Language.h"
#include "Log.h"
#include "LootMgr.h"
#include "LootPackets.h"
#include "Mail.h"
#include "MailPackets.h"
#include "MapManager.h"
#include "MiscPackets.h"
#include "MotionMaster.h"
#include "MovementPackets.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "OutdoorPvP.h"
#include "OutdoorPvPMgr.h"
#include "Pet.h"
#include "PetPackets.h"
#include "QueryHolder.h"
#include "QuestDef.h"
#include "QuestPackets.h"
#include "Realm.h"
#include "ReputationMgr.h"
#include "Scenario.h"
#include "SkillDiscovery.h"
#include "SocialMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "TalentPackets.h"
#include "ToyPackets.h"
#include "TradeData.h"
#include "TransmogrificationPackets.h"
#include "Transport.h"
#include "UpdateData.h"
#include "UpdateFieldFlags.h"
#include "Util.h"
#include "Vehicle.h"
#include "VehiclePackets.h"
#include "Weather.h"
#include "WeatherMgr.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "WorldStatePackets.h"
#include <G3D/g3dmath.h>
#include "PhaseMgr.h"
#include "Chat.h"
#include "ObjectMgr.h"
#include "ConditionMgr.h"
#include "Garrison.h"
#include "SpellAuraEffects.h"
#include "WorldStatePackets.h"
#include "MiscPackets.h"
#include "ScriptMgr.h"
#include "CreatureTextMgr.h"
#include "CombatAI.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

class phase_sacer_holy_41957 : public PlayerScript
{
public:
    phase_sacer_holy_41957() : PlayerScript("phase_sacer_holy_41957") {}


    void OnUpdate(Player* player, uint32 diff) override
    {
        if (player->getClass() == CLASS_PRIEST && player->GetMapId() == 0 && player->GetZoneId() == 85 && player->GetAreaId() == 173
            && player->GetQuestStatus(41957) == QUEST_STATUS_COMPLETE)
        {
            player->TeleportTo(1220, -785.4245, 4558.1738, 726.3496, 1.632);
        }

        //Poniendo fase 6230 al llegar a dalaran con la quest completa
        if (player->getClass() == CLASS_PRIEST && player->GetMapId() == 1220 && 
            (player->GetQuestStatus(41957) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(41957) == QUEST_STATUS_REWARDED) 
            && player->GetQuestStatus(41966) == QUEST_STATUS_NONE) 
        {                     
            std::set<uint32> phaseIds_sacer_holy_quest_41957;
            
            {
                if (PhaseEntry const* phase = sPhaseStore.LookupEntry(6230))
                    phaseIds_sacer_holy_quest_41957.insert(phase->ID);
            }
                  player->SetPhaseId(phaseIds_sacer_holy_quest_41957, true);
           
        }
                
        if (player->getClass() == CLASS_PRIEST && player->GetMapId() == 1220 &&
            (player->GetQuestStatus(41966)== QUEST_STATUS_INCOMPLETE  || player->GetQuestStatus(41966) == QUEST_STATUS_COMPLETE || 
                player->GetQuestStatus(41966) == QUEST_STATUS_REWARDED) && player->GetQuestStatus(41967) == QUEST_STATUS_NONE)
        {
            std::set<uint32> phaseIds_sacer_holy_quest_41966;

            {
                if (PhaseEntry const* phase1 = sPhaseStore.LookupEntry(6231))
                    phaseIds_sacer_holy_quest_41966.insert(phase1->ID);
            }
            player->SetPhaseId(phaseIds_sacer_holy_quest_41966, true);

        }
         
        if (player->getClass() == CLASS_PRIEST && player->GetMapId() == 1220 &&
            player->GetQuestStatus(41966) == QUEST_STATUS_REWARDED && player->GetQuestStatus(41967) == QUEST_STATUS_REWARDED &&
            player->GetQuestStatus(42074) == QUEST_STATUS_REWARDED)
        {
            std::set<uint32> phase_end = player->GetPhases();
            phase_end.erase(6230);
            phase_end.erase(6231);
            player->SetPhaseId(phase_end, true);
        }          

    }
};


class quest_39654 : public PlayerScript
{
public:
    quest_39654() : PlayerScript("quest_39654") {}


    void OnUpdate(Player* player, uint32 diff) override
    {
        if ((player->GetQuestStatus(39654) == QUEST_STATUS_COMPLETE) && (player->GetQuestStatus(39654) != QUEST_STATUS_REWARDED))
        {
            player->learnSpell(192085, false);

        }

    }
};

class boss_announcer1 : public PlayerScript
{
public:
    boss_announcer1() : PlayerScript("boss_announcer1") {}

    void OnCreatureKill(Player* player, Creature* boss)
    {
        if (boss->isWorldBoss())
        {
            std::string plr = player->GetName();
            std::string boss_n = boss->GetName();
            // bool ingroup = player->GetGroup();
            std::string tag_colour = "7bbef7";
            std::string plr_colour = "7bbef7";
            std::string boss_colour = "ff0000";
            std::ostringstream stream;
            stream << "|CFF" << tag_colour <<
                "|r|cff" << plr_colour << " " << plr <<
                "|r y su grupo mataron a |CFF" << boss_colour << "[" << boss_n << "]|r " "que es un jefe" << "!";
            sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
        }

    };
};

class resu_mago_gesta : public PlayerScript
{
public:
    resu_mago_gesta() : PlayerScript("resu_mago_gesta") {}


    void OnUpdate(Player* player, uint32 diff) override
    {
        if (player->getClass() == CLASS_MAGE && player->GetMapId() == 1494 && player->GetZoneId() == 7777)
        {
            if (player->HasAuraType(SPELL_AURA_SPIRIT_OF_REDEMPTION))
                player->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);


            if (!player->isAlive())
            {
                player->ResurrectPlayer(1.0f);
                player->SpawnCorpseBones();
                player->Yell("NOOOOOO QUE MANCO SOY", LANG_UNIVERSAL);
            }
        }

    }
};


// 36287  // Quest save the children 14368
class npc_cynthia_36287 : public CreatureScript
{
public:
    npc_cynthia_36287() : CreatureScript("npc_cynthia_36287") {}

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(14368) == QUEST_STATUS_INCOMPLETE)
        {
            /*sCreatureTextMgr->SendChat(creature, 0, NULL, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, player);
            creature->AI()->Talk(1);*/
            player->KilledMonsterCredit(36287);
            return true;
        }
        return false;
    }
};



// 36289
class npc_ashley_36289 : public CreatureScript
{
public:
    npc_ashley_36289() : CreatureScript("npc_ashley_36289") {}

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(14368) == QUEST_STATUS_INCOMPLETE)
        {
            /*sCreatureTextMgr->SendChat(creature, 0, NULL , CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, player);
            creature->AI()->Talk(1);*/
            player->KilledMonsterCredit(36289);
            return true;
        }
        return false;
    }
};

// 36288
class npc_james_36288 : public CreatureScript
{
public:
    npc_james_36288() : CreatureScript("npc_james_36288") {}

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(14368) == QUEST_STATUS_INCOMPLETE)
        {
            /*sCreatureTextMgr->SendChat(creature, 0, NULL, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, player);
            creature->AI()->Talk(1);*/
            player->KilledMonsterCredit(36288);
            return true;
        }
        return false;
    }
};




void AddSC_custom_lf()
{
    new phase_sacer_holy_41957();
    new quest_39654();
    new boss_announcer1();
    new resu_mago_gesta();
    new npc_cynthia_36287();
    new npc_ashley_36289();
    new npc_james_36288();
    
}
