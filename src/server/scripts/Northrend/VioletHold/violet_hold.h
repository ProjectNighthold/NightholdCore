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

#ifndef DEF_VIOLET_HOLD_H
#define DEF_VIOLET_HOLD_H

enum Data
{
    DATA_1ST_BOSS_EVENT,
    DATA_2ND_BOSS_EVENT,
    DATA_CYANIGOSA_EVENT,
    DATA_WAVE_COUNT,
    DATA_REMOVE_NPC,
    DATA_PORTAL_LOCATION,
    DATA_DOOR_INTEGRITY,
    DATA_NPC_PRESENCE_AT_DOOR,
    DATA_NPC_PRESENCE_AT_DOOR_ADD,
    DATA_NPC_PRESENCE_AT_DOOR_REMOVE,
    DATA_START_BOSS_ENCOUNTER,
    DATA_FIRST_BOSS,
    DATA_SECOND_BOSS,
    DATA_ACTIVATE_CRYSTAL,
    DATA_MAIN_EVENT_PHASE,
    DATA_DEFENSELESS,
};

enum Data64
{
    DATA_MORAGG,
    DATA_EREKEM,
    DATA_EREKEM_GUARD_1,
    DATA_EREKEM_GUARD_2,
    DATA_ICHORON,
    DATA_LAVANTHOR,
    DATA_XEVOZZ,
    DATA_ZURAMAT,
    DATA_CYANIGOSA,
    DATA_MORAGG_CELL,
    DATA_EREKEM_CELL,
    DATA_EREKEM_LEFT_GUARD_CELL,
    DATA_EREKEM_RIGHT_GUARD_CELL,
    DATA_ICHORON_CELL,
    DATA_LAVANTHOR_CELL,
    DATA_XEVOZZ_CELL,
    DATA_ZURAMAT_CELL,
    DATA_MAIN_DOOR,
    DATA_SINCLARI,
    DATA_TELEPORTATION_PORTAL,
    DATA_SABOTEUR_PORTAL,
    DATA_ADD_TRASH_MOB,
    DATA_DEL_TRASH_MOB
};

enum Bosses
{
    BOSS_NONE,              // 0 used as marker for not yet randomized
    BOSS_MORAGG,
    BOSS_EREKEM,
    BOSS_ICHORON,
    BOSS_LAVANTHOR,
    BOSS_XEVOZZ,
    BOSS_ZURAMAT,
    BOSS_CYANIGOSA
};

enum CreaturesIds
{
    CREATURE_TELEPORTATION_PORTAL                   = 31011,
    CREATURE_PORTAL_GUARDIAN                        = 30660,
    CREATURE_PORTAL_KEEPER                          = 30695,
    CREATURE_XEVOZZ                                 = 29266,
    CREATURE_LAVANTHOR                              = 29312,
    CREATURE_ICHORON                                = 29313,
    CREATURE_ZURAMAT                                = 29314,
    CREATURE_EREKEM                                 = 29315,
    CREATURE_EREKEM_GUARD                           = 29395,
    CREATURE_MORAGG                                 = 29316,
    CREATURE_CYANIGOSA                              = 31134,
    CREATURE_SINCLARI                               = 30658,
    CREATURE_SABOTEOUR                              = 31079,
    NPC_VIOLET_HOLD_GUARD                           = 30659,
    NPC_DEFENSE_SYSTEM                              = 30837
};

enum Events
{
    EVENT_ACTIVATE_CRYSTAL = 20001
};

#endif