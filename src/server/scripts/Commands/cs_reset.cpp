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
Name: reset_commandscript
%Complete: 100
Comment: All reset related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"

class reset_commandscript : public CommandScript
{
public:
    reset_commandscript() : CommandScript("reset_commandscript") { }

    ChatCommand* GetCommands() const override
    {
        static ChatCommand resetCommandTable[] =
        {
            { "achievements",   SEC_ADMINISTRATOR,  true,  &HandleResetAchievementsCommand,     "", NULL },
            { "honor",          SEC_ADMINISTRATOR,  true,  &HandleResetHonorCommand,            "", NULL },
            { "spells",         SEC_ADMINISTRATOR,  true,  &HandleResetSpellsCommand,           "", NULL },
            { "stats",          SEC_ADMINISTRATOR,  true,  &HandleResetStatsCommand,            "", NULL },
            { "talents",        SEC_ADMINISTRATOR,  true,  &HandleResetTalentsCommand,          "", NULL },
            { "all",            SEC_ADMINISTRATOR,  true,  &HandleResetAllCommand,              "", NULL },
            { NULL,             0,                  false, NULL,                                "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "reset",          SEC_ADMINISTRATOR,  true, NULL,                                 "", resetCommandTable },
            { NULL,             0,                  false, NULL,                                "", NULL }
        };
        return commandTable;
    }

    static bool HandleResetAchievementsCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid targetGuid;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid))
            return false;

        if (target)
            target->GetAchievementMgr()->Reset();
        else
            AchievementMgr<Player>::DeleteFromDB(targetGuid);

        return true;
    }

    static bool HandleResetHonorCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        if (!handler->extractPlayerTarget((char*)args, &target))
            return false;

        target->SetUInt32Value(PLAYER_FIELD_YESTERDAY_HONORABLE_KILLS, 0);
        target->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, 0);
        target->UpdateAchievementCriteria(CRITERIA_TYPE_EARN_HONORABLE_KILL);

        return true;
    }

    static bool HandleResetStatsOrLevelHelper(Player* player)
    {
        ChrClassesEntry const* classEntry = sChrClassesStore.LookupEntry(player->getClass());
        if (!classEntry)
        {
            TC_LOG_ERROR(LOG_FILTER_GENERAL, "Class %u not found in DBC (Wrong DBC files?)", player->getClass());
            return false;
        }

        uint8 powerType = classEntry->DisplayPower;

        // reset m_form if no aura
        if (!player->HasAuraType(SPELL_AURA_MOD_SHAPESHIFT))
            player->SetShapeshiftForm(FORM_NONE);

        player->SetFloatValue(UNIT_FIELD_BOUNDING_RADIUS, DEFAULT_WORLD_OBJECT_SIZE);
        player->SetFloatValue(UNIT_FIELD_COMBAT_REACH, DEFAULT_COMBAT_REACH);

        player->setFactionForRace(player->getRace());

        player->SetUInt32Value(UNIT_FIELD_BYTES_0, ((player->getRace()) | (player->getClass() << 8) | (player->getGender() << 16) | (powerType << 24)));

        // reset only if player not in some form;
        if (player->GetShapeshiftForm() == FORM_NONE)
            player->InitDisplayIds();

        player->SetByteValue(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_PVP);

        player->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);

        //-1 is default value
        player->SetInt32Value(PLAYER_FIELD_WATCHED_FACTION_INDEX, -1);

        //player->SetUInt32Value(PLAYER_FIELD_BYTES_1, 0xEEE00000);
        return true;
    }

    static bool HandleResetSpellsCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
            return false;

        if (target)
        {
            target->resetSpells();

            ChatHandler(target).SendSysMessage(LANG_RESET_SPELLS);
            if (!handler->GetSession() || handler->GetSession()->GetPlayer() != target)
                handler->PSendSysMessage(LANG_RESET_SPELLS_ONLINE, handler->GetNameLink(target).c_str());
        }
        else
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
            stmt->setUInt16(0, uint16(AT_LOGIN_RESET_SPELLS));
            stmt->setUInt64(1, targetGuid.GetGUIDLow());
            CharacterDatabase.Execute(stmt);

            handler->PSendSysMessage(LANG_RESET_SPELLS_OFFLINE, targetName.c_str());
        }

        return true;
    }

    static bool HandleResetStatsCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        if (!handler->extractPlayerTarget((char*)args, &target))
            return false;

        if (!HandleResetStatsOrLevelHelper(target))
            return false;

        target->InitRunes();
        target->InitStatsForLevel(true);
        target->InitTaxiNodesForLevel();
        target->InitTalentForLevel();

        return true;
    }

    static bool HandleResetTalentsCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target)
        {
            target->ResetTalentSpecialization();
            target->ResetTalents(true);
            target->SendTalentsInfoData(false);
            ChatHandler(target).SendSysMessage(LANG_RESET_TALENTS);
            if (!handler->GetSession() || handler->GetSession()->GetPlayer() != target)
                handler->PSendSysMessage(LANG_RESET_TALENTS_ONLINE, handler->GetNameLink(target).c_str());

            Pet* pet = target->GetPet();
            if (pet)
                target->SendTalentsInfoData(true);
            return true;
        }
        if (targetGuid)
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
            stmt->setUInt16(0, uint16(AT_LOGIN_NONE | AT_LOGIN_RESET_PET_TALENTS));
            stmt->setUInt64(1, targetGuid.GetGUIDLow());
            CharacterDatabase.Execute(stmt);

            std::string nameLink = handler->playerLink(targetName);
            handler->PSendSysMessage(LANG_RESET_TALENTS_OFFLINE, nameLink.c_str());
            return true;
        }
        handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleResetAllCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        ObjectGuid targetGuid;
        std::string targetName;
        if (!handler->extractPlayerTarget((char*) args, &target, &targetGuid, &targetName))
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target)
        {
            target->resetSpells();
            target->ResetTalentSpecialization();
            target->ResetTalents(true);
            target->SendTalentsInfoData(false);

            ChatHandler(target).SendSysMessage(LANG_RESET_TALENTS);
            if (!handler->GetSession() || handler->GetSession()->GetPlayer() != target)
                handler->PSendSysMessage(LANG_RESET_TALENTS_ONLINE, handler->GetNameLink(target).c_str());

            return true;
        }
        if (targetGuid)
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ADD_AT_LOGIN_FLAG);
            stmt->setUInt16(0, uint16(AT_LOGIN_NONE | AT_LOGIN_RESET_SPELLS | AT_LOGIN_RESET_TALENTS));
            stmt->setUInt64(1, targetGuid.GetGUIDLow());
            CharacterDatabase.Execute(stmt);

            std::string nameLink = handler->playerLink(targetName);
            handler->PSendSysMessage(LANG_RESET_TALENTS_OFFLINE, nameLink.c_str());
            return true;
        }
        handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
        handler->SetSentErrorMessage(true);
        return false;
    }
};

void AddSC_reset_commandscript()
{
    new reset_commandscript();
}
