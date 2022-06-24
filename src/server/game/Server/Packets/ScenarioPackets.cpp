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

#include "ScenarioPackets.h"

void WorldPackets::Scenario::QueryScenarioPOI::Read()
{
    MissingScenarioPOITreeIDs.resize(_worldPacket.read<uint32>());
    for (size_t i = 0; i < MissingScenarioPOITreeIDs.size(); i++)
        MissingScenarioPOITreeIDs.push_back(_worldPacket.read<uint32>());
}

WorldPacket const* WorldPackets::Scenario::ScenarioPOIs::Write()
{
    _worldPacket << static_cast<uint32>(PoiInfos.size());
    for (auto const& map : PoiInfos)
    {
        _worldPacket << map.CriteriaTreeID;
        _worldPacket << static_cast<uint32>(map.BlobDatas.size());
        for (auto const& blob : map.BlobDatas)
        {
            _worldPacket << blob.BlobID;
            _worldPacket << blob.MapID;
            _worldPacket << blob.WorldMapAreaID;
            _worldPacket << blob.Floor;
            _worldPacket << blob.Priority;
            _worldPacket << blob.Flags;
            _worldPacket << blob.WorldEffectID;
            _worldPacket << blob.PlayerConditionID;
            _worldPacket << static_cast<uint32>(blob.Points.size());
            for (auto const& point : blob.Points)
            {
                _worldPacket << point.X;
                _worldPacket << point.Y;
            }
        }
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scenario::ScenarioProgressUpdate::Write()
{
    _worldPacket << Progress;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scenario::ScenarioState::Write()
{
    _worldPacket << ScenarioID;
    _worldPacket << CurrentStep;
    _worldPacket << DifficultyID;
    _worldPacket << WaveCurrent;
    _worldPacket << WaveMax;
    _worldPacket << TimerDuration;
    _worldPacket << static_cast<uint32>(Progress.size());
    _worldPacket << static_cast<uint32>(BonusObjectives.size());
    _worldPacket << static_cast<uint32>(ActiveSteps.size());
    _worldPacket << static_cast<uint32>(Spells.size());

    for (auto const& v : ActiveSteps)
        _worldPacket << v;

    _worldPacket.WriteBit(ScenarioComplete);
    _worldPacket.FlushBits();

    for (auto const& map : Progress)
        _worldPacket << map;

    for (auto const& obj : BonusObjectives)
    {
        _worldPacket << obj.BonusObjectiveID;
        _worldPacket.WriteBit(obj.ObjectiveComplete);
        _worldPacket.FlushBits();
    }

    for (auto const& obj : Spells)
    {
        _worldPacket << obj.SpellID;
        _worldPacket.WriteBit(obj.Usable);
        _worldPacket.FlushBits();
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scenario::ScenarioCompleted::Write()
{
    _worldPacket << ScenarioID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Scenario::ScenarioBoot::Write()
{
    _worldPacket << ScenarioID;
    _worldPacket << UnkInt;
    _worldPacket << UnkByte;

    return &_worldPacket;
}
