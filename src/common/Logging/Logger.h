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

#ifndef LOGGER_H
#define LOGGER_H

#include "Appender.h"
#include "Define.h"
#include "LogCommon.h"
#include <unordered_map>
#include <memory>
#include <string>

class Logger
{
public:
    Logger();
    ~Logger();

    void Create(std::string const& name, LogFilterType type, LogLevel level);
    void addAppender(uint8 type, Appender *);
    void delAppender(uint8 type);

    std::string const& getName() const;
    LogFilterType getType() const;
    LogLevel getLogLevel() const;
    void setLogLevel(LogLevel level);
    void write(LogMessage* message);

private:
    std::string name;
    LogFilterType type;
    LogLevel level;
    std::unordered_map<uint8, Appender*> appenders;
};

#endif
