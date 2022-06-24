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

#ifndef TRINITY_DISABLEMGR_H
#define TRINITY_DISABLEMGR_H

class Unit;

enum DisableType
{
    DISABLE_TYPE_SPELL                  = 0,
    DISABLE_TYPE_QUEST                  = 1,
    DISABLE_TYPE_MAP                    = 2,
    DISABLE_TYPE_BATTLEGROUND           = 3,
    DISABLE_TYPE_CRITERIA               = 4,
    DISABLE_TYPE_OUTDOORPVP             = 5,
    DISABLE_TYPE_VMAP                   = 6,
    DISABLE_TYPE_MMAP                   = 7,
    DISABLE_TYPE_LFG                    = 8,
    DISABLE_TYPE_ACHIEVEMENT            = 9,
    DISABLE_TYPE_CRITERIA_TREE          = 10,
    DISABLE_TYPE_MAX                    = 11,
};

enum SpellDisableTypes
{
    SPELL_DISABLE_PLAYER            = 0x1,
    SPELL_DISABLE_CREATURE          = 0x2,
    SPELL_DISABLE_PET               = 0x4,
    SPELL_DISABLE_DEPRECATED_SPELL  = 0x8,
    SPELL_DISABLE_MAP               = 0x10,
    SPELL_DISABLE_AREA              = 0x20,
    SPELL_DISABLE_LOS               = 0x40,
    MAX_SPELL_DISABLE_TYPE = (  SPELL_DISABLE_PLAYER | SPELL_DISABLE_CREATURE | SPELL_DISABLE_PET |
                                SPELL_DISABLE_DEPRECATED_SPELL | SPELL_DISABLE_MAP | SPELL_DISABLE_AREA |
                                SPELL_DISABLE_LOS)
};

enum VmapDisableTypes
{
    VMAP_DISABLE_AREAFLAG       = 0x1,
    VMAP_DISABLE_HEIGHT         = 0x2,
    VMAP_DISABLE_LOS            = 0x4,
    VMAP_DISABLE_LIQUIDSTATUS   = 0x8,
};

enum MMapDisableTypes
{
    MMAP_DISABLE_PATHFINDING    = 0x0
};

namespace DisableMgr
{
    void LoadDisables();
    bool IsDisabledFor(DisableType type, uint32 entry, Unit const* unit = nullptr, uint8 flags = 0);
    void CheckQuestDisables();
    bool IsVMAPDisabledFor(uint32 entry, uint8 flags);
    bool IsPathfindingEnabled(uint32 mapId);
}

#endif //TRINITY_DISABLEMGR_H
