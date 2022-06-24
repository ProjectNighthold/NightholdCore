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

template<uint32 t_Level> class BattlePay_Level : BattlePayProductScript
{
public:
    explicit BattlePay_Level(std::string scriptName) : BattlePayProductScript(scriptName) {}

    void OnProductDelivery(WorldSession* session, Battlepay::Product const& /*product*/) override
    {
        auto player = session->GetPlayer();
        if (!player)
            return;

        player->GiveLevel(t_Level);
        player->SaveToDB();
    }

    bool CanBuy(WorldSession* session, Battlepay::Product const& /*product*/, std::string& reason) override
    {
        auto player = session->GetPlayer();
        if (!player)
        {
            reason = sObjectMgr->GetTrinityString(Battlepay::String::NeedToBeInGame, session->GetSessionDbLocaleIndex());
            return false;
        }

        if (t_Level <= player->getLevel())
        {
            reason = sObjectMgr->GetTrinityString(Battlepay::String::TooHighLevel, session->GetSessionDbLocaleIndex());
            return false;
        }

        return true;
    }
};

template <uint32 t_AccountServiceFlag> class BattlePay_AccountService : BattlePayProductScript
{
public:
    explicit BattlePay_AccountService(std::string scriptName) : BattlePayProductScript(scriptName) {}

    void OnProductDelivery(WorldSession* /*session*/, Battlepay::Product const& /*product*/) override
    {
        //session->SetServiceFlags(t_AccountServiceFlag);
    }

    bool CanBuy(WorldSession* /*session*/, Battlepay::Product const& /*product*/, std::string& reason) override
    {

        return true;
    }
};

void AddSC_BattlePay_Services()
{
    new BattlePay_Level<100>("battlepay_service_level100");
    //new BattlePay_AccountService<ServiceFlags::PremadePve>("battlepay_service_premade");
}
