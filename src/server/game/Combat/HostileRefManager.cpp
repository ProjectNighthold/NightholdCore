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

#include "HostileRefManager.h"
#include "ThreatManager.h"
#include "Unit.h"
#include "SpellInfo.h"

HostileRefManager::HostileRefManager(Unit* owner)
{
    iOwner = owner;
}

HostileRefManager::~HostileRefManager()
{
    deleteReferences();
}

Unit* HostileRefManager::getOwner()
{
    return iOwner;
}

void HostileRefManager::threatAssist(Unit* victim, float baseThreat, SpellInfo const* threatSpell)
{
    if (getSize() == 0 || baseThreat == 0.0f)
        return;

    SpellSchoolMask schoolMask = threatSpell ? threatSpell->GetSchoolMask() : SPELL_SCHOOL_MASK_NORMAL;
    float threat = ThreatCalcHelper::calcThreat(victim, iOwner, baseThreat, schoolMask, threatSpell);

    std::lock_guard<std::recursive_mutex> guard(i_threat_lock);
    HostileReference* ref = getFirst();
    threat /= getSize();
    while (ref)
    {
        if (ref->getSource())
        {
            if (Unit* owner = ref->getSource()->getOwner())
            {
                volatile uint32 entryorguid = owner->IsPlayer() ? owner->GetGUIDLow() : owner->GetEntry();
                if (owner->isAlive() && !owner->IsDelete() && owner->IsInWorld())
                    if (ThreatCalcHelper::isValidProcess(victim, owner, threatSpell))
                        ref->getSource()->doAddThreat(victim, threat, schoolMask, threatSpell);
            }
        }

        ref = ref->next();
    }
}

void HostileRefManager::addTempThreat(float threat, bool apply)
{
    std::lock_guard<std::recursive_mutex> guard(i_threat_lock);
    HostileReference* ref = getFirst();

    while (ref)
    {
        if (apply)
        {
            if (ref->getTempThreatModifier() == 0.0f)
                ref->addTempThreat(threat);
        }
        else
            ref->resetTempThreat();

        ref = ref->next();
    }
}

void HostileRefManager::addThreatPercent(int32 percent)
{
    std::lock_guard<std::recursive_mutex> guard(i_threat_lock);
    HostileReference* ref = getFirst();
    while (ref)
    {
        ref->addThreatPercent(percent);
        ref = ref->next();
    }
}

void HostileRefManager::setOnlineOfflineState(bool isOnline)
{
    std::lock_guard<std::recursive_mutex> guard(i_threat_lock);
    HostileReference* ref = getFirst();
    while (ref)
    {
        ref->setOnlineOfflineState(isOnline);
        ref = ref->next();
    }
}

void HostileRefManager::updateThreatTables()
{
    std::lock_guard<std::recursive_mutex> guard(i_threat_lock);
    HostileReference* ref = getFirst();
    while (ref)
    {
        ref->updateOnlineStatus();
        ref = ref->next();
    }
}

void HostileRefManager::deleteReferences()
{
    std::lock_guard<std::recursive_mutex> guard(i_threat_lock);
    HostileReference* ref = getFirst();
    while (ref)
    {
        HostileReference* nextRef = ref->next();
        ref->removeReference();
        delete ref;
        ref = nextRef;
    }
}

void HostileRefManager::deleteReferencesForFaction(uint32 faction)
{
    std::lock_guard<std::recursive_mutex> guard(i_threat_lock);
    HostileReference* ref = getFirst();
    while (ref)
    {
        HostileReference* nextRef = ref->next();
        if (ref->getSource()->getOwner()->getFactionTemplateEntry()->Faction == faction)
        {
            ref->removeReference();
            delete ref;
        }
        ref = nextRef;
    }
}

HostileReference* HostileRefManager::getFirst()
{
    return reinterpret_cast<HostileReference*>(RefManager<Unit, ThreatManager>::getFirst());
}

void HostileRefManager::deleteReference(Unit* creature)
{
    std::lock_guard<std::recursive_mutex> guard(i_threat_lock);
    HostileReference* ref = getFirst();
    while (ref)
    {
        HostileReference* nextRef = ref->next();
        if (ref->getSource()->getOwner() == creature)
        {
            ref->removeReference();
            delete ref;
            break;
        }
        ref = nextRef;
    }
}

void HostileRefManager::setOnlineOfflineState(Unit* creature, bool isOnline)
{
    std::lock_guard<std::recursive_mutex> guard(i_threat_lock);
    HostileReference* ref = getFirst();
    while (ref)
    {
        HostileReference* nextRef = ref->next();
        if (ref->getSource()->getOwner() == creature)
        {
            ref->setOnlineOfflineState(isOnline);
            break;
        }
        ref = nextRef;
    }
}

void HostileRefManager::UpdateVisibility()
{
    std::lock_guard<std::recursive_mutex> guard(i_threat_lock);
    HostileReference* ref = getFirst();
    while (ref)
    {
        HostileReference* nextRef = ref->next();
        if (!ref->getSource()->getOwner()->canSeeOrDetect(getOwner()))
        {
            ref->setOnlineOfflineState(false);
            nextRef = ref->next();
            //ref->removeReference();
            //delete ref;
        }
        else
            ref->setOnlineOfflineState(true);
        ref = nextRef;
    }
}

bool HostileRefManager::HasTarget(Unit* creature)
{
    HostileReference* ref = getFirst();
    while (ref)
    {
        HostileReference* nextRef = ref->next();
        if (ref->getSource()->getOwner() == creature)
        {
            return true;
        }
        ref = nextRef;
    }
    return false;
}
