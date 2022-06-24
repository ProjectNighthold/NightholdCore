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
#include "WorldSession.h"

void WorldSession::HandleScenePlaybackCanceled(WorldPackets::Scene::SceneInstance& packet)
{
    SendPacket(WorldPackets::Scene::CancelScene(packet.SceneInstanceID).Write());

    if (_player)
        _player->SceneCompleted(packet.SceneInstanceID);
}

void WorldSession::HandleScenePlaybackComplete(WorldPackets::Scene::SceneInstance& packet)
{
    if(_player)
        _player->SceneCompleted(packet.SceneInstanceID);
}

void WorldSession::HandleSceneTriggerEvent(WorldPackets::Scene::SceneTriggerEvent& packet)
{
    if(_player)
        _player->TrigerScene(packet.SceneInstanceID, packet.Event);
}
