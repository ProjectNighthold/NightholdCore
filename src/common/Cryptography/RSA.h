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

#include "Define.h"
#include <openssl/objects.h>
#include <openssl/rsa.h>
#include <string>
#include <type_traits>

class BigNumber;

namespace Trinity
{
namespace Crypto
{
class RSA
{
public:
    RSA(RSA const& rsa) = delete;
    RSA& operator=(RSA const& rsa) = delete;

    struct PublicKey {};
    struct PrivateKey {};

    struct NoPadding : std::integral_constant<int32, RSA_NO_PADDING> {};
    struct PKCS1Padding : std::integral_constant<int32, RSA_PKCS1_PADDING> {};

    struct SHA256 : std::integral_constant<int32, NID_sha256> {};

    RSA();
    RSA(RSA&& rsa);
    ~RSA();

    template <typename KeyTag>
    bool LoadFromFile(std::string const& fileName, KeyTag);

    template <typename KeyTag>
    bool LoadFromString(std::string const& keyPem, KeyTag);

    uint32 GetOutputSize() const { return uint32(RSA_size(_rsa)); }
    BigNumber GetModulus() const;

    template <typename KeyTag, typename PaddingTag>
    bool Encrypt(uint8 const* data, std::size_t dataLength, uint8* output, KeyTag, PaddingTag)
    {
        return Encrypt<KeyTag>(data, dataLength, output, PaddingTag::value);
    }

    template <typename HashTag>
    bool Sign(uint8 const* dataHash, std::size_t dataHashLength, uint8* output, HashTag)
    {
        return Sign(HashTag::value, dataHash, dataHashLength, output);
    }

private:
    template <typename KeyTag>
    bool Encrypt(uint8 const* data, std::size_t dataLength, uint8* output, int32 paddingType);

    bool Sign(int32 hashType, uint8 const* dataHash, std::size_t dataHashLength, uint8* output);

    ::RSA* _rsa;
};
}
}