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

#include "ChallengeModePackets.h"
#include "WowTime.hpp"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::ChallengeMode::ModeAttempt const& modeAttempt)
{
    data << modeAttempt.InstanceRealmAddress;
    data << modeAttempt.AttemptID;
    data << modeAttempt.CompletionTime;
    data << MS::Utilities::WowTime::Encode(modeAttempt.CompletionDate);
    data << modeAttempt.MedalEarned;
    data << static_cast<uint32>(modeAttempt.Members.size());
    for (auto const& map : modeAttempt.Members)
    {
        data << map.VirtualRealmAddress;
        data << map.NativeRealmAddress;
        data << map.Guid;
        data << map.SpecializationID;
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::ChallengeMode::ItemReward const& itemReward)
{
    data << itemReward.ItemID;
    data << itemReward.ItemDisplayID;
    data << itemReward.Quantity;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::ChallengeMode::MapChallengeModeReward const& mapChallengeModeReward)
{
    data << static_cast<uint32>(mapChallengeModeReward.Rewards.size());
    for (auto const& map : mapChallengeModeReward.Rewards)
    {
        data << static_cast<uint32>(map.ItemRewards.size());
        data << static_cast<uint32>(map.CurrencyRewards.size());
        data << map.Money;

        for (auto const& item : map.ItemRewards)
            data << item;

        for (auto const& currency : map.CurrencyRewards)
        {
            data << currency.CurrencyID;
            data << currency.Quantity;
        }
    }

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::ChallengeMode::ChallengeModeMap const& challengeModeMap)
{
    data << challengeModeMap.MapId;
    data << challengeModeMap.ChallengeID;
    data << challengeModeMap.BestCompletionMilliseconds;
    data << challengeModeMap.LastCompletionMilliseconds;
    data << challengeModeMap.CompletedChallengeLevel;
    data << MS::Utilities::WowTime::Encode(challengeModeMap.BestMedalDate);

    data << static_cast<uint32>(challengeModeMap.BestSpecID.size());

    for (auto const& v : challengeModeMap.Affixes)
        data << v;

    for (auto const& map : challengeModeMap.BestSpecID)
        data << map;

    return data;
}

void WorldPackets::ChallengeMode::RequestLeaders::Read()
{
    _worldPacket >> MapId;
    _worldPacket >> ChallengeID;
    LastGuildUpdate = _worldPacket.read<uint32>();
    LastRealmUpdate = _worldPacket.read<uint32>();
}

WorldPacket const* WorldPackets::ChallengeMode::RequestLeadersResult::Write()
{
    _worldPacket << MapID;
    _worldPacket << ChallengeID;
    _worldPacket << MS::Utilities::WowTime::Encode(LastGuildUpdate);
    _worldPacket << MS::Utilities::WowTime::Encode(LastRealmUpdate);

    _worldPacket << static_cast<uint32>(GuildLeaders.size());
    _worldPacket << static_cast<uint32>(RealmLeaders.size());

    for (auto const& guildLeaders : GuildLeaders)
        _worldPacket << guildLeaders;

    for (auto const& realmLeaders : RealmLeaders)
        _worldPacket << realmLeaders;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ChallengeMode::Rewards::Write()
{
    _worldPacket << static_cast<uint32>(MapChallengeModeRewards.size());
    _worldPacket << static_cast<uint32>(ItemRewards.size());

    for (auto const& map : MapChallengeModeRewards)
        _worldPacket << map;

    for (auto const& item : ItemRewards)
        _worldPacket << item;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ChallengeMode::AllMapStats::Write()
{
    _worldPacket << static_cast<uint32>(ChallengeModeMaps.size());
    for (auto const& map : ChallengeModeMaps)
        _worldPacket << map;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ChallengeMode::ChallengeModeReset::Write()
{
    _worldPacket << MapID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ChallengeMode::ChallengeModeStart::Write()
{
    _worldPacket << MapID;
    _worldPacket << ChallengeID;
    _worldPacket << StartedChallengeLevel;

    for (uint32 v : Affixes)
        _worldPacket << v;

    _worldPacket << DeathCount;
    _worldPacket << uint32(0); // ClientEncounterStartPlayerInfo

    _worldPacket.WriteBit(Energized);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ChallengeMode::ChallengeModeComplete::Write()
{
    _worldPacket << CompletionMilliseconds;
    _worldPacket << MapID;
    _worldPacket << ChallengeID;
    _worldPacket << StartedChallengeLevel;

    _worldPacket.WriteBit(IsCompletedInTimer);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ChallengeMode::ChallengeModeNewPlayerRecord::Write()
{
    _worldPacket << CompletionMilliseconds;
    _worldPacket << MapID;
    _worldPacket << StartedChallengeLevel;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::ChallengeMode::ChallengeModeMapStatsUpdate::Write()
{
    _worldPacket << Stats;

    return &_worldPacket;
}

void WorldPackets::ChallengeMode::StartChallengeMode::Read()
{
    _worldPacket >> Bag;
    _worldPacket >> Slot;
    _worldPacket >> GameObjectGUID;
}

WorldPacket const* WorldPackets::ChallengeMode::ChallengeModeUpdateDeathCount::Write()
{
    _worldPacket << DeathCount;
    return &_worldPacket;
}
