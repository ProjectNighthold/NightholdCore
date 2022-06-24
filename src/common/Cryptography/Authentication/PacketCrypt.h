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

#ifndef _PACKETCRYPT_H
#define _PACKETCRYPT_H

#include "Cryptography/ARC4.h"

class BigNumber;

class PacketCrypt
{
    public:
        PacketCrypt(uint32 rc4InitSize);
        virtual ~PacketCrypt() { }

        virtual void Init(BigNumber* K) = 0;
        void DecryptRecv(uint8* data, size_t length);
        void EncryptSend(uint8* data, size_t length);

        bool IsInitialized() const { return _initialized; }

    protected:
        ARC4 _clientDecrypt;
        ARC4 _serverEncrypt;
        bool _initialized;
};

#endif // _PACKETCRYPT_H
