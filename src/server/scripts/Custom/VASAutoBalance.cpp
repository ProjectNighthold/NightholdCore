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

/*
* Script Name: AutoBalance
* Original Authors: KalCorp and Vaughner
* Maintainer(s): CVMagic
* Original Script Name: VAS.AutoBalance
* Description: This script is intended to scale based on number of players, instance mobs & world bosses' health, mana, and damage.
*/


#include "Configuration/Config.h"
#include "Unit.h"
#include "Chat.h"
#include "Creature.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "World.h"
#include "Map.h"
#include "ScriptMgr.h"
#include <vector>


struct AutoBalanceCreatureInfo
{
    uint32 instancePlayerCount;
    float DamageMultiplier;
};

static std::map<ObjectGuid, AutoBalanceCreatureInfo> CreatureInfo; // A hook should be added to remove the mapped entry when the creature is dead or this should be added into the creature object
static std::map<int, int> forcedCreatureIds;                   // The map values correspond with the VAS.AutoBalance.XX.Name entries in the configuration file.
static int8 PlayerCountDifficultyOffset; //cheaphack for difficulty server-wide. Another value TODO in player class for the party leader's value to determine dungeon difficulty.
int GetValidDebugLevel()
{
    int debugLevel = sConfigMgr->GetIntDefault("VASAutoBalance.DebugLevel", 2);

    if ((debugLevel < 0) || (debugLevel > 3))
    {
        return 1;
    }
    return debugLevel;
}

void LoadForcedCreatureIdsFromString(std::string creatureIds, int forcedPlayerCount) // Used for reading the string from the configuration file to for those creatures who need to be scaled for XX number of players.
{
    std::string delimitedValue;
    std::stringstream creatureIdsStream;

    creatureIdsStream.str(creatureIds);
    while (std::getline(creatureIdsStream, delimitedValue, ',')) // Process each Creature ID in the string, delimited by the comma - ","
    {
        int creatureId = atoi(delimitedValue.c_str());
        if (creatureId >= 0)
        {
            forcedCreatureIds[creatureId] = forcedPlayerCount;
        }
    }
}

int GetForcedCreatureId(int creatureId)
{
    if (forcedCreatureIds.find(creatureId) == forcedCreatureIds.end()) // Don't want the forcedCreatureIds map to blowup to a massive empty array
    {
        return 0;
    }
    return forcedCreatureIds[creatureId];
}

class VAS_AutoBalance_WorldScript : public WorldScript
{
public:
    VAS_AutoBalance_WorldScript()
        : WorldScript("VAS_AutoBalance_WorldScript")
    {
    }

    /*void OnBeforeConfigLoad(bool reload) override
    {
    // from skeleton module
    if (!reload) {
    std::string conf_path = _CONF_DIR;
    std::string cfg_file = conf_path+"/VASAutoBalance.conf";
    #ifdef WIN32
    cfg_file = "VASAutoBalance.conf";
    #endif
    std::string cfg_def_file = cfg_file + ".dist";
    sConfigMgr->LoadMore(cfg_def_file.c_str());

    sConfigMgr->LoadMore(cfg_file.c_str());
    }
    // end from skeleton module
    }*/
    void OnStartup()
    {
    }

    void SetInitialWorldSettings()
    {
        forcedCreatureIds.clear();
        LoadForcedCreatureIdsFromString(sConfigMgr->GetStringDefault("VASAutoBalance.ForcedID40", ""), 40);
        LoadForcedCreatureIdsFromString(sConfigMgr->GetStringDefault("VASAutoBalance.ForcedID25", ""), 25);
        LoadForcedCreatureIdsFromString(sConfigMgr->GetStringDefault("VASAutoBalance.ForcedID10", ""), 10);
        LoadForcedCreatureIdsFromString(sConfigMgr->GetStringDefault("VASAutoBalance.ForcedID5", ""), 5);
        LoadForcedCreatureIdsFromString(sConfigMgr->GetStringDefault("VASAutoBalance.ForcedID2", ""), 2);
        PlayerCountDifficultyOffset = 0;
    }
};

class VAS_AutoBalance_PlayerScript : public PlayerScript
{
public:
    VAS_AutoBalance_PlayerScript()
        : PlayerScript("VAS_AutoBalance_PlayerScript")
    {
    }
};

