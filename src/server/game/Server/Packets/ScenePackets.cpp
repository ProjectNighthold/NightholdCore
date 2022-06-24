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

#include "ScenePackets.h"

void WorldPackets::Scene::SceneInstance::Read()
{
    _worldPacket >> SceneInstanceID;
}

WorldPacket const* WorldPackets::Scene::CancelScene::Write()
{
    _worldPacket << SceneInstanceID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scene::PlayScene::Write()
{
    _worldPacket << SceneID;
    _worldPacket << PlaybackFlags;
    _worldPacket << SceneInstanceID;
    _worldPacket << SceneScriptPackageID;
    _worldPacket << TransportGUID;
    _worldPacket << Pos;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scene::PetBattleRound::Write()
{
    _worldPacket << SceneObjectGUID;
    _worldPacket << MsgData;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scene::SceneObjectFinalRound::Write()
{
    _worldPacket << SceneObjectGUID;
    _worldPacket << MsgData;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scene::PetBattleFinished::Write()
{
    _worldPacket << SceneObjectGUID;

    return &_worldPacket;
}

void WorldPackets::Scene::SceneTriggerEvent::Read()
{
    uint32 len = _worldPacket.ReadBits(6);
    _worldPacket >> SceneInstanceID;
    Event = _worldPacket.ReadString(len);
}

WorldPacket const* WorldPackets::Scene::SceneObjectPetBattleInitialUpdate::Write()
{
    _worldPacket << SceneObjectGUID;
    _worldPacket << MsgData;

    return &_worldPacket;
}
