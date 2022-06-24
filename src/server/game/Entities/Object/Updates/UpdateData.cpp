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

#include "Common.h"
#include "ByteBuffer.h"
#include "WorldPacket.h"
#include "UpdateData.h"
#include "Opcodes.h"
#include "World.h"

UpdateData::UpdateData(uint16 map) : m_map(map), m_blockCount(0)
{
}

void UpdateData::AddOutOfRangeGUID(GuidSet& guids)
{
    m_outOfRangeGUIDs.insert(guids.begin(), guids.end());
}

void UpdateData::AddOutOfRangeGUID(ObjectGuid guid)
{
    m_outOfRangeGUIDs.insert(guid);
}

void UpdateData::AddUpdateBlock(const ByteBuffer &block)
{
    m_data.append(block);
    ++m_blockCount;
}

bool UpdateData::BuildPacket(WorldPacket* packet)
{
    ASSERT(packet->empty());                                // shouldn't happen
    packet->Initialize(SMSG_UPDATE_OBJECT, 2 + 4 + (m_outOfRangeGUIDs.empty() ? 0 : 1 + 4 + 9 * m_outOfRangeGUIDs.size()) + m_data.wpos());

    if (!HasData())
        return false;

    *packet << uint32(m_blockCount);
    *packet << uint16(m_map);

    if (packet->WriteBit(!m_outOfRangeGUIDs.empty()))
    {
        *packet << uint16(m_outOfRangeGUIDs.size());
        *packet << uint32(m_outOfRangeGUIDs.size());

        for (auto const& guid : m_outOfRangeGUIDs)
            *packet << guid;
    }

    *packet << uint32(m_data.size());
    packet->append(m_data);
    return true;
}

bool UpdateData::HasData() const
{
    return m_blockCount > 0 || !m_outOfRangeGUIDs.empty();
}

void UpdateData::Clear()
{
    m_data.clear();
    m_outOfRangeGUIDs.clear();
    m_blockCount = 0;
    m_map = 0;
}

GuidSet const& UpdateData::GetOutOfRangeGUIDs() const
{
    return m_outOfRangeGUIDs;
}

