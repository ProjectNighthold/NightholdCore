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

#ifndef __NPCHANDLER_H
#define __NPCHANDLER_H

struct QEmote
{
    uint32 _Emote;
    uint32 _Delay;
};

#define MAX_GOSSIP_TEXT_EMOTES 3

struct NpcTextData
{
    float Probability;
    uint32 BroadcastTextID;
};

#define MAX_NPC_TEXT_OPTIONS 8

struct NpcText
{
    NpcTextData Data[MAX_NPC_TEXT_OPTIONS];
};

struct PageTextLocale
{
    StringVector Text;
};

struct NpcTextLocale
{
    NpcTextLocale() { Text_0.resize(TOTAL_LOCALES - 1); Text_1.resize(TOTAL_LOCALES - 1); }

    std::vector<StringVector> Text_0;
    std::vector<StringVector> Text_1;
};
#endif

