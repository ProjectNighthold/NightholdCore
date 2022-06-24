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

#ifndef KillRewarder_h__
#define KillRewarder_h__

#include "Define.h"

class Player;
class Unit;
class Group;

class KillRewarder
{
public:
    KillRewarder(Player* killer, Unit* victim, bool isBattleGround);

    void Reward();

private:
    void _InitXP(Player* player);
    void _InitGroupData();

    void _RewardHonor(Player* player);
    void _RewardXP(Player* player, float rate);
    void _RewardReputation(Player* player, float rate);
    void _RewardKillCredit(Player* player);
    void _RewardPlayer(Player* player, bool isDungeon);
    void _RewardGroup();

    Player* _killer;
    Player* _maxNotGrayMember;
    Unit* _victim;
    Group* _group;
    uint32 _count;
    uint32 _countForRep;
    uint32 _sumLevel;
    uint32 _xp;
    float _groupRate;
    uint8 _maxLevel;
    bool _isBattleGround;
    bool _isFullXP;
    bool _isPvP;
};

#endif // KillRewarder_h__
