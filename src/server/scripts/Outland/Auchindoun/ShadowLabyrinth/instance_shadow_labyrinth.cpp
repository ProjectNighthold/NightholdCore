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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "shadow_labyrinth.h"

DoorData const doorData[] =
{
    { GO_REFECTORY_DOOR,        DATA_BLACKHEART_THE_INCITER,    DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { GO_SCREAMING_HALL_DOOR,   DATA_GRANDMASTER_VORPIL,        DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { 0,                        0,                              DOOR_TYPE_ROOM,     BOUNDARY_NONE } // END
};

class instance_shadow_labyrinth : public InstanceMapScript
{
    public:
        instance_shadow_labyrinth() : InstanceMapScript(SLScriptName, 555) { }

        struct instance_shadow_labyrinth_InstanceMapScript : public InstanceScript
        {
            instance_shadow_labyrinth_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                AmbassadorHellmawGUID.Clear();
                GrandmasterVorpilGUID.Clear();
                FelOverseerCount      = 0;
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_AMBASSADOR_HELLMAW:
                        AmbassadorHellmawGUID = creature->GetGUID();
                        break;
                    case NPC_GRANDMASTER_VORPIL:
                        GrandmasterVorpilGUID = creature->GetGUID();
                        break;
                    case NPC_FEL_OVERSEER:
                        if (creature->isAlive())
                        {
                            ++FelOverseerCount;
                            if (Creature* hellmaw = instance->GetCreature(AmbassadorHellmawGUID))
                                hellmaw->AI()->DoAction(ACTION_AMBASSADOR_HELLMAW_BANISH);
                        }
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go)
            {
                switch (go->GetEntry())
                {
                    case GO_REFECTORY_DOOR:
                    case GO_SCREAMING_HALL_DOOR:
                        AddDoor(go, true);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go)
            {
                switch (go->GetEntry())
                {
                    case GO_REFECTORY_DOOR:
                    case GO_SCREAMING_HALL_DOOR:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit)
            {
                Creature* creature = unit->ToCreature();
                if (!creature)
                    return;

                if (creature->GetEntry() == NPC_FEL_OVERSEER)
                {
                    if (FelOverseerCount)
                        --FelOverseerCount;

                    if (!FelOverseerCount)
                        if (Creature* hellmaw = instance->GetCreature(AmbassadorHellmawGUID))
                            hellmaw->AI()->DoAction(ACTION_AMBASSADOR_HELLMAW_INTRO);
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_FEL_OVERSEER:
                        return !FelOverseerCount ? 1 : 0;
                    default:
                        break;
                }
                return 0;
            }

            ObjectGuid GetGuidData(uint32 type) const
            {
                switch (type)
                {
                    case DATA_GRANDMASTER_VORPIL:
                        return GrandmasterVorpilGUID;
                    default:
                        break;
                }
                return ObjectGuid::Empty;
            }

        protected:
            ObjectGuid AmbassadorHellmawGUID;
            ObjectGuid GrandmasterVorpilGUID;
            uint32 FelOverseerCount;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_shadow_labyrinth_InstanceMapScript(map);
        }
};

void AddSC_instance_shadow_labyrinth()
{
    new instance_shadow_labyrinth();
}
