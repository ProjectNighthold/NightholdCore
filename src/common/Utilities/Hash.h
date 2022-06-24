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

#ifndef TrinityCore_Hash_h__
#define TrinityCore_Hash_h__

#include <functional>
#include <utility>

namespace Trinity
{
    template<typename T>
    void hash_combine(std::size_t& seed, T const& val)
    {
        seed ^= std::hash<T>()(val) + 0x9E3779B9 + (seed << 6) + (seed >> 2);
    }
}

 //! Hash implementation for std::pair to allow using pairs in unordered_set or as key for unordered_map
 //! Individual types used in pair must be hashable by std::hash
namespace std
{
    template<class K, class V>
    struct hash<std::pair<K, V>>
    {
        size_t operator()(std::pair<K, V> const& p) const
        {
            size_t hashVal = 0;
            Trinity::hash_combine(hashVal, p.first);
            Trinity::hash_combine(hashVal, p.second);
            return hashVal;
        }
    };
}

#endif // TrinityCore_Hash_h__
