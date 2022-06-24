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

#ifndef TRINITY_GAME_OBJECT_VISITORS_HPP
#define TRINITY_GAME_OBJECT_VISITORS_HPP

#include "Object.h"
#include "Map.h"

namespace Trinity {

template <typename Notifier>
inline void VisitNearbyObject(WorldObject const *obj, float radius, Notifier &notifier)
{
    if (obj->IsInWorld())
        obj->GetMap()->VisitAll(obj->GetPositionX(), obj->GetPositionY(), radius, notifier);
}

template <typename Notifier>
inline void VisitNearbyGridObject(WorldObject const *obj, float radius, Notifier &notifier)
{
    if (obj->IsInWorld())
        obj->GetMap()->VisitGrid(obj->GetPositionX(), obj->GetPositionY(), radius, notifier);
}

template <typename Notifier>
inline void VisitNearbyWorldObject(WorldObject const *obj, float radius, Notifier &notifier)
{
    if (obj->IsInWorld())
    {
        if (Map* map = obj->GetMap())
            map->VisitWorld(obj->GetPositionX(), obj->GetPositionY(), radius, notifier);
    }
}

} // namespace Trinity

#endif // TRINITY_GAME_OBJECT_VISITORS_HPP
