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

#include "Define.h"

#include "BattlenetAccountMgr.h"
#include "AccountMgr.h"
#include "Chat.h"
#include "Language.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "DatabaseEnv.h"

class battlenet_account_commandscript : public CommandScript
{
public:
    battlenet_account_commandscript() : CommandScript("battlenet_account_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> accountSetCommandTable =
        {
            { "password", SEC_ADMINISTRATOR,                                 true,  &HandleAccountSetPasswordCommand, ""}
        };

        static std::vector<ChatCommand> accountLockCommandTable =
        {
            //{ "country", SEC_ADMINISTRATOR,                                 true, &HandleAccountLockCountryCommand, "", NULL },
            { "ip",      SEC_ADMINISTRATOR,                                 true, &HandleAccountLockIpCommand, ""}
        };

        static std::vector<ChatCommand> accountCommandTable =
        {
            { "create",     SEC_ADMINISTRATOR,                                true, &HandleAccountCreateCommand, ""},
            { "lock",       SEC_ADMINISTRATOR,                                false, NULL, "", accountLockCommandTable },
            { "set",        SEC_ADMINISTRATOR,                                true, NULL, "", accountSetCommandTable },
            { "password",   SEC_ADMINISTRATOR,                                false, &HandleAccountPasswordCommand, ""}
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "bnetaccount", SEC_ADMINISTRATOR,                    true, NULL, "", accountCommandTable }
        };

