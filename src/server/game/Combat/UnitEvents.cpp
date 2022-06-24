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

#include "UnitEvents.h"

UnitBaseEvent::UnitBaseEvent(uint32 pType)
{
    iType = pType;
}

uint32 UnitBaseEvent::getType() const
{
    return iType;
}

bool UnitBaseEvent::matchesTypeMask(uint32 pMask) const
{
    return (iType & pMask) != 0;
}

void UnitBaseEvent::setType(uint32 pType)
{
    iType = pType;
}

ThreatRefStatusChangeEvent::ThreatRefStatusChangeEvent(uint32 pType): UnitBaseEvent(pType), iThreatManager(nullptr)
{
    iHostileReference = nullptr;
}

ThreatRefStatusChangeEvent::ThreatRefStatusChangeEvent(uint32 pType, HostileReference* pHostileReference): UnitBaseEvent(pType), iThreatManager(nullptr)
{
    iHostileReference = pHostileReference;
}

ThreatRefStatusChangeEvent::ThreatRefStatusChangeEvent(uint32 pType, HostileReference* pHostileReference, float pValue): UnitBaseEvent(pType), iThreatManager(nullptr)
{
    iHostileReference = pHostileReference;
    iFValue = pValue;
}

ThreatRefStatusChangeEvent::ThreatRefStatusChangeEvent(uint32 pType, HostileReference* pHostileReference, bool pValue): UnitBaseEvent(pType), iThreatManager(nullptr)
{
    iHostileReference = pHostileReference;
    iBValue = pValue;
}

int32 ThreatRefStatusChangeEvent::getIValue() const
{
    return iIValue;
}

float ThreatRefStatusChangeEvent::getFValue() const
{
    return iFValue;
}

bool ThreatRefStatusChangeEvent::getBValue() const
{
    return iBValue;
}

void ThreatRefStatusChangeEvent::setBValue(bool pValue)
{
    iBValue = pValue;
}

HostileReference* ThreatRefStatusChangeEvent::getReference() const
{
    return iHostileReference;
}

void ThreatRefStatusChangeEvent::setThreatManager(ThreatManager* pThreatManager)
{
    iThreatManager = pThreatManager;
}

ThreatManager* ThreatRefStatusChangeEvent::getThreatManager() const
{
    return iThreatManager;
}

ThreatManagerEvent::ThreatManagerEvent(uint32 pType): ThreatRefStatusChangeEvent(pType), iThreatContainer(nullptr)
{
}

ThreatManagerEvent::ThreatManagerEvent(uint32 pType, HostileReference* pHostileReference): ThreatRefStatusChangeEvent(pType, pHostileReference), iThreatContainer(nullptr)
{
}

void ThreatManagerEvent::setThreatContainer(ThreatContainer* pThreatContainer)
{
    iThreatContainer = pThreatContainer;
}

ThreatContainer* ThreatManagerEvent::getThreatContainer() const
{
    return iThreatContainer;
}
