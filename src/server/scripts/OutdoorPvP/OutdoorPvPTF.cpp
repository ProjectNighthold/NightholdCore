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
#include "OutdoorPvPTF.h"
#include "Packets/WorldStatePackets.h"
#include "OutdoorPvP.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "Language.h"
#include "World.h"

OutdoorPvPTF::OutdoorPvPTF()
{
    m_TypeId = OUTDOOR_PVP_TF;

    m_IsLocked = false;
    m_LockTimer = TF_LOCK_TIME;
    m_LockTimerUpdate = 0;

    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;

    hours_left = 6;
    second_digit = 0;
    first_digit = 0;
}

OPvPCapturePointTF::OPvPCapturePointTF(OutdoorPvP* pvp, OutdoorPvPTF_TowerType type)
: OPvPCapturePoint(pvp), m_TowerType(type), m_TowerState(TF_TOWERSTATE_N)
{
    SetCapturePointData(TFCapturePoints[type].entry, TFCapturePoints[type].map, TFCapturePoints[type].x, TFCapturePoints[type].y, TFCapturePoints[type].z, TFCapturePoints[type].o, TFCapturePoints[type].rot0, TFCapturePoints[type].rot1, TFCapturePoints[type].rot2, TFCapturePoints[type].rot3);
}

void OPvPCapturePointTF::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(static_cast<WorldStates>(TFTowerWorldStates[m_TowerType].n), bool(m_TowerState & TF_TOWERSTATE_N));
    packet.Worldstates.emplace_back(static_cast<WorldStates>(TFTowerWorldStates[m_TowerType].h), bool(m_TowerState & TF_TOWERSTATE_H));
    packet.Worldstates.emplace_back(static_cast<WorldStates>(TFTowerWorldStates[m_TowerType].a), bool(m_TowerState & TF_TOWERSTATE_A));
}

void OutdoorPvPTF::FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet)
{
    packet.Worldstates.emplace_back(TF_UI_TOWER_SLIDER_POS, 50);
    packet.Worldstates.emplace_back(TF_UI_TOWER_SLIDER_N, 100);
    packet.Worldstates.emplace_back(TF_UI_TOWER_SLIDER_DISPLAY, 0);

    packet.Worldstates.emplace_back(TF_UI_TOWER_COUNT_H, m_HordeTowersControlled);
    packet.Worldstates.emplace_back(TF_UI_TOWER_COUNT_A, m_AllianceTowersControlled);
    packet.Worldstates.emplace_back(TF_UI_TOWERS_CONTROLLED_DISPLAY, !m_IsLocked);

    packet.Worldstates.emplace_back(TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT, first_digit);
    packet.Worldstates.emplace_back(TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT, second_digit);
    packet.Worldstates.emplace_back(TF_UI_LOCKED_TIME_HOURS, hours_left);

    packet.Worldstates.emplace_back(TF_UI_LOCKED_DISPLAY_NEUTRAL, m_IsLocked && !m_HordeTowersControlled && !m_AllianceTowersControlled);
    packet.Worldstates.emplace_back(TF_UI_LOCKED_DISPLAY_HORDE, m_IsLocked && (m_HordeTowersControlled > m_AllianceTowersControlled));
    packet.Worldstates.emplace_back(TF_UI_LOCKED_DISPLAY_ALLIANCE, m_IsLocked && (m_HordeTowersControlled < m_AllianceTowersControlled));

    for (auto itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        itr->second->FillInitialWorldStates(packet);
}

void OutdoorPvPTF::SendRemoveWorldStates(Player* player)
{
    player->SendUpdateWorldState(TF_UI_TOWER_SLIDER_POS, 0);
    player->SendUpdateWorldState(TF_UI_TOWER_SLIDER_N, 0);
    player->SendUpdateWorldState(TF_UI_TOWER_SLIDER_DISPLAY, 0);

    player->SendUpdateWorldState(TF_UI_TOWER_COUNT_H, 0);
    player->SendUpdateWorldState(TF_UI_TOWER_COUNT_A, 0);
    player->SendUpdateWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY, 0);

    player->SendUpdateWorldState(TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT, 0);
    player->SendUpdateWorldState(TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT, 0);
    player->SendUpdateWorldState(TF_UI_LOCKED_TIME_HOURS, 0);

    player->SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL, 0);
    player->SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_HORDE, 0);
    player->SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE, 0);

    for (int i = 0; i < TF_TOWER_NUM; ++i)
    {
        player->SendUpdateWorldState(WorldStates(TFTowerWorldStates[i].n), 0);
        player->SendUpdateWorldState(WorldStates(TFTowerWorldStates[i].h), 0);
        player->SendUpdateWorldState(WorldStates(TFTowerWorldStates[i].a), 0);
    }
}

