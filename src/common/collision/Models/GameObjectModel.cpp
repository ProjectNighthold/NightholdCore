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

#include "VMapFactory.h"
#include "VMapManager2.h"
#include "VMapDefinitions.h"
#include "WorldModel.h"
#include "GameObjectModel.h"
#include "Log.h"
#include "MapTree.h"
#include "Timer.h"

using G3D::Vector3;
using G3D::Ray;
using G3D::AABox;

struct GameobjectModelData
{
    GameobjectModelData(char const* name_, uint32 nameLength, Vector3 const& lowBound, Vector3 const& highBound, bool isWmo_) :
        bound(lowBound, highBound), name(name_, nameLength), isWmo(isWmo_) { }

    AABox bound;
    std::string name;
    bool isWmo;
};

struct ModelTreeIntersectionCallback
{
    ModelTreeIntersectionCallback(std::set<uint32> const& phases) : _didHit(false), _phases(phases), _go(0) { }

    bool operator()(G3D::Ray const& r, GameObjectModel const& obj, float& distance)
    {
        _didHit = obj.intersectRay(r, distance, true, _phases);
        if (_didHit)
        {
            if (obj.owner->IsDoor()) // Collision for door
                distance = distance > 1.0f ? distance - 1.0f : 0.0f;
            _go = const_cast<GameObject*>(obj.owner->GetOwner());
        }
        return _didHit;
    }

    bool didHit() const { return _didHit; }
    GameObject* _go;

private:
    bool _didHit;
    std::set<uint32> _phases;
};

typedef std::unordered_map<uint32, GameobjectModelData> ModelList;
ModelList model_list;

void LoadGameObjectModelList(std::string const& dataPath)
{
    uint32 oldMSTime = getMSTime();

    FILE* model_list_file = fopen((dataPath + "vmaps/" + VMAP::GAMEOBJECT_MODELS).c_str(), "rb");
    if (!model_list_file)
    {
        TC_LOG_DEBUG(LOG_FILTER_VMAPS, "Unable to open '%s' file.", VMAP::GAMEOBJECT_MODELS);
        return;
    }

    char magic[8];
    if (fread(magic, 1, 8, model_list_file) != 8
        || memcmp(magic, VMAP::VMAP_MAGIC, 8) != 0)
    {
        TC_LOG_DEBUG(LOG_FILTER_VMAPS, "File '%s' has wrong header, expected %s.", VMAP::GAMEOBJECT_MODELS, VMAP::VMAP_MAGIC);
        fclose(model_list_file);
        return;
    }

    uint32 name_length, displayId;
    uint8 isWmo;
    char buff[500];
    while (true)
    {
        Vector3 v1, v2;
        if (fread(&displayId, sizeof(uint32), 1, model_list_file) != 1)
            if (feof(model_list_file))  // EOF flag is only set after failed reading attempt
                break;

        if (fread(&isWmo, sizeof(uint8), 1, model_list_file) != 1
            || fread(&name_length, sizeof(uint32), 1, model_list_file) != 1
            || name_length >= sizeof(buff)
            || fread(&buff, sizeof(char), name_length, model_list_file) != name_length
            || fread(&v1, sizeof(Vector3), 1, model_list_file) != 1
            || fread(&v2, sizeof(Vector3), 1, model_list_file) != 1)
        {
            TC_LOG_DEBUG(LOG_FILTER_VMAPS, "File '%s' seems to be corrupted!", VMAP::GAMEOBJECT_MODELS);
            break;
        }

        if (v1.isNaN() || v2.isNaN())
        {
            TC_LOG_DEBUG(LOG_FILTER_VMAPS, "File '%s' Model '%s' has invalid v1%s v2%s values!", VMAP::GAMEOBJECT_MODELS, std::string(buff, name_length).c_str(), v1.toString().c_str(), v2.toString().c_str());
            continue;
        }

        model_list.emplace(std::piecewise_construct, std::forward_as_tuple(displayId), std::forward_as_tuple(&buff[0], name_length, v1, v2, isWmo != 0));
    }

    fclose(model_list_file);
    TC_LOG_DEBUG(LOG_FILTER_VMAPS, ">> Loaded %u GameObject models in %u ms", uint32(model_list.size()), GetMSTimeDiffToNow(oldMSTime));
}

GameObjectModel::~GameObjectModel()
{
    if (iModel)
        ((VMAP::VMapManager2*)VMAP::VMapFactory::createOrGetVMapManager())->releaseModelInstance(name);
}

