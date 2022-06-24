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

#ifndef __MESSAGEBUFFER_H_
#define __MESSAGEBUFFER_H_

#include "Define.h"
#include <vector>

class MessageBuffer
{
    typedef std::vector<uint8>::size_type size_type;

public:
    MessageBuffer();
    explicit MessageBuffer(std::size_t initialSize);
    MessageBuffer(MessageBuffer const& right);
    MessageBuffer(MessageBuffer&& right) noexcept;

    void Reset();
    void Resize(size_type bytes);

    uint8* GetBasePointer();
    uint8* GetReadPointer();
    uint8* GetWritePointer();

    void ReadCompleted(size_type bytes);
    void WriteCompleted(size_type bytes);

    size_type GetActiveSize() const;
    size_type GetRemainingSpace() const;
    size_type GetBufferSize() const;

    // Discards inactive data
    void Normalize();

    // Ensures there's "some" free space, make sure to call Normalize() before this
    void EnsureFreeSpace();

    void Write(void const* data, std::size_t size);

    std::vector<uint8>&& Move();

    MessageBuffer& operator=(MessageBuffer& right);
    MessageBuffer& operator=(MessageBuffer&& right) noexcept;

private:
    size_type _wpos;
    size_type _rpos;
    std::vector<uint8> _storage;
};

#endif /* __MESSAGEBUFFER_H_ */
