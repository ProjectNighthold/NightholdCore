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

#ifndef _UNITEVENTS
#define _UNITEVENTS

#include "Common.h"

class ThreatContainer;
class ThreatManager;
class HostileReference;

enum UNIT_EVENT_TYPE
{
    // Player/Pet changed on/offline status
    UEV_THREAT_REF_ONLINE_STATUS        = 1<<0,

    // Threat for Player/Pet changed
    UEV_THREAT_REF_THREAT_CHANGE        = 1<<1,

    // Player/Pet will be removed from list (dead) [for internal use]
    UEV_THREAT_REF_REMOVE_FROM_LIST     = 1<<2,

    // Player/Pet entered/left  water or some other place where it is/was not accessible for the creature
    UEV_THREAT_REF_ASSECCIBLE_STATUS    = 1<<3,

    // Threat list is going to be sorted (if dirty flag is set)
    UEV_THREAT_SORT_LIST                = 1<<4,

    // New target should be fetched, could tbe the current target as well
    UEV_THREAT_SET_NEXT_TARGET          = 1<<5,

    // A new victim (target) was set. Could be NULL
    UEV_THREAT_VICTIM_CHANGED           = 1<<6,

    // Future use
    //UEV_UNIT_KILLED                   = 1<<7,

    //Future use
    //UEV_UNIT_HEALTH_CHANGE            = 1<<8,
};

#define UEV_THREAT_REF_EVENT_MASK (UEV_THREAT_REF_ONLINE_STATUS | UEV_THREAT_REF_THREAT_CHANGE | UEV_THREAT_REF_REMOVE_FROM_LIST | UEV_THREAT_REF_ASSECCIBLE_STATUS)
#define UEV_THREAT_MANAGER_EVENT_MASK (UEV_THREAT_SORT_LIST | UEV_THREAT_SET_NEXT_TARGET | UEV_THREAT_VICTIM_CHANGED)
#define UEV_ALL_EVENT_MASK (0xffffffff)


class UnitBaseEvent
{
    uint32 iType;
public:
    UnitBaseEvent(uint32 pType);
    uint32 getType() const;
    bool matchesTypeMask(uint32 pMask) const;

    void setType(uint32 pType);
};

class ThreatRefStatusChangeEvent : public UnitBaseEvent
{
    HostileReference* iHostileReference;
    union
    {
        float iFValue;
        int32 iIValue;
        bool iBValue;
    };
    ThreatManager* iThreatManager;
public:
    ThreatRefStatusChangeEvent(uint32 pType);
    ThreatRefStatusChangeEvent(uint32 pType, HostileReference* pHostileReference);
    ThreatRefStatusChangeEvent(uint32 pType, HostileReference* pHostileReference, float pValue);
    ThreatRefStatusChangeEvent(uint32 pType, HostileReference* pHostileReference, bool pValue);

    int32 getIValue() const;
    float getFValue() const;
    bool getBValue() const;
    void setBValue(bool pValue);

    HostileReference* getReference() const;

    void setThreatManager(ThreatManager* pThreatManager);
    ThreatManager* getThreatManager() const;
};

class ThreatManagerEvent : public ThreatRefStatusChangeEvent
{
    ThreatContainer* iThreatContainer;
public:
    ThreatManagerEvent(uint32 pType);
    ThreatManagerEvent(uint32 pType, HostileReference* pHostileReference);

    void setThreatContainer(ThreatContainer* pThreatContainer);
    ThreatContainer* getThreatContainer() const;
};

#endif
