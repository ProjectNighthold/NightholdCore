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

#ifndef APPENDERCONSOLE_H
#define APPENDERCONSOLE_H

#include <string>
#include "Appender.h"
#include "LogCommon.h"

enum ColorTypes : uint8
{
    BLACK,
    RED,
    GREEN,
    BROWN,
    BLUE,
    MAGENTA,
    CYAN,
    GREY,
    YELLOW,
    LRED,
    LGREEN,
    LBLUE,
    LMAGENTA,
    LCYAN,
    WHITE,

    MaxColors
};

class AppenderConsole : public Appender
{
public:
    AppenderConsole(uint8 _id, std::string const& name, LogLevel level, AppenderFlags flags);
    void InitColors(const std::string& init_str);

private:
    void SetColor(bool stdout_stream, ColorTypes color);
    void ResetColor(bool stdout_stream);
    void _write(LogMessage const* message) override;
    bool _colored;
    ColorTypes _colors[NUM_ENABLED_LOG_LEVELS];
};

#endif
