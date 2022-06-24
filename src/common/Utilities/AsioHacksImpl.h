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

#ifndef AsioHacksImpl_h__
#define AsioHacksImpl_h__

#include <boost/asio/strand.hpp>

namespace Trinity
{
    class AsioStrand : public boost::asio::io_service::strand
    {
    public:
        explicit AsioStrand(boost::asio::io_service& io_service) : boost::asio::io_service::strand(io_service) { }
    };
}

#endif // AsioHacksImpl_h__
