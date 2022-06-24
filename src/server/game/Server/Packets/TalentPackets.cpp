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

#include "TalentPackets.h"

WorldPacket const* WorldPackets::Talent::UpdateTalentData::Write()
{
    _worldPacket << Info.ActiveGroup;
    _worldPacket << Info.ActiveSpecID;
    _worldPacket << static_cast<uint32>(Info.TalentGroups.size());

    for (auto const& talentGroupInfo : Info.TalentGroups)
    {
        _worldPacket << talentGroupInfo.SpecID;

        _worldPacket << static_cast<uint32>(talentGroupInfo.TalentIDs.size());
        _worldPacket << static_cast<uint32>(talentGroupInfo.PvPTalentIDs.size());

        for (uint16 talentID : talentGroupInfo.TalentIDs)
            _worldPacket << talentID;

        for (uint16 talentID : talentGroupInfo.PvPTalentIDs)
            _worldPacket << talentID;
    }

    return &_worldPacket;
}

void WorldPackets::Talent::LearnTalent::Read()
{
    Talents.resize(_worldPacket.ReadBits(6));
    for (uint16& talent : Talents)
        _worldPacket >> talent;
}

void WorldPackets::Talent::LearnPvpTalents::Read()
{
    TalentIDs.resize(_worldPacket.ReadBits(6));
    for (uint16& talent : TalentIDs)
        _worldPacket >> talent;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Talent::LearnTalentFailedData const& failed)
{
    data.WriteBits(static_cast<uint32>(failed.Reason), 4);
    data.FlushBits();
    data << failed.SpecID;
    data << static_cast<int32>(failed.TalentIDs.size());
    for (uint16 const& id : failed.TalentIDs)
        data << id;

    return data;
}

WorldPacket const* WorldPackets::Talent::LearnTalentFailed::Write()
{
    _worldPacket << Talent;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Talent::LearnPvPTalentFailed::Write()
{
    _worldPacket << PvPTalent;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Talent::GlyphBinding const& glyphBinding)
{
    data << uint32(glyphBinding.SpellID);
    data << uint16(glyphBinding.GlyphID);
    return data;
}

WorldPacket const* WorldPackets::Talent::ActiveGlyphs::Write()
{
    _worldPacket << static_cast<uint32>(Glyphs.size());
    for (GlyphBinding const& glyph : Glyphs)
        _worldPacket << glyph;

    _worldPacket.WriteBit(IsFullUpdate);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