bool GameObjectModel::initialize(std::unique_ptr<GameObjectModelOwnerBase> modelOwner, std::string const& dataPath)
{
    ModelList::const_iterator it = model_list.find(modelOwner->GetDisplayId());
    if (it == model_list.end())
        return false;

    G3D::AABox mdl_box(it->second.bound);
    // ignore models with no bounds
    if (mdl_box == G3D::AABox::zero())
    {
        TC_LOG_DEBUG(LOG_FILTER_VMAPS, "GameObject model %s has zero bounds, loading skipped", it->second.name.c_str());
        return false;
    }

    iModel = ((VMAP::VMapManager2*)VMAP::VMapFactory::createOrGetVMapManager())->acquireModelInstance(dataPath + "vmaps/", it->second.name);

    if (!iModel)
        return false;

    name = it->second.name;
    iPos = modelOwner->GetPosition();
    iScale = modelOwner->GetScale();
    iInvScale = 1.f / iScale;

    G3D::Matrix3 iRotation = G3D::Matrix3::fromEulerAnglesZYX(modelOwner->GetOrientation(), 0, 0);
    iInvRot = iRotation.inverse();
    // transform bounding box:
    mdl_box = AABox(mdl_box.low() * iScale, mdl_box.high() * iScale);
    AABox rotated_bounds;
    for (int i = 0; i < 8; ++i)
        rotated_bounds.merge(iRotation * mdl_box.corner(i));

    iBound = rotated_bounds + iPos;
#ifdef SPAWN_CORNERS
    // test:
    for (int i = 0; i < 8; ++i)
    {
        Vector3 pos(iBound.corner(i));
        modelOwner->DebugVisualizeCorner(pos);
    }
#endif

    owner = std::move(modelOwner);
    isWmo = it->second.isWmo;
    return true;
}

GameObjectModel* GameObjectModel::Create(std::unique_ptr<GameObjectModelOwnerBase> modelOwner, std::string const& dataPath)
{
    GameObjectModel* mdl = new GameObjectModel();
    if (!mdl->initialize(std::move(modelOwner), dataPath))
    {
        delete mdl;
        return NULL;
    }

    return mdl;
}

bool GameObjectModel::intersectRay(G3D::Ray const& ray, float& maxDist, bool stopAtFirstHit, std::set<uint32> const& phases) const
{
    if (!owner || !isCollisionEnabled() || !owner->IsSpawned())
        return false;

    if (!owner->InSamePhaseId(phases))
        return false;

    float time = ray.intersectionTime(iBound);
    if (time == G3D::finf())
        return false;

    // child bounds are defined in object space:
    Vector3 p = iInvRot * (ray.origin() - iPos) * iInvScale;
    Ray modRay(p, iInvRot * ray.direction());
    float distance = maxDist * iInvScale;
    bool hit = iModel->IntersectRay(modRay, distance, stopAtFirstHit);
    if (hit)
    {
        distance *= iScale;
        maxDist = distance;
    }
    return hit;
}

bool GameObjectModel::intersectLine(G3D::Ray const& ray, float& maxDist, bool stopAtFirstHit, std::set<uint32> const& phases) const
{
    if (!isCollisionEnabled() || !owner->IsSpawned())
        return false;

    if (!owner->InSamePhaseId(phases))
        return false;

    float time = ray.intersectionTime(iBound);
    if (time == G3D::finf())
        return false;

    // child bounds are defined in object space:
    Vector3 p = iInvRot * (ray.origin() - iPos) * iInvScale;
    Ray modRay(p, iInvRot * ray.direction());
    float distance = maxDist * iInvScale;
    bool hit = iModel->intersectLine(modRay, distance, stopAtFirstHit);

    // TC_LOG_ERROR(LOG_FILTER_DYNLOS, "GameObjectModel::intersectLine distance %f hit %u iInvScale %f iScale %f maxDist %f", distance, hit, iInvScale, iScale, maxDist);

    if (hit)
    {
        distance *= iScale;
        maxDist = distance;
    }
    return hit;
}

void GameObjectModel::intersectPoint(G3D::Vector3 const& point, VMAP::AreaInfo& info, std::set<uint32> const& phases) const
{
    if (!owner || !isCollisionEnabled() || !owner->IsSpawned() || !isMapObject())
        return;

    if (!owner->InSamePhaseId(phases))
        return;

    if (!iBound.contains(point))
        return;

    // child bounds are defined in object space:
    Vector3 pModel = iInvRot * (point - iPos) * iInvScale;
    Vector3 zDirModel = iInvRot * Vector3(0.f, 0.f, -1.f);
    float zDist;
    if (iModel->IntersectPoint(pModel, zDirModel, zDist, info))
    {
        Vector3 modelGround = pModel + zDist * zDirModel;
        float world_Z = ((modelGround * iInvRot) * iScale + iPos).z;
        if (info.ground_Z < world_Z)
        {
            info.ground_Z = world_Z;
            info.adtId = owner->GetNameSetId();
        }
    }
}

