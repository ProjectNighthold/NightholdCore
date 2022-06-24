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

#include "MapTree.h"
#include "ModelInstance.h"
#include "VMapManager2.h"
#include "VMapDefinitions.h"
#include "Log.h"
#include "Errors.h"

#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

using G3D::Vector3;

namespace VMAP
{

    class MapRayCallback
    {
        public:
            MapRayCallback(ModelInstance* val): prims(val), hit(false) { }
            bool operator()(const G3D::Ray& ray, uint32 entry, float& distance, bool pStopAtFirstHit=true)
            {
                bool result = prims[entry].intersectRay(ray, distance, pStopAtFirstHit);
                if (result)
                    hit = true;
                return result;
            }
        bool didHit() { return hit; }
    protected:
        ModelInstance* prims;
        bool hit;
    };

    class MapRayLineCallback
    {
        public:
            MapRayLineCallback(ModelInstance* val): prims(val), hit(false) { }
            bool operator()(const G3D::Ray& ray, uint32 entry, float& distance, bool pStopAtFirstHit=true)
            {
                bool result = prims[entry].intersectLine(ray, distance, pStopAtFirstHit);
                if (result)
                    hit = true;
                return result;
            }
        bool didHit() { return hit; }
    protected:
        ModelInstance* prims;
        bool hit;
    };

    class AreaInfoCallback
    {
        public:
            AreaInfoCallback(ModelInstance* val): prims(val) { }
            void operator()(const Vector3& point, uint32 entry)
            {
#ifdef VMAP_DEBUG
                TC_LOG_DEBUG(LOG_FILTER_MAPS, "AreaInfoCallback: trying to intersect '%s'", prims[entry].name.c_str());
#endif
                prims[entry].intersectPoint(point, aInfo);
            }

            ModelInstance* prims;
            AreaInfo aInfo;
    };

    class LocationInfoCallback
    {
        public:
            LocationInfoCallback(ModelInstance* val, LocationInfo &info): prims(val), locInfo(info), result(false) { }
            void operator()(const Vector3& point, uint32 entry)
            {
#ifdef VMAP_DEBUG
                TC_LOG_DEBUG(LOG_FILTER_MAPS, "LocationInfoCallback: trying to intersect '%s'", prims[entry].name.c_str());
#endif
                if (prims[entry].GetLocationInfo(point, locInfo))
                    result = true;
            }

            ModelInstance* prims;
            LocationInfo &locInfo;
            bool result;
    };

    //=========================================================

    std::string StaticMapTree::getTileFileName(uint32 mapID, uint32 tileX, uint32 tileY)
    {
        std::stringstream tilefilename;
        tilefilename.fill('0');
        tilefilename << std::setw(4) << mapID << '_';
        //tilefilename << std::setw(2) << tileX << '_' << std::setw(2) << tileY << ".vmtile";
        tilefilename << std::setw(2) << tileY << '_' << std::setw(2) << tileX << ".vmtile";
        return tilefilename.str();
    }

    bool StaticMapTree::getAreaInfo(Vector3 &pos, uint32 &flags, int32 &adtId, int32 &rootId, int32 &groupId) const
    {
        AreaInfoCallback intersectionCallBack(iTreeValues);
        iTree.intersectPoint(pos, intersectionCallBack);
        if (intersectionCallBack.aInfo.result)
        {
            flags = intersectionCallBack.aInfo.flags;
            adtId = intersectionCallBack.aInfo.adtId;
            rootId = intersectionCallBack.aInfo.rootId;
            groupId = intersectionCallBack.aInfo.groupId;
            pos.z = intersectionCallBack.aInfo.ground_Z;
            return true;
        }
        return false;
    }

    bool StaticMapTree::GetLocationInfo(const Vector3 &pos, LocationInfo &info) const
    {
        LocationInfoCallback intersectionCallBack(iTreeValues, info);
        iTree.intersectPoint(pos, intersectionCallBack);
        return intersectionCallBack.result;
    }

    StaticMapTree::StaticMapTree(uint32 mapID, const std::string &basePath)
        : iMapID(mapID), iTreeValues(NULL), iNTreeValues(0), iBasePath(basePath)
    {
        if (iBasePath.length() > 0 && iBasePath[iBasePath.length()-1] != '/' && iBasePath[iBasePath.length()-1] != '\\')
        {
            iBasePath.push_back('/');
        }
    }

