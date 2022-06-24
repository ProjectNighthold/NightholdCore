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

#ifndef _ADDONMGR_H
#define _ADDONMGR_H

#include <openssl/md5.h>
#include <string>
#include "Define.h"

struct AddonInfo
{
    AddonInfo(std::string const& name, uint8 _hasPubKey, uint32 crc, uint8 state, bool crcOrPubKey)
        : Name(name), hasPubKey(_hasPubKey), CRC(crc), State(state), UsePublicKeyOrCRC(crcOrPubKey) {}

    std::string Name;
    uint8 hasPubKey;
    uint32 CRC;
    uint8 State;
    bool UsePublicKeyOrCRC;
};

struct SavedAddon
{
    SavedAddon(std::string const& name, uint32 crc)
    {
        Name = name;
        CRC = crc;
    }

    std::string Name;
    uint32 CRC;
};

#define STANDARD_ADDON_CRC 0x4c1c776d

namespace AddonMgr
{
    void LoadFromDB();
    void SaveAddon(AddonInfo const& addon);
    SavedAddon const* GetAddonInfo(std::string const& name);
}

#endif

