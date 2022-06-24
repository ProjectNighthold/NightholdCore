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

#ifndef _BIH_WRAP
#define _BIH_WRAP

#include "BoundingIntervalHierarchy.h"
#include <G3D/Table.h>
#include <G3D/Array.h>
#include <G3D/Set.h>

typedef std::lock_guard<std::recursive_mutex> RecursiveGuard;

template<class T, class BoundsFunc = BoundsTrait<T> >
class BIHWrap
{
    template<class RayCallback>
    struct MDLCallback
    {
        const T* const* objects;
        RayCallback& _callback;
        uint32 objects_size;

        MDLCallback(RayCallback& callback, const T* const* objects_array, uint32 objects_size ) : objects(objects_array), _callback(callback), objects_size(objects_size) { }

        /// Intersect ray
        bool operator() (const G3D::Ray& ray, uint32 idx, float& maxDist, bool /*stopAtFirst*/)
        {
            if (idx >= objects_size)
                return false;
            if (const T* obj = objects[idx])
                return _callback(ray, *obj, maxDist/*, stopAtFirst*/);
            return false;
        }

        /// Intersect point
        void operator() (const G3D::Vector3& p, uint32 idx)
        {
            if (idx >= objects_size)
                return;
            if (const T* obj = objects[idx])
                _callback(p, *obj);
        }
    };

    typedef G3D::Array<const T*> ObjArray;

    BIH m_tree;
    ObjArray m_objects;
    G3D::Table<const T*, uint32> m_obj2Idx;
    G3D::Set<const T*> m_objects_to_push;
    int unbalanced_times;
    std::recursive_mutex balance_lock;

public:
    BIHWrap() : unbalanced_times(0) { }

    void insert(const T& obj)
    {
        ++unbalanced_times;
        m_objects_to_push.insert(&obj);
    }

    void remove(const T& obj)
    {
        ++unbalanced_times;
        uint32 Idx = 0;
        const T * temp;
        if (m_obj2Idx.getRemove(&obj, temp, Idx))
            m_objects[Idx] = NULL;
        else
            m_objects_to_push.remove(&obj);
    }

    void balance()
    {
        if (unbalanced_times == 0)
            return;

        unbalanced_times = 0;
        RecursiveGuard guard(balance_lock);
        m_objects.fastClear();
        m_obj2Idx.getKeys(m_objects);
        m_objects_to_push.getMembers(m_objects);
        //assert that m_obj2Idx has all the keys

        m_tree.build(m_objects, BoundsFunc::getBounds2);
    }

    template<typename RayCallback>
    void intersectRay(const G3D::Ray& ray, RayCallback& intersectCallback, float& maxDist)
    {
        balance();
        MDLCallback<RayCallback> temp_cb(intersectCallback, m_objects.getCArray(), m_objects.size());
        m_tree.intersectRay(ray, temp_cb, maxDist, true);
    }

    template<typename IsectCallback>
    void intersectPoint(const G3D::Vector3& point, IsectCallback& intersectCallback)
    {
        balance();
        MDLCallback<IsectCallback> callback(intersectCallback, m_objects.getCArray(), m_objects.size());
        m_tree.intersectPoint(point, callback);
    }
};

#endif // _BIH_WRAP
