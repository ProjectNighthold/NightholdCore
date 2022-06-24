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

#include "Logger.h"

Logger::Logger() : name(""), type(LOG_FILTER_GENERAL), level(LOG_LEVEL_DISABLED)
{
}

void Logger::Create(std::string const& _name, LogFilterType _type, LogLevel _level)
{
    name = _name;
    type = _type;
    level = _level;
}

Logger::~Logger()
{
    appenders.clear();
}

std::string const& Logger::getName() const
{
    return name;
}

LogFilterType Logger::getType() const
{
    return type;
}

LogLevel Logger::getLogLevel() const
{
    return level;
}

void Logger::addAppender(uint8 id, Appender* appender)
{
    appenders[id] = appender;
}

void Logger::delAppender(uint8 id)
{
    appenders.erase(id);
}

void Logger::setLogLevel(LogLevel _level)
{
    level = _level;
}

void Logger::write(LogMessage* message)
{
    if (!level || level > message->level || message->text.empty())
    {
        //fprintf(stderr, "Logger::write: Logger %s, Level %u. Msg %s Level %u WRONG LEVEL MASK OR EMPTY MSG\n", getName().c_str(), messge.level, message.text.c_str(), .message.level); // DEBUG - RemoveMe
        return;
    }

    for (auto& appender : appenders)
        if (appender.second)
            appender.second->write(message);
}
