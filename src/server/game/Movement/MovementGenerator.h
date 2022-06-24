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

#ifndef TRINITY_MOVEMENTGENERATOR_H
#define TRINITY_MOVEMENTGENERATOR_H

#include "ObjectRegistry.h"
#include "FactoryHolder.h"
#include "Common.h"
#include "MotionMaster.h"

class Unit;

class MovementGenerator
{
    public:
        virtual ~MovementGenerator();

        virtual void Initialize(Unit &) = 0;
        virtual void Finalize(Unit &) = 0;

        virtual void Reset(Unit &) = 0;

        virtual bool Update(Unit &, const uint32& time_diff) = 0;

        virtual MovementGeneratorType GetMovementGeneratorType() = 0;

        virtual void unitSpeedChanged() { }

        // used by Evade code for select point to evade with expected restart default movement
        virtual bool GetResetPosition(Unit &, float& /*x*/, float& /*y*/, float& /*z*/) { return false; }
};

template<class T, class D>
class MovementGeneratorMedium : public MovementGenerator
{
    public:
        void Initialize(Unit &u) override
        {
            //u->AssertIsType<T>();
            (static_cast<D*>(this))->DoInitialize(*((T*)&u));
        }
        void Finalize(Unit &u) override
        {
            //u->AssertIsType<T>();
            (static_cast<D*>(this))->DoFinalize(*((T*)&u));
        }
        void Reset(Unit &u) override
        {
            //u->AssertIsType<T>();
            (static_cast<D*>(this))->DoReset(*((T*)&u));
        }
        bool Update(Unit &u, const uint32& time_diff) override
        {
            //u->AssertIsType<T>();
            return (static_cast<D*>(this))->DoUpdate(*((T*)&u), time_diff);
        }
};

struct SelectableMovement : public FactoryHolder<MovementGenerator, MovementGeneratorType>
{
    SelectableMovement(MovementGeneratorType mgt) : FactoryHolder<MovementGenerator, MovementGeneratorType>(mgt) {}
};

template<class REAL_MOVEMENT>
struct MovementGeneratorFactory : public SelectableMovement
{
    MovementGeneratorFactory(MovementGeneratorType mgt) : SelectableMovement(mgt) {}

    MovementGenerator* Create(void *) const override;
};

typedef FactoryHolder<MovementGenerator, MovementGeneratorType> MovementGeneratorCreator;
typedef FactoryHolder<MovementGenerator, MovementGeneratorType>::FactoryHolderRegistry MovementGeneratorRegistry;
#endif

