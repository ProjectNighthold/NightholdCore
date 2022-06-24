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
#include "BattlePayMgr.h"
#include "BattlePayData.h"

class battlepay_commandscript : public CommandScript
{
public:
    battlepay_commandscript() : CommandScript("battlepay_commandscript") { }

    ChatCommand* GetCommands() const override
    {
        static ChatCommand BattlepayCommandTable[] =
        {
            { "reload",                 SEC_ADMINISTRATOR,  false,  &HandleReloadBattlePay,         "", nullptr },
            { nullptr,                  0,                  false,  nullptr,                        "", nullptr }
        };

        static ChatCommand CommandTable[] =
        {
             { "battlepay",             SEC_ADMINISTRATOR,  true,   nullptr,                        "", BattlepayCommandTable },
             { nullptr,                 0,                  false,  nullptr,                        "", nullptr }
        };

        return CommandTable;
    }

    static bool HandleReloadBattlePay(ChatHandler* /*chatHandler*/, char const* /*args*/)
    {
        //sBattlepayMgr->();
        sBattlePayDataStore->Initialize();
        return true;
    }
};

void AddSC_battlepay_commandscript()
{
    new battlepay_commandscript();
}
