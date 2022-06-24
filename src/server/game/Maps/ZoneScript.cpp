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

#include "ZoneScript.h"
#include "Creature.h"
#include "WorldStatePackets.h"

ZoneScript::ZoneScript(): m_type(ZONE_TYPE_MAP) { }

void ZoneScript::SetType(uint8 type)
{
    m_type = type;
}

uint32 ZoneScript::GetCreatureEntry(uint32, CreatureData const* data)
{
    return data->id;
}

InstanceScript* ZoneScript::ToInstanceScript()
{
    if (m_type == ZONE_TYPE_INSTANCE)
        return reinterpret_cast<InstanceScript*>(this);
    return nullptr;
}