/*class VAS_AutoBalance_UnitScript : public UnitScript
{
public:
    VAS_AutoBalance_UnitScript() : UnitScript("VAS_AutoBalance_UnitScript") { }

    uint32 DealDamage(Unit* AttackerUnit, Unit *playerVictim, uint32 damage, DamageEffectType damagetype) override
    {
        if ((AttackerUnit->GetMap()->IsDungeon() && playerVictim->GetMap()->IsDungeon()) || sConfigMgr->GetIntDefault("VASAutoBalance.DungeonsOnly", 1) < 1)
            if (AttackerUnit->GetTypeId() != TYPEID_PLAYER)
            {
                damage = VAS_Modifer_DealDamage(AttackerUnit, damage);
            }
        return damage;
    }

    void ModifyPeriodicDamageAurasTick(Unit *target, Unit *caster, uint32& damage) override
    {
        if ((caster->GetMap()->IsDungeon() && target->GetMap()->IsDungeon()) || sConfigMgr->GetIntDefault("VASAutoBalance.DungeonsOnly", 1) < 1)
            if (caster->GetTypeId() != TYPEID_PLAYER)
            {
                if (!((caster->isHunterPet() || caster->isPet() || caster->isSummon()) && caster->IsControlledByPlayer()))
                    damage = (float)damage * (float)CreatureInfo[caster->GetGUID()].DamageMultiplier;
            }
    }

    void ModifySpellDamageTaken(Unit* target, Unit* attacker, int32& damage) override
    {
        if (sConfigMgr->GetIntDefault("VASAutoBalance.DungeonsOnly", 1) < 1 || (attacker->GetMap()->IsDungeon() && target->GetMap()->IsDungeon()) || (attacker->GetMap()->IsBattleground() && target->GetMap()->IsBattleground()))
        {
            if (attacker->GetTypeId() != TYPEID_PLAYER)
            {
                if ((attacker->isHunterPet() || attacker->isPet() || attacker->isSummon()) && attacker->IsControlledByPlayer())
                    return;
                damage = (float)damage * (float)CreatureInfo[attacker->GetGUID()].DamageMultiplier;
            }
        }
    }

    void ModifyMeleeDamage(Unit* target, Unit* attacker, uint32& damage) override
    {
        // Make sure the Attacker and the Victim are in the same location, in addition that the attacker is not player.
        if ((sConfigMgr->GetIntDefault("VASAutoBalance.DungeonsOnly", 1) < 1 || (attacker->GetMap()->IsDungeon() && target->GetMap()->IsDungeon()) || (attacker->GetMap()->IsBattleground() && target->GetMap()->IsBattleground())) && (attacker->GetTypeId() != TYPEID_PLAYER))
            if (!((attacker->isHunterPet() || attacker->isPet() || attacker->isSummon()) && attacker->IsControlledByPlayer())) // Make sure that the attacker Is not a Pet of some sort
            {
                damage = (float)damage * (float)CreatureInfo[attacker->GetGUID()].DamageMultiplier;
            }
        return;
    }

    uint32 VAS_Modifer_DealDamage(Unit* AttackerUnit, uint32 damage)
    {
        if ((AttackerUnit->isHunterPet() || AttackerUnit->isPet() || AttackerUnit->isSummon()) && AttackerUnit->IsControlledByPlayer())
            return damage;

        float damageMultiplier = CreatureInfo[AttackerUnit->GetGUID()].DamageMultiplier;

        return damage * damageMultiplier;

    }
};*/


class VAS_AutoBalance_AllMapScript : public AllMapScript
{
public:
    VAS_AutoBalance_AllMapScript()
        : AllMapScript("VAS_AutoBalance_AllMapScript")
    {
    }

