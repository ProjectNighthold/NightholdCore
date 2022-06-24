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

#include "PassiveAI.h"
#include "ReactorAI.h"
#include "CombatAI.h"
#include "GuardAI.h"
#include "PetAI.h"
#include "TotemAI.h"
#include "RandomMovementGenerator.h"
#include "MovementGeneratorImpl.h"
#include "CreatureAIRegistry.h"
#include "WaypointMovementGenerator.h"
#include "CreatureAIFactory.h"
#include "SmartAI.h"

namespace AIRegistry
{
    void Initialize()
    {
        (new CreatureAIFactory<NullCreatureAI>("NullCreatureAI"))->RegisterSelf();
        (new CreatureAIFactory<TriggerAI>("TriggerAI"))->RegisterSelf();
        (new CreatureAIFactory<AggressorAI>("AggressorAI"))->RegisterSelf();
        (new CreatureAIFactory<ReactorAI>("ReactorAI"))->RegisterSelf();
        (new CreatureAIFactory<PassiveAI>("PassiveAI"))->RegisterSelf();
        (new CreatureAIFactory<CritterAI>("CritterAI"))->RegisterSelf();
        (new CreatureAIFactory<GuardAI>("GuardAI"))->RegisterSelf();
        (new CreatureAIFactory<PetAI>("PetAI"))->RegisterSelf();
        (new CreatureAIFactory<AnyPetAI>("AnyPetAI"))->RegisterSelf();
        (new CreatureAIFactory<TotemAI>("TotemAI"))->RegisterSelf();
        (new CreatureAIFactory<CombatAI>("CombatAI"))->RegisterSelf();
        (new CreatureAIFactory<CasterAI>("CasterAI"))->RegisterSelf();
        (new CreatureAIFactory<ArcherAI>("ArcherAI"))->RegisterSelf();
        (new CreatureAIFactory<TurretAI>("TurretAI"))->RegisterSelf();
        (new CreatureAIFactory<VehicleAI>("VehicleAI"))->RegisterSelf();
        (new CreatureAIFactory<SmartAI>("SmartAI"))->RegisterSelf();
        (new CreatureAIFactory<BattlePetAI>("BattlePetAI"))->RegisterSelf();

        (new GameObjectAIFactory<GameObjectAI>("GameObjectAI"))->RegisterSelf();
        (new GameObjectAIFactory<SmartGameObjectAI>("SmartGameObjectAI"))->RegisterSelf();

        (new MovementGeneratorFactory<RandomMovementGenerator<Creature> >(RANDOM_MOTION_TYPE))->RegisterSelf();
        (new MovementGeneratorFactory<WaypointMovementGenerator<Creature> >(WAYPOINT_MOTION_TYPE))->RegisterSelf();
    }
}

