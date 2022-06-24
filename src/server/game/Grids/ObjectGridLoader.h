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

#ifndef TRINITY_OBJECTGRIDLOADER_H
#define TRINITY_OBJECTGRIDLOADER_H

#include "Define.h"
#include "GridDefines.h"
#include "Cell.h"

namespace Trinity {

struct ObjectGridLoader final
{
    static void LoadN(NGrid const &grid, Map *map, Cell cell);
};

//Stop the creatures before unloading the NGrid
struct ObjectGridStoper final
{
    void Visit(CreatureMapType &m);

    template <typename NotInterested>
    void Visit(NotInterested &) { }
    std::mutex _lock;
};

// Move the foreign creatures back to respawn positions before unloading the NGrid
struct ObjectGridEvacuator final
{
    void Visit(CreatureMapType &m);
    void Visit(GameObjectMapType &m);

    template <typename NotInterested>
    void Visit(NotInterested &) { }
};

// Clean up and remove from world
struct ObjectGridCleaner final
{
    template <typename AnyMapType>
    void Visit(AnyMapType &m);
};

// Delete objects before deleting NGrid
struct ObjectGridUnloader final
{
    template <typename AnyMapType>
    void Visit(AnyMapType &m);
    std::mutex _lock;
};

} // namespace Trinity

#endif
