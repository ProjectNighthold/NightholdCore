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

/// \addtogroup world
/// @{
/// \file

#ifndef __WEATHER_H
#define __WEATHER_H

#include "Common.h"
#include "SharedDefines.h"
#include "Timer.h"

class Player;

#define WEATHER_SEASONS 4
struct WeatherSeasonChances
{
    uint32 rainChance;
    uint32 snowChance;
    uint32 stormChance;
};

struct WeatherData
{
    WeatherSeasonChances data[WEATHER_SEASONS];
    uint32 ScriptId;
};

enum WeatherState : uint32
{
    WEATHER_STATE_FINE              = 0,
    WEATHER_STATE_FOG               = 1, // Used in some instance encounters.
    WEATHER_STATE_LIGHT_RAIN        = 3,
    WEATHER_STATE_MEDIUM_RAIN       = 4,
    WEATHER_STATE_HEAVY_RAIN        = 5,
    WEATHER_STATE_LIGHT_SNOW        = 6,
    WEATHER_STATE_MEDIUM_SNOW       = 7,
    WEATHER_STATE_HEAVY_SNOW        = 8,
    WEATHER_STATE_LIGHT_SANDSTORM   = 22,
    WEATHER_STATE_MEDIUM_SANDSTORM  = 41,
    WEATHER_STATE_HEAVY_SANDSTORM   = 42,
    WEATHER_STATE_THUNDERS          = 86,
    WEATHER_STATE_BLACKRAIN         = 90,
    WEATHER_STATE_BLACKSNOW         = 106
};

/// Weather for one zone
class Weather
{
    public:

        Weather(uint32 zone, WeatherData const* weatherChances);
        ~Weather() { };

        bool Update(uint32 diff);
        bool ReGenerate();
        bool UpdateWeather();

        void SendWeatherUpdateToPlayer(Player* player);
        static void SendFineWeatherUpdateToPlayer(Player* player);
        void SetWeather(WeatherType type, float grade);

        /// For which zone is this weather?
        uint32 GetZone() const { return m_zone; };
        uint32 GetScriptId() const { return m_weatherChances->ScriptId; }

    private:

        WeatherState GetWeatherState() const;
        uint32 m_zone;
        WeatherType m_type;
        float m_grade;
        IntervalTimer m_timer;
        WeatherData const* m_weatherChances;
};

#endif
