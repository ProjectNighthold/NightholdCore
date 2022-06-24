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

#ifndef TRINITYCORE_WORLDPACKET_H
#define TRINITYCORE_WORLDPACKET_H

#include "Common.h"
#include "Opcodes.h"
#include "ByteBuffer.h"

class WorldPacket : public ByteBuffer
{
    public:
        WorldPacket() : ByteBuffer(0), m_opcode(MAX_OPCODE), _connection(CONNECTION_TYPE_DEFAULT) { }
        WorldPacket(uint16 opcode, size_t res = 200, ConnectionType connection = CONNECTION_TYPE_DEFAULT) : ByteBuffer(res), m_opcode(opcode), _connection(connection) { }
        WorldPacket(WorldPacket&& packet) noexcept : ByteBuffer(std::move(packet)), m_opcode(packet.m_opcode), _connection(packet._connection) { }
        WorldPacket(WorldPacket const& right) : ByteBuffer(right), m_opcode(right.m_opcode), _connection(right._connection) { }

        WorldPacket& operator=(WorldPacket const& right)
        {
            if (this != &right)
            {
                m_opcode = right.m_opcode;
                _connection = right._connection;
                ByteBuffer::operator =(right);
            }

            return *this;
        }

        WorldPacket& operator=(WorldPacket&& right) noexcept
        {
            if (this != &right)
            {
                m_opcode = right.m_opcode;
                _connection = right._connection;
                ByteBuffer::operator=(std::move(right));
            }

            return *this;
        }

        WorldPacket(uint16 opcode, MessageBuffer&& buffer, ConnectionType connection = CONNECTION_TYPE_DEFAULT) : ByteBuffer(std::move(buffer)), m_opcode(opcode), _connection(connection) { }

        void Initialize(uint16 opcode, size_t newres = 200, ConnectionType connection = CONNECTION_TYPE_DEFAULT)
        {
            clear();
            _storage.reserve(newres);
            m_opcode = opcode;
            _connection = connection;
        }

        uint16 GetOpcode() const { return m_opcode; }
        void SetOpcode(uint16 opcode) { m_opcode = opcode; }

        ConnectionType GetConnection() const { return _connection; }

    protected:
        uint16 m_opcode;
        ConnectionType _connection;
};

#endif
