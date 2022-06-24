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

/* ScriptData
SDName: Instance_Hellfire_Ramparts
SD%Complete: 50
SDComment:
SDCategory: Hellfire Ramparts
EndScriptData */

#include "hellfire_ramparts.h"

class instance_ramparts : public InstanceMapScript
{
    public:
        instance_ramparts() : InstanceMapScript("instance_ramparts", 543) { }

        struct instance_ramparts_InstanceMapScript : public InstanceScript
        {
            instance_ramparts_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_VAZRUDEN_HERALD:
                        vazrudenTheHeraldGUID = creature->GetGUID();
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_FEL_IRON_CHEST_NORMAL:
                    case GO_FEL_IRON_CHEST_HEROIC:
                        felIronChestGUID = go->GetGUID();
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_VAZRUDEN:
                    case DATA_NAZAN:
                        if (GetBossState(DATA_VAZRUDEN) == DONE && GetBossState(DATA_NAZAN) == DONE)
                        {
                            if (Creature* vh = instance->GetCreature(vazrudenTheHeraldGUID))
                                vh->DespawnOrUnsummon();
                            if (GameObject* chest = instance->GetGameObject(felIronChestGUID))
                                DoRespawnGameObject(felIronChestGUID, 86400);
                        }
                        break;
                    default:
                        break;
                }
                return true;
            }

        protected:
            ObjectGuid vazrudenTheHeraldGUID;
            ObjectGuid felIronChestGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_ramparts_InstanceMapScript(map);
        }
};

void AddSC_instance_ramparts()
{
    new instance_ramparts;
}
