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

#include "MapObject.h"

MapObject::MapObject()
{
    _moveState = MAP_OBJECT_CELL_MOVE_NONE;
    _newPosition.Relocate(0.0f, 0.0f, 0.0f, 0.0f);
}

Cell const& MapObject::GetCurrentCell() const
{
    return _currentCell;
}

void MapObject::SetCurrentCell(Cell const& cell)
{
    _currentCell = cell;
}

void MapObject::SetNewCellPosition(float x, float y, float z, float o)
{
    _moveState = MAP_OBJECT_CELL_MOVE_ACTIVE;
    _newPosition.Relocate(x, y, z, o);
}
