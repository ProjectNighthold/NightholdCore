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
#include "WorldSession.h"
#include "Scenario.h"

void WorldSession::HandleQueryScenarioPOI(WorldPackets::Scenario::QueryScenarioPOI& packet)
{
    TC_LOG_DEBUG(LOG_FILTER_SPELLS_AURAS, "HandleQueryScenarioPOI MissingScenarioPOITreeIDs %u", packet.MissingScenarioPOITreeIDs.size());

    WorldPackets::Scenario::ScenarioPOIs poIs;
    WorldPackets::Scenario::ScenarioPOIs::POIData& infos = poIs.PoiInfos[packet.MissingScenarioPOITreeIDs.size()];

    for (auto const& treeID : packet.MissingScenarioPOITreeIDs)
    {
        ScenarioPOIVector const* poi = sObjectMgr->GetScenarioPOIVector(treeID);
        if (!poi)
        {
            infos.CriteriaTreeID = treeID;
            continue;
        }

        infos.CriteriaTreeID = treeID;
        WorldPackets::Scenario::ScenarioPOIs::POIData::BlobData& blobData = infos.BlobDatas[poi->size()];

        for (ScenarioPOIVector::const_iterator itr = poi->begin(); itr != poi->end(); ++itr)
        {
            blobData.BlobID = itr->BlobID;
            blobData.MapID = itr->MapID;
            blobData.WorldMapAreaID = itr->WorldMapAreaID;
            blobData.Floor = itr->Floor;
            blobData.Priority = itr->Priority;
            blobData.Flags = itr->Flags;
            blobData.WorldEffectID = itr->WorldEffectID;
            blobData.PlayerConditionID = itr->PlayerConditionID;

            WorldPackets::Scenario::ScenarioPOIs::POIData::BlobData::POIPointData& points = blobData.Points[itr->points.size()];

            for (std::vector<ScenarioPOIPoint>::const_iterator itr2 = itr->points.begin(); itr2 != itr->points.end(); ++itr2)
            {
                points.X = itr2->x;
                points.Y = itr2->y;
            }
        }
    }

    SendPacket(poIs.Write());
}
