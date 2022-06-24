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
Name: honor_commandscript
%Complete: 100
Comment: All honor related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"

class honor_commandscript : public CommandScript
{
public:
    honor_commandscript() : CommandScript("honor_commandscript") { }

    ChatCommand* GetCommands() const override
    {
        static ChatCommand honorAddCommandTable[] =
        {
            { "kill",           SEC_GAMEMASTER,     false, &HandleHonorAddKillCommand,         "", NULL },
            { "",               SEC_GAMEMASTER,     false, &HandleHonorAddCommand,             "", NULL },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };

        static ChatCommand honorCommandTable[] =
        {
            { "add",            SEC_GAMEMASTER,     false, NULL,               "", honorAddCommandTable },
            { "update",         SEC_GAMEMASTER,     false, &HandleHonorUpdateCommand,          "", NULL },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            { "honor",          SEC_GAMEMASTER,     false, NULL,                  "", honorCommandTable },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }

    static bool HandleHonorAddCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        uint32 amount = (uint32)atoi(args);
        target->RewardHonor(NULL, 1, amount);
        return true;
    }

    static bool HandleHonorAddKillCommand(ChatHandler* handler, char const* /*args*/)
    {
        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (target->GetTypeId() == TYPEID_PLAYER && handler->HasLowerSecurity((Player*)target, ObjectGuid::Empty))
            return false;

        handler->GetSession()->GetPlayer()->RewardHonor(target, 1);
        return true;
    }

    static bool HandleHonorUpdateCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        target->UpdateHonorFields();
        return true;
    }
};

void AddSC_honor_commandscript()
{
    new honor_commandscript();
}
