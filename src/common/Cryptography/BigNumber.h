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

#ifndef _AUTH_BIGNUMBER_H
#define _AUTH_BIGNUMBER_H

#include "Define.h"
#include <memory>
#include <string>

struct bignum_st;

class BigNumber
{
public:
    BigNumber();
    BigNumber(BigNumber const& bn);
    BigNumber(uint32);
    ~BigNumber();

    void SetDword(uint32);
    void SetQword(uint64);
    void SetBinary(uint8 const* bytes, int32 len);
    void SetHexStr(char const* str);

    void SetRand(int32 numbits);

    BigNumber& operator=(BigNumber const& bn);

    BigNumber operator+=(BigNumber const& bn);
    BigNumber operator+(BigNumber const& bn);

    BigNumber operator-=(BigNumber const& bn);
    BigNumber operator-(BigNumber const& bn);

    BigNumber operator*=(BigNumber const& bn);
    BigNumber operator*(BigNumber const& bn);

    BigNumber operator/=(BigNumber const& bn);
    BigNumber operator/(BigNumber const& bn);

    BigNumber operator%=(BigNumber const& bn);
    BigNumber operator%(BigNumber const& bn);

    bool IsZero() const;
    bool IsNegative() const;

    BigNumber ModExp(BigNumber const& bn1, BigNumber const& bn2);
    BigNumber Exp(BigNumber const&);

    int32 GetNumBytes(void);

    struct bignum_st* BN();

    uint32 AsDword();

    std::unique_ptr<uint8[]> AsByteArray(int32 minSize = 0, bool littleEndian = true);

    std::string AsHexStr() const;
    std::string AsDecStr() const;

private:
    struct bignum_st *_bn;

};
#endif

