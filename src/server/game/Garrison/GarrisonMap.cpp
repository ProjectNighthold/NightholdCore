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

#include "GarrisonMap.h"
#include "Garrison.h"
#include "ObjectAccessor.h"
#include "ObjectGridLoader.h"
#include "GameObject.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"

GarrisonMap::GarrisonMap(uint32 id, time_t expiry, uint32 instanceId, Map* parent, ObjectGuid const& owner) : InstanceMap(id, expiry, instanceId, DIFFICULTY_NORMAL, parent), _owner(owner)
{
    GarrisonMap::InitVisibilityDistance();
}

Garrison* GarrisonMap::GetGarrison()
{
    if (_garrison)
        return _garrison;

    if (Player* owner = ObjectAccessor::FindPlayer(_owner))
        _garrison = owner->GetGarrisonPtr();

    return _garrison;
}

void GarrisonMap::InitVisibilityDistance()
{
    //init visibility distance for instances
    m_VisibleDistance = sWorld->GetMaxVisibleDistanceInBG();
    m_VisibilityNotifyPeriod = World::GetVisibilityNotifyPeriodInBGArenas();
}

bool GarrisonMap::AddPlayerToMap(Player* player, bool initPlayer /*= true*/)
{
    if (player->GetGUID() == _owner)
        _garrison = player->GetGarrisonPtr();

    return InstanceMap::AddPlayerToMap(player, initPlayer);
}

bool GarrisonMap::onEnsureGridLoaded(NGrid* grid, Cell const& _cell)
{
    if (!_garrison)
        return false;

    if (!_garrison->_plots.empty())
    {
        Cell i_cell = _cell;
        i_cell.data.Part.cell_y = 0;
        for (uint32 x = 0; x < MAX_NUMBER_OF_CELLS; ++x)
        {
            i_cell.data.Part.cell_x = x;
            for (uint32 y = 0; y < MAX_NUMBER_OF_CELLS; ++y)
            {
                i_cell.data.Part.cell_y = y;

                CellCoord cellCoord = i_cell.GetCellCoord();
                for (auto& plot : _garrison->_plots)
                {
                    Position const& spawn = plot.second.PacketInfo.PlotPos;
                    CellCoord const spawnCoord = Trinity::ComputeCellCoord(spawn.GetPositionX(), spawn.GetPositionY());
                    if (cellCoord != spawnCoord)
                        continue;

                    if (GameObject* go = plot.second.CreateGameObject(this, _garrison->GetFaction(), _garrison))
                        AddToMap(go);
                }
            }
        }
    }
    return true;
}