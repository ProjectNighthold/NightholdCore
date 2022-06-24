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

#ifndef _DYNTREE_H
#define _DYNTREE_H

#include "Define.h"
#include <set>
;
namespace G3D
{
    class Ray;
    class Vector3;
}

class GameObjectModel;
struct DynTreeImpl;
class GameObject;

struct DynamicTreeCallback
{
    GameObject* go = nullptr;
};

typedef std::lock_guard<std::recursive_mutex> RecursiveGuard;

class DynamicMapTree
{
    DynTreeImpl *impl;

public:

    DynamicMapTree();
    ~DynamicMapTree();

    bool isInLineOfSight(G3D::Vector3 const& startPos, G3D::Vector3 const& endPos, std::set<uint32> const& phases, DynamicTreeCallback* dCallback = nullptr) const;
    bool getIntersectionTime(std::set<uint32> const& phases, G3D::Ray const& ray, G3D::Vector3 const& endPos, float& maxDist, DynamicTreeCallback* dCallback = nullptr) const;
    bool getObjectHitPos(std::set<uint32> const& phases, G3D::Vector3 const& startPos, G3D::Vector3 const& endPos, G3D::Vector3& resultHitPos, float modifyDist, DynamicTreeCallback* dCallback = nullptr) const;

    float getHeight(float x, float y, float z, float maxSearchDist, std::set<uint32> const& phases, DynamicTreeCallback* dCallback = nullptr) const;
    bool getAreaInfo(float x, float y, float& z, std::set<uint32> const& phases, uint32& flags, int32& adtId, int32& rootId, int32& groupId) const;

    void insert(const GameObjectModel&);
    void remove(const GameObjectModel&);
    bool contains(const GameObjectModel&) const;

    void balance();
    void update(uint32 diff);
    mutable std::recursive_mutex dynamic_lock;
};

#endif // _DYNTREE_H
