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

#include "PacketCrypt.h"

PacketCrypt::PacketCrypt(uint32 rc4InitSize)
    : _clientDecrypt(rc4InitSize), _serverEncrypt(rc4InitSize), _initialized(false)
{
}

void PacketCrypt::DecryptRecv(uint8* data, size_t len)
{
    if (!_initialized)
        return;

    _clientDecrypt.UpdateData(len, data);
}

void PacketCrypt::EncryptSend(uint8* data, size_t len)
{
    if (!_initialized)
        return;

    _serverEncrypt.UpdateData(len, data);
}
