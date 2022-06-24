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

#ifndef PacketUtilities_h__
#define PacketUtilities_h__

#include "ByteBuffer.h"

namespace WorldPackets
{
    class PacketArrayMaxCapacityException : public ByteBufferException
    {
    public:
        PacketArrayMaxCapacityException(std::size_t requestedSize, std::size_t sizeLimit)
        {
            std::ostringstream builder;
            builder << "Attempted to read more array elements from packet " << requestedSize << " than allowed " << sizeLimit;
            message().assign(builder.str());
        }
    };

    template <typename T>
    class CompactArray
    {
    public:
        CompactArray() : _mask(0) { }

        CompactArray(CompactArray const& right) : _mask(right._mask), _contents(right._contents)
        { }

        CompactArray(CompactArray&& right) noexcept : _mask(right._mask), _contents(std::move(right._contents))
        {
            right._mask = 0;
        }

        CompactArray& operator= (CompactArray const& right)
        {
            _mask = right._mask;
            _contents = right._contents;
            return *this;
        }

        CompactArray& operator= (CompactArray&& right) noexcept
        {
            _mask = right._mask;
            right._mask = 0;
            _contents = std::move(right._contents);
            return *this;
        }

        uint32 GetMask() const { return _mask; }
        T const& operator[](size_t index) const { return _contents[index]; }
        size_t GetSize() const { return _contents.size(); }

        void Insert(size_t index, T const& value)
        {
            ASSERT(index < 0x20);

            _mask |= 1 << index;
            if (_contents.size() <= index)
                _contents.resize(index + 1);
            _contents[index] = value;
        }

        void Clear()
        {
            _mask = 0;
            _contents.clear();
        }

        bool operator==(CompactArray const& r) const
        {
            if (_mask != r._mask)
                return false;

            return _contents == r._contents;
        }

        bool operator!=(CompactArray const& r) const { return !(*this == r); }

    private:
        uint32 _mask;
        std::vector<T> _contents;
    };

    template <typename T>
    ByteBuffer& operator<<(ByteBuffer& data, CompactArray<T> const& v)
    {
        uint32 mask = v.GetMask();
        data << uint32(mask);
        for (size_t i = 0; i < v.GetSize(); ++i)
        {
            if (mask & (1 << i))
                data << v[i];
        }

        return data;
    }

    template <typename T>
    ByteBuffer& operator >> (ByteBuffer& data, CompactArray<T>& v)
    {
        uint32 mask;
        data >> mask;

        for (size_t index = 0; mask != 0; mask >>= 1, ++index)
        {
            if ((mask & 1) != 0)
            {
                T value;
                data >> value;
                v.Insert(index, value);
            }
        }

        return data;
    }
}

#endif // PacketUtilities_h__