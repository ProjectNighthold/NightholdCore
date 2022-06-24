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

#ifndef _WARDEN_MAC_H
#define _WARDEN_MAC_H

#include "ARC4.h"
#include <map>
#include "BigNumber.h"
#include "ByteBuffer.h"
#include "Warden.h"

class WorldSession;
class Warden;

class WardenMac : public Warden
{
    public:
        WardenMac(WorldSession* session);
        ~WardenMac();

        void HandleHashResult(ByteBuffer &buff) override {}
        void HandleHashResultSpecial(ByteBuffer &buff) override;
        void HandleExtendedData(ByteBuffer &buff) override {}
        void HandleStringData(ByteBuffer &buff) override {}
        void HandleModuleFailed() override;
        void RequestBaseData() override {}
        void SendExtendedData() override {}

        void HandleData(ByteBuffer &buff) override {}

        // temp
        void ActivateModule() override;
};

#endif
