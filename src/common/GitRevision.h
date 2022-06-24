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

#ifndef __GITREVISION_H__
#define __GITREVISION_H__

#include <string>
#include "Define.h"

namespace GitRevision
{
    char const* GetHash();
    char const* GetDate();
    char const* GetBranch();
    char const* GetCMakeCommand();
    char const* GetBuildDirectory();
    char const* GetSourceDirectory();
    char const* GetMySQLExecutable();
    char const* GetFullDatabase();
    char const* GetHotfixesDatabase();
    char const* GetFullVersion();
    char const* GetCompanyNameStr();
    char const* GetLegalCopyrightStr();
    char const* GetFileVersionStr();
    char const* GetProductVersionStr();
}

#endif
