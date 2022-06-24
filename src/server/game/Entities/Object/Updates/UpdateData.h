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

#ifndef __UPDATEDATA_H
#define __UPDATEDATA_H

#include "ByteBuffer.h"
#include "ObjectGuid.h"

class WorldPacket;

enum OBJECT_UPDATE_TYPE
{
    UPDATETYPE_VALUES               = 0,
    UPDATETYPE_CREATE_OBJECT        = 1,
    UPDATETYPE_CREATE_OBJECT2       = 2,
    UPDATETYPE_OUT_OF_RANGE_OBJECTS = 3,
};

enum OBJECT_UPDATE_FLAGS
{
    UPDATEFLAG_NONE                  = 0x0000,
    UPDATEFLAG_SELF                  = 0x0001,
    UPDATEFLAG_TRANSPORT             = 0x0002,
    UPDATEFLAG_HAS_TARGET            = 0x0004,
    UPDATEFLAG_LIVING                = 0x0008,
    UPDATEFLAG_STATIONARY_POSITION   = 0x0010,
    UPDATEFLAG_VEHICLE               = 0x0020,
    UPDATEFLAG_GO_TRANSPORT_POSITION = 0x0040,
    UPDATEFLAG_ROTATION              = 0x0080,
    UPDATEFLAG_ANIMKITS              = 0x0100,
    UPDATEFLAG_SCENE_OBJECT          = 0x0200,
    UPDATEFLAG_AREA_TRIGGER          = 0x0400,
    UPDATEFLAG_HAS_WORLDEFFECTID     = 0x0800,
    UPDATEFLAG_PLAY_HOVER_ANIM       = 0x1000,
};

class Player;

class UpdateData
{
    public:
        UpdateData(uint16 map);

        void AddOutOfRangeGUID(GuidSet& guids);
        void AddOutOfRangeGUID(ObjectGuid guid);
        void AddUpdateBlock(const ByteBuffer &block);
        bool BuildPacket(WorldPacket* packet);
        bool HasData() const;
        void Clear();

        GuidSet const& GetOutOfRangeGUIDs() const;

    protected:
        uint16 m_map;
        uint32 m_blockCount;
        GuidSet m_outOfRangeGUIDs;
        ByteBuffer m_data;
};
#endif

