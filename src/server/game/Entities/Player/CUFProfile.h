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

#ifndef CUFProfile_h__
#define CUFProfile_h__

#include "Define.h"
#include <bitset>
#include <string>

#define MAX_CUF_PROFILES 5

enum CUFBoolOptions
{
    CUF_KEEP_GROUPS_TOGETHER,
    CUF_DISPLAY_PETS,
    CUF_DISPLAY_MAIN_TANK_AND_ASSIST,
    CUF_DISPLAY_HEAL_PREDICTION,
    CUF_DISPLAY_AGGRO_HIGHLIGHT,
    CUF_DISPLAY_ONLY_DISPELLABLE_DEBUFFS,
    CUF_DISPLAY_POWER_BAR,
    CUF_DISPLAY_BORDER,
    CUF_USE_CLASS_COLORS,
    CUF_DISPLAY_HORIZONTAL_GROUPS,
    CUF_DISPLAY_NON_BOSS_DEBUFFS,
    CUF_DYNAMIC_POSITION,
    CUF_LOCKED,
    CUF_SHOWN,
    CUF_AUTO_ACTIVATE_2_PLAYERS,
    CUF_AUTO_ACTIVATE_3_PLAYERS,
    CUF_AUTO_ACTIVATE_5_PLAYERS,
    CUF_AUTO_ACTIVATE_10_PLAYERS,
    CUF_AUTO_ACTIVATE_15_PLAYERS,
    CUF_AUTO_ACTIVATE_25_PLAYERS,
    CUF_AUTO_ACTIVATE_40_PLAYERS,
    CUF_AUTO_ACTIVATE_SPEC_1,
    CUF_AUTO_ACTIVATE_SPEC_2,
    CUF_AUTO_ACTIVATE_SPEC_3,
    CUF_AUTO_ACTIVATE_SPEC_4,
    CUF_AUTO_ACTIVATE_PVP,
    CUF_AUTO_ACTIVATE_PVE,

    CUF_BOOL_OPTIONS_COUNT,
};

struct CUFProfile
{
    CUFProfile()
    {
        FrameHeight = 0;
        FrameWidth = 0;
        SortBy = 0;
        HealthText = 0;
        TopPoint = 0;
        BottomPoint = 0;
        LeftPoint = 0;
        TopOffset = 0;
        BottomOffset = 0;
        LeftOffset = 0;
    }

    CUFProfile(std::string const& name, uint16 frameHeight, uint16 frameWidth, uint8 sortBy, uint8 healthText, uint32 boolOptions,
        uint8 topPoint, uint8 bottomPoint, uint8 leftPoint, uint16 topOffset, uint16 bottomOffset, uint16 leftOffset)
        : ProfileName(name), BoolOptions(int(boolOptions))
    {
        FrameHeight = frameHeight;
        FrameWidth = frameWidth;
        SortBy = sortBy;
        HealthText = healthText;
        TopPoint = topPoint;
        BottomPoint = bottomPoint;
        LeftPoint = leftPoint;
        TopOffset = topOffset;
        BottomOffset = bottomOffset;
        LeftOffset = leftOffset;
    }

    std::string ProfileName;
    uint16 FrameHeight;
    uint16 FrameWidth;
    uint16 TopOffset;
    uint16 BottomOffset;
    uint16 LeftOffset;
    uint8 SortBy;
    uint8 HealthText;
    uint8 TopPoint;
    uint8 BottomPoint;
    uint8 LeftPoint;

    std::bitset<CUF_BOOL_OPTIONS_COUNT> BoolOptions;
};

#endif // CUFProfile_h__