    void OnPlayerEnterAll(Map* map, Player* player)
    {
        if (!sConfigMgr->GetBoolDefault("VASAutoBalance.Instances", true))
            return;

        if (sConfigMgr->GetIntDefault("VASAutoBalance.PlayerChangeNotify", 1) > 0)
        {
            if ((map->GetEntry()->IsDungeon()) && !player->isGameMaster())
            {
                Map::PlayerList const &playerList = map->GetPlayers();
                if (!playerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator playerIteration = playerList.begin(); playerIteration != playerList.end(); ++playerIteration)
                    {
                        if (Player* playerHandle = playerIteration->getSource())
                        {
                            ChatHandler chatHandle = ChatHandler(playerHandle->GetSession());
                            chatHandle.PSendSysMessage("|cffFF0000 [AutoBalance]|r|cffFF8000 %s entered the Instance %s. Auto setting player count to %u (Player Difficulty Offset = %u) |r", player->GetName(), map->GetMapName(), map->GetPlayersCountExceptGMs() + PlayerCountDifficultyOffset, PlayerCountDifficultyOffset);
                        }
                    }
                }
            }
        }
    }

    void OnPlayerLeaveAll(Map* map, Player* player)
    {

        int instancePlayerCount = map->GetPlayersCountExceptGMs() - 1;

        if (instancePlayerCount >= 1)
        {
            if (sConfigMgr->GetIntDefault("VASAutoBalance.PlayerChangeNotify", 1) > 0)
            {
                if ((map->GetEntry()->IsDungeon()) && !player->isGameMaster())
                {
                    Map::PlayerList const &playerList = map->GetPlayers();
                    if (!playerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator playerIteration = playerList.begin(); playerIteration != playerList.end(); ++playerIteration)
                        {
                            if (Player* playerHandle = playerIteration->getSource())
                            {
                                ChatHandler chatHandle = ChatHandler(playerHandle->GetSession());
                                chatHandle.PSendSysMessage("|cffFF0000 [VAS-AutoBalance]|r|cffFF8000 %s left the Instance %s. Auto setting player count to %u (Player Difficulty Offset = %u) |r", player->GetName(), map->GetMapName(), instancePlayerCount, PlayerCountDifficultyOffset);
                            }
                        }
                    }
                }
            }
        }
    }
};

