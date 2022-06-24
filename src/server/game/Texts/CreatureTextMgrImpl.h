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

#ifndef CreatureTextMgrImpl_h__
#define CreatureTextMgrImpl_h__

#include "CreatureTextMgr.h"
#include "CellImpl.h"
#include "ChatPackets.h"
#include "GridNotifiers.h"
#include "Group.h"
#include "World.h"
#include "WorldSession.h"
#include "ObjectVisitors.hpp" 

template<class Builder>
class CreatureTextLocalizer
{
public:
    CreatureTextLocalizer(Builder const& builder, ChatMsg msgType) : _builder(builder), _msgType(msgType)
    {
        _packetCache.resize(MAX_LOCALES);
    }

    ~CreatureTextLocalizer()
    {
        for (auto i = 0; i < _packetCache.size(); ++i)
            delete _packetCache[i];
    }

    void operator()(Player const* player) const
    {
        if (!player->IsInWorld())
            return;

        auto session = player->GetSession();
        if (!session || session->PlayerLoading() || session->PlayerLogout())
            return;

        auto localeConstant = session->GetSessionDbLocaleIndex();
        WorldPackets::Chat::Chat* messageTemplate;

        if (!_packetCache[localeConstant])
        {
            messageTemplate = static_cast<WorldPackets::Chat::Chat*>(_builder(localeConstant));
            messageTemplate->Write();
            _packetCache[localeConstant] = messageTemplate;
        }
        else
            messageTemplate = _packetCache[localeConstant];

        switch (_msgType)
        {
            case CHAT_MSG_MONSTER_WHISPER:
            case CHAT_MSG_RAID_BOSS_WHISPER:
            {
                auto message(*messageTemplate);
                message.SetReceiver(player, localeConstant);
                player->SendDirectMessage(message.Write());
                return;
            }
            default:
                break;
        }

        player->SendDirectMessage(messageTemplate->GetRawPacket());
    }

private:
    mutable std::vector<WorldPackets::Chat::Chat*> _packetCache;
    Builder const& _builder;
    ChatMsg _msgType;
};

template<class Builder>
void CreatureTextMgr::SendChatPacket(WorldObject* source, Builder const& builder, ChatMsg msgType, WorldObject const* whisperTarget /*= nullptr*/, TextRange range /*= TEXT_RANGE_NORMAL*/, Team team /*= TEAM_OTHER*/, bool gmOnly /*= false*/)
{
    if (!source)
        return;

    CreatureTextLocalizer<Builder> localizer(builder, msgType);

    switch (msgType)
    {
        case CHAT_MSG_MONSTER_PARTY:
        {
            if (!whisperTarget)
                return;

            if (auto whisperPlayer = whisperTarget->ToPlayer())
                if (auto group = whisperPlayer->GetGroup())
                    group->BroadcastWorker(localizer);
            return;
        }
        case CHAT_MSG_MONSTER_WHISPER:
        case CHAT_MSG_RAID_BOSS_WHISPER:
        {
            if (range == TEXT_RANGE_NORMAL) //ignores team and gmOnly
            {
                if (!whisperTarget || !whisperTarget->IsPlayer())
                    return;

                localizer(const_cast<Player*>(whisperTarget->ToPlayer()));
                return;
            }
            break;
        }
        default:
            break;
    }

    switch (range)
    {
        case TEXT_RANGE_AREA:
        {
            auto areaId = source->GetCurrentAreaID();
            source->GetMap()->ApplyOnEveryPlayer([&](Player* player)
            {
                if (player->GetCurrentAreaID() == areaId && (!team || Team(player->GetTeam()) == team) && (!gmOnly || player->isGameMaster()))
                    localizer(player);
            });
            return;
        }
        case TEXT_RANGE_ZONE:
        {
            auto zoneId = source->GetCurrentZoneID();
            source->GetMap()->ApplyOnEveryPlayer([&](Player* player)
            {
                if (player->GetCurrentZoneID() == zoneId && (!team || Team(player->GetTeam()) == team) && (!gmOnly || player->isGameMaster()))
                    localizer(player);
            });
            return;
        }
        case TEXT_RANGE_MAP:
        {
            if (whisperTarget)
                source = const_cast<WorldObject*>(whisperTarget); // sometimes npc can be on other map/zone

            source->GetMap()->ApplyOnEveryPlayer([&](Player* player)
            {
                if ((!team || Team(player->GetTeam()) == team) && (!gmOnly || player->isGameMaster()))
                    localizer(player);
            });
            return;
        }
        case TEXT_RANGE_WORLD:
        {
            auto const& smap = sWorld->GetAllSessions();
            for (const auto& iter : smap)
                if (auto player = iter.second->GetPlayer())
                    if (player->GetSession() && (!team || Team(player->GetTeam()) == team) && (!gmOnly || player->isGameMaster()))
                        localizer(player);
            return;
        }
        case TEXT_RANGE_NORMAL:
        default:
            break;
    }

    float dist = GetRangeForChatType(msgType);
    Trinity::PlayerDistWorker<CreatureTextLocalizer<Builder> > worker(source, dist, localizer);
    Trinity::VisitNearbyWorldObject(source, dist, worker);
}

#endif // CreatureTextMgrImpl_h__
