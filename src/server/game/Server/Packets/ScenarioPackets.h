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

#ifndef ScenarioPackets_h__
#define ScenarioPackets_h__

#include "Packet.h"
#include "AchievementPackets.h"

namespace WorldPackets
{
    namespace Scenario
    {
        class QueryScenarioPOI final : public ClientPacket
        {
        public:
            QueryScenarioPOI(WorldPacket&& packet) : ClientPacket(CMSG_QUERY_SCENARIO_POI, std::move(packet)) { }

            void Read() override;

            std::vector<uint32> MissingScenarioPOITreeIDs;
        };

        class ScenarioPOIs final : public ServerPacket
        {
        public:
            ScenarioPOIs() : ServerPacket(SMSG_SCENARIO_POIS, 4) { }

            WorldPacket const* Write() override;

            struct POIData
            {
                struct BlobData
                {
                    struct POIPointData
                    {
                        uint32 X = 0;
                        uint32 Y = 0;
                    };

                    uint32 BlobID = 0;
                    uint32 MapID = 0;
                    uint32 WorldMapAreaID = 0;
                    uint32 Floor = 0;
                    uint32 Priority = 0;
                    uint32 Flags = 0;
                    uint32 WorldEffectID = 0;
                    uint32 PlayerConditionID = 0;
                    std::vector<POIPointData> Points;
                };

                uint32 CriteriaTreeID = 0;
                std::vector<BlobData> BlobDatas;
            };

            std::vector<POIData> PoiInfos;
        };

        class ScenarioProgressUpdate final : public ServerPacket
        {
        public:
            ScenarioProgressUpdate() : ServerPacket(SMSG_SCENARIO_PROGRESS_UPDATE) { }

            WorldPacket const* Write() override;

            Achievement::CriteriaTreeProgress Progress;
        };

        struct BonusObjectiveData
        {
            uint32 BonusObjectiveID = 0;
            bool ObjectiveComplete = false;
        };

        class ScenarioState final : public ServerPacket
        {
        public:
            ScenarioState() : ServerPacket(SMSG_SCENARIO_STATE, 33) { }

            WorldPacket const* Write() override;

            struct ScenarioSpellUpdate
            {
                uint32 SpellID = 0;
                bool Usable = false;
            };
            
            std::vector<BonusObjectiveData> BonusObjectives;
            std::vector<Achievement::CriteriaTreeProgress> Progress;
            std::vector<ScenarioSpellUpdate> Spells;
            std::vector<uint32> ActiveSteps;
            uint32 ScenarioID = 0;
            int32 CurrentStep = 0;
            uint32 DifficultyID = 0;
            uint32 WaveCurrent = 0;
            uint32 WaveMax = 0;
            uint32 TimerDuration = 0;
            bool ScenarioComplete = false;
        };

        class ScenarioCompleted final : public ServerPacket
        {
        public:
            ScenarioCompleted() : ServerPacket(SMSG_SCENARIO_COMPLETED, 4) { }

            WorldPacket const* Write() override;

            uint32 ScenarioID = 0;
        };

        class ScenarioBoot final : public ServerPacket
        {
        public:
            ScenarioBoot() : ServerPacket(SMSG_SCENARIO_BOOT, 9) { }

            WorldPacket const* Write() override;

            uint32 ScenarioID = 0;
            uint32 UnkInt = 0;
            uint8 UnkByte = 0;
        };
    }
}

#endif // ScenarioPackets_h__
