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

#ifndef TRINITY_OBJECTDEFINES_H
#define TRINITY_OBJECTDEFINES_H

#include "ObjectGuid.h"

#define CONTACT_DISTANCE            0.5f
#define INTERACTION_DISTANCE        5.0f
#define PETBATTLE_INTERACTION_DIST  20.0f
#define ATTACK_DISTANCE             5.0f
#define LOOT_DISTANCE               25.0f
#define MAX_VISIBILITY_DISTANCE     SIZE_OF_GRIDS           // max distance for visible objects
#define SIGHT_RANGE_UNIT            50.0f
#define DEFAULT_VISIBILITY_DISTANCE 90.0f                   // default visible distance, 90 yards on continents
#define DEFAULT_VISIBILITY_INSTANCE 170.0f                  // default visible distance in instances, 170 yards
#define DEFAULT_VISIBILITY_BGARENAS SIZE_OF_GRIDS           // default visible distance in BG/Arenas, roughly 533 yards
#define DEFAULT_WORLD_OBJECT_SIZE   0.306f                  // player size, also currently used (correctly?) for any non Unit world objects
#define MAGIC_RANGE                 30.0f
#define GLOBAL_VISIBILITY_DISTANCE  1000.0f

// used for creating values for respawn for example
#define MAKE_PAIR64(l, h)  uint64(uint32(l) | (uint64(h) << 32))
#define PAIR64_HIPART(x)   (uint32)((uint64(x) >> 32) & UI64LIT(0x00000000FFFFFFFF))
#define PAIR64_LOPART(x)   (uint32)(uint64(x)         & UI64LIT(0x00000000FFFFFFFF))
#define MAKE_PAIR16(l, h)  uint16(uint8(l) | (uint16(h) << 8))
#define MAKE_PAIR32(l, h)  uint32(uint16(l) | (uint32(h) << 16))
#define PAIR32_HIPART(x)   (uint16)((uint32(x) >> 16) & 0x0000FFFF)
#define PAIR32_LOPART(x)   (uint16)(uint32(x)         & 0x0000FFFF)


#endif

