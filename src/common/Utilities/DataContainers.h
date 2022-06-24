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

#ifndef DataContainersH
#define DataContainersH

#include <boost/any.hpp>

namespace Trinity
{
    class AnyDataContainer
    {
        std::unordered_map<std::string, boost::any> dataMap;

    public:
        template<typename T>
        void Set(std::string const& key, T value)
        {
            dataMap[key] = value;
        }

        template<typename T>
        T GetValue(std::string const& key, T defaultValue = T()) const
        {
            auto itr = dataMap.find(key);
            if (itr != dataMap.end())
                return boost::any_cast<T>(itr->second);
            return defaultValue;
        }

        bool Exist(std::string const& key) const
        {
            return dataMap.find(key) != dataMap.end();
        }

        void Remove(std::string const& key)
        {
            dataMap.erase(key);
        }

        uint32 Increment(std::string const& key, uint32 increment = 1)
        {
            auto currentValue = GetValue<uint32>(key, uint32(0));
            Set(key, currentValue += increment);
            return currentValue;
        }

        bool IncrementOrProcCounter(std::string const& key, uint32 maxVal, uint32 increment = 1)
        {
            auto newValue = Increment(key, increment);
            if (newValue < maxVal)
                return false;

            Remove(key);
            return true;
        }
    };
}

#endif