void OPvPCapturePointTF::UpdateTowerState()
{
    m_PvP->SendUpdateWorldState(WorldStates(TFTowerWorldStates[m_TowerType].n), uint32(bool(m_TowerState & TF_TOWERSTATE_N)));
    m_PvP->SendUpdateWorldState(WorldStates(TFTowerWorldStates[m_TowerType].h), uint32(bool(m_TowerState & TF_TOWERSTATE_H)));
    m_PvP->SendUpdateWorldState(WorldStates(TFTowerWorldStates[m_TowerType].a), uint32(bool(m_TowerState & TF_TOWERSTATE_A)));
}

bool OPvPCapturePointTF::HandlePlayerEnter(Player* player)
{
    if (OPvPCapturePoint::HandlePlayerEnter(player))
    {
        player->SendUpdateWorldState(TF_UI_TOWER_SLIDER_DISPLAY, 1);
        player->SendUpdateWorldState(TF_UI_TOWER_SLIDER_POS, ceil((m_value + m_maxValue) / (2 * m_maxValue) * 100.0f));
        player->SendUpdateWorldState(TF_UI_TOWER_SLIDER_N, m_neutralValuePct);
        return true;
    }
    return false;
}

void OPvPCapturePointTF::HandlePlayerLeave(Player* player)
{
    player->SendUpdateWorldState(TF_UI_TOWER_SLIDER_DISPLAY, 0);
    OPvPCapturePoint::HandlePlayerLeave(player);
}

bool OutdoorPvPTF::Update(uint32 diff)
{
    bool changed = OutdoorPvP::Update(diff);

    if (changed)
    {
        if (m_AllianceTowersControlled == TF_TOWER_NUM)
        {
            TeamApplyBuff(TEAM_ALLIANCE, TF_CAPTURE_BUFF);
            m_IsLocked = true;
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL, 0);
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_HORDE, 0);
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE, 1);
            SendUpdateWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY, 0);
        }
        else if (m_HordeTowersControlled == TF_TOWER_NUM)
        {
            TeamApplyBuff(TEAM_HORDE, TF_CAPTURE_BUFF);
            m_IsLocked = true;
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL, 0);
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_HORDE, 1);
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE, 0);
            SendUpdateWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY, 0);
        }
        else
        {
            TeamCastSpell(TEAM_ALLIANCE, -TF_CAPTURE_BUFF);
            TeamCastSpell(TEAM_HORDE, -TF_CAPTURE_BUFF);
        }
        SendUpdateWorldState(TF_UI_TOWER_COUNT_A, m_AllianceTowersControlled);
        SendUpdateWorldState(TF_UI_TOWER_COUNT_H, m_HordeTowersControlled);
    }
    if (m_IsLocked)
    {
        // lock timer is down, release lock
        if (m_LockTimer < diff)
        {
            m_LockTimer = TF_LOCK_TIME;
            m_LockTimerUpdate = 0;
            m_IsLocked = false;
            SendUpdateWorldState(TF_UI_TOWERS_CONTROLLED_DISPLAY, 1);
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_NEUTRAL, 0);
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_HORDE, 0);
            SendUpdateWorldState(TF_UI_LOCKED_DISPLAY_ALLIANCE, 0);
        }
        else
        {
            // worldstateui update timer is down, update ui with new time data
            if (m_LockTimerUpdate < diff)
            {
                m_LockTimerUpdate = TF_LOCK_TIME_UPDATE;
                uint32 minutes_left = m_LockTimer / 60000;
                hours_left = minutes_left / 60;
                minutes_left -= hours_left * 60;
                second_digit = minutes_left % 10;
                first_digit = minutes_left / 10;

                SendUpdateWorldState(TF_UI_LOCKED_TIME_MINUTES_FIRST_DIGIT, first_digit);
                SendUpdateWorldState(TF_UI_LOCKED_TIME_MINUTES_SECOND_DIGIT, second_digit);
                SendUpdateWorldState(TF_UI_LOCKED_TIME_HOURS, hours_left);
            } else m_LockTimerUpdate -= diff;
            m_LockTimer -= diff;
        }
    }
    return changed;
}

