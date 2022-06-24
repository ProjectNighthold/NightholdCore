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

#ifndef TRINITY_CELLIMPL_H
#define TRINITY_CELLIMPL_H

#include "Cell.h"
#include "Map.h"
#include "Object.h"

inline Cell::Cell(CellCoord const& p)
{
    data.Part.grid_x = p.x_coord / MAX_NUMBER_OF_CELLS;
    data.Part.grid_y = p.y_coord / MAX_NUMBER_OF_CELLS;
    data.Part.cell_x = p.x_coord % MAX_NUMBER_OF_CELLS;
    data.Part.cell_y = p.y_coord % MAX_NUMBER_OF_CELLS;
    data.Part.nocreate = 0;
    data.Part.reserved = 0;
}

inline Cell::Cell(float x, float y)
{
    CellCoord p = Trinity::ComputeCellCoord(x, y);
    data.Part.grid_x = p.x_coord / MAX_NUMBER_OF_CELLS;
    data.Part.grid_y = p.y_coord / MAX_NUMBER_OF_CELLS;
    data.Part.cell_x = p.x_coord % MAX_NUMBER_OF_CELLS;
    data.Part.cell_y = p.y_coord % MAX_NUMBER_OF_CELLS;
    data.Part.nocreate = 0;
    data.Part.reserved = 0;
}

inline CellArea Cell::CalculateCellArea(float x, float y, float radius)
{
    if (radius <= 0.0f)
    {
        CellCoord center = Trinity::ComputeCellCoord(x, y).normalize();
        return CellArea(center, center);
    }

    CellCoord centerX = Trinity::ComputeCellCoord(x - radius, y - radius).normalize();
    CellCoord centerY = Trinity::ComputeCellCoord(x + radius, y + radius).normalize();

    return CellArea(centerX, centerY);
}

template <typename Visitor>
void Cell::Visit(CellCoord const& standing_cell, Visitor &&visitor, Map& map, float radius, float x_off, float y_off) const
{
    if (!standing_cell.IsCoordValid())
        return;

    //ALWAYS visit standing cell first!!! Since we deal with small radiuses
    //it is very essential to call visitor for standing cell firstly...
    map.Visit(*this, std::forward<Visitor>(visitor));

    //no jokes here... Actually placing ASSERT() here was good idea, but
    //we had some problems with DynamicObjects, which pass radius = 0.0f (DB issue?)
    //maybe it is better to just return when radius <= 0.0f?
    if (radius <= 0.0f)
        return;

    //lets limit the upper value for search radius
    if (radius > SIZE_OF_GRIDS)
        radius = SIZE_OF_GRIDS;

    //lets calculate object coord offsets from cell borders.
    CellArea area = Cell::CalculateCellArea(x_off, y_off, radius);
    //if radius fits inside standing cell
    if (!area)
        return;

    //visit all cells, found in CalculateCellArea()
    //if radius is known to reach cell area more than 4x4 then we should call optimized VisitCircle
    //currently this technique works with MAX_NUMBER_OF_CELLS 16 and higher, with lower values
    //there are nothing to optimize because SIZE_OF_GRID_CELL is too big...
    if ((area.high_bound.x_coord > (area.low_bound.x_coord + 4)) && (area.high_bound.y_coord > (area.low_bound.y_coord + 4)))
        return VisitCircle(visitor, map, area.low_bound, area.high_bound, standing_cell);

    // loop the cell range
    for (uint32 x = area.low_bound.x_coord; x <= area.high_bound.x_coord; ++x)
    {
        for (uint32 y = area.low_bound.y_coord; y <= area.high_bound.y_coord; ++y)
        {
            CellCoord cellCoord(x, y);
            //lets skip standing cell since we already visited it
            if (cellCoord != standing_cell)
            {
                Cell r_zone(cellCoord);
                r_zone.data.Part.nocreate = this->data.Part.nocreate;
                map.Visit(r_zone, std::forward<Visitor>(visitor));
            }
        }
    }
}

template <typename Visitor>
void Cell::Visit(CellCoord const& standing_cell, Visitor &&visitor, Map& map, WorldObject const& obj, float radius) const
{
    //we should increase search radius by object's radius, otherwise
    //we could have problems with huge creatures, which won't attack nearest players etc
    Visit(standing_cell, std::forward<Visitor>(visitor), map, radius + obj.GetObjectSize(), obj.GetPositionX(), obj.GetPositionY());
}

template <typename Visitor>
void Cell::VisitCircle(Visitor &visitor, Map& map, CellCoord const& begin_cell, CellCoord const& end_cell, CellCoord const &standing_cell) const
{
    //here is an algorithm for 'filling' circum-squared octagon
    uint32 x_shift = (uint32)ceilf((end_cell.x_coord - begin_cell.x_coord) * 0.3f - 0.5f);
    //lets calculate x_start/x_end coords for central strip...
    const uint32 x_start = begin_cell.x_coord + x_shift;
    const uint32 x_end = end_cell.x_coord - x_shift;

    //visit central strip with constant width...
    for (uint32 x = x_start; x <= x_end; ++x)
    {
        for (uint32 y = begin_cell.y_coord; y <= end_cell.y_coord; ++y)
        {
            CellCoord cellCoord(x, y);
            if (cellCoord != standing_cell)
            {
                Cell r_zone(cellCoord);
                r_zone.data.Part.nocreate = this->data.Part.nocreate;
                map.Visit(r_zone, visitor);
            }
        }
    }

    //if x_shift == 0 then we have too small cell area, which were already
    //visited at previous step, so just return from procedure...
    if (x_shift == 0)
        return;

    uint32 y_start = end_cell.y_coord;
    uint32 y_end = begin_cell.y_coord;

    //now we are visiting borders of an octagon...
    for (uint32 step = 1; step <= (x_start - begin_cell.x_coord); ++step)
    {
        //each step reduces strip height by 2 cells...
        y_end += 1;
        y_start -= 1;
        for (uint32 y = y_start; y >= y_end; --y)
        {
            //we visit cells symmetrically from both sides, heading from center to sides and from up to bottom
            //e.g. filling 2 trapezoids after filling central cell strip...
            CellCoord cellCoord_left(x_start - step, y);
            if (cellCoord_left != standing_cell)
            {
                Cell r_zone_left(cellCoord_left);
                r_zone_left.data.Part.nocreate = this->data.Part.nocreate;
                map.Visit(r_zone_left, visitor);
            }

            //right trapezoid cell visit
            CellCoord cellCoord_right(x_end + step, y);
            if (cellCoord_right != standing_cell)
            {
                Cell r_zone_right(cellCoord_right);
                r_zone_right.data.Part.nocreate = this->data.Part.nocreate;
                map.Visit(r_zone_right, visitor);
            }
        }
    }
}

#endif
