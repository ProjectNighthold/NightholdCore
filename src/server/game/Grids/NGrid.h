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

#ifndef TRINITY_NGRID_H
#define TRINITY_NGRID_H

/** NGrid is nothing more than a wrapper of the Grid with an NxN cells
 */

#include "Grid.h"
#include "GridDefines.h"
#include "GridInfo.h"

#define DEFAULT_VISIBILITY_NOTIFY_PERIOD 1000

enum GridState
{
    GRID_STATE_INVALID,
    GRID_STATE_ACTIVE,
    GRID_STATE_IDLE,
    GRID_STATE_REMOVAL,
    MAX_GRID_STATE
};

class NGrid final
{
public:
    NGrid(int32 x, int32 y, time_t expiry, bool unload = true);
    Grid& GetGrid(const uint32 x, const uint32 y);
    Grid const& GetGrid(const uint32 x, const uint32 y) const;

    GridState GetGridState() const;
    void SetGridState(GridState s);

    int32 getX() const;
    int32 getY() const;

    bool isGridObjectDataLoaded() const;
    void setGridObjectDataLoaded(bool pLoaded);

    GridInfo& getGridInfo();

    const TimeTracker& getTimeTracker() const;

    bool getUnloadLock() const;
    void setUnloadReferenceLock(bool on);
    void incUnloadActiveLock();
    void decUnloadActiveLock();

    void ResetTimeTracker(time_t interval);
    void UpdateTimeTracker(time_t diff);

    // Visit all Grids (cells) in NGrid (grid)
    template <typename Visitor>
    void VisitAllGrids(Visitor &&visitor)
    {
        for (auto &cell : i_cells)
            cell.Visit(visitor);
    }

    // Visit a single Grid (cell) in NGrid (grid)
    template <typename Visitor>
    void VisitGrid(const uint32 x, const uint32 y, Visitor &&visitor)
    {
        GetGrid(x, y).Visit(visitor);
    }

    template <typename T>
    std::size_t GetWorldObjectCountInNGrid() const
    {
        std::size_t count = 0;
        for (auto &cell : i_cells)
            count += cell.GetWorldObjectCountInGrid<T>();
        return count;
    }

private:
    GridInfo i_GridInfo;
    int32 i_x;
    int32 i_y;
    GridState i_cellstate;
    Grid i_cells[MAX_NUMBER_OF_CELLS * MAX_NUMBER_OF_CELLS];
    bool i_GridObjectDataLoaded;
};

#endif
