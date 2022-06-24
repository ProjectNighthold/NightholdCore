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

#ifndef IteratorPair_h__
#define IteratorPair_h__

#include "Define.h"
#include <utility>

namespace Trinity
{
    /**
     * @class IteratorPair
     *
     * @brief Utility class to enable range for loop syntax for multimap.equal_range uses
     */
    template<class iterator>
    class IteratorPair
    {
    public:
        IteratorPair() : _iterators() { }
        IteratorPair(std::pair<iterator, iterator> iterators) : _iterators(iterators) { }

        iterator begin() const { return _iterators.first; }
        iterator end() const { return _iterators.second; }

    private:
        std::pair<iterator, iterator> _iterators;
    };

    namespace Containers
    {
        template<class M>
        auto MapEqualRange(M& map, typename M::key_type const& key) -> IteratorPair<decltype(map.begin())>
        {
            return { map.equal_range(key) };
        }
    }
    //! namespace Containers
}
//! namespace Trinity

#endif // IteratorPair_h__
