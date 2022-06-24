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

#ifndef _GAMEOBJECT_MODEL_H
#define _GAMEOBJECT_MODEL_H

#include <G3D/Matrix3.h>
#include <G3D/Vector3.h>
#include <G3D/AABox.h>
#include <G3D/Ray.h>

#include "Define.h"
#include <memory>
#include <set>

namespace VMAP
{
    class WorldModel;
    struct AreaInfo;
}

class GameObject;
struct GameObjectDisplayInfoEntry;

class GameObjectModelOwnerBase
{
public:
    virtual ~GameObjectModelOwnerBase() = default;

    virtual bool IsSpawned() const { return false; }
    virtual uint32 GetDisplayId() const { return 0; }
    virtual uint8 GetNameSetId() const = 0;
    virtual bool IsDoor() const { return false; }
    virtual uint32 GetPhaseMask() const { return 0; }
    virtual bool InSamePhaseId(std::set<uint32> const& /*phases*/) const { return false; }
    virtual G3D::Vector3 GetPosition() const { return G3D::Vector3::zero(); }
    virtual float GetOrientation() const { return 0.0f; }
    virtual float GetScale() const { return 1.0f; }
    virtual void DebugVisualizeCorner(G3D::Vector3 const& /*corner*/) const { }
    virtual GameObject const* GetOwner() const { return nullptr; }
    virtual uint32 GetGUIDLow() const { return 0; }
};

class GameObjectModel /*, public Intersectable*/
{
    GameObjectModel() : _collisionEnabled(false), iInvScale(0), iScale(0), iModel(nullptr), isWmo(false) { }
public:
    std::string name;

    const G3D::AABox& getBounds() const { return iBound; }

    ~GameObjectModel();

    const G3D::Vector3& getPosition() const { return iPos;}

    /* Enables/disables collision */
    void enableCollision(bool enable) { _collisionEnabled = enable; }
    bool isCollisionEnabled() const { return _collisionEnabled; }
    bool isMapObject() const { return isWmo; }

    bool intersectRay(G3D::Ray const& ray, float& maxDist, bool stopAtFirstHit, std::set<uint32> const& phases) const;
    bool intersectLine(G3D::Ray const& ray, float& maxDist, bool stopAtFirstHit, std::set<uint32> const& phases) const;

    bool isInLineOfSight(G3D::Vector3 const& startPos, G3D::Vector3 const& endPos, std::set<uint32> const& phases) const;
    bool getObjectHitPos(std::set<uint32> const& phases, G3D::Vector3 const& startPos, G3D::Vector3 const& endPos, G3D::Vector3& resultHitPos, float modifyDist) const;
    float getHeight(float x, float y, float z, float maxSearchDist, std::set<uint32> const& phases) const;
    void intersectPoint(G3D::Vector3 const& point, VMAP::AreaInfo& info, std::set<uint32> const& phases) const;

    static GameObjectModel* Create(std::unique_ptr<GameObjectModelOwnerBase> modelOwner, std::string const& dataPath);

    bool UpdatePosition();
    std::unique_ptr<GameObjectModelOwnerBase> owner;

private:
    bool initialize(std::unique_ptr<GameObjectModelOwnerBase> modelOwner, std::string const& dataPath);

    bool _collisionEnabled;
    G3D::AABox iBound;
    G3D::Matrix3 iInvRot;
    G3D::Vector3 iPos;
    float iInvScale;
    float iScale;
    VMAP::WorldModel* iModel;
    bool isWmo;
};

void LoadGameObjectModelList(std::string const& dataPath);

#endif // _GAMEOBJECT_MODEL_H