void OutdoorPvPTF::HandlePlayerEnterZone(ObjectGuid guid, uint32 zone)
{
    Player* player = ObjectAccessor::GetObjectInMap(guid, m_map, (Player*)nullptr);
    if (!player)
        return;

    if (player->GetTeam() == ALLIANCE)
    {
        if (m_AllianceTowersControlled >= TF_TOWER_NUM)
            player->CastSpell(player, TF_CAPTURE_BUFF, true);
    }
    else
    {
        if (m_HordeTowersControlled >= TF_TOWER_NUM)
            player->CastSpell(player, TF_CAPTURE_BUFF, true);
    }
    OutdoorPvP::HandlePlayerEnterZone(guid, zone);
}

void OutdoorPvPTF::HandlePlayerLeaveZone(ObjectGuid guid, uint32 zone)
{
    Player* player = ObjectAccessor::GetObjectInMap(guid, m_map, (Player*)nullptr);
    if (!player)
        return;

    // remove buffs
    player->RemoveAurasDueToSpell(TF_CAPTURE_BUFF);
    OutdoorPvP::HandlePlayerLeaveZone(guid, zone);
}

uint32 OutdoorPvPTF::GetAllianceTowersControlled() const
{
    return m_AllianceTowersControlled;
}

void OutdoorPvPTF::SetAllianceTowersControlled(uint32 count)
{
    m_AllianceTowersControlled = count;
}

uint32 OutdoorPvPTF::GetHordeTowersControlled() const
{
    return m_HordeTowersControlled;
}

void OutdoorPvPTF::SetHordeTowersControlled(uint32 count)
{
    m_HordeTowersControlled = count;
}

bool OutdoorPvPTF::IsLocked() const
{
    return m_IsLocked;
}

bool OutdoorPvPTF::SetupOutdoorPvP()
{
    // add the zones affected by the pvp buff
    if (!m_zonesRegistered)
        for (uint8 i = 0; i < OutdoorPvPTFBuffZonesNum; ++i)
            RegisterZone(OutdoorPvPTFBuffZones[i]);

    m_zonesRegistered = true;

    return true;
}

void OutdoorPvPTF::Initialize(uint32 zone)
{
    if (m_zonesRegistered)
        return;

    m_zonesRegistered = true;

    AddCapturePoint(new OPvPCapturePointTF(this, TF_TOWER_NW));
    AddCapturePoint(new OPvPCapturePointTF(this, TF_TOWER_N));
    AddCapturePoint(new OPvPCapturePointTF(this, TF_TOWER_NE));
    AddCapturePoint(new OPvPCapturePointTF(this, TF_TOWER_SE));
    AddCapturePoint(new OPvPCapturePointTF(this, TF_TOWER_S));

    m_AllianceTowersControlled = 0;
    m_HordeTowersControlled = 0;

    m_IsLocked = false;
    m_LockTimer = TF_LOCK_TIME;
    m_LockTimerUpdate = 0;
    hours_left = 6;
    second_digit = 0;
    first_digit = 0;
}

bool OPvPCapturePointTF::Update(uint32 diff)
{
    // can update even in locked state if gathers the controlling faction
    bool canupdate = ((((OutdoorPvPTF*)m_PvP)->GetAllianceTowersControlled() > 0) && m_activePlayers[0].size() > m_activePlayers[1].size()) ||
            ((((OutdoorPvPTF*)m_PvP)->GetHordeTowersControlled() > 0) && m_activePlayers[0].size() < m_activePlayers[1].size());
    // if gathers the other faction, then only update if the pvp is unlocked
    canupdate = canupdate || !((OutdoorPvPTF*)m_PvP)->IsLocked();
    return canupdate && OPvPCapturePoint::Update(diff);
}