    //=========================================================
    //! Make sure to call unloadMap() to unregister acquired model references before destroying
    StaticMapTree::~StaticMapTree()
    {
        delete[] iTreeValues;
    }

    //=========================================================
    /**
    If intersection is found within pMaxDist, sets pMaxDist to intersection distance and returns true.
    Else, pMaxDist is not modified and returns false;
    */

    bool StaticMapTree::getIntersectionTime(const G3D::Ray& pRay, float &pMaxDist, bool pStopAtFirstHit) const
    {
        float distance = pMaxDist;
        MapRayCallback intersectionCallBack(iTreeValues);
        iTree.intersectRay(pRay, intersectionCallBack, distance, pStopAtFirstHit);
        if (intersectionCallBack.didHit())
            pMaxDist = distance;
        return intersectionCallBack.didHit();
    }

    bool StaticMapTree::getIntersectionLine(const G3D::Ray& pRay, float &pMaxDist, bool pStopAtFirstHit) const
    {
        float distance = pMaxDist;
        MapRayLineCallback intersectionCallBack(iTreeValues);
        iTree.intersectRay(pRay, intersectionCallBack, distance, pStopAtFirstHit);
        if (intersectionCallBack.didHit())
            pMaxDist = distance;
        return intersectionCallBack.didHit();
    }
    //=========================================================

    bool StaticMapTree::isInLineOfSight(const Vector3& pos1, const Vector3& pos2) const
    {
        float maxDist = (pos2 - pos1).magnitude();
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
        // direction with length of 1
        G3D::Ray ray = G3D::Ray::fromOriginAndDirection(pos1, (pos2 - pos1)/maxDist);
        if (getIntersectionLine(ray, maxDist, true))
            return false;

        return true;
    }
    //=========================================================
    /**
    When moving from pos1 to pos2 check if we hit an object. Return true and the position if we hit one
    Return the hit pos or the original dest pos
    */

    bool StaticMapTree::getObjectHitPos(const Vector3& pPos1, const Vector3& pPos2, Vector3& pResultHitPos, float pModifyDist) const
    {
        bool result=false;
        float maxDist = (pPos2 - pPos1).magnitude();
        // valid map coords should *never ever* produce float overflow, but this would produce NaNs too
        if (maxDist >= std::numeric_limits<float>::max())
            return false;
        // ASSERT(maxDist < std::numeric_limits<float>::max());
        // prevent NaN values which can cause BIH intersection to enter infinite loop
        if (maxDist < 1e-10f)
        {
            pResultHitPos = pPos2;
            return false;
        }
        Vector3 dir = (pPos2 - pPos1)/maxDist;              // direction with length of 1
        G3D::Ray ray(pPos1, dir);
        float dist = maxDist;
        if (getIntersectionTime(ray, dist, false))
        {
            pResultHitPos = pPos1 + dir * dist;
            if (pModifyDist < 0)
            {
                if ((pResultHitPos - pPos1).magnitude() > -pModifyDist)
                {
                    pResultHitPos = pResultHitPos + dir*pModifyDist;
                }
                else
                {
                    pResultHitPos = pPos1;
                }
            }
            else
            {
                pResultHitPos = pResultHitPos + dir*pModifyDist;
            }
            result = true;
        }
        else
        {
            pResultHitPos = pPos2;
            result = false;
        }
        return result;
    }

    //=========================================================

    float StaticMapTree::getHeight(const Vector3& pPos, float maxSearchDist) const
    {
        float height = G3D::finf();
        Vector3 dir = Vector3(0, 0, -1);
        G3D::Ray ray(pPos, dir);   // direction with length of 1
        float maxDist = maxSearchDist;
        if (getIntersectionTime(ray, maxDist, false))
        {
            height = pPos.z - maxDist;
        }
        return(height);
    }

    StaticMapTree::TileFileOpenResult StaticMapTree::OpenMapTileFile(std::string const& basePath, uint32 mapID, uint32 tileX, uint32 tileY, VMapManager2* vm)
    {
        TileFileOpenResult result;
        result.Name = basePath + getTileFileName(mapID, tileX, tileY);
        result.File = fopen(result.Name.c_str(), "rb");
        if (!result.File)
        {
            int32 parentMapId = vm->getParentMapId(mapID);
            if (parentMapId != -1)
            {
                result.Name = basePath + getTileFileName(parentMapId, tileX, tileY);
                result.File = fopen(result.Name.c_str(), "rb");
            }
        }

        return result;
    }

