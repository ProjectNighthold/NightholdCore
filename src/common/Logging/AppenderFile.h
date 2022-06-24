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

#ifndef APPENDERFILE_H
#define APPENDERFILE_H

#include "Appender.h"

class AppenderFile : public Appender
{
public:
    AppenderFile(uint8 _id, std::string const& _name, LogLevel level, const char* filename, const char* logDir, const char* mode, AppenderFlags flags);
    ~AppenderFile();
    FILE* OpenFile(std::string const& _name, std::string const& _mode, bool _backup);

private:
    void _write(LogMessage const* message) override;
    FILE* logfile;
    std::string filename;
    std::string logDir;
    std::string mode;
    bool dynamicName;
    bool backup;
};

#endif
