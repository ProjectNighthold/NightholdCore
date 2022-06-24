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

#ifndef AsioHacksFwd_h__
#define AsioHacksFwd_h__

namespace boost
{
    namespace posix_time
    {
        class ptime;
    }

    namespace asio
    {
        namespace ip
        {
            class address;

            class tcp;

            template <typename InternetProtocol>
            class basic_endpoint;

            typedef basic_endpoint<tcp> tcp_endpoint;

            template <typename InternetProtocol>
            class resolver_service;

            template <typename InternetProtocol, typename ResolverService>
            class basic_resolver;

            typedef basic_resolver<tcp, resolver_service<tcp>> tcp_resolver;
        }

        template <typename Time>
        struct time_traits;

        template <typename TimeType, typename TimeTraits>
        class deadline_timer_service;

        template <typename Time, typename TimeTraits, typename TimerService>
        class basic_deadline_timer;

        typedef basic_deadline_timer<posix_time::ptime, time_traits<posix_time::ptime>, deadline_timer_service<posix_time::ptime, time_traits<posix_time::ptime>>> deadline_timer;
    }
}

namespace Trinity
{
    class AsioStrand;
}

#endif // AsioHacksFwd_h__
