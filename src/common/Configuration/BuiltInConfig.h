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

#ifndef BUILT_IN_CONFIG_H
#define BUILT_IN_CONFIG_H

#include "Define.h"
#include <string>

/// Provides helper functions to access built-in values
/// which can be overwritten in config
namespace BuiltInConfig
{
    /// Returns the CMake command when any is specified in the config,
    /// returns the built-in path otherwise
    std::string GetCMakeCommand();
    /// Returns the build directory path when any is specified in the config,
    /// returns the built-in one otherwise
    std::string GetBuildDirectory();
    /// Returns the source directory path when any is specified in the config,
    /// returns the built-in one otherwise
    std::string GetSourceDirectory();
    /// Returns the path to the mysql executable (`mysql`) when any is specified
    /// in the config, returns the built-in one otherwise
    std::string GetMySQLExecutable();

} // namespace BuiltInConfig

#endif // BUILT_IN_CONFIG_H
