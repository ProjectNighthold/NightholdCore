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

#ifndef _WARDEN_WIN_H
#define _WARDEN_WIN_H

#include <map>
#include "ARC4.h"
#include "BigNumber.h"
#include "ByteBuffer.h"
#include "Warden.h"

class WorldSession;
class Warden;

class WardenWin : public Warden
{
    public:
        WardenWin(WorldSession* session);
        ~WardenWin() {}

        void InitializeModule();
        void InitializeMPQCheckFunc(ByteBuffer& buff);
        void InitializeLuaCheckFunc(ByteBuffer& buff);
        void InitializeTimeCheckFunc(ByteBuffer& buff);

        void HandleHashResult(ByteBuffer &buff) override;
        void HandleHashResultSpecial(ByteBuffer &buff) override;
        void HandleModuleFailed() override;
        void RequestBaseData() override;
        void SendExtendedData() override;

        void HandleData(ByteBuffer &buff) override;
        void HandleChecks(ByteBuffer &buff);

        void HandleExtendedData(ByteBuffer &buff) override;
        void HandleStringData(ByteBuffer &buff) override;
        void HandleFailedSync(uint32 clientSeqIndex);

        // temp
        void ActivateModule() override;

        void BuildBaseChecksRequest(ByteBuffer &buff);
        void BuildSequenceHeader(ByteBuffer &buff);
        void AddCheckData(uint16 id, ByteBuffer &buff, ByteBuffer &stringBuf, uint8 &index);

        template<class T>
        void WriteAddress(ByteBuffer & buff, T address);

    private:
        std::map<std::string, std::vector<uint16>> _baseChecksList;
        std::vector<uint16> _currentChecks;

        uint32 _sequencePacketIndex;
};

#endif
