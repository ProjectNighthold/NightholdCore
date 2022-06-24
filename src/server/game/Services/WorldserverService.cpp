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

#include "WorldserverService.h"
#include "Log.h"
#include "RealmList.h"
#include "RealmList.pb.h"
#include "BattlenetRpcErrorCodes.h"
#include "JSON/ProtobufJSON.h"
#include <zlib.h>
#include "Config.h"

Battlenet::GameUtilitiesService::GameUtilitiesService(WorldSession* session) : BaseService(session)
{
}

uint32 Battlenet::GameUtilitiesService::HandleProcessClientRequest(game_utilities::v1::ClientRequest const* request, game_utilities::v1::ClientResponse* response)
{
    Attribute const* command = nullptr;
    std::unordered_map<std::string, Variant const*> params;

    for (int32 i = 0; i < request->attribute_size(); ++i)
    {
        Attribute const& attr = request->attribute(i);
        params[attr.name()] = &attr.value();
        if (strstr(attr.name().c_str(), "Command_") == attr.name().c_str())
            command = &attr;
    }

    if (!command)
    {
        TC_LOG_ERROR(LOG_FILTER_BATTLENET, "%s sent ClientRequest with no command.", GetCallerInfo().c_str());
        return ERROR_RPC_MALFORMED_REQUEST;
    }

    if (command->name() == "Command_RealmListRequest_v1_b9")
        return HandleRealmListRequest(params, response);
    
    if (command->name() == "Command_RealmJoinRequest_v1_b9")
        return HandleRealmJoinRequest(params, response);

    TC_LOG_ERROR(LOG_FILTER_BATTLENET, "%s sent ClientRequest with ERROR_RPC_NOT_IMPLEMENTED", GetCallerInfo().c_str());
    return ERROR_RPC_NOT_IMPLEMENTED;
}

uint32 Battlenet::GameUtilitiesService::HandleRealmListRequest(std::unordered_map<std::string, Variant const*> params, game_utilities::v1::ClientResponse* response)
{
    std::string subRegionId;
    auto subRegion = params.find("Command_RealmListRequest_v1_b9");
    if (subRegion != params.end())
        subRegionId = subRegion->second->string_value();

    std::vector<uint8> compressed = sRealmList->GetRealmList(realm.Build, subRegionId, sConfigMgr->GetIntDefault("Battlegroup", 1));

    if (compressed.empty())
        return ERROR_UTIL_SERVER_FAILED_TO_SERIALIZE_RESPONSE;

    Attribute* attribute = response->add_attribute();
    attribute->set_name("Param_RealmList");
    attribute->mutable_value()->set_blob_value(compressed.data(), compressed.size());

    JSON::RealmList::RealmCharacterCountList realmCharacterCounts;
    for (auto const& characterCount : _session->GetRealmCharacterCounts())
    {
        ::JSON::RealmList::RealmCharacterCountEntry* countEntry = realmCharacterCounts.add_counts();
        countEntry->set_wowrealmaddress(characterCount.first);
        countEntry->set_count(characterCount.second);
    }

    std::string json = "JSONRealmCharacterCountList:" + JSON::Serialize(realmCharacterCounts);

    uLongf compressedLength = compressBound(json.length());
    compressed.resize(4 + compressedLength);
    *reinterpret_cast<uint32*>(compressed.data()) = json.length() + 1;

    if (compress(compressed.data() + 4, &compressedLength, reinterpret_cast<uint8 const*>(json.c_str()), json.length() + 1) != Z_OK)
        return ERROR_UTIL_SERVER_FAILED_TO_SERIALIZE_RESPONSE;

    attribute = response->add_attribute();
    attribute->set_name("Param_CharacterCountList");
    attribute->mutable_value()->set_blob_value(compressed.data(), compressedLength + 4);

    return ERROR_OK;
}

uint32 Battlenet::GameUtilitiesService::HandleRealmJoinRequest(std::unordered_map<std::string, Variant const*> params, game_utilities::v1::ClientResponse* response)
{
    auto realmAddress = params.find("Param_RealmAddress");
    if (realmAddress != params.end())
        return sRealmList->JoinRealm(uint32(realmAddress->second->uint_value()), realm.Build, boost::asio::ip::address::from_string(_session->GetRemoteAddress()), _session->GetRealmListSecret(),
            _session->GetSessionDbcLocale(), _session->GetOS(), _session->GetAccountName(), response);

    return ERROR_WOW_SERVICES_INVALID_JOIN_TICKET;
}

uint32 Battlenet::GameUtilitiesService::HandleGetAllValuesForAttribute(game_utilities::v1::GetAllValuesForAttributeRequest const* request, game_utilities::v1::GetAllValuesForAttributeResponse* response)
{
    if (request->attribute_key() == "Command_RealmListRequest_v1_b9")
    {
        sRealmList->WriteSubRegions(response);
        return ERROR_OK;
    }

    return ERROR_RPC_NOT_IMPLEMENTED;
}
