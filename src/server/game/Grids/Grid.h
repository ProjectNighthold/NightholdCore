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

#ifndef TRINITY_GRID_H
#define TRINITY_GRID_H

/*
  @class Grid
  Grid is a logical segment of the game world represented inside TrinIty.
  Grid is bind at compile time to a particular type of object which
  we call it the object of interested.  There are many types of loader,
  specially, dynamic loader, static loader, or on-demand loader.  There's
  a subtle difference between dynamic loader and on-demand loader but
  this is implementation specific to the loader class.  From the
  Grid's perspective, the loader meets its API requirement is suffice.
  */

#include "Define.h"
#include "TypeContainer.h"
#include "TypeContainerVisitor.h"

class Corpse;
class Creature;
class DynamicObject;
class GameObject;
class Pet;
class Player;
class AreaTrigger;
class EventObject;

class Grid final
{
public:
    typedef TYPELIST_7(GameObject, Creature/*except pets*/, DynamicObject, Corpse/*Bones*/, AreaTrigger, Conversation, EventObject) GridObjectTypeList;

    // Creature used instead pet to simplify *::Visit templates (not required duplicate code for Creature->Pet case)
    typedef TYPELIST_7(Player, Creature/*pets*/, Corpse/*resurrectable*/, DynamicObject/*farsight target*/, AreaTrigger, Conversation, EventObject) WorldObjectTypeList;

    typedef Trinity::TypeMapContainer<GridObjectTypeList> GridObjectMap;

    typedef Trinity::TypeMapContainer<WorldObjectTypeList> WorldObjectMap;

    template <typename SpecificObject>
    void AddWorldObject(SpecificObject *obj)
    {
        i_worldObjects.insert<SpecificObject>(obj);
    }

    template<typename SpecificObject>
    void AddGridObject(SpecificObject *obj)
    {
        i_gridObjects.insert<SpecificObject>(obj);
    }

    template <typename T>
    std::size_t GetWorldObjectCountInGrid() const
    {
        return i_worldObjects.count<T>();
    }

    // Visit grid objects
    template <typename T>
    void Visit(Trinity::TypeContainerVisitor<T, GridObjectMap> &visitor)
    {
        visitor.Visit(i_gridObjects);
    }

    // Visit world objects
    template <typename T>
    void Visit(Trinity::TypeContainerVisitor<T, WorldObjectMap> &visitor)
    {
        visitor.Visit(i_worldObjects);
    }

private:
    GridObjectMap i_gridObjects;
    WorldObjectMap i_worldObjects;
};

namespace Trinity
{

template <typename T>
TypeContainerVisitor<T, Grid::GridObjectMap> makeGridVisitor(T &searcher)
{
    return TypeContainerVisitor<T, Grid::GridObjectMap>(searcher);
}

template <typename T>
TypeContainerVisitor<T, Grid::WorldObjectMap> makeWorldVisitor(T &searcher)
{
    return TypeContainerVisitor<T, Grid::WorldObjectMap>(searcher);
}

} // namespace Trinity

#endif
