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

#include "ChannelPackets.h"

WorldPacket const* WorldPackets::Channel::ChannelListResponse::Write()
{
    _worldPacket.WriteBit(_Display);
    _worldPacket.WriteBits(_Channel.length(), 7);
    _worldPacket << _ChannelFlags;
    _worldPacket << uint32(_Members.size());
    _worldPacket.WriteString(_Channel);

    for (ChannelPlayer const& player : _Members)
    {
        _worldPacket << player.Guid;
        _worldPacket << uint32(player.VirtualRealmAddress);
        _worldPacket << uint8(player.Flags);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Channel::ChannelNotify::Write()
{
    _worldPacket.WriteBits(Type, 6);
    _worldPacket.WriteBits(_Channel.length(), 7);
    _worldPacket.WriteBits(Sender.length(), 6);

    _worldPacket << SenderGuid;
    _worldPacket << SenderAccountID;
    _worldPacket << uint32(SenderVirtualRealm);
    _worldPacket << TargetGuid;
    _worldPacket << uint32(TargetVirtualRealm);
    _worldPacket << int32(ChatChannelID);

    if (Type == CHAT_MODE_CHANGE_NOTICE)
    {
        _worldPacket << uint8(OldFlags);
        _worldPacket << uint8(NewFlags);
    }

    _worldPacket.WriteString(_Channel);
    _worldPacket.WriteString(Sender);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Channel::ChannelNotifyJoined::Write()
{
    _worldPacket.WriteBits(_Channel.length(), 7);
    _worldPacket.WriteBits(ChannelWelcomeMsg.length(), 10);
    _worldPacket << _ChannelFlags;
    _worldPacket << ChatChannelID;
    _worldPacket << uint64(InstanceID);
    _worldPacket.WriteString(_Channel);
    _worldPacket.WriteString(ChannelWelcomeMsg);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Channel::ChannelNotifyLeft::Write()
{
    _worldPacket.WriteBits(Channel.length(), 7);
    _worldPacket.WriteBit(Suspended);
    _worldPacket << int32(ChatChannelID);
    _worldPacket.WriteString(Channel);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Channel::UserlistAdd::Write()
{
    _worldPacket << AddedUserGUID;
    _worldPacket << uint8(UserFlags);
    _worldPacket << uint32(_ChannelFlags);
    _worldPacket << uint32(ChannelID);
    _worldPacket.WriteBits(ChannelName.length(), 7);
    _worldPacket.WriteString(ChannelName);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Channel::UserlistRemove::Write()
{
    _worldPacket << RemovedUserGUID;
    _worldPacket << uint32(_ChannelFlags);
    _worldPacket << uint32(ChannelID);
    _worldPacket.WriteBits(ChannelName.length(), 7);
    _worldPacket.WriteString(ChannelName);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Channel::UserlistUpdate::Write()
{
    _worldPacket << UpdatedUserGUID;
    _worldPacket << uint8(UserFlags);
    _worldPacket << uint32(_ChannelFlags);
    _worldPacket << uint32(ChannelID);
    _worldPacket.WriteBits(ChannelName.length(), 7);
    _worldPacket.WriteString(ChannelName);

    return &_worldPacket;
}

WorldPackets::Channel::ChannelPlayerCommand::ChannelPlayerCommand(WorldPacket&& packet): ClientPacket(std::move(packet))
{
    switch (GetOpcode())
    {
    default:
        ASSERT(false);
    case CMSG_CHAT_CHANNEL_ANNOUNCEMENTS:
    case CMSG_CHAT_CHANNEL_BAN:
    case CMSG_CHAT_CHANNEL_DECLINE_INVITE:
    case CMSG_CHAT_CHANNEL_DISPLAY_LIST:
    case CMSG_CHAT_CHANNEL_INVITE:
    case CMSG_CHAT_CHANNEL_KICK:
    case CMSG_CHAT_CHANNEL_LIST:
    case CMSG_CHAT_CHANNEL_MODERATE:
    case CMSG_CHAT_CHANNEL_MODERATOR:
    case CMSG_CHAT_CHANNEL_MUTE:
    case CMSG_CHAT_CHANNEL_OWNER:
    case CMSG_CHAT_CHANNEL_PASSWORD:
    case CMSG_CHAT_CHANNEL_SET_OWNER:
    case CMSG_CHAT_CHANNEL_SILENCE_ALL:
    case CMSG_CHAT_CHANNEL_UNBAN:
    case CMSG_CHAT_CHANNEL_UNMODERATOR:
    case CMSG_CHAT_CHANNEL_UNMUTE:
    case CMSG_CHAT_CHANNEL_UNSILENCE_ALL:
        break;
    }
}

void WorldPackets::Channel::ChannelPlayerCommand::Read()
{
    switch (GetOpcode())
    {
        case CMSG_CHAT_CHANNEL_BAN:
        case CMSG_CHAT_CHANNEL_INVITE:
        case CMSG_CHAT_CHANNEL_KICK:
        case CMSG_CHAT_CHANNEL_MODERATOR:
        case CMSG_CHAT_CHANNEL_MUTE:
        case CMSG_CHAT_CHANNEL_SET_OWNER:
        case CMSG_CHAT_CHANNEL_SILENCE_ALL:
        case CMSG_CHAT_CHANNEL_UNBAN:
        case CMSG_CHAT_CHANNEL_UNMODERATOR:
        case CMSG_CHAT_CHANNEL_UNMUTE:
        case CMSG_CHAT_CHANNEL_UNSILENCE_ALL:
        {
            uint32 channelNameLength = _worldPacket.ReadBits(7);
            uint32 nameLength = _worldPacket.ReadBits(9);
            ChannelName = _worldPacket.ReadString(channelNameLength);
            Name = _worldPacket.ReadString(nameLength);
            break;
        }
        case CMSG_CHAT_CHANNEL_ANNOUNCEMENTS:
        case CMSG_CHAT_CHANNEL_DECLINE_INVITE:
        case CMSG_CHAT_CHANNEL_DISPLAY_LIST:
        case CMSG_CHAT_CHANNEL_LIST:
        case CMSG_CHAT_CHANNEL_MODERATE:
        case CMSG_CHAT_CHANNEL_OWNER:
            ChannelName = _worldPacket.ReadString(_worldPacket.ReadBits(7));
            break;
        case CMSG_CHAT_CHANNEL_PASSWORD:
        {
            uint32 channelNameLength = _worldPacket.ReadBits(7);
            uint32 nameLength = _worldPacket.ReadBits(7);
            ChannelName = _worldPacket.ReadString(channelNameLength);
            Name = _worldPacket.ReadString(nameLength);
            break;
        }
        default:
            break;
    }
}

void WorldPackets::Channel::JoinChannel::Read()
{
    _worldPacket >> ChatChannelId;
    CreateVoiceSession = _worldPacket.ReadBit();
    Internal = _worldPacket.ReadBit();
    uint32 channelLength = _worldPacket.ReadBits(7);
    uint32 passwordLength = _worldPacket.ReadBits(7);
    ChannelName = _worldPacket.ReadString(channelLength);
    Password = _worldPacket.ReadString(passwordLength);
}

void WorldPackets::Channel::LeaveChannel::Read()
{
    _worldPacket >> ZoneChannelID;
    ChannelName = _worldPacket.ReadString(_worldPacket.ReadBits(7));
}