        return commandTable;
    }

    /// Create an account
    static bool HandleAccountCreateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string email;

        ///- %Parse the command line arguments
        char* accountName = strtok((char*)args, " ");
        char* password = strtok(NULL, " ");
        if (!accountName || !password)
            return false;

        if (!strchr(accountName, '@'))
        {
            handler->SendSysMessage(LANG_ACCOUNT_INVALID_BNET_NAME);
            handler->SetSentErrorMessage(true);
            return false;
        }

        switch (Battlenet::AccountMgr::CreateBattlenetAccount(std::string(accountName), std::string(password)))
        {
            case AccountOpResult::AOR_OK:
                handler->PSendSysMessage(LANG_ACCOUNT_CREATED, accountName);
                if (handler->GetSession())
                {
                    TC_LOG_INFO(LOG_FILTER_CHARACTER, "Battle.net account: %d (IP: %s) Character:[%s] (GUID: %u) created Account %s",
                        handler->GetSession()->GetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                        handler->GetSession()->GetPlayer()->GetName(), handler->GetSession()->GetPlayer()->GetGUID().GetGUIDLow(),
                        accountName);
                }
                break;
            case AccountOpResult::AOR_NAME_TOO_LONG:
                handler->SendSysMessage(LANG_ACCOUNT_TOO_LONG);
                handler->SetSentErrorMessage(true);
                return false;
            case AccountOpResult::AOR_NAME_ALREADY_EXIST:
                handler->SendSysMessage(LANG_ACCOUNT_ALREADY_EXIST);
                handler->SetSentErrorMessage(true);
                return false;
            case AccountOpResult::AOR_PASS_TOO_LONG:
                handler->SendSysMessage(LANG_PASSWORD_TOO_LONG);
                handler->SetSentErrorMessage(true);
                return false;
            default:
                break;
        }

        return true;
    }

    // Sets country lock on own account
    static bool HandleAccountLockCountryCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(LANG_USE_BOL);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string param = (char*)args;
        if (!param.empty())
        {
            if (param == "on")
            {
                /*PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_LOGON_COUNTRY);
                uint32 ip = inet_addr(handler->GetSession()->GetRemoteAddress().c_str());
                EndianConvertReverse(ip);
                stmt->setUInt32(0, ip);
                PreparedQueryResult result = LoginDatabase.Query(stmt);
                if (result)
                {
                    Field* fields = result->Fetch();
                    std::string country = fields[0].GetString();
                    stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_ACCOUNT_LOCK_CONTRY);
                    stmt->setString(0, country);
                    stmt->setUInt32(1, handler->GetSession()->GetBattlenetAccountId());
                    LoginDatabase.Execute(stmt);
                    handler->PSendSysMessage(LANG_COMMAND_ACCLOCKLOCKED);
                }
                else
                {
                    handler->PSendSysMessage("[IP2NATION] Table empty");
                    TC_LOG_DEBUG("server.authserver", "[IP2NATION] Table empty");
                }*/
            }
            else if (param == "off")
            {
                /*PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_ACCOUNT_LOCK_CONTRY);
                stmt->setString(0, "00");
                stmt->setUInt32(1, handler->GetSession()->GetBattlenetAccountId());
                LoginDatabase.Execute(stmt);
                handler->PSendSysMessage(LANG_COMMAND_ACCLOCKUNLOCKED);*/
            }
            return true;
        }

        handler->SendSysMessage(LANG_USE_BOL);
        handler->SetSentErrorMessage(true);
        return false;
    }

    // Sets ip lock on own account
    static bool HandleAccountLockIpCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(LANG_USE_BOL);
            handler->SetSentErrorMessage(true);
            return false;
        }

        std::string param = (char*)args;

        if (!param.empty())
        {
            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BNET_ACCOUNT_LOCK);

            if (param == "on")
            {
                stmt->setBool(0, true);                                     // locked
                handler->PSendSysMessage(LANG_COMMAND_ACCLOCKLOCKED);
            }
            else if (param == "off")
            {
                stmt->setBool(0, false);                                    // unlocked
                handler->PSendSysMessage(LANG_COMMAND_ACCLOCKUNLOCKED);
            }

            stmt->setUInt32(1, handler->GetSession()->GetBattlenetAccountId());

            LoginDatabase.Execute(stmt);
            return true;
        }

        handler->SendSysMessage(LANG_USE_BOL);
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleAccountPasswordCommand(ChatHandler* handler, char const* args)
    {
        // If no args are given at all, we can return false right away.
        if (!*args)
        {
            handler->SendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Command is supposed to be: .account password [$oldpassword] [$newpassword] [$newpasswordconfirmation] [$emailconfirmation]
        char* oldPassword = strtok((char*)args, " ");       // This extracts [$oldpassword]
        char* newPassword = strtok(NULL, " ");              // This extracts [$newpassword]
        char* passwordConfirmation = strtok(NULL, " ");     // This extracts [$newpasswordconfirmation]

        //Is any of those variables missing for any reason ? We return false.
        if (!oldPassword || !newPassword || !passwordConfirmation)
        {
            handler->SendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // We compare the old, saved password to the entered old password - no chance for the unauthorized.
        if (!Battlenet::AccountMgr::CheckPassword(handler->GetSession()->GetAccountId(), std::string(oldPassword)))
        {
            handler->SendSysMessage(LANG_COMMAND_WRONGOLDPASSWORD);
            handler->SetSentErrorMessage(true);
            TC_LOG_INFO(LOG_FILTER_CHARACTER, "Battle.net account: %u (IP: %s) Character:[%s] (GUID: %u) Tried to change password, but the provided old password is wrong.",
                handler->GetSession()->GetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                handler->GetSession()->GetPlayer()->GetName(), handler->GetSession()->GetPlayer()->GetGUID().GetGUIDLow());
            return false;
        }

        // Making sure that newly entered password is correctly entered.
        if (strcmp(newPassword, passwordConfirmation) != 0)
        {
            handler->SendSysMessage(LANG_NEW_PASSWORDS_NOT_MATCH);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Changes password and prints result.
        AccountOpResult result = Battlenet::AccountMgr::ChangePassword(handler->GetSession()->GetBattlenetAccountId(), std::string(newPassword));
        switch (result)
        {
            case AccountOpResult::AOR_OK:
                handler->SendSysMessage(LANG_COMMAND_PASSWORD);
                TC_LOG_INFO(LOG_FILTER_CHARACTER, "Battle.net account: %u (IP: %s) Character:[%s] (GUID: %u) Changed Password.",
                    handler->GetSession()->GetBattlenetAccountId(), handler->GetSession()->GetRemoteAddress().c_str(),
                    handler->GetSession()->GetPlayer()->GetName(), handler->GetSession()->GetPlayer()->GetGUID().GetGUIDLow());
                break;
            case AccountOpResult::AOR_PASS_TOO_LONG:
                handler->SendSysMessage(LANG_PASSWORD_TOO_LONG);
                handler->SetSentErrorMessage(true);
                return false;
            default:
                handler->SendSysMessage(LANG_COMMAND_NOTCHANGEPASSWORD);
                handler->SetSentErrorMessage(true);
                return false;
        }

        return true;
    }

    /// Set password for account
    static bool HandleAccountSetPasswordCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
        {
            handler->SendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        ///- Get the command line arguments
        char* account = strtok((char*)args, " ");
        char* password = strtok(NULL, " ");
        char* passwordConfirmation = strtok(NULL, " ");

        if (!account || !password || !passwordConfirmation)
            return false;

        std::string accountName = account;
        if (!Utf8ToUpperOnlyLatin(accountName))
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 targetAccountId = Battlenet::AccountMgr::GetId(accountName);
        if (!targetAccountId)
        {
            handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (strcmp(password, passwordConfirmation))
        {
            handler->SendSysMessage(LANG_NEW_PASSWORDS_NOT_MATCH);
            handler->SetSentErrorMessage(true);
            return false;
        }

        AccountOpResult result = Battlenet::AccountMgr::ChangePassword(targetAccountId, password);

        switch (result)
        {
            case AccountOpResult::AOR_OK:
                handler->SendSysMessage(LANG_COMMAND_PASSWORD);
                break;
            case AccountOpResult::AOR_NAME_NOT_EXIST:
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return false;
            case AccountOpResult::AOR_PASS_TOO_LONG:
                handler->SendSysMessage(LANG_PASSWORD_TOO_LONG);
                handler->SetSentErrorMessage(true);
                return false;
            default:
                break;
        }
        return true;
    }
};

void AddSC_battlenet_account_commandscript()
{
    new battlenet_account_commandscript();
}
