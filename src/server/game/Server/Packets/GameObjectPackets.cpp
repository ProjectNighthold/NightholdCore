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

#include "GameObjectPackets.h"

void WorldPackets::GameObject::GameObjectUse::Read()
{
    _worldPacket >> Guid;
}

void WorldPackets::GameObject::GameObjReportUse::Read()
{
    _worldPacket >> Guid;
}

WorldPacket const* WorldPackets::GameObject::GameObjectDespawn::Write()
{
    _worldPacket << ObjectGUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::GameObject::GameObjectUiAction::Write()
{
    _worldPacket << ObjectGUID;
    _worldPacket << ActionID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::GameObject::PageText::Write()
{
    _worldPacket << GameObjectGUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::GameObject::GameObjectActivateAnimKit::Write()
{
    _worldPacket << ObjectGUID;
    _worldPacket << uint32(AnimKitID);
    _worldPacket.WriteBit(Maintain);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::GameObject::GoCustomAnim::Write()
{
    _worldPacket << ObjectGUID;
    _worldPacket << CustomAnim;
    _worldPacket.WriteBit(PlayAsDespawn);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::GameObject::GameObjectResetState::Write()
{
    _worldPacket << ObjectGUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::GameObject::GameObjectPlaySpellVisual::Write()
{
    _worldPacket << ObjectGUID;
    _worldPacket << ActivatorGUID;
    _worldPacket << SpellVisualID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::GameObject::DestructibleBuildingDamage::Write()
{
    _worldPacket << Target;
    _worldPacket << Caster;
    _worldPacket << Owner;
    _worldPacket << Damage;
    _worldPacket << SpellID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::GameObject::PlayObjectSound::Write()
{
    _worldPacket << SoundId;
    _worldPacket << SourceObjectGUID;
    _worldPacket << TargetObjectGUID;
    _worldPacket << Pos;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::GameObject::GameObjectSetState::Write()
{
    _worldPacket << ObjectGUID;
    _worldPacket << StateID;

    return &_worldPacket;
}
