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

#include "AppenderDB.h"
#include "Database/DatabaseEnv.h"

AppenderDB::AppenderDB(uint8 id, std::string const& name, LogLevel level, uint8 realmId):
Appender(id, name, APPENDER_DB, level), realm(realmId), enable(false)
{
}

AppenderDB::~AppenderDB() = default;

void AppenderDB::_write(LogMessage const* message)
{
    if (!enable)
        return;

    switch (message->type)
    {
        case LOG_FILTER_SQL:
        case LOG_FILTER_SQL_DRIVER:
        case LOG_FILTER_SQL_DEV:
            break; // Avoid infinite loop, PExecute triggers Logging with LOG_FILTER_SQL type
        default:
            auto stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_LOG);
            stmt->setUInt64(0, message->mtime);
            stmt->setUInt32(1, realm);
            stmt->setUInt8(2, message->type);
            stmt->setUInt8(3, message->level);
            stmt->setString(4, message->text);
            LoginDatabase.Execute(stmt);
            break;
    }
}

void AppenderDB::setEnable(bool _enable)
{
    enable = _enable;
}
