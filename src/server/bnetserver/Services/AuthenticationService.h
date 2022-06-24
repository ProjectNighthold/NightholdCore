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

#ifndef AuthenticationService_h__
#define AuthenticationService_h__

#include "Common.h"
#include "Service.h"
#include "authentication_service.pb.h"

namespace Battlenet
{
    class Session;

    namespace Services
    {
        class Authentication : public Service<authentication::v1::AuthenticationService>
        {
            typedef Service<authentication::v1::AuthenticationService> AuthenticationService;

        public:
            Authentication(Session* session);

            uint32 HandleLogon(authentication::v1::LogonRequest const* request, NoData* respons) override;
            uint32 HandleVerifyWebCredentials(authentication::v1::VerifyWebCredentialsRequest const* request, NoData* respons) override;
        };
    }
}

#endif // AuthenticationService_h__