    //=========================================================

    bool StaticMapTree::CanLoadMap(const std::string &vmapPath, uint32 mapID, uint32 tileX, uint32 tileY, VMapManager2* vm)
    {
        std::string basePath = vmapPath;
        if (basePath.length() > 0 && basePath[basePath.length()-1] != '/' && basePath[basePath.length()-1] != '\\')
            basePath.push_back('/');
        std::string fullname = basePath + VMapManager2::getMapFileName(mapID);
        bool success = true;
        FILE* rf = fopen(fullname.c_str(), "rb");
        if (!rf)
            return false;

        char chunk[8];
        if (!readChunk(rf, chunk, VMAP_MAGIC, 8))
        {
            fclose(rf);
            return false;
        }
        FILE* tf = OpenMapTileFile(basePath, mapID, tileX, tileY, vm).File;
        if (!tf)
            success = false;
        else
        {
            if (!readChunk(tf, chunk, VMAP_MAGIC, 8))
                success = false;
            fclose(tf);
        }
        fclose(rf);
        return success;
    }

    //=========================================================

    bool StaticMapTree::InitMap(std::string const& fname)
    {
        TC_LOG_DEBUG(LOG_FILTER_MAPS, "StaticMapTree::InitMap() : initializing StaticMapTree '%s'", fname.c_str());
        bool success = false;
        std::string fullname = iBasePath + fname;
        FILE* rf = fopen(fullname.c_str(), "rb");
        if (!rf)
            return false;

        char chunk[8];

        if (readChunk(rf, chunk, VMAP_MAGIC, 8) &&
            readChunk(rf, chunk, "NODE", 4) &&
            iTree.readFromFile(rf))
        {
            iNTreeValues = iTree.primCount();
            iTreeValues = new ModelInstance[iNTreeValues];
            success = true;
        }

        if (success)
        {
            success = readChunk(rf, chunk, "SIDX", 4);
            uint32 spawnIndicesSize = 0;
            uint32 spawnId;
            uint32 spawnIndex;
            if (success && fread(&spawnIndicesSize, sizeof(uint32), 1, rf) != 1) success = false;
            for (uint32 i = 0; i < spawnIndicesSize && success; ++i)
            {
                if (fread(&spawnId, sizeof(uint32), 1, rf) == 1 && fread(&spawnIndex, sizeof(uint32), 1, rf) == 1)
                    iSpawnIndices[spawnId] = spawnIndex;
                else
                    success = false;
            }
        }

        fclose(rf);
        return success;
    }

    //=========================================================

    void StaticMapTree::UnloadMap(VMapManager2* vm)
    {
        for (loadedSpawnMap::iterator i = iLoadedSpawns.begin(); i != iLoadedSpawns.end(); ++i)
        {
            iTreeValues[i->first].setUnloaded();
            for (uint32 refCount = 0; refCount < i->second; ++refCount)
                vm->releaseModelInstance(iTreeValues[i->first].name);
        }
        iLoadedSpawns.clear();
        iLoadedTiles.clear();
    }

    //=========================================================

