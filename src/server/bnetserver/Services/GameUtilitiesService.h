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

#ifndef GameUtilitiesServiceService_h__
#define GameUtilitiesServiceService_h__

#include "Common.h"
#include "Service.h"
#include "game_utilities_service.pb.h"

namespace Battlenet
{
    class Session;

    namespace Services
    {
        class GameUtilities : public Service<game_utilities::v1::GameUtilitiesService>
        {
            typedef Service<game_utilities::v1::GameUtilitiesService> GameUtilitiesService;

        public:
            GameUtilities(Session* session);

            uint32 HandleProcessClientRequest(game_utilities::v1::ClientRequest const* request, game_utilities::v1::ClientResponse* response) override;
            uint32 HandleGetAllValuesForAttribute(game_utilities::v1::GetAllValuesForAttributeRequest const* request, game_utilities::v1::GetAllValuesForAttributeResponse* response) override;
        };
    }
}

#endif // GameUtilitiesServiceService_h__
