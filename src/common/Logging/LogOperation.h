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

#ifndef LOGOPERATION_H
#define LOGOPERATION_H

#include "Define.h"
#include <memory>

class Logger;
struct LogMessage;

class LogOperation
{
public:
    LogOperation(Logger * _logger, std::unique_ptr<LogMessage>&& _msg);
    ~LogOperation();

    int call();

protected:
    Logger * logger;
    std::unique_ptr<LogMessage> msg;
};

#endif
