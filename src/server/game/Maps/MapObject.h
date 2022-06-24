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

#ifndef MapObject_h__
#define MapObject_h__

#include "Cell.h"
#include "Position.h"

class Map;
class ObjectGridLoader;

enum MapObjectCellMoveState
{
    MAP_OBJECT_CELL_MOVE_NONE, //not in move list
    MAP_OBJECT_CELL_MOVE_ACTIVE, //in move list
    MAP_OBJECT_CELL_MOVE_INACTIVE, //in move list but should not move
};

class MapObject
{
    friend class Map; //map for moving creatures
    friend class ObjectGridLoader; //grid loader for loading creatures

protected:
    MapObject();

private:
    Cell const& GetCurrentCell() const;
    void SetCurrentCell(Cell const& cell);
    void SetNewCellPosition(float x, float y, float z, float o);
    
    Cell _currentCell;
    MapObjectCellMoveState _moveState;
    Position _newPosition;
};

#endif // MapObject_h__
