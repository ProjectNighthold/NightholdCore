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
#include "Bracket.h"

class rbg_commandscript : public CommandScript
{
public:
    rbg_commandscript() : CommandScript("rbg_commandscript") { }

    ChatCommand* GetCommands() const override
    {
        static ChatCommand rgbSetCommandTable[] =
        {
            { "info",          SEC_PLAYER,               false,  &HandleRBGCommand,         "", NULL },
            { "join",          SEC_MODERATOR,            false,  &HandleJoinCommand,     "", NULL },
            { NULL,            SEC_PLAYER,               false,  NULL,                      "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            { "bracket",            SEC_PLAYER,         true,  NULL,                   "", rgbSetCommandTable },
            { NULL,             0,                  false, NULL,                   "", NULL }
        };
        return commandTable;
    }

    static bool HandleRBGCommand(ChatHandler* handler, const char* args)
    {
        Player* player = handler->GetSession()->GetPlayer();
        Bracket* rbg = player->getBracket(MS::Battlegrounds::BracketType::RatedBattleground);
        handler->PSendSysMessage("Rating: %u;", rbg->getRating());
        handler->PSendSysMessage("Wins: %u; Total: %u;", rbg->GetBracketInfo(BRACKET_SEASON_WIN), rbg->GetBracketInfo(BRACKET_SEASON_GAMES));
        return true;
    }

    //! 0 - MS::Battlegrounds::BracketType::Arena2v2, 3 - MS::Battlegrounds::BracketType::RatedBattleground, look at enum of BracketType
    static bool HandleJoinCommand(ChatHandler* handler, const char* args)
    {
       
        handler->GetSession()->JoinBracket(MS::Battlegrounds::BracketType::RatedBattleground);
        return true;
    }
};

void AddSC_bracket_commandscript()
{
    new rbg_commandscript();
}
