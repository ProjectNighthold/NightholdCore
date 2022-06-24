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

#include "ARC4.h"

ARC4::ARC4(uint32 len) : m_ctx(EVP_CIPHER_CTX_new())
{
    EVP_CIPHER_CTX_init(m_ctx);
    EVP_EncryptInit_ex(m_ctx, EVP_rc4(), nullptr, nullptr, nullptr);
    EVP_CIPHER_CTX_set_key_length(m_ctx, len);
}

ARC4::ARC4(uint8* seed, uint32 len) : m_ctx(EVP_CIPHER_CTX_new())
{
    EVP_CIPHER_CTX_init(m_ctx);
    EVP_EncryptInit_ex(m_ctx, EVP_rc4(), nullptr, nullptr, nullptr);
    EVP_CIPHER_CTX_set_key_length(m_ctx, len);
    EVP_EncryptInit_ex(m_ctx, nullptr, nullptr, seed, nullptr);
}

ARC4::~ARC4()
{
    EVP_CIPHER_CTX_free(m_ctx);
}

void ARC4::Init(uint8* seed)
{
    EVP_EncryptInit_ex(m_ctx, nullptr, nullptr, seed, nullptr);
}

void ARC4::UpdateData(int len, uint8* data)
{
    int outlen = 0;
    EVP_EncryptUpdate(m_ctx, data, &outlen, data, len);
    EVP_EncryptFinal_ex(m_ctx, data, &outlen);
}

void ARC4::rc4_init(RC4_Context * ctx, const uint8 * seed, int seedlen)
{
    for (int i = 0; i < 256; ++i)
        ctx->S[i] = i;

    ctx->x = 0;
    ctx->y = 0;

    int j = 0;

    for (int i = 0; i < 256; ++i)
    {
        j = (j + ctx->S[i] + seed[i % seedlen]) % 256;
        std::swap(ctx->S[i], ctx->S[j]);
    }
}

void ARC4::rc4_process(RC4_Context * ctx, uint8 * data, int datalen)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < datalen; ++i)
    {
        ctx->x = (ctx->x + 1) % 256;
        ctx->y = (ctx->y + ctx->S[ctx->x]) % 256;
        std::swap(ctx->S[ctx->x], ctx->S[ctx->y]);
        j = (ctx->S[ctx->x] + ctx->S[ctx->y]) % 256;
        data[i] ^= ctx->S[j];
    }
}
