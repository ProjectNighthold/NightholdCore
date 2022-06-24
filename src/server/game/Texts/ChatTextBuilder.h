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

#ifndef __CHATTEXT_BUILDER_H
#define __CHATTEXT_BUILDER_H

#include "Chat.h"
#include "CreatureTextMgr.h"

namespace Trinity
{
class BroadcastTextBuilder
{
public:
    BroadcastTextBuilder(Unit const* obj, ChatMsg msgType, uint32 textId, WorldObject const* target = nullptr, uint32 achievementId = 0);
    WorldPackets::Packet* operator()(LocaleConstant locale) const;

private:
    Unit const* _source;
    WorldObject const* _target;
    ChatMsg _msgType;
    uint32 _textId;
    uint32 _achievementId;
};

class CustomChatTextBuilder
{
public:
    CustomChatTextBuilder(WorldObject const* obj, ChatMsg msgType, std::string const& text, Language language = LANG_UNIVERSAL, WorldObject const* target = nullptr);
    WorldPackets::Packet* operator()(LocaleConstant locale) const;

private:
    WorldObject const* _source;
    WorldObject const* _target;
    ChatMsg _msgType;
    Language _language;
    std::string _text;
};

class TrinityStringChatBuilder
{
public:
    TrinityStringChatBuilder(WorldObject const* obj, ChatMsg msgType, uint32 textId, WorldObject const* target = nullptr, va_list* args = nullptr);
    WorldPackets::Packet* operator()(LocaleConstant locale) const;

private:
    WorldObject const* _source;
    WorldObject const* _target;
    va_list* _args;
    ChatMsg _msgType;
    uint32 _textId;
};
}

#endif // __CHATTEXT_BUILDER_H
