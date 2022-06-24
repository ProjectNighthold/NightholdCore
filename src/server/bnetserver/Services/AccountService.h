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

#ifndef AccountService_h__
#define AccountService_h__

#include "Common.h"
#include "Service.h"
#include "account_service.pb.h"

namespace Battlenet
{
    class Session;

    namespace Services
    {
        class Account : public Service<account::v1::AccountService>
        {
            typedef Service<account::v1::AccountService> AccountService;

        public:
            Account(Session* session);

            uint32 HandleGetAccountState(account::v1::GetAccountStateRequest const* request, account::v1::GetAccountStateResponse* response) override;
            uint32 HandleGetGameAccountState(account::v1::GetGameAccountStateRequest const* request, account::v1::GetGameAccountStateResponse* response) override;
        };
    }
}

#endif // AccountService_h__
