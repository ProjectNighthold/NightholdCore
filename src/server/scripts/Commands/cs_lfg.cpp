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
#include "Chat.h"
#include "LFGMgr.h"
#include "Group.h"

void GetPlayerInfo(ChatHandler* handler, Player* player)
{
    if (!player)
        return;

    Group* grp = player->GetGroup();
    if (!grp)
        return;

    ObjectGuid gguid = grp->GetGUID();
    uint32 queueId = sLFGMgr->GetQueueId(gguid);

    ObjectGuid guid = player->GetGUID();
    lfg::LfgDungeonSet dungeons = sLFGMgr->GetSelectedDungeons(guid, queueId);

    std::string const& state = lfg::GetStateString(sLFGMgr->GetState(guid, queueId));
    handler->PSendSysMessage(LANG_LFG_PLAYER_INFO, player->GetName(),
        state.c_str(), uint8(dungeons.size()), lfg::ConcatenateDungeons(dungeons).c_str(),
        lfg::GetRolesString(sLFGMgr->GetRoles(guid, queueId)).c_str(), "");
}

class lfg_commandscript : public CommandScript
{
public:
    lfg_commandscript() : CommandScript("lfg_commandscript") { }

    ChatCommand* GetCommands() const override
    {
        static ChatCommand lfgCommandTable[] =
        {
            {   "clean",  SEC_ADMINISTRATOR, false,      &HandleLfgCleanCommand, "", NULL },
            {   "group",     SEC_GAMEMASTER, false,  &HandleLfgGroupInfoCommand, "", NULL },
            {    "join",  SEC_ADMINISTRATOR, false,       &HandleLfgJoinCommand, "", NULL },
            { "options",  SEC_ADMINISTRATOR, false,    &HandleLfgOptionsCommand, "", NULL },
            {  "player",     SEC_GAMEMASTER, false, &HandleLfgPlayerInfoCommand, "", NULL },
            {   "queue",     SEC_GAMEMASTER, false,  &HandleLfgQueueInfoCommand, "", NULL },
            {      NULL,         SEC_PLAYER, false,                        NULL, "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            {       "lfg",   SEC_GAMEMASTER, false,                        NULL, "", lfgCommandTable },
            {  NULL,             SEC_PLAYER, false,                        NULL, "", NULL }
        };
        return commandTable;
    }

    static bool HandleLfgJoinCommand(ChatHandler* handler, char const* args)
    {
        if (!sLFGMgr->isOptionEnabled(lfg::LFG_OPTION_ENABLE_DUNGEON_FINDER | lfg::LFG_OPTION_ENABLE_RAID_BROWSER))
            return false;

        Player* player = handler->getSelectedPlayer();
        if (!player)
            return false;

        Tokenizer tokens(args, ' ');
        if (tokens.size() < 2)
            return false;

        uint32 roles = 1;
        lfg::LfgDungeonSet dungeons;
        for (uint32 i = 0; i < tokens.size(); ++i)
        {
            if (i == 0)
                roles = std::atoi(tokens[i]);
            else
                dungeons.insert(std::atoi(tokens[i]));
        }

        sLFGMgr->JoinLfg(player, uint8(roles), dungeons);
        return true;
    }

    static bool HandleLfgPlayerInfoCommand(ChatHandler* handler, char const* args)
    {
        Player* target = NULL;
        std::string playerName;
        if (!handler->extractPlayerTarget((char*)args, &target, NULL, &playerName))
            return false;

        GetPlayerInfo(handler, target);
        return true;
    }

    static bool HandleLfgGroupInfoCommand(ChatHandler* handler, char const* args)
    {
        Player* target = NULL;
        std::string playerName;
        if (!handler->extractPlayerTarget((char*)args, &target, NULL, &playerName))
            return false;

        Group* grp = target->GetGroup();
        if (!grp)
        {
            handler->PSendSysMessage(LANG_LFG_NOT_IN_GROUP, playerName.c_str());
            return true;
        }

        ObjectGuid guid = grp->GetGUID();
        uint32 queueId = sLFGMgr->GetQueueId(guid);
        std::string const& state = lfg::GetStateString(sLFGMgr->GetState(guid, queueId));
        handler->PSendSysMessage(LANG_LFG_GROUP_INFO, grp->isLFGGroup(),
            state.c_str(), sLFGMgr->GetDungeon(guid));

        for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
            GetPlayerInfo(handler, itr->getSource());

        return true;
    }

    static bool HandleLfgOptionsCommand(ChatHandler* handler, char const* args)
    {
        int32 options = -1;
        if (char* str = strtok((char*)args, " "))
        {
            int32 tmp = atoi(str);
            if (tmp > -1)
                options = tmp;
        }

        if (options != -1)
        {
            sLFGMgr->SetOptions(options);
            handler->PSendSysMessage(LANG_LFG_OPTIONS_CHANGED);
        }
        handler->PSendSysMessage(LANG_LFG_OPTIONS, sLFGMgr->GetOptions());
        return true;
    }

    static bool HandleLfgQueueInfoCommand(ChatHandler* handler, char const* args)
    {
        handler->SendSysMessage(sLFGMgr->DumpQueueInfo(atoi(args) != 0).c_str());
        return true;
    }

    static bool HandleLfgCleanCommand(ChatHandler* handler, char const* /*args*/)
    {
        handler->PSendSysMessage(LANG_LFG_CLEAN);
        sLFGMgr->Clean();
        return true;
    }
};

void AddSC_lfg_commandscript()
{
    new lfg_commandscript();
}
