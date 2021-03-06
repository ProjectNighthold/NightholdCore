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

#ifndef __PLAYERTAXI_H__
#define __PLAYERTAXI_H__

#include "WorldSession.h"

class PlayerTaxi
{
public:
    PlayerTaxi();
    ~PlayerTaxi() { }
    // Nodes
    void InitTaxiNodesForLevel(uint32 race, uint32 chrClass, uint8 level);
    void LoadTaxiMask(std::string const& data);

    bool IsTaximaskNodeKnown(uint32 nodeidx) const;

    bool SetTaximaskNode(uint32 nodeidx);
    void AppendTaximaskTo(WorldPackets::Taxi::ShowTaxiNodes& data, bool all, Player* player);
    TaxiMask const& GetTaxiMask() const;

    // Destinations
    bool LoadTaxiDestinationsFromString(std::string const& values, uint32 team);
    std::string SaveTaxiDestinationsToString();

    void ClearTaxiDestinations();
    void AddTaxiDestination(uint32 dest);
    void SetTaxiDestination(std::vector<uint32>& nodes);
    uint32 GetTaxiSource() const;
    uint32 GetTaxiDestination() const;
    uint32 GetCurrentTaxiPath() const;
    uint32 NextTaxiDestination();
    bool RequestEarlyLanding();
    std::deque<uint32> const& GetPath() const;
    bool empty() const;

    friend std::ostringstream& operator<< (std::ostringstream& ss, PlayerTaxi const& taxi);
private:
    TaxiMask m_taximask;
    std::deque<uint32> m_TaxiDestinations;
};

std::ostringstream& operator << (std::ostringstream& ss, PlayerTaxi const& taxi);

#endif
