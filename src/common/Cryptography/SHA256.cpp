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

#include "SHA256.h"
#include "BigNumber.h"
#include <cstring>
#include <cstdarg>

SHA256Hash::SHA256Hash()
{
    SHA256_Init(&mC);
    memset(mDigest, 0, SHA256_DIGEST_LENGTH * sizeof(uint8));
}

SHA256Hash::~SHA256Hash()
{
    SHA256_Init(&mC);
}

void SHA256Hash::UpdateData(uint8 const* data, size_t len)
{
    SHA256_Update(&mC, data, len);
}

void SHA256Hash::UpdateData(const std::string &str)
{
    UpdateData((uint8 const*)str.c_str(), str.length());
}

void SHA256Hash::UpdateBigNumbers(BigNumber* bn0, ...)
{
    va_list v;

    va_start(v, bn0);
    auto bn = bn0;
    while (bn)
    {
        UpdateData(bn->AsByteArray().get(), bn->GetNumBytes());
        bn = va_arg(v, BigNumber*);
    }
    va_end(v);
}

void SHA256Hash::Initialize()
{
    SHA256_Init(&mC);
}

void SHA256Hash::Finalize(void)
{
    SHA256_Final(mDigest, &mC);
}

uint8* SHA256Hash::GetDigest()
{
    return mDigest;
}

uint32 SHA256Hash::GetLength() const
{
    return SHA256_DIGEST_LENGTH;
}
