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

#ifndef GridObject_h__
#define GridObject_h__

template <typename ObjectType>
class GridObject
{
    typedef GridObject<ObjectType> SelfType;
    typedef std::vector<ObjectType*> ObjectTypeStorage;

public:
    GridObject() : _storage(), _offset(0) { }

    virtual ~GridObject() { }

    bool IsInGrid() const
    {
        return _storage != nullptr;
    }

    void AddToGrid(ObjectTypeStorage& storage)
    {
        if (IsInGrid())
            return;

        _storage = &storage;
        _offset = _storage->size();
        _storage->emplace_back(static_cast<ObjectType*>(this));
    }

    void RemoveFromGrid()
    {
        if (!IsInGrid())
            return;

        if (!(_storage->size() > _offset))
            return;

        auto& atOffset = (*_storage)[_offset];
        if (atOffset != static_cast<ObjectType*>(this))
            return;

        if (atOffset != _storage->back())
        {
            std::swap(atOffset, _storage->back());
            static_cast<SelfType*>(atOffset)->_offset = _offset;
        }

        _storage->pop_back();
        _storage = nullptr;
    }

private:
    ObjectTypeStorage* _storage;
    std::size_t _offset;
};

#endif
