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

#include "EquipmentSetPackets.h"

WorldPacket const* WorldPackets::EquipmentSet::EquipmentSetID::Write()
{
    _worldPacket << uint64(GUID);
    _worldPacket << int32(Type);
    _worldPacket << uint32(SetID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::EquipmentSet::LoadEquipmentSet::Write()
{
    _worldPacket << static_cast<uint32>(SetData.size());

    for (EquipmentSetInfo::EquipmentSetData const* equipSet : SetData)
    {
        _worldPacket << int32(equipSet->Type);
        _worldPacket << uint64(equipSet->Guid);
        _worldPacket << uint32(equipSet->SetID);
        _worldPacket << uint32(equipSet->IgnoreMask);

        for (uint8 i = 0; i < EQUIPEMENT_SET_SLOTS; ++i)
        {
            _worldPacket << equipSet->Pieces[i];
            _worldPacket << equipSet->Appearances[i];
        }

        _worldPacket.append(equipSet->Enchants.data(), equipSet->Enchants.size());

        _worldPacket.WriteBit(equipSet->AssignedSpecIndex != -1);
        _worldPacket.WriteBits(equipSet->SetName.length(), 8);
        _worldPacket.WriteBits(equipSet->SetIcon.length(), 9);
        _worldPacket.FlushBits();

        if (equipSet->AssignedSpecIndex != -1)
            _worldPacket << int32(equipSet->AssignedSpecIndex);

        _worldPacket.WriteString(equipSet->SetName);
        _worldPacket.WriteString(equipSet->SetIcon);
    }

    return &_worldPacket;
}

void WorldPackets::EquipmentSet::SaveEquipmentSet::Read()
{
    Set.Type = EquipmentSetInfo::EquipmentSetType(_worldPacket.read<int32>());
    _worldPacket >> Set.Guid;
    _worldPacket >> Set.SetID;
    _worldPacket >> Set.IgnoreMask;

    for (uint8 i = 0; i < EQUIPEMENT_SET_SLOTS; ++i)
    {
        _worldPacket >> Set.Pieces[i];
        _worldPacket >> Set.Appearances[i];
    }

    _worldPacket >> Set.Enchants[0];
    _worldPacket >> Set.Enchants[1];

    _worldPacket.FlushBits();

    bool hasSpecIndex = _worldPacket.ReadBit();
    uint32 setNameLength = _worldPacket.ReadBits(8);
    uint32 setIconLength = _worldPacket.ReadBits(9);

    if (hasSpecIndex)
        _worldPacket >> Set.AssignedSpecIndex;

    Set.SetName = _worldPacket.ReadString(setNameLength);
    Set.SetIcon = _worldPacket.ReadString(setIconLength);
}

void WorldPackets::EquipmentSet::DeleteEquipmentSet::Read()
{
    _worldPacket >> ID;
}

void WorldPackets::EquipmentSet::UseEquipmentSet::Read()
{
    _worldPacket >> Inv;

    for (uint8 i = 0; i < EQUIPEMENT_SET_SLOTS; ++i)
    {
        _worldPacket >> Items[i].Item;
        _worldPacket >> Items[i].ContainerSlot;
        _worldPacket >> Items[i].Slot;
    }

    _worldPacket >> GUID;
}

WorldPacket const* WorldPackets::EquipmentSet::UseEquipmentSetResult::Write()
{
    _worldPacket << uint64(GUID);
    _worldPacket << uint8(Reason);

    return &_worldPacket;
}

void WorldPackets::EquipmentSet::AssignEquipmentSetSpec::Read()
{
    _worldPacket >> GUID;
    _worldPacket >> SpecID;
}