/*class VAS_AutoBalance_AllCreatureScript : public AllCreatureScript
{
public:
    VAS_AutoBalance_AllCreatureScript() : AllCreatureScript("VAS_AutoBalance_AllCreatureScript") { }

    void Creature_SelectLevel(const CreatureTemplate *creatureTemplate, Creature* creature) override
    {
        if (creature->GetMap()->IsDungeon() || sConfigMgr->GetIntDefault("VASAutoBalance.DungeonsOnly", 1) < 1)
        {
            auto& creatureInfo = CreatureInfo[creature->GetGUID()];
            creatureInfo.instancePlayerCount = GetPlayerCount(creature);
            ModifyCreatureAttributes(creature);
        }
    }

    void OnAllCreatureUpdate(Creature* creature, uint32 diff) override
    {
        auto& creatureInfo = CreatureInfo[creature->GetGUID()];
        uint32 currentPlayerCount = GetPlayerCount(creature);

        if (creatureInfo.instancePlayerCount != currentPlayerCount)
        {
            creatureInfo.instancePlayerCount = currentPlayerCount;

            if (creature->GetMap()->IsDungeon() || creature->GetMap()->IsBattleground() || sConfigMgr->GetIntDefault("VASAutoBalance.DungeonsOnly", 1) < 1)
                ModifyCreatureAttributes(creature);
        }
    }

    void ModifyCreatureAttributes(Creature* creature)
    {
        if (((creature->isHunterPet() || creature->isPet() || creature->isSummon()) && creature->IsControlledByPlayer()) ||
            (creature->GetMap()->IsDungeon() && sConfigMgr->GetIntDefault("VASAutoBalance.Instances", 1) < 1) ||
            creature->GetMap()->GetPlayersCountExceptGMs() <= 0)
        {
            return;
        }

        auto& creatureInfo = CreatureInfo[creature->GetGUID()];
        CreatureTemplate const *creatureTemplate = creature->GetCreatureTemplate();
        CreatureBaseStats const* creatureStats = sObjectMgr->GetCreatureBaseStats(creature->getLevel(), creatureTemplate->unit_class);

        float damageMultiplier = 1.0f;
        float healthMultiplier = 1.0f;

        uint32 baseHealth = creatureStats->GenerateHealth(creatureTemplate);
        uint32 baseMana = creatureStats->GenerateMana(creatureTemplate);
        uint32 maxNumberOfPlayers = ((InstanceMap*)sMapMgr->FindMap(creature->GetMapId(), creature->GetInstanceId()))->GetMaxPlayers();
        uint32 scaledHealth = 0;
        uint32 scaledMana = 0;

        //   VAS SOLO  - By MobID
        if (GetForcedCreatureId(creatureTemplate->Entry) > 0)
        {
            maxNumberOfPlayers = GetForcedCreatureId(creatureTemplate->Entry); // Force maxNumberOfPlayers to be changed to match the Configuration entry.
        }

        // (tanh((X-2.2)/1.5) +1 )/2    // 5 Man formula X = Number of Players
        // (tanh((X-5)/2) +1 )/2        // 10 Man Formula X = Number of Players
        // (tanh((X-16.5)/6.5) +1 )/2   // 25 Man Formula X = Number of players
        //
        // Note: The 2.2, 5, and 16.5 are the number of players required to get 50% health.
        //       It's not required this be a whole number, you'd adjust this to raise or lower
        //       the hp modifier for per additional player in a non-whole group. These
        //       values will eventually be part of the configuration file once I finalize the mod.
        //
        //       The 1.5, 2, and 6.5 modify the rate of percentage increase between
        //       number of players. Generally the closer to the value of 1 you have this
        //       the less gradual the rate will be. For example in a 5 man it would take 3
        //       total players to face a mob at full health.
        //
        //       The +1 and /2 values raise the TanH function to a positive range and make
        //       sure the modifier never goes above the value or 1.0 or below 0.
        //
        //       Lastly this formula has one side effect on full groups Bosses and mobs will
        //       never have full health, this can be tested against by making sure the number
        //       of players match the maxNumberOfPlayers variable.

        switch (maxNumberOfPlayers)
        {
        case 40:
            healthMultiplier = (float)creatureInfo.instancePlayerCount / (float)maxNumberOfPlayers; // 40 Man Instances oddly enough scale better with the old formula
            break;
        case 25:
            healthMultiplier = (tanh((creatureInfo.instancePlayerCount - 16.5f) / 1.5f) + 1.0f) / 2.0f;
            break;
        case 10:
            healthMultiplier = (tanh((creatureInfo.instancePlayerCount - 4.5f) / 1.5f) + 1.0f) / 2.0f;
            break;
        case 2:
            healthMultiplier = (float)creatureInfo.instancePlayerCount / (float)maxNumberOfPlayers;                   // Two Man Creatures are too easy if handled by the 5 man formula, this would only
            break;                                                                         // apply in the situation where it's specified in the configuration file.
        default:
            healthMultiplier = (tanh((creatureInfo.instancePlayerCount - 2.2f) / 1.5f) + 1.0f) / 2.0f;    // default to a 5 man group
        }

        //   VAS SOLO  - Map 0,1 and 530 ( World Mobs )                                                               // This may be where VAS_AutoBalance_CheckINIMaps might have come into play. None the less this is
        if ((creature->GetMapId() == 0 || creature->GetMapId() == 1 || creature->GetMapId() == 530) && (creature->isElite() || creature->isWorldBoss()))  // specific to World Bosses and elites in those Maps, this is going to use the entry XPlayer in place of instancePlayerCount.
        {
            if (baseHealth > 800000) {
                healthMultiplier = (tanh((sConfigMgr->GetFloatDefault("VASAutoBalance.numPlayer", 1.0f) - 5.0f) / 1.5f) + 1.0f) / 2.0f;

            }
            else {
                healthMultiplier = (tanh((sConfigMgr->GetFloatDefault("VASAutoBalance.numPlayer", 1.0f) - 2.2f) / 1.5f) + 1.0f) / 2.0f; // Assuming a 5 man configuration, as World Bosses have been relatively retired since BC so unless the boss has some substantial baseHealth
            }

        }

        // Ensure that the healthMultiplier is not lower than the configuration specified value. -- This may be Deprecated later.
        if (healthMultiplier <= sConfigMgr->GetFloatDefault("VASAutoBalance.MinHPModifier", 0.1f))
        {
            healthMultiplier = sConfigMgr->GetFloatDefault("VASAutoBalance.MinHPModifier", 0.1f);
        }

        //Getting the list of Classes in this group - this will be used later on to determine what additional scaling will be required based on the ratio of tank/dps/healer
        //GetPlayerClassList(creature, playerClassList); // Update playerClassList with the list of all the participating Classes

        //healthMultiplier *= sConfigMgr->GetFloatDefault("VASAutoBalance.CustomBaldazzarHealthModifier", 0.7f);

        scaledHealth = uint32((baseHealth * healthMultiplier) + 1.0f);
        // Now adjusting Mana, Mana is something that can be scaled linearly
        if (maxNumberOfPlayers == 0) {
            scaledMana = uint32((baseMana * healthMultiplier) + 1.0f);
            // Now Adjusting Damage, this too is linear for now .... this will have to change I suspect.
            damageMultiplier = healthMultiplier;
        }
        else {
            scaledMana = ((baseMana / maxNumberOfPlayers) * creatureInfo.instancePlayerCount);
            // Now Adjusting Damage, this too is linear for now .... this will have to change I suspect.
            damageMultiplier = (float)creatureInfo.instancePlayerCount / (float)maxNumberOfPlayers;

        }

        // Can not be less then Min_D_Mod
        if (damageMultiplier <= sConfigMgr->GetFloatDefault("VASAutoBalance.MinDamageModifier", 0.1f))
        {
            damageMultiplier = sConfigMgr->GetFloatDefault("VASAutoBalance.MinDamageModifier", 0.1f);
        }

        //damageMultiplier *= sConfigMgr->GetFloatDefault("VASAutoBalance.CustomBaldazzarDamageModifier", 0.7f);

        creature->SetCreateHealth(scaledHealth);
        creature->SetMaxHealth(scaledHealth);
        creature->ResetPlayerDamageReq();
        creature->SetCreateMana(scaledMana);
        creature->SetMaxPower(POWER_MANA, scaledMana);
        creature->SetPower(POWER_MANA, scaledMana);
        creature->SetModifierValue(UNIT_MOD_HEALTH, BASE_VALUE, (float)scaledHealth);
        creature->SetModifierValue(UNIT_MOD_MANA, BASE_VALUE, (float)scaledMana);
        creatureInfo.DamageMultiplier = damageMultiplier;
    }

    uint32 GetPlayerCount(Creature* creature)
    {
        return creature->GetMap()->GetPlayersCountExceptGMs() + PlayerCountDifficultyOffset;
    }

};*/
class VAS_AutoBalance_CommandScript : public CommandScript
{
public:
    VAS_AutoBalance_CommandScript() : CommandScript("VAS_AutoBalance_CommandScript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> vasCommandTable =
        {
            { "setoffset",  SEC_GAMEMASTER, true,   &HandleVasSetOffsetCommand, ""},
            { "getoffset",  SEC_GAMEMASTER, true,   &HandleVasGetOffsetCommand, ""}
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "vas",    SEC_GAMEMASTER, false,  NULL,                           "", vasCommandTable }
        };
        return commandTable;
    }

    static bool HandleVasSetOffsetCommand(ChatHandler* handler, const char* args)
    {
        if (!*args)
        {
            handler->PSendSysMessage(".vas setoffset #");
            handler->PSendSysMessage("Sets the Player Difficulty Offset for instances. Example: (You + offset(1) = 2 player difficulty).");
            return false;
        }
        char* offset = strtok((char*)args, " ");
        int32 offseti = -1;

        if (offset)
        {
            offseti = (uint32)atoi(offset);
            handler->PSendSysMessage("Changing Player Difficulty Offset to %i.", offseti);
            PlayerCountDifficultyOffset = offseti;
            return true;
        }
        else
            handler->PSendSysMessage("Error changing Player Difficulty Offset! Please try again.");
        return false;
    }
    static bool HandleVasGetOffsetCommand(ChatHandler* handler, const char* /*args*/)
    {
        handler->PSendSysMessage("Current Player Difficulty Offset = %i", PlayerCountDifficultyOffset);
        return true;
    }
};
void AddSC_VAS_AutoBalance()
{
    new VAS_AutoBalance_WorldScript;
    new VAS_AutoBalance_PlayerScript;
    //new VAS_AutoBalance_UnitScript;
    //new VAS_AutoBalance_AllCreatureScript;
    new VAS_AutoBalance_AllMapScript;
    new VAS_AutoBalance_CommandScript;
}
