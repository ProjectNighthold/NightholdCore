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

#ifndef TRINITY_CONFUSEDGENERATOR_H
#define TRINITY_CONFUSEDGENERATOR_H

#include "MovementGenerator.h"
#include "Timer.h"

template<class T>
class ConfusedMovementGenerator : public MovementGeneratorMedium< T, ConfusedMovementGenerator<T> >
{
    public:
        explicit ConfusedMovementGenerator() : i_nextMoveTime(0), i_duration(0), i_x(0), i_y(0), i_z(0), moving_to_start(false), speed(0)
        {
        }

        void DoInitialize(T &);
        void DoFinalize(T &);
        void DoReset(T &);
        bool DoUpdate(T &, const uint32 &);

        MovementGeneratorType GetMovementGeneratorType() override { return CONFUSED_MOTION_TYPE; }
    private:
        TimeTracker i_nextMoveTime;
        uint32 i_duration;
        float i_x, i_y, i_z;
        bool moving_to_start;
        float speed;
};
#endif

