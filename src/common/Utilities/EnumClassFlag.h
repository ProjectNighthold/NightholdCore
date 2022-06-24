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

#ifndef EnumClassFlag_h__
#define EnumClassFlag_h__

#include <type_traits>

template< class T >
using underlying_type_t = typename std::underlying_type<T>::type;

template<typename T>
class EnumClassFlag
{
    static_assert(std::is_enum<T>::value, "EnumClassFlag must be used only with enums");

public:
    /*implicit*/ EnumClassFlag(T value) : _value(value) { }

    EnumClassFlag& operator&=(EnumClassFlag right)
    {
        _value = static_cast<T>(static_cast<underlying_type_t<T>>(_value) & static_cast<underlying_type_t<T>>(right._value));
        return *this;
    }

    friend EnumClassFlag operator&(EnumClassFlag left, EnumClassFlag right)
    {
        return left &= right;
    }

    EnumClassFlag operator|=(EnumClassFlag right)
    {
        _value = static_cast<T>(static_cast<underlying_type_t<T>>(_value) | static_cast<underlying_type_t<T>>(right._value));
        return *this;
    }

    friend EnumClassFlag operator|(EnumClassFlag left, EnumClassFlag right)
    {
        return left |= right;
    }

    EnumClassFlag operator~() const
    {
        return static_cast<T>(~static_cast<underlying_type_t<T>>(_value));
    }

    void RemoveFlag(EnumClassFlag flag)
    {
        _value = static_cast<T>(static_cast<underlying_type_t<T>>(_value) & ~static_cast<underlying_type_t<T>>(flag._value));
    }

    bool HasFlag(T flag) const
    {
        return (static_cast<underlying_type_t<T>>(_value) & static_cast<underlying_type_t<T>>(flag)) != 0;
    }

    operator T() const
    {
        return _value;
    }

    underlying_type_t<T> AsUnderlyingType() const
    {
        return static_cast<underlying_type_t<T>>(_value);
    }

private:
    T _value;
};

#endif // EnumClassFlag_h__