    bool StaticMapTree::LoadMapTile(uint32 tileX, uint32 tileY, VMapManager2* vm)
    {
        if (!iTreeValues)
        {
            TC_LOG_DEBUG(LOG_FILTER_MAPS, "StaticMapTree::LoadMapTile() : tree has not been initialized [%u, %u]", tileX, tileY);
            return false;
        }
        bool result = true;

        TileFileOpenResult fileResult = OpenMapTileFile(iBasePath, iMapID, tileX, tileY, vm);
        if (fileResult.File)
        {
            char chunk[8];

            if (!readChunk(fileResult.File, chunk, VMAP_MAGIC, 8))
                result = false;
            uint32 numSpawns = 0;
            if (result && fread(&numSpawns, sizeof(uint32), 1, fileResult.File) != 1)
                result = false;
            for (uint32 i=0; i<numSpawns && result; ++i)
            {
                // read model spawns
                ModelSpawn spawn;
                result = ModelSpawn::readFromFile(fileResult.File, spawn);
                if (result)
                {
                    // acquire model instance
                    WorldModel* model = vm->acquireModelInstance(iBasePath, spawn.name);
                    if (!model)
                        TC_LOG_DEBUG(LOG_FILTER_MAPS, "StaticMapTree::LoadMapTile() : could not acquire WorldModel pointer [%u, %u]", tileX, tileY);

                    // update tree
                    auto spawnIndex = iSpawnIndices.find(spawn.ID);
                    if (spawnIndex != iSpawnIndices.end())
                    {
                        uint32 referencedVal = spawnIndex->second;
                        if (!iLoadedSpawns.count(referencedVal))
                        {
                            if (referencedVal >= iNTreeValues)
                            {
                                TC_LOG_DEBUG(LOG_FILTER_MAPS, "StaticMapTree::LoadMapTile() : invalid tree element (%u/%u) referenced in tile %s", referencedVal, iNTreeValues, fileResult.Name.c_str());
                                continue;
                            }

                            iTreeValues[referencedVal] = ModelInstance(spawn, model);
                            iLoadedSpawns[referencedVal] = 1;
                        }
                        else
                        {
                            ++iLoadedSpawns[referencedVal];
#ifdef VMAP_DEBUG
                            if (iTreeValues[referencedVal].ID != spawn.ID)
                                TC_LOG_DEBUG(LOG_FILTER_MAPS, "StaticMapTree::LoadMapTile() : trying to load wrong spawn in node");
                            else if (iTreeValues[referencedVal].name != spawn.name)
                                TC_LOG_DEBUG(LOG_FILTER_MAPS, "StaticMapTree::LoadMapTile() : name collision on GUID=%u", spawn.ID);
#endif
                        }
                    }
                    else
                        result = false;
                }
            }
            iLoadedTiles[packTileID(tileX, tileY)] = true;
            fclose(fileResult.File);
        }
        else
            iLoadedTiles[packTileID(tileX, tileY)] = false;
        return result;
    }

    //=========================================================

    void StaticMapTree::UnloadMapTile(uint32 tileX, uint32 tileY, VMapManager2* vm)
    {
        uint32 tileID = packTileID(tileX, tileY);
        loadedTileMap::iterator tile = iLoadedTiles.find(tileID);
        if (tile == iLoadedTiles.end())
        {
            TC_LOG_DEBUG(LOG_FILTER_MAPS, "StaticMapTree::UnloadMapTile() : trying to unload non-loaded tile - Map:%u X:%u Y:%u", iMapID, tileX, tileY);
            return;
        }
        if (tile->second) // file associated with tile
        {
            TileFileOpenResult fileResult = OpenMapTileFile(iBasePath, iMapID, tileX, tileY, vm);
            if (fileResult.File)
            {
                bool result=true;
                char chunk[8];
                if (!readChunk(fileResult.File, chunk, VMAP_MAGIC, 8))
                    result = false;
                uint32 numSpawns;
                if (fread(&numSpawns, sizeof(uint32), 1, fileResult.File) != 1)
                    result = false;
                for (uint32 i=0; i<numSpawns && result; ++i)
                {
                    // read model spawns
                    ModelSpawn spawn;
                    result = ModelSpawn::readFromFile(fileResult.File, spawn);
                    if (result)
                    {
                        // release model instance
                        vm->releaseModelInstance(spawn.name);

                        // update tree
                        auto spawnIndex = iSpawnIndices.find(spawn.ID);
                        if (spawnIndex == iSpawnIndices.end())
                            result = false;
                        else
                        {
                            uint32 referencedNode = spawnIndex->second;
                            if (!iLoadedSpawns.count(referencedNode))
                            TC_LOG_DEBUG(LOG_FILTER_MAPS, "StaticMapTree::UnloadMapTile() : trying to unload non-referenced model '%s' (ID:%u)", spawn.name.c_str(), spawn.ID);
                            else if (--iLoadedSpawns[referencedNode] == 0)
                            {
                                iTreeValues[referencedNode].setUnloaded();
                                iLoadedSpawns.erase(referencedNode);
                            }
                        }
                    }
                }
                fclose(fileResult.File);
            }
        }
        iLoadedTiles.erase(tile);
    }

    void StaticMapTree::getModelInstances(ModelInstance* &models, uint32 &count)
    {
        models = iTreeValues;
        count = iNTreeValues;
    }
}
