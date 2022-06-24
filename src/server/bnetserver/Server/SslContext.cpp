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

#include "SslContext.h"
#include "Log.h"

bool Battlenet::SslContext::Initialize()
{
    boost::system::error_code err;

#define LOAD_CHECK(fn) do { fn; \
    if (err) \
    { \
        TC_LOG_ERROR(LOG_FILTER_GENERAL, #fn " failed: %s", err.message().c_str()); \
        return false; \
    } } while (0)

    LOAD_CHECK(instance().set_options(boost::asio::ssl::context::no_sslv3, err));
    LOAD_CHECK(instance().use_certificate_chain_file("bnetserver.cert.pem", err));
    LOAD_CHECK(instance().use_private_key_file("bnetserver.key.pem", boost::asio::ssl::context::pem, err));

#undef LOAD_CHECK

    return true;
}

boost::asio::ssl::context& Battlenet::SslContext::instance()
{
    static boost::asio::ssl::context context(boost::asio::ssl::context::sslv23);
    return context;
}
