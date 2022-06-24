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

#ifndef _HOSTILEREFMANAGER
#define _HOSTILEREFMANAGER

#include "RefManager.h"

class Unit;
class ThreatManager;
class HostileReference;
class SpellInfo;

class HostileRefManager : public RefManager<Unit, ThreatManager>
{
    Unit* iOwner;
    std::recursive_mutex i_threat_lock;
public:
    explicit HostileRefManager(Unit* owner);
    ~HostileRefManager();

    Unit* getOwner();

    void threatAssist(Unit* victim, float baseThreat, SpellInfo const* threatSpell = nullptr);

    void addTempThreat(float threat, bool apply);

    void addThreatPercent(int32 percent);

    void deleteReferences();

    void deleteReferencesForFaction(uint32 faction);

    HostileReference* getFirst();

    void updateThreatTables();

    void setOnlineOfflineState(bool isOnline);

    void setOnlineOfflineState(Unit* creature, bool isOnline);

    bool HasTarget(Unit* creature);

    void deleteReference(Unit* creature);

    void UpdateVisibility();
};

#endif
