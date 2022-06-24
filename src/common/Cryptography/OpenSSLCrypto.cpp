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

#include <OpenSSLCrypto.h>
#include <openssl/crypto.h>
#include <vector>
#include <thread>
#include <mutex>

std::vector<std::mutex*> cryptoLocks;

static void lockingCallback(int mode, int type, const char* /*file*/, int /*line*/)
{
    if (mode & CRYPTO_LOCK)
        cryptoLocks[type]->lock();
    else
        cryptoLocks[type]->unlock();
}

static void threadIdCallback(CRYPTO_THREADID * id)
{
    (void)id;
    CRYPTO_THREADID_set_numeric(id, std::hash<std::thread::id>()(std::this_thread::get_id()));
}

void OpenSSLCrypto::threadsSetup()
{
    cryptoLocks.resize(CRYPTO_num_locks());
    for(int i = 0 ; i < CRYPTO_num_locks(); ++i)
    {
        cryptoLocks[i] = new std::mutex();
    }

    (void)&threadIdCallback;
    CRYPTO_THREADID_set_callback(threadIdCallback);

    (void)&lockingCallback;
    CRYPTO_set_locking_callback(lockingCallback);
}

void OpenSSLCrypto::threadsCleanup()
{
    CRYPTO_set_locking_callback(NULL);
    CRYPTO_THREADID_set_callback(NULL);
    for(int i = 0 ; i < CRYPTO_num_locks(); ++i)
    {
        delete cryptoLocks[i];
    }
    cryptoLocks.resize(0);
}
