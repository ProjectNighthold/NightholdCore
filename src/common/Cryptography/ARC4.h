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

#ifndef _AUTH_SARC4_H
#define _AUTH_SARC4_H

#include "Define.h"
#include <openssl/evp.h>

struct RC4_Context
{
    uint8 S[256] = {};
    uint8 x = 0;
    uint8 y = 0;
};

class ARC4
{
public:
    ARC4(uint32 len);
    ARC4(uint8* seed, uint32 len);
    ~ARC4();
    void Init(uint8* seed);
    void UpdateData(int len, uint8* data);

    static void rc4_init(RC4_Context * ctx, const uint8 * seed, int seedlen);
    static void rc4_process(RC4_Context * ctx, uint8 * data, int datalen);
private:
    EVP_CIPHER_CTX* m_ctx;
};

#endif
