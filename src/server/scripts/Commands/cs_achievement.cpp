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
Name: achievement_commandscript
%Complete: 100
Comment: All achievement related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "AchievementMgr.h"

class achievement_commandscript : public CommandScript
{
public:
    achievement_commandscript() : CommandScript("achievement_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> achievementCommandTable=
        {
            { "add",            SEC_ADMINISTRATOR,  false,  &HandleAchievementAddCommand,      ""},
            { "criteria",       SEC_ADMINISTRATOR,  false,  &HandleAchievementCriteriaCommand, ""},
            { "info",           SEC_ADMINISTRATOR,  false,  &HandleAchievementInfoCommand,     ""},
            { "delete",         SEC_ADMINISTRATOR,  false,  &HandleAchievementDeleteCommand,   ""}
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "achievement",    SEC_ADMINISTRATOR,  false, NULL,            "", achievementCommandTable }
        };
        return commandTable;
    }

    static bool HandleAchievementAddCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 achievementId = atoi((char*)args);
        if (!achievementId)
        {
            if (char* id = handler->extractKeyFromLink((char*)args, "Hachievement"))
                achievementId = atoi(id);
            if (!achievementId)
                return false;
        }

        Player* target = handler->getSelectedPlayer();
        if (!target)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (AchievementEntry const* achievementEntry = sAchievementStore.LookupEntry(achievementId))
            target->CompletedAchievement(achievementEntry);

        return true;
    }

    static bool HandleAchievementCriteriaCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* criteriatr = strtok((char*)args, " ");
        char* miscValueStr1 = strtok(NULL, " ");
        char* miscValueStr2 = strtok(NULL, " ");
        char* miscValueStr3 = strtok(NULL, " ");

        uint32 criteriaType = criteriatr ? atoi(criteriatr) : 0;
        uint32 miscValue1 = miscValueStr1 ? atoi(miscValueStr1) : 0;
        uint32 miscValue2 = miscValueStr2 ? atoi(miscValueStr2) : 0;
        uint32 miscValue3 = miscValueStr3 ? atoi(miscValueStr3) : 0;
        TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "HandleAchievementCriteriaCommand criteriaType %i miscValue1 %i miscValue2 %i, miscValue3 %i", criteriaType, miscValue1, miscValue2, miscValue3);

        if(Player* player = handler->GetSession()->GetPlayer())
        {
            if(!criteriaType)
                player->KilledMonsterCredit(miscValue1);

            player->UpdateAchievementCriteria(CriteriaTypes(criteriaType), miscValue1, miscValue2, miscValue3, handler->getSelectedUnit(), true);
        }

        return true;
    }

    static bool HandleAchievementInfoCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 achievementId = atoi((char*)args);
        if (!achievementId)
        {
            if (char* id = handler->extractKeyFromLink((char*)args, "Hachievement"))
                achievementId = atoi(id);
            if (!achievementId)
                return false;
        }

        // if (AchievementEntry const* achievement = sAchievementStore.LookupEntry(achievementId))
        // {
            // TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "AchievementInfo achievement %u", achievement->ID);

            // if(Player* player = handler->GetSession()->GetPlayer())
            // {
                // TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "AchievementInfo player %u", achievement->ID);
                // if(CriteriaProgressTree* treeProgress = player->GetAchievementMgr().GetCriteriaTreeProgressMap(achievement->CriteriaTree))
                // {
                    // TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "AchievementInfo criteriaTree %u, achievement %u ChildrenTree %u ChildrenCriteria %u", achievement->CriteriaTree, achievement->ID, treeProgress->ChildrenTree.size(), treeProgress->ChildrenCriteria.size());

                    // for (std::vector<CriteriaProgressTree*>::iterator itr = treeProgress->ChildrenTree.begin(); itr != treeProgress->ChildrenTree.end(); ++itr)
                        // TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "AchievementInfo ChildrenTree criteriaTree %u parent %u", (*itr)->criteriaTree->ID, (*itr)->criteriaTree->Parent);

                    // for (std::vector<CriteriaTreeProgress const*>::const_iterator itr = treeProgress->ChildrenCriteria.begin(); itr != treeProgress->ChildrenCriteria.end(); ++itr)
                    // {
                        // CriteriaTreeProgress const* progress = *itr;
                        // if(!progress)
                        // {
                            // TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "AchievementInfo ChildrenCriteria error progress achievement %u", achievement->ID);
                            // continue;
                        // }
                        // CriteriaEntry const* criteria = progress->criteria;
                        // if(!criteria)
                        // {
                            // TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "AchievementInfo ChildrenCriteria error criteria achievement %u criteriaTree %u parent %u", achievement->ID, progress->criteriaTree->ID, progress->parent->ID);
                            // continue;
                        // }
                        // TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "AchievementInfo ChildrenCriteria criteria achievement %u criteriaTree %u parent %u criteria %u completed %i deactiveted %i",
                        // achievement->ID, progress->criteriaTree ? progress->criteriaTree->ID : 0, progress->parent ? progress->parent->ID : 0, criteria->ID, progress->completed, progress->deactiveted);
                    // }
                // }
            // }
        // }
        // else
            TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "AchievementInfo error achievement %u not found", achievementId);

        return true;
    }

    static bool HandleAchievementDeleteCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* achievtr = strtok((char*)args, " ");

        uint32 achievmentID = achievtr ? atoi(achievtr) : 0;
        TC_LOG_DEBUG(LOG_FILTER_ACHIEVEMENTSYS, "HandleAchievementDeleteCommand achievmentID %i", achievmentID);
        if (!achievmentID)
            return false;

        Player* player = handler->getSelectedPlayer();
        if (!player)
            player = handler->GetSession()->GetPlayer();

        if(player)
        {
            CharacterDatabase.PExecute("DELETE FROM account_achievement WHERE achievement = '%u' AND account = '%u'", achievmentID, player->GetSession()->GetAccountId());
            CharacterDatabase.PExecute("DELETE FROM character_achievement WHERE achievement = '%u' AND guid = '%u'", achievmentID, player->GetGUIDLow());
        }

        return true;
    }
};

void AddSC_achievement_commandscript()
{
    new achievement_commandscript();
}
