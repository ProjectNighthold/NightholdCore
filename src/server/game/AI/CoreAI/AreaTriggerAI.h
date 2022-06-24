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

#ifndef TRINITY_AREATRIGGERAI_H
#define TRINITY_AREATRIGGERAI_H

#include "AreaTrigger.h"
#include "Define.h"

class AreaTrigger;
class Unit;

class AreaTriggerAI
{
    protected:
        AreaTrigger* const at;
    public:
        explicit AreaTriggerAI(AreaTrigger* a);
        virtual ~AreaTriggerAI();

        // Called when the AreaTrigger has just been initialized, just before added to map
        virtual void OnInitialize() { }

        // Called when the AreaTrigger has just been created
        virtual void OnCreate() { }

        // Called on each AreaTrigger update
        virtual void OnUpdate(uint32 /*diff*/) { }

        // Called when the AreaTrigger reach its destination
        virtual void OnDestinationReached() { }

        // Called when an unit enter the AreaTrigger
        virtual void OnUnitEnter(Unit* /*unit*/) { }

        // Called when an unit exit the AreaTrigger, or when the AreaTrigger is removed
        virtual void OnUnitExit(Unit* /*unit*/) { }

        // Called when the AreaTrigger is removed and clear affectedPlayers
        virtual void BeforeRemove(Unit* /*unit*/) { }

        // Called when the AreaTrigger is removed
        virtual void OnRemove() { }

        // Called when the AreaTrigger is create
        virtual bool CalculateSpline(Position const* pos, Position& startPos, Position& endPos, std::vector<Position>& path) { return false; }

        // Called when the AreaTrigger is create
        virtual void CalculateDuration(int32& duration) { }

        // Called AreaTrigger on Action
        virtual bool IsValidTarget(Unit* caster, Unit* target, AreaTriggerActionMoment actionM) { return false; }

        // Called when the AreaTrigger is update target
        virtual void ActionOnUpdate(GuidList& affectedPlayers) { }

        // Call special function from scripts
        virtual uint32 CallSpecialFunction(uint32 Num = 0) { return 0; }

        // Called instead GetAttackableUnitListInRange function
        virtual bool CreateUnitList(std::list<Unit*>& unitList) { return false; }

        // Call on Spline Point Reached
        virtual void OnChangeSplineId(uint32 splineIdNew, uint32 splineIdOld) { }

        // Call when the InitSplines
        virtual void ModifyMoveSpeed(float& speed) { }
};

class NullAreaTriggerAI : public AreaTriggerAI
{
    public:
        explicit NullAreaTriggerAI(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }
};

#endif
