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

#ifndef _AUTH_HMAC_H
#define _AUTH_HMAC_H

#include "Define.h"
#include <string>
#include <openssl/hmac.h>
#include <openssl/sha.h>

class BigNumber;

#define SEED_KEY_SIZE 16

typedef EVP_MD const* (*HashCreateFn)();

template<HashCreateFn HashCreator, uint32 DigestLength>
class HmacHash
{
public:
    HmacHash(uint32 len, uint8 const* seed);
    ~HmacHash();
    void UpdateData(std::string const& str);
    void UpdateData(uint8 const* data, size_t len);
    void Finalize();
    uint8* ComputeHash(BigNumber* bn);
    uint8* GetDigest() { return _digest; }
    uint32 GetLength() const { return DigestLength; }
private:
    HMAC_CTX* _ctx;
    uint8 _digest[DigestLength];
};

typedef HmacHash<EVP_sha1, SHA_DIGEST_LENGTH> HmacSha1;
typedef HmacHash<EVP_sha256, SHA256_DIGEST_LENGTH> HmacSha256;

#endif
