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

#ifndef TRINITY_IDLEMOVEMENTGENERATOR_H
#define TRINITY_IDLEMOVEMENTGENERATOR_H

#include "MovementGenerator.h"

class IdleMovementGenerator : public MovementGenerator
{
    public:

        void Initialize(Unit &) override;
        void Finalize(Unit &) override{  }
        void Reset(Unit &) override;
        bool Update(Unit &, const uint32&) override { return true; }
        MovementGeneratorType GetMovementGeneratorType() override { return IDLE_MOTION_TYPE; }
};

extern IdleMovementGenerator si_idleMovement;

class RotateMovementGenerator : public MovementGenerator
{
    public:
        explicit RotateMovementGenerator(uint32 time, RotateDirection direction, bool _repeat = false) : m_duration(time), m_maxDuration(time), m_direction(direction), repeat(_repeat) {}

        void Initialize(Unit& owner) override;
        void Finalize(Unit& owner) override;
        void Reset(Unit& owner) override { Initialize(owner); }
        bool Update(Unit& owner, const uint32& time_diff) override;
        MovementGeneratorType GetMovementGeneratorType() override { return ROTATE_MOTION_TYPE; }

    private:
        uint32 m_duration, m_maxDuration;
        RotateDirection m_direction;
        bool repeat;
};

class DistractMovementGenerator : public MovementGenerator
{
    public:
        explicit DistractMovementGenerator(uint32 timer) : m_timer(timer) {}

        void Initialize(Unit& owner) override;
        void Finalize(Unit& owner) override;
        void Reset(Unit& owner) override { Initialize(owner); }
        bool Update(Unit& owner, const uint32& time_diff) override;
        MovementGeneratorType GetMovementGeneratorType() override { return DISTRACT_MOTION_TYPE; }

    private:
        uint32 m_timer;
};

class AssistanceDistractMovementGenerator : public DistractMovementGenerator
{
    public:
        AssistanceDistractMovementGenerator(uint32 timer) :
            DistractMovementGenerator(timer) {}

        MovementGeneratorType GetMovementGeneratorType() override { return ASSISTANCE_DISTRACT_MOTION_TYPE; }
        void Finalize(Unit& unit) override;
};

#endif

