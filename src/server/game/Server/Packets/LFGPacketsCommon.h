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

#ifndef LFGPacketsCommon_h__
#define LFGPacketsCommon_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace LFG
    {
        enum class RideType : uint32
        {
            None = 0,
            Battlegrounds = 1,
            Lfg = 2,
            PvPPetBattle = 3,
            LfgListApplication = 4, // LFGListParty
            PetBattle = 5,
            LfgListApplicant = 6, // LFGListPlayer
        };

        struct RideTicket
        {
            ObjectGuid RequesterGuid;
            uint32 Id = 0;
            RideType Type = RideType::None;
            int32 Time = 0;
        };
    }
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::RideTicket& ticket);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::RideTicket const& ticket);

#endif // LFGPacketsCommon_h__
