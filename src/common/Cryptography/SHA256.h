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

#ifndef SHA256_h__
#define SHA256_h__

#include "Define.h"
#include <string>
#include <type_traits>
#include <openssl/sha.h>

class BigNumber;

class SHA256Hash
{
public:
    typedef std::integral_constant<uint32, SHA256_DIGEST_LENGTH> DigestLength;

    SHA256Hash();
    ~SHA256Hash();

    void UpdateBigNumbers(BigNumber* bn0, ...);

    void UpdateData(uint8 const* data, size_t len);
    void UpdateData(std::string const& str);

    void Initialize();
    void Finalize();

    uint8* GetDigest();
    uint32 GetLength() const;

private:
    SHA256_CTX mC;
    uint8 mDigest[SHA256_DIGEST_LENGTH];
};

#endif // SHA256_h__