void OPvPCapturePointTF::ChangeState()
{
    // if changing from controlling alliance to horde
    if (m_OldState == OBJECTIVESTATE_ALLIANCE)
    {
        if (uint32 alliance_towers = ((OutdoorPvPTF*)m_PvP)->GetAllianceTowersControlled())
            ((OutdoorPvPTF*)m_PvP)->SetAllianceTowersControlled(--alliance_towers);
        sWorld->SendZoneText(OutdoorPvPTFBuffZones[0], sObjectMgr->GetTrinityStringForDBCLocale(LANG_OPVP_TF_LOSE_A));
    }
    // if changing from controlling horde to alliance
    else if (m_OldState == OBJECTIVESTATE_HORDE)
    {
        if (uint32 horde_towers = ((OutdoorPvPTF*)m_PvP)->GetHordeTowersControlled())
            ((OutdoorPvPTF*)m_PvP)->SetHordeTowersControlled(--horde_towers);
        sWorld->SendZoneText(OutdoorPvPTFBuffZones[0], sObjectMgr->GetTrinityStringForDBCLocale(LANG_OPVP_TF_LOSE_H));
    }

    uint32 artkit = 21;

    switch (m_State)
    {
    case OBJECTIVESTATE_ALLIANCE:
    {
        m_TowerState = TF_TOWERSTATE_A;
        artkit = 2;
        uint32 alliance_towers = ((OutdoorPvPTF*)m_PvP)->GetAllianceTowersControlled();
        if (alliance_towers < TF_TOWER_NUM)
            ((OutdoorPvPTF*)m_PvP)->SetAllianceTowersControlled(++alliance_towers);
        sWorld->SendZoneText(OutdoorPvPTFBuffZones[0], sObjectMgr->GetTrinityStringForDBCLocale(LANG_OPVP_TF_CAPTURE_A));
        for (PlayerSet::iterator itr = m_activePlayers[0].begin(); itr != m_activePlayers[0].end(); ++itr)
            (*itr)->AreaExploredOrEventHappens(TF_ALLY_QUEST);
        break;
    }
    case OBJECTIVESTATE_HORDE:
    {
        m_TowerState = TF_TOWERSTATE_H;
        artkit = 1;
        uint32 horde_towers = ((OutdoorPvPTF*)m_PvP)->GetHordeTowersControlled();
        if (horde_towers < TF_TOWER_NUM)
            ((OutdoorPvPTF*)m_PvP)->SetHordeTowersControlled(++horde_towers);
        sWorld->SendZoneText(OutdoorPvPTFBuffZones[0], sObjectMgr->GetTrinityStringForDBCLocale(LANG_OPVP_TF_CAPTURE_H));
        for (PlayerSet::iterator itr = m_activePlayers[1].begin(); itr != m_activePlayers[1].end(); ++itr)
            (*itr)->AreaExploredOrEventHappens(TF_HORDE_QUEST);
        break;
    }
    case OBJECTIVESTATE_NEUTRAL:
    case OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE:
    case OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE:
    case OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE:
    case OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE:
        m_TowerState = TF_TOWERSTATE_N;
        break;
    }

    if (GameObject* flag = sObjectAccessor->FindGameObject(m_capturePointGUID))
        flag->SetGoArtKit(artkit);

    UpdateTowerState();
}

void OPvPCapturePointTF::SendChangePhase()
{
    SendUpdateWorldState(TF_UI_TOWER_SLIDER_DISPLAY, 1);
    SendUpdateWorldState(TF_UI_TOWER_SLIDER_POS, ceil((m_value + m_maxValue) / (2 * m_maxValue) * 100.0f));
    SendUpdateWorldState(TF_UI_TOWER_SLIDER_N, m_neutralValuePct);
}

class OutdoorPvP_terokkar_forest : public OutdoorPvPScript
{
    public:

        OutdoorPvP_terokkar_forest()
            : OutdoorPvPScript("outdoorpvp_tf")
        {
        }

        OutdoorPvP* GetOutdoorPvP() const override
        {
            return new OutdoorPvPTF();
        }
};

void AddSC_outdoorpvp_tf()
{
    new OutdoorPvP_terokkar_forest();
}
