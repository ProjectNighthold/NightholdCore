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

#ifndef EquipementSet_h__
#define EquipementSet_h__

#include "Define.h"
#include "ObjectGuid.h"
#include <array>
#include <map>

enum EquipmentSetUpdateState
{
    EQUIPMENT_SET_UNCHANGED = 0,
    EQUIPMENT_SET_CHANGED = 1,
    EQUIPMENT_SET_NEW = 2,
    EQUIPMENT_SET_DELETED = 3
};

#define EQUIPEMENT_SET_SLOTS 19

struct EquipmentSetInfo
{
    enum EquipmentSetType : int32
    {
        EQUIPMENT = 0,
        TRANSMOG = 1
    };

    struct EquipmentSetData
    {
        std::array<ObjectGuid, EQUIPEMENT_SET_SLOTS> Pieces;
        std::array<int32, EQUIPEMENT_SET_SLOTS> Appearances;
        std::array<int32, 2> Enchants;
        uint64 Guid = 0;
        uint32 SetID = 0;
        uint32 IgnoreMask = 0;
        EquipmentSetType Type = EQUIPMENT;
        int32 AssignedSpecIndex = -1;
        std::string SetName;
        std::string SetIcon;
    } Data;

    EquipmentSetUpdateState State = EQUIPMENT_SET_NEW;
};

#define MAX_EQUIPMENT_SET_INDEX 20                          // client limit

typedef std::map<uint64, EquipmentSetInfo> EquipmentSetContainer;

#endif // EquipementSet_h__
