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

#include "BuiltInConfig.h"
#include "Config.h"
#include "GitRevision.h"

template<typename Fn>
static std::string GetStringWithDefaultValueFromFunction(
    std::string const& key, Fn getter)
{
    std::string const value = sConfigMgr->GetStringDefault(key, "");
    return value.empty() ? getter() : value;
}

std::string BuiltInConfig::GetCMakeCommand()
{
    return GetStringWithDefaultValueFromFunction(
        "CMakeCommand", GitRevision::GetCMakeCommand);
}

std::string BuiltInConfig::GetBuildDirectory()
{
    return GetStringWithDefaultValueFromFunction(
        "BuildDirectory", GitRevision::GetBuildDirectory);
}

std::string BuiltInConfig::GetSourceDirectory()
{
    return GetStringWithDefaultValueFromFunction(
        "SourceDirectory", GitRevision::GetSourceDirectory);
}

std::string BuiltInConfig::GetMySQLExecutable()
{
    return GetStringWithDefaultValueFromFunction(
        "MySQLExecutable", GitRevision::GetMySQLExecutable);
}
