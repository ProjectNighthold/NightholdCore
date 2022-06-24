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

#include "Vignette.h"
#include "ObjectMgr.h"

namespace Vignette
{

Entity::Entity(VignetteEntry const* vignetteEntry, uint32 mapID) : _zoneID{ 0 }
{
    ASSERT(vignetteEntry != nullptr);
    _needClientUpdate = false;
    _map = mapID;
    _vignetteEntry = vignetteEntry;
    _type = Type::SourceCreature;
}

Entity::~Entity() = default;

void Entity::Create(Type type, Position const& position, uint32 zoneID, ObjectGuid sourceGuid)
{
    _guid = ObjectGuid::Create<HighGuid::Vignette>(_map, _vignetteEntry->ID, sObjectMgr->GetGenerator<HighGuid::Vignette>()->Generate());
    _type = type;
    _position = position;
    _zoneID = zoneID;
    _sourceGuid = sourceGuid;
}

void Entity::UpdatePosition(Position newPosition)
{
    if (static_cast<int32>(_position.GetPositionX()) == static_cast<int32>(newPosition.GetPositionX()) && static_cast<int32>(_position.GetPositionY()) == static_cast<int32>(newPosition.GetPositionY()))
        return;

    _position = newPosition;
    _needClientUpdate = true;
}

void Entity::ResetNeedClientUpdate()
{
    _needClientUpdate = false;
}

ObjectGuid Entity::GetGuid() const
{
    return _guid;
}

ObjectGuid Entity::GeSourceGuid() const
{
    return _sourceGuid;
}

Type Entity::GetVignetteType() const
{
    return _type;
}

bool Entity::NeedClientUpdate() const
{
    return _needClientUpdate;
}

Position const& Entity::GetPosition() const
{
    return _position;
}

uint32 Entity::GetZoneID() const
{
    return _zoneID;
}

VignetteEntry const* Entity::GetVignetteEntry() const
{
    return _vignetteEntry;
}

}
