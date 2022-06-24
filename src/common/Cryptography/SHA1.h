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

#ifndef _AUTH_SHA1_H
#define _AUTH_SHA1_H

#include "Define.h"
#include <string>
#include <type_traits>
#include <openssl/sha.h>

class BigNumber;

class SHA1Hash
{
public:
    typedef std::integral_constant<uint32, SHA_DIGEST_LENGTH> DigestLength;

    SHA1Hash();
    ~SHA1Hash();

    void UpdateBigNumbers(BigNumber* bn0, ...);

    void UpdateData(const uint8 *dta, int len);
    void UpdateData(const std::string &str);

    void Initialize();
    void Finalize();

    uint8 *GetDigest(void) { return mDigest; }
    int GetLength(void) const { return SHA_DIGEST_LENGTH; }

private:
    SHA_CTX mC;
    uint8 mDigest[SHA_DIGEST_LENGTH];
};

/// Returns the SHA1 hash of the given content as hex string.
std::string CalculateSHA1Hash(std::string const& content);

#endif
