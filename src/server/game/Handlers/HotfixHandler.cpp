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

#include "WorldSession.h"
#include "Containers.h"
#include "HotfixPackets.h"
#include "DB2Store.h"

void WorldSession::HandleHotfixRequest(WorldPackets::Hotfix::HotfixRequest& packet)
{
    auto const& hotfixes = sDB2Manager.GetHotfixData();
    WorldPackets::Hotfix::HotfixResponse hotfixQueryResponse;
    hotfixQueryResponse.Hotfixes.reserve(packet.Hotfixes.size());
    for (auto hotfixId : packet.Hotfixes)
    {
        if (auto hotfix = Trinity::Containers::MapGetValuePtr(hotfixes, hotfixId))
        {
            auto storage = sDB2Manager.GetStorage(PAIR64_HIPART(hotfixId));
            if (!storage)
                continue;

            WorldPackets::Hotfix::HotfixData hotfixData;
            hotfixData.ID = hotfixId;
            hotfixData.RecordID = *hotfix;
            if (storage->HasRecord(hotfixData.RecordID))
            {
                hotfixData.Data = boost::in_place();
                storage->WriteRecord(hotfixData.RecordID, GetSessionDbcLocale(), *hotfixData.Data);
            }

            hotfixQueryResponse.Hotfixes.emplace_back(std::move(hotfixData));
        }
    }

    SendPacket(hotfixQueryResponse.Write());
}

void WorldSession::HandleDBQueryBulk(WorldPackets::Hotfix::DBQueryBulk& packet)
{
    auto store = sDB2Manager.GetStorage(packet.TableHash);
    if (!store)
    {
        TC_LOG_DEBUG(LOG_FILTER_GENERAL, "DBQueryBulk:: client requested unused db2 storage: %u; can by finded in DB2Hashes", packet.TableHash);
        return;
    }

    for (auto const& rec : packet.Queries)
    {
        WorldPackets::Hotfix::DBReply response;
        response.TableHash = packet.TableHash;
        response.RecordID = rec.RecordID;

        if (store->HasRecord(rec.RecordID))
        {
            response.Allow = true;
            response.Timestamp = sWorld->GetGameTime();
            store->WriteRecord(rec.RecordID, GetSessionDbcLocale(), response.Data);
        }
        else
            response.Timestamp = time(nullptr);

        SendPacket(response.Write());
    }
}

void WorldSession::SendHotfixList(int32 version)
{
    SendPacket(WorldPackets::Hotfix::AvailableHotfixes(version, sDB2Manager.GetHotfixData()).Write());
}
