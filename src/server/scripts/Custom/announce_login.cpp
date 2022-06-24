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

#include "Config.h"
#include "World.h"
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
#include "ConditionMgr.h"
#include "Garrison.h"
#include "SpellAuraEffects.h"
#include "WorldStatePackets.h"
#include "MiscPackets.h"
#include "BattlePayPackets.h"
#include "BattlePayMgr.h"
#include "BattlePayData.h"
#include "ScriptMgr.h"
#include "DatabaseEnv.h"
#include "Common.h"
#include "ObjectMgr.h"
#include "BattlePayMgr.h"
#include "WorldSession.h"
#include "Player.h"
#include "BattlePayData.h"
#include "DatabaseEnv.h"
#include "QuestData.h"
#include "LoginQueryHolder.h"
#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "PetBattle.h"
#include "BattlePetData.h"
#include "CharacterService.h"
#include "CollectionMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"

class announce_login : public PlayerScript
{
public:
    announce_login() : PlayerScript("announce_login") { }

    void OnLogin(Player* player, bool /*loginFirst*/)
    {
		//if (sConfigMgr->GetBoolDefault("Login.Announcer.Enable", true))
		//{
        
            if (player->GetTeam() == ALLIANCE)
            {
                std::ostringstream ss;
                ss << "|cff3DAEFF[ Login Announcer ]|cffFFD800 : Player|cff4CFF00 " << player->GetName() << " |cffFFD800 Is Online. This Player is |cff0026FF Alliance";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
            }
            else
            {
                std::ostringstream ss;
                ss << "|cff3DAEFF[ Login Announcer ]|cffFFD800 : Player |cff4CFF00 " << player->GetName() << " |cffFFD800 Is Online. This Player is |cffFF0000 Horde";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
            }
        
		//}
    }
};

void AddSC_announce_login()
{
    new announce_login;
}