bool GameObjectModel::getObjectHitPos(std::set<uint32> const& phases, G3D::Vector3 const& startPos, G3D::Vector3 const& endPos, G3D::Vector3& resultHitPos, float modifyDist) const
{
    bool result = false;
    float maxDist = (endPos - startPos).magnitude();
    // valid map coords should *never ever* produce float overflow, but this would produce NaNs too
    if (maxDist >= std::numeric_limits<float>::max())
        return false;
    // ASSERT(maxDist < std::numeric_limits<float>::max());
    // prevent NaN values which can cause BIH intersection to enter infinite loop
    if (maxDist < 1e-10f)
    {
        resultHitPos = endPos;
        return false;
    }
    G3D::Vector3 dir = (endPos - startPos)/maxDist;              // direction with length of 1
    G3D::Ray ray(startPos, dir);
    float dist = maxDist;
    if (intersectRay(ray, dist, false, phases))
    {
        resultHitPos = startPos + dir * dist;
        if (modifyDist < 0)
        {
            if ((resultHitPos - startPos).magnitude() > -modifyDist)
                resultHitPos += dir * modifyDist;
            else
                resultHitPos = startPos;
        }
        else
            resultHitPos += dir * modifyDist;

        result = true;
    }
    else
    {
        resultHitPos = endPos;
        result = false;
    }
    // TC_LOG_ERROR(LOG_FILTER_DYNLOS, "GameObjectModel::getObjectHitPos dist %f maxDist %f hit %u resultHitPos %f %f %f", dist, maxDist, result, resultHitPos.x, resultHitPos.y, resultHitPos.x);
    return result;
}

bool GameObjectModel::isInLineOfSight(G3D::Vector3 const& startPos, G3D::Vector3 const& endPos, std::set<uint32> const& phases) const
{
    float maxDist = (endPos - startPos).magnitude();

    if (!G3D::fuzzyGt(maxDist, 0))
        return true;

    // return false if distance is over max float, in case of cheater teleporting to the end of the universe
    if (maxDist == std::numeric_limits<float>::max() || !std::isfinite(maxDist))
        return false;

    // valid map coords should *never ever* produce float overflow, but this would produce NaNs too
    if (maxDist >= std::numeric_limits<float>::max())
        return false;
    // ASSERT(maxDist < std::numeric_limits<float>::max());
    // prevent NaN values which can cause BIH intersection to enter infinite loop
    if (maxDist < 1e-10f)
        return true;

    G3D::Ray ray(startPos, (endPos - startPos) / maxDist);
    bool hit = intersectLine(ray, maxDist, true, phases);
    // TC_LOG_ERROR(LOG_FILTER_DYNLOS, "GameObjectModel::isInLineOfSight maxSearchDist %f hit %u", maxDist, hit);

    return !hit;
}

float GameObjectModel::getHeight(float x, float y, float z, float maxSearchDist, std::set<uint32> const& phases) const
{
    G3D::Vector3 v(x, y, z + 0.5f);
    G3D::Ray ray(v, G3D::Vector3(0, 0, -1));

    bool hit = intersectRay(ray, maxSearchDist, false, phases);
    // TC_LOG_ERROR(LOG_FILTER_DYNLOS, "GameObjectModel::getHeight maxSearchDist %f v.z %f hit %u height %f", maxSearchDist, v.z, hit, v.z - maxSearchDist);

    if (hit)
        return v.z - maxSearchDist;
    else
        return -G3D::finf();
}

bool GameObjectModel::UpdatePosition()
{
    if (!iModel)
        return false;

    ModelList::const_iterator it = model_list.find(owner->GetDisplayId());
    if (it == model_list.end())
        return false;

    G3D::AABox mdl_box(it->second.bound);
    // ignore models with no bounds
    if (mdl_box == G3D::AABox::zero())
    {
        TC_LOG_DEBUG(LOG_FILTER_VMAPS, "GameObject model %s has zero bounds, loading skipped", it->second.name.c_str());
        return false;
    }

    iPos = owner->GetPosition();

    G3D::Matrix3 iRotation = G3D::Matrix3::fromEulerAnglesZYX(owner->GetOrientation(), 0, 0);
    iInvRot = iRotation.inverse();
    // transform bounding box:
    mdl_box = AABox(mdl_box.low() * iScale, mdl_box.high() * iScale);
    AABox rotated_bounds;
    for (int i = 0; i < 8; ++i)
        rotated_bounds.merge(iRotation * mdl_box.corner(i));

    iBound = rotated_bounds + iPos;
#ifdef SPAWN_CORNERS
    // test:
    for (int i = 0; i < 8; ++i)
    {
        Vector3 pos(iBound.corner(i));
        owner->DebugVisualizeCorner(pos);
    }
#endif

    return true;
}
