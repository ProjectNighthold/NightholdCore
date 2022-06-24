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

#include "Realm.h"
#include "StringFormat.h"
#include <boost/asio/ip/address.hpp>

boost::asio::ip::address Realm::GetAddressForClient(boost::asio::ip::address const& clientAddr) const
{
    boost::asio::ip::address realmIp;

    // Attempt to send best address for client
    if (clientAddr.is_loopback())
    {
        // Try guessing if realm is also connected locally
        if (LocalAddress->is_loopback() || ExternalAddress->is_loopback())
            realmIp = clientAddr;
        else
        {
            // Assume that user connecting from the machine that bnetserver is located on
            // has all realms available in his local network
            realmIp = *LocalAddress;
        }
    }
    else
    {
        if (!LocalAddress || !LocalSubnetMask)
            return realmIp;

        if (clientAddr.is_v4() && (clientAddr.to_v4().to_ulong() & LocalSubnetMask->to_v4().to_ulong()) == (LocalAddress->to_v4().to_ulong() & LocalSubnetMask->to_v4().to_ulong()))
            realmIp = *LocalAddress;
        else
            realmIp = *ExternalAddress;
    }

    // Return external IP
    return realmIp;
}

uint32 Realm::GetConfigId() const
{
    return ConfigIdByType[Type];
}

uint32 const Realm::ConfigIdByType[MAX_CLIENT_REALM_TYPE] =
{
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14
};

Battlenet::RealmHandle::RealmHandle(): Region(0), Site(0), Realm(0)
{
}

Battlenet::RealmHandle::RealmHandle(uint8 region, uint8 battlegroup, uint32 index): Region(region), Site(battlegroup), Realm(index)
{
}

Battlenet::RealmHandle::RealmHandle(uint32 realmAddress): Region((realmAddress >> 24) & 0xFF), Site((realmAddress >> 16) & 0xFF), Realm(realmAddress & 0xFFFF)
{
}

bool Battlenet::RealmHandle::operator<(RealmHandle const& r) const
{
    return Realm < r.Realm;
}

uint32 Battlenet::RealmHandle::GetAddress() const
{
    return (Region << 24) | (Site << 16) | uint16(Realm);
}

std::string Battlenet::RealmHandle::GetAddressString() const
{
    return Trinity::StringFormat("%u-%u-%u", Region, Site, Realm);
}

std::string Battlenet::RealmHandle::GetSubRegionAddress() const
{
    return Trinity::StringFormat("%u-%u-0", Region, Site);
}
