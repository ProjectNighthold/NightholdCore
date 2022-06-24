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

#include "MessageBuffer.h"

MessageBuffer::MessageBuffer(): _wpos(0), _rpos(0), _storage()
{
    _storage.resize(2048);
}

MessageBuffer::MessageBuffer(std::size_t initialSize): _wpos(0), _rpos(0), _storage()
{
    _storage.resize(initialSize);
}

MessageBuffer::MessageBuffer(MessageBuffer const& right): _wpos(right._wpos), _rpos(right._rpos), _storage(right._storage)
{
}

MessageBuffer::MessageBuffer(MessageBuffer&& right) noexcept: _wpos(right._wpos), _rpos(right._rpos), _storage(right.Move())
{
}

void MessageBuffer::Reset()
{
    _wpos = 0;
    _rpos = 0;
}

void MessageBuffer::Resize(size_type bytes)
{
    _storage.resize(bytes);
}

uint8* MessageBuffer::GetBasePointer()
{
    return _storage.data();
}

uint8* MessageBuffer::GetReadPointer()
{
    return GetBasePointer() + _rpos;
}

uint8* MessageBuffer::GetWritePointer()
{
    return GetBasePointer() + _wpos;
}

void MessageBuffer::ReadCompleted(size_type bytes)
{
    _rpos += bytes;
}

void MessageBuffer::WriteCompleted(size_type bytes)
{
    _wpos += bytes;
}

MessageBuffer::size_type MessageBuffer::GetActiveSize() const
{
    return _wpos - _rpos;
}

MessageBuffer::size_type MessageBuffer::GetRemainingSpace() const
{
    return _storage.size() - _wpos;
}

MessageBuffer::size_type MessageBuffer::GetBufferSize() const
{
    return _storage.size();
}

void MessageBuffer::Normalize()
{
    if (_rpos)
    {
        if (_rpos != _wpos)
            memmove(GetBasePointer(), GetReadPointer(), GetActiveSize());
        _wpos -= _rpos;
        _rpos = 0;
    }
}

void MessageBuffer::EnsureFreeSpace()
{
    // resize buffer if it's already full
    if (GetRemainingSpace() == 0)
        _storage.resize(_storage.size() * 3 / 2);
}

void MessageBuffer::Write(void const* data, std::size_t size)
{
    if (size)
    {
        memcpy(GetWritePointer(), data, size);
        WriteCompleted(size);
    }
}

std::vector<uint8>&& MessageBuffer::Move()
{
    _wpos = 0;
    _rpos = 0;
    return std::move(_storage);
}

MessageBuffer& MessageBuffer::operator=(MessageBuffer& right)
{
    if (this != &right)
    {
        _wpos = right._wpos;
        _rpos = right._rpos;
        _storage = right._storage;
    }

    return *this;
}

MessageBuffer& MessageBuffer::operator=(MessageBuffer&& right) noexcept
{
    if (this != &right)
    {
        _wpos = right._wpos;
        _rpos = right._rpos;
        _storage = right.Move();
    }

    return *this;
}
