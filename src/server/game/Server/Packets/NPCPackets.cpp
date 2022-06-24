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

#include "NPCPackets.h"
#include "ItemPackets.h"

void WorldPackets::NPC::Hello::Read()
{
    _worldPacket >> Unit;
}

WorldPacket const* WorldPackets::NPC::GossipMessage::Write()
{
    _worldPacket << GossipGUID;
    _worldPacket << GossipID;
    _worldPacket << FriendshipFactionID;
    _worldPacket << TextID;

    _worldPacket << static_cast<int32>(GossipOptions.size());
    _worldPacket << static_cast<int32>(GossipText.size());

    for (ClientGossipOptions const& options : GossipOptions)
    {
        _worldPacket << options.ClientOption;
        _worldPacket << options.OptionNPC;
        _worldPacket << options.OptionFlags;
        _worldPacket << options.OptionCost;

        _worldPacket.WriteBits(options.Text.size(), 12);
        _worldPacket.WriteBits(options.Confirm.size(), 12);
        _worldPacket.FlushBits();

        _worldPacket.WriteString(options.Text);
        _worldPacket.WriteString(options.Confirm);
    }

    for (ClientGossipText const& text : GossipText)
    {
        _worldPacket << text.QuestID;
        _worldPacket << text.QuestType;
        _worldPacket << text.QuestLevel;
        _worldPacket << text.QuestMaxScalingLevel;
        _worldPacket << text.QuestFlags[0];
        _worldPacket << text.QuestFlags[1];

        _worldPacket.WriteBit(text.Repeatable);
        _worldPacket.WriteBits(text.QuestTitle.size(), 9);
        _worldPacket.FlushBits();

        _worldPacket.WriteString(text.QuestTitle);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::NPC::VendorInventory::Write()
{
    _worldPacket << Vendor;
    _worldPacket << Reason;

    _worldPacket << static_cast<int32>(Items.size());
    for (VendorItem const& item : Items)
    {
        _worldPacket << item.MuID;
        _worldPacket << item.Type;
        _worldPacket << item.Quantity;
        _worldPacket << item.Price;
        _worldPacket << item.Durability;
        _worldPacket << item.StackCount;
        _worldPacket << item.ExtendedCostID;
        _worldPacket << item.PlayerConditionFailed;
        _worldPacket << item.Item;

        _worldPacket.WriteBit(item.DoNotFilterOnVendor);
        _worldPacket.FlushBits();
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::NPC::TrainerList::Write()
{
    _worldPacket << TrainerGUID;
    _worldPacket << TrainerType;
    _worldPacket << TrainerID;

    _worldPacket << static_cast<int32>(Spells.size());
    for (TrainerListSpell const& spell : Spells)
    {
        _worldPacket << spell.SpellID;
        _worldPacket << spell.MoneyCost;
        _worldPacket << spell.ReqSkillLine;
        _worldPacket << spell.ReqSkillRank;

        for (uint32 i = 0; i < MAX_TRAINERSPELL_ABILITY_REQS; ++i)
            _worldPacket << spell.ReqAbility[i];

        _worldPacket << spell.Usable;
        _worldPacket << spell.ReqLevel;
    }

    _worldPacket.WriteBits(Greeting.length(), 11);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(Greeting);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::NPC::ShowBank::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::NPC::ShowAdventureMap::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}

void WorldPackets::NPC::GossipSelectOption::Read()
{
    _worldPacket >> GossipUnit;
    _worldPacket >> GossipID;
    _worldPacket >> GossipIndex;
    uint32 length = _worldPacket.ReadBits(8);
    PromotionCode = _worldPacket.ReadString(length);
}

WorldPacket const* WorldPackets::NPC::PlayerTabardVendorActivate::Write()
{
    _worldPacket << Vendor;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::NPC::GossipPOI::Write()
{
    _worldPacket.WriteBits(Flags, 14);
    _worldPacket.WriteBits(Name.length(), 6);
    _worldPacket << Pos;
    _worldPacket << Icon;
    _worldPacket << Importance;
    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

void WorldPackets::NPC::SpiritHealerActivate::Read()
{
    _worldPacket >> Healer;
}

WorldPacket const* WorldPackets::NPC::SpiritHealerConfirm::Write()
{
    _worldPacket << Unit;

    return &_worldPacket;
}

void WorldPackets::NPC::TrainerBuySpell::Read()
{
    _worldPacket >> TrainerGUID;
    _worldPacket >> TrainerID;
    _worldPacket >> SpellID;
}

WorldPacket const* WorldPackets::NPC::TrainerBuyFailed::Write()
{
    _worldPacket << TrainerGUID;
    _worldPacket << SpellID;
    _worldPacket << TrainerFailedReason;

    return &_worldPacket;
}

void WorldPackets::NPC::RequestStabledPets::Read()
{
    _worldPacket >> StableMaster;
}

WorldPacket const* WorldPackets::NPC::OpenAlliedRaceDetails::Write()
{
    _worldPacket << SenderGUID;
    _worldPacket << RaceID;

    return &_worldPacket;
}
