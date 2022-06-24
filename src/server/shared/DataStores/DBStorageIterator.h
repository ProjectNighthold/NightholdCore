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

#ifndef DBStorageIterator_h__
#define DBStorageIterator_h__

#include "Define.h"
#include <iterator>

template<class T>
class DBStorageIterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
    DBStorageIterator() : _index(nullptr), _pos(0), _end(0) { }
    DBStorageIterator(T** index, uint32 size, uint32 pos = 0) : _index(index), _pos(pos), _end(size)
    {
        if (_pos < _end)
        {
            while (_pos < _end && !_index[_pos])
                ++_pos;
        }
    }

    T const* operator->() { return _index[_pos]; }
    T const* operator*() { return _index[_pos]; }

    bool operator==(DBStorageIterator const& right) const { /*ASSERT(_index == right._index, "Iterator belongs to a different container")*/ return _pos == right._pos; }
    bool operator!=(DBStorageIterator const& right) const { return !(*this == right); }

    DBStorageIterator& operator++()
    {
        if (_pos < _end)
        {
            do
                ++_pos;
            while (_pos < _end && !_index[_pos]);
        }

        return *this;
    }

    DBStorageIterator operator++(int)
    {
        DBStorageIterator tmp = *this;
        ++*this;
        return tmp;
    }

private:
    T** _index;
    uint32 _pos;
    uint32 _end;
};

#endif // DBStorageIterator_h__
