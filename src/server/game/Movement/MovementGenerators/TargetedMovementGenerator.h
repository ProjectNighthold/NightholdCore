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

#ifndef TRINITY_TARGETEDMOVEMENTGENERATOR_H
#define TRINITY_TARGETEDMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "FollowerReference.h"
#include "Timer.h"
#include "Unit.h"
#include "PathGenerator.h"

class TargetedMovementGeneratorBase
{
    public:
        TargetedMovementGeneratorBase(Unit &target) { i_target.link(&target, this); }
        void stopFollowing() { }
    protected:
        FollowerReference i_target;
};

template<class T, typename D>
class TargetedMovementGeneratorMedium : public MovementGeneratorMedium< T, D >, public TargetedMovementGeneratorBase
{
    protected:
        TargetedMovementGeneratorMedium(Unit &target, float offset, float angle) :
            TargetedMovementGeneratorBase(target), i_recheckDistance(0), i_targetSearchingTimer(0),
            i_offset(offset), i_angle(angle), i_recalculateTravel(false),
            i_targetReached(false), i_path(nullptr)
        {
        }
        ~TargetedMovementGeneratorMedium() { delete i_path; }

    public:
        bool DoUpdate(T &, const uint32 &);
        Unit* GetTarget() const { return i_target.getTarget(); }

        void unitSpeedChanged() override { i_recalculateTravel=true; }
        void UpdateFinalDistance(float fDistance);
        bool IsReachable() const { return (i_path) ? (i_path->GetPathType() & PATHFIND_NORMAL) : true; }
    protected:
        void _setTargetLocation(T &);
        void _updateSpeed(T &u);

        TimeTrackerSmall i_recheckDistance;
        uint32 i_targetSearchingTimer;
        float i_offset;
        float i_angle;
        bool i_recalculateTravel : 1;
        bool i_targetReached : 1;
        PathGenerator* i_path;
};

template<class T>
class ChaseMovementGenerator : public TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >
{
    public:
        ChaseMovementGenerator(Unit &target)
            : TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >(target) {}
        ChaseMovementGenerator(Unit &target, float offset, float angle)
            : TargetedMovementGeneratorMedium<T, ChaseMovementGenerator<T> >(target, offset, angle) {}
        ~ChaseMovementGenerator() {}

        MovementGeneratorType GetMovementGeneratorType() override { return CHASE_MOTION_TYPE; }

        void DoInitialize(T &);
        void DoFinalize(T &);
        void DoReset(T &);
        void MovementInform(T &);

        static void _clearUnitStateMove(T &u) { u.ClearUnitState(UNIT_STATE_CHASE_MOVE); }
        static void _addUnitStateMove(T &u)  { u.AddUnitState(UNIT_STATE_CHASE_MOVE); }
        bool EnableWalking() const { return false;}
        bool _lostTarget(T &u) const { return u.getVictim() != this->GetTarget(); }
        void _reachTarget(T &);
};

template<class T>
class FetchMovementGenerator : public TargetedMovementGeneratorMedium<T, FetchMovementGenerator<T> >
{
    public:
        FetchMovementGenerator(Unit &target)
            : TargetedMovementGeneratorMedium<T, FetchMovementGenerator<T> >(target) {}
        FetchMovementGenerator(Unit &target, float offset, float angle)
            : TargetedMovementGeneratorMedium<T, FetchMovementGenerator<T> >(target, offset, angle) {}
        ~FetchMovementGenerator() {}

        MovementGeneratorType GetMovementGeneratorType() override { return FOLLOW_MOTION_TYPE; }

        void DoInitialize(T &);
        void DoFinalize(T &);
        void DoReset(T &);
        void MovementInform(T &);

        static void _clearUnitStateMove(T &u) { u.ClearUnitState(UNIT_STATE_FOLLOW_MOVE); }
        static void _addUnitStateMove(T &u)  { u.AddUnitState(UNIT_STATE_FOLLOW_MOVE); }
        bool EnableWalking() const { return false;}
        bool _lostTarget(T &u) const { return false; }
        void _reachTarget(T &);
};

template<class T>
class FollowMovementGenerator : public TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >
{
    public:
        FollowMovementGenerator(Unit &target)
            : TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >(target){}
        FollowMovementGenerator(Unit &target, float offset, float angle)
            : TargetedMovementGeneratorMedium<T, FollowMovementGenerator<T> >(target, offset, angle) {}
        ~FollowMovementGenerator() {}

        MovementGeneratorType GetMovementGeneratorType() override { return FOLLOW_MOTION_TYPE; }

        void DoInitialize(T &);
        void DoFinalize(T &);
        void DoReset(T &);
        void MovementInform(T &);

        static void _clearUnitStateMove(T &u) { u.ClearUnitState(UNIT_STATE_FOLLOW_MOVE); }
        static void _addUnitStateMove(T &u)  { u.AddUnitState(UNIT_STATE_FOLLOW_MOVE); }
        bool EnableWalking() const;
        bool _lostTarget(T &) const { return false; }
        void _reachTarget(T &) {}
    private:
        void _updateSpeed(T &u);
};

#endif

