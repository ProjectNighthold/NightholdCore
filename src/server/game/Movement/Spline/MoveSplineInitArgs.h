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

#ifndef TRINITYSERVER_MOVESPLINEINIT_ARGS_H
#define TRINITYSERVER_MOVESPLINEINIT_ARGS_H

#include "MoveSplineFlag.h"
#include "ObjectGuid.h"

namespace Movement
{
    typedef std::vector<G3D::Vector3> PointsArray;

    struct FacingInfo
    {
        struct
        {
            float x, y, z;
        } f;

        ObjectGuid target;
        MonsterMoveType type;
        float angle;

        FacingInfo(float o) : type(MONSTER_MOVE_NORMAL), angle(o) { f.x = f.y = f.z = 0.0f; }
        FacingInfo(ObjectGuid t) : target(t), type(MONSTER_MOVE_NORMAL), angle(0) { f.x = f.y = f.z = 0.0f; }
        FacingInfo(): type(MONSTER_MOVE_NORMAL), angle(0) { f.x = f.y = f.z = 0.0f; }
    };

    struct SpellEffectExtraData
    {
        ObjectGuid Target;
        uint32 SpellVisualId = 0;
        uint32 ProgressCurveId = 0;
        uint32 ParabolicCurveId = 0;
    };

    struct MoveSplineInitArgs
    {
        MoveSplineInitArgs(size_t path_capacity = 16);

        Optional<SpellEffectExtraData> spellEffectExtra;
        PointsArray path;
        FacingInfo facing;
        MoveSplineFlag flags;
        int32 path_Idx_offset;
        float velocity;
        float parabolic_amplitude;
        float time_perc;
        uint32 splineId;
        float initialOrientation;
        bool walk;
        bool HasVelocity;
        bool TransformForTransport;

        /** Returns true to show that the arguments were configured correctly and MoveSpline initialization will succeed. */
        bool Validate() const;
    private:
        bool _checkPathLengths() const;
    };
}

#endif // TRINITYSERVER_MOVESPLINEINIT_ARGS_H
