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

#include "Creature.h"
#include "CreatureAISelector.h"
#include "PassiveAI.h"

#include "MovementGenerator.h"
#include "Pet.h"
#include "TemporarySummon.h"
#include "CreatureAIFactory.h"
#include "ScriptMgr.h"

namespace FactorySelector
{
    CreatureAI* selectAI(Creature* creature)
    {
        CreatureAICreator const* aiFactory = nullptr;
        if (creature->isPet())
            aiFactory = sCreatureAIRegistry->GetRegistryItem("PetAI");

        if (!aiFactory)
            if (auto scriptedAI = sScriptMgr->GetCreatureAI(creature))
                return scriptedAI;

        auto ainame = creature->GetAIName();
        if (!aiFactory && !ainame.empty())
            aiFactory = sCreatureAIRegistry->GetRegistryItem(ainame);

        if (!aiFactory)
        {
            if (creature->isMinion())
                aiFactory = sCreatureAIRegistry->GetRegistryItem("BattlePetAI");

            if (creature->IsVehicle() && creature->CanVehicleAI())
                aiFactory = sCreatureAIRegistry->GetRegistryItem("VehicleAI");
            else if (creature->HasUnitTypeMask(UNIT_MASK_CONTROLABLE_GUARDIAN) && static_cast<Guardian*>(creature)->GetOwner()->IsPlayer())
                aiFactory = sCreatureAIRegistry->GetRegistryItem("PetAI");
            else if (creature->HasFlag64(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK))
                aiFactory = sCreatureAIRegistry->GetRegistryItem("NullCreatureAI");
            else if (creature->isGuard())
                aiFactory = sCreatureAIRegistry->GetRegistryItem("GuardAI");
            else if (creature->HasUnitTypeMask(UNIT_MASK_CONTROLABLE_GUARDIAN))
                aiFactory = sCreatureAIRegistry->GetRegistryItem("PetAI");
            else if (creature->isTotem())
                aiFactory = sCreatureAIRegistry->GetRegistryItem("TotemAI");
            else if (creature->isAnySummons())
                aiFactory = sCreatureAIRegistry->GetRegistryItem("AnyPetAI");
            else if (creature->isTrigger())
            {
                if (creature->m_templateSpells[0])
                    aiFactory = sCreatureAIRegistry->GetRegistryItem("TriggerAI");
                else
                    aiFactory = sCreatureAIRegistry->GetRegistryItem("NullCreatureAI");
            }
            else if (creature->GetCreatureType() == CREATURE_TYPE_CRITTER && !creature->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
                aiFactory = sCreatureAIRegistry->GetRegistryItem("CritterAI");
        }

        if (!aiFactory)
        {
            auto best_val = -1;
            auto const& l = sCreatureAIRegistry->GetRegisteredItems();
            for (const auto& iter : l)
            {
                CreatureAICreator const* factory = iter.second;
                auto p = dynamic_cast<const SelectableAI*>(factory);
                ASSERT(p);
                auto val = p->Permit(creature);
                if (val > best_val)
                {
                    best_val = val;
                    aiFactory = p;
                }
            }
        }

        // select NullCreatureAI if not another cases
        ainame = aiFactory == nullptr ? "NullCreatureAI" : aiFactory->key();

        TC_LOG_DEBUG(LOG_FILTER_TSCR, "Creature %u used AI is %s.", creature->GetGUIDLow(), ainame.c_str());
        creature->SetNPCAIName(ainame);
        return aiFactory == nullptr ? new NullCreatureAI(creature) : aiFactory->Create(creature);
    }

    MovementGenerator* selectMovementGenerator(Creature* creature)
    {
        auto& mv_registry(*MovementGeneratorRegistry::instance());
        ASSERT(creature->GetCreatureTemplate());
        auto mv_factory = mv_registry.GetRegistryItem(creature->GetDefaultMovementType());

        /* if (mv_factory == NULL)
        {
            int best_val = -1;
            StringVector l;
            mv_registry.GetRegisteredItems(l);
            for (StringVector::iterator iter = l.begin(); iter != l.end(); ++iter)
            {
            const MovementGeneratorCreator *factory = mv_registry.GetRegistryItem((*iter).c_str());
            const SelectableMovement *p = dynamic_cast<const SelectableMovement *>(factory);
            ASSERT(p != NULL);
            int val = p->Permit(creature);
            if (val > best_val)
            {
                best_val = val;
                mv_factory = p;
            }
            }
        }*/

        return mv_factory == nullptr ? nullptr : mv_factory->Create(creature);
    }

    GameObjectAI* SelectGameObjectAI(GameObject* go)
    {
        if (auto scriptedAI = sScriptMgr->GetGameObjectAI(go))
            return scriptedAI;

        auto aiFactory = sGameObjectAIRegistry->GetRegistryItem(go->GetAIName());
        auto ainame = aiFactory == nullptr || go->GetScriptId() ? "NullGameObjectAI" : aiFactory->key();

        TC_LOG_DEBUG(LOG_FILTER_TSCR, "GameObject %u used AI is %s.", go->GetGUIDLow(), ainame.c_str());

        return aiFactory == nullptr ? new NullGameObjectAI(go) : aiFactory->Create(go);
    }
}
