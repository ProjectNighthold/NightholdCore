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

#include "AppenderFile.h"
#include "Common.h"

AppenderFile::AppenderFile(uint8 id, std::string const& name, LogLevel level, const char* _filename, const char* _logDir, const char* _mode, AppenderFlags _flags)
    : Appender(id, name, APPENDER_FILE, level, _flags), filename(_filename), logDir(_logDir), mode(_mode)
{
    dynamicName = std::string::npos != filename.find("%s");
    backup = (_flags & APPENDER_FLAGS_MAKE_FILE_BACKUP) != 0;

    logfile = !dynamicName ? OpenFile(_filename, _mode, backup) : nullptr;
}

AppenderFile::~AppenderFile()
{
    if (logfile)
    {
        fclose(logfile);
        logfile = nullptr;
    }
}

void AppenderFile::_write(LogMessage const* message)
{
    if (dynamicName)
    {
        char namebuf[260/*MAX_PATH*/];
        snprintf(namebuf, 260/*MAX_PATH*/, filename.c_str(), message->param1.c_str());
        logfile = OpenFile(namebuf, mode, backup);
    }

    if (logfile)
    {
        fprintf(logfile, "%s%s", message->prefix.c_str(), message->text.c_str());
        fflush(logfile);

        if (dynamicName)
        {
            fclose(logfile);
            logfile = nullptr;
        }
    }
}

FILE* AppenderFile::OpenFile(std::string const &filename, std::string const &mode, bool backup)
{
    if (mode == "w" && backup)
    {
        auto newName(filename);
        newName.push_back('.');
        newName.append(LogMessage::getTimeStr(time(nullptr)));
        rename(filename.c_str(), newName.c_str()); // no error handling... if we couldn't make a backup, just ignore
    }

    return fopen((logDir + filename).c_str(), mode.c_str());
}
