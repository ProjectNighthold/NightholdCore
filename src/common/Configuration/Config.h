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

#ifndef CONFIG_H
#define CONFIG_H

#include "Define.h"
#include <vector>

class ConfigMgr
{
    ConfigMgr() = default;
    ~ConfigMgr() = default;

public:

    ConfigMgr(ConfigMgr const&) = delete;
    ConfigMgr& operator=(ConfigMgr const&) = delete;

    bool LoadInitial(std::string const& file, std::string& error);

    static ConfigMgr* instance();

    bool Reload(std::string& error);

    std::string GetStringDefault(std::string const& name, const std::string& def);
    bool GetBoolDefault(std::string const& name, bool def);
    int GetIntDefault(std::string const& name, int def);
    float GetFloatDefault(std::string const& name, float def);

    std::string const& GetFilename();
    std::vector<std::string> GetKeysByString(std::string const& name);
};

#define sConfigMgr ConfigMgr::instance()

#endif
