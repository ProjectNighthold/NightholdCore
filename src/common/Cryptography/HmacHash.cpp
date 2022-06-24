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

#include "HmacHash.h"
#include "BigNumber.h"
#include "Errors.h"
#include <cstring>

#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x10100000L
HMAC_CTX* HMAC_CTX_new()
{
    HMAC_CTX *ctx = new HMAC_CTX();
    HMAC_CTX_init(ctx);
    return ctx;
}

void HMAC_CTX_free(HMAC_CTX* ctx)
{
    HMAC_CTX_cleanup(ctx);
    delete ctx;
}
#endif

template<HashCreateFn HashCreator, uint32 DigestLength>
HmacHash<HashCreator, DigestLength>::HmacHash(uint32 len, uint8 const* seed) : _ctx(HMAC_CTX_new())
{
    HMAC_Init_ex(_ctx, seed, len, HashCreator(), nullptr);
    memset(_digest, 0, DigestLength);
}

template<HashCreateFn HashCreator, uint32 DigestLength>
HmacHash<HashCreator, DigestLength>::~HmacHash()
{
    HMAC_CTX_free(_ctx);
}

template<HashCreateFn HashCreator, uint32 DigestLength>
void HmacHash<HashCreator, DigestLength>::UpdateData(std::string const& str)
{
    HMAC_Update(_ctx, reinterpret_cast<uint8 const*>(str.c_str()), str.length());
}

template<HashCreateFn HashCreator, uint32 DigestLength>
void HmacHash<HashCreator, DigestLength>::UpdateData(uint8 const* data, size_t len)
{
    HMAC_Update(_ctx, data, len);
}

template<HashCreateFn HashCreator, uint32 DigestLength>
void HmacHash<HashCreator, DigestLength>::Finalize()
{
    uint32 length = 0;
    HMAC_Final(_ctx, _digest, &length);
    ASSERT(length == DigestLength);
}

template<HashCreateFn HashCreator, uint32 DigestLength>
uint8* HmacHash<HashCreator, DigestLength>::ComputeHash(BigNumber* bn)
{
    HMAC_Update(_ctx, bn->AsByteArray().get(), bn->GetNumBytes());
    Finalize();
    return _digest;
}

template class HmacHash<EVP_sha1, SHA_DIGEST_LENGTH>;
template class HmacHash<EVP_sha256, SHA256_DIGEST_LENGTH>;
