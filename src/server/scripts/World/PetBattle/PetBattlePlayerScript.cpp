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
#include "PetBattle.h"
#include "Common.h"
#include "PetBattleSystem.h"

class PlayerScriptPetBattle : public PlayerScript
{
public:
    PlayerScriptPetBattle() : PlayerScript("PlayerScriptPetBattle") { }

    void OnMovementInform(Player* player, uint32 mveType, uint32 id) override
    {
        if (player && mveType == POINT_MOTION_TYPE && id == PETBATTLE_ENTER_MOVE_SPLINE_ID)
        {
            m_Mutex.lock();
            m_DelayedPetBattleStart[player->GetGUID()] = getMSTime() + 1000;
            m_Mutex.unlock();
        }
    }

    void OnUpdate(Player* player, uint32 /*diff*/) override
    {
        m_Mutex.lock();

        if (m_DelayedPetBattleStart.find(player->GetGUID()) != m_DelayedPetBattleStart.end())
        {
            if (m_DelayedPetBattleStart[player->GetGUID()] > getMSTime())
            {
                m_DelayedPetBattleStart.erase(m_DelayedPetBattleStart.find(player->GetGUID()));

                if (PetBattle* battle = sPetBattleSystem->GetBattle(player->_petBattleId))
                {
                    player->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_IMMUNE_TO_NPC); // Immuned only to NPC
                    player->SetControlled(true, UNIT_STATE_ROOT);
                    battle->Begin();
                }
            }
        }

        m_Mutex.unlock();
    }

    std::map<ObjectGuid, uint32> m_DelayedPetBattleStart;
    std::mutex m_Mutex;
};

void AddSC_PetBattlePlayerScript()
{
    new PlayerScriptPetBattle;
}
