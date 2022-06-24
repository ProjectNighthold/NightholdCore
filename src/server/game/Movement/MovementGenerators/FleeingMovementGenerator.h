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

#ifndef TRINITY_FLEEINGMOVEMENTGENERATOR_H
#define TRINITY_FLEEINGMOVEMENTGENERATOR_H

#include "MovementGenerator.h"

template<class T>
class FleeingMovementGenerator : public MovementGeneratorMedium< T, FleeingMovementGenerator<T> >
{
    public:
        explicit FleeingMovementGenerator(ObjectGuid fright) : is_water_ok(false), is_land_ok(false), i_only_forward(false), i_caster_x(0), i_caster_y(0), i_caster_z(0), i_x(0), i_y(0), i_z(0), i_last_distance_from_caster(0), i_to_distance_from_caster(0), i_cur_angle(0), i_frightGUID(fright), i_nextCheckTime(0)
        {
        }

        void DoInitialize(T &);
        void DoFinalize(T &);
        void DoReset(T &);
        bool DoUpdate(T &, const uint32 &);

        MovementGeneratorType GetMovementGeneratorType() override { return FLEEING_MOTION_TYPE; }

    private:
        void _setTargetLocation(T &owner);
        bool _getPoint(T &owner, float &x, float &y, float &z);
        bool _setMoveData(T &owner);
        void _Init(T &);

        bool is_water_ok   :1;
        bool is_land_ok    :1;
        bool i_only_forward:1;

        float i_caster_x;
        float i_caster_y;
        float i_caster_z;
        float i_x, i_y, i_z;
        float i_last_distance_from_caster;
        float i_to_distance_from_caster;
        float i_cur_angle;
        ObjectGuid i_frightGUID;
        TimeTracker i_nextCheckTime;
};

class TimedFleeingMovementGenerator : public FleeingMovementGenerator<Creature>
{
    public:
        TimedFleeingMovementGenerator(ObjectGuid fright, uint32 time) :
            FleeingMovementGenerator<Creature>(fright),
            i_totalFleeTime(time) {}

        MovementGeneratorType GetMovementGeneratorType() override { return TIMED_FLEEING_MOTION_TYPE; }
        bool DoUpdate(Unit &, const uint32&);
        void DoFinalize(Unit &);

    private:
        TimeTracker i_totalFleeTime;
};

#endif

