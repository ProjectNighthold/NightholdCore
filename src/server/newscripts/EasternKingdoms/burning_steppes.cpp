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
SDName: Burning_Steppes
SD%Complete: 0
SDComment:
SDCategory: Burning Steppes
EndScriptData */


#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

class at_wod_dark_portal : public AreaTriggerScript
{
public:
    at_wod_dark_portal() : AreaTriggerScript("at_wod_dark_portal") { }

    enum spells
    {
        SPELL_TIME_SHIFT = 176111,

        SPELL_ASHRAN_TELE = 176809,
        SPELL_ASHRAN_HORDE = 173143,  //5352.16 Y: -3944.96 Z: 32.7331 O: 3.921144
        SPELL_ASHRAN_ALLIANCE = 167220,
        SPELL_TELE_OUT_ALLIANCE = 167221, //Teleport Out: Alliance / 2308.57 Y: 447.469 Z: 5.11977 O: 2.199202
        SPELL_TELE_OUT_HORDE = 167220,//Teleport Out: Alliance

        SPELL_TELE_INTRO = 167771,
        MOVIE_HORDE = 185,
        MOVIE_ALLIANCE = 187,

        QUEST__A = 35884,
        QUEST__H = 34446,
    };

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/, bool /*enter*/)
    {
        if (player->getLevel() < 90 || player->HasAura(SPELL_TIME_SHIFT))
            return false;       //tele to outlend

        if (player->GetQuestStatus(QUEST__A) == QUEST_STATUS_REWARDED ||
            player->GetQuestStatus(QUEST__H) == QUEST_STATUS_REWARDED)
        {
            player->CastSpell(player, player->GetTeam() == HORDE ? SPELL_TELE_OUT_HORDE : SPELL_TELE_OUT_ALLIANCE);
        }
        else
            player->CastSpell(player, SPELL_TELE_INTRO);

        return true;
    }
};

void AddSC_burning_steppes()
{
    new at_wod_dark_portal();
}
