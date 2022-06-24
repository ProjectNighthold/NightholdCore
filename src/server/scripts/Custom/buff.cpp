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

#include "Group.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "Chat.h"

enum spells
{
    INSPIRED_BUFF = 110055,
    BERSERK_BUFF  = 160137,
};

class buff_npc : public CreatureScript
{
public:
    buff_npc() : CreatureScript("buff_npc") {}

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(4, "Buff me!", GOSSIP_SENDER_MAIN, 1);
        player->ADD_GOSSIP_ITEM(4, "Never mind", GOSSIP_SENDER_MAIN, 100);
        player->PlayerTalkClass->SendGossipMenu(9425, creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();

        switch (player->getClass())
        {
        case CLASS_WARRIOR:
        {
            player->AddAura(INSPIRED_BUFF, player);
            player->AddAura(BERSERK_BUFF, player);
            creature->MonsterWhisper("You are now buffed!", player->GetGUID(), true);
        }break;

        case CLASS_PALADIN:
        {
            player->AddAura(INSPIRED_BUFF, player);
            player->AddAura(BERSERK_BUFF, player);
            creature->MonsterWhisper("You are now buffed!", player->GetGUID(), true);
        }break;

        case CLASS_HUNTER:
        {
            player->AddAura(INSPIRED_BUFF, player);
            player->AddAura(BERSERK_BUFF, player);
            creature->MonsterWhisper("You are now buffed!", player->GetGUID(), true);
        }break;

        case CLASS_ROGUE:
        {
            player->AddAura(INSPIRED_BUFF, player);
            player->AddAura(BERSERK_BUFF, player);
            creature->MonsterWhisper("You are now buffed!", player->GetGUID(), true);
        }break;

        case CLASS_PRIEST:
        {
            player->AddAura(INSPIRED_BUFF, player);
            player->AddAura(BERSERK_BUFF, player);
            creature->MonsterWhisper("You are now buffed!", player->GetGUID(), true);
        }break;

        case CLASS_DEATH_KNIGHT:
        {
            player->AddAura(INSPIRED_BUFF, player);
            player->AddAura(BERSERK_BUFF, player);
            creature->MonsterWhisper("You are now buffed!", player->GetGUID(), true);
        }break;

        case CLASS_SHAMAN:
        {
            player->AddAura(INSPIRED_BUFF, player);
            player->AddAura(BERSERK_BUFF, player);
            creature->MonsterWhisper("You are now buffed!", player->GetGUID(), true);
        }break;

        case CLASS_MAGE:
        {
            player->AddAura(INSPIRED_BUFF, player);
            player->AddAura(BERSERK_BUFF, player);
            creature->MonsterWhisper("You are now buffed!", player->GetGUID(), true);
        }break;

        case CLASS_WARLOCK:
        {
            player->AddAura(INSPIRED_BUFF, player);
            player->AddAura(BERSERK_BUFF, player);
            creature->MonsterWhisper("You are now buffed!", player->GetGUID(), true);
        }break;

        case CLASS_DRUID:
        {
            player->AddAura(INSPIRED_BUFF, player);
            player->AddAura(BERSERK_BUFF, player);
            creature->MonsterWhisper("You are now buffed!", player->GetGUID(), true);
        }break;

        case CLASS_DEMON_HUNTER:
        {
            player->AddAura(INSPIRED_BUFF, player);
            player->AddAura(BERSERK_BUFF, player);
            creature->MonsterWhisper("You are now buffed!", player->GetGUID(), true);
        }break;

        case 100:
        {
            player->CLOSE_GOSSIP_MENU();
        }break;

        }
        return true;
    }
};

void AddSC_buff_npc()
{
    new buff_npc();
}