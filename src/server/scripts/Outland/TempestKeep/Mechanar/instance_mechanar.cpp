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
#include "mechanar.h"

static DoorData const doorData[] =
{
    { GO_DOOR_MOARG_1,          DATA_GATEWATCHER_IRON_HAND,     DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { GO_DOOR_MOARG_2,          DATA_GATEWATCHER_GYROKILL,      DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { GO_DOOR_NETHERMANCER,     DATA_NETHERMANCER_SEPRETHREA,   DOOR_TYPE_ROOM,     BOUNDARY_NONE },
    { 0,                        0,                              DOOR_TYPE_ROOM,     BOUNDARY_NONE }
};

class instance_mechanar : public InstanceMapScript
{
    public:
        instance_mechanar(): InstanceMapScript("instance_mechanar", 554) { }

        struct instance_mechanar_InstanceMapScript : public InstanceScript
        {
            ObjectGuid chahcelegionGUID;
            
            instance_mechanar_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
            }
            
            void OnGameObjectCreate(GameObject* gameObject)
            {
                switch (gameObject->GetEntry())
                {
                    case GO_DOOR_MOARG_1:
                    case GO_DOOR_MOARG_2:
                    case GO_DOOR_NETHERMANCER:
                        AddDoor(gameObject, true);
                        break;
                    case GO_CHACHE_LEGION:
                        chahcelegionGUID = gameObject->GetGUID();
                        break;
                    default:
                        break;
                }
            }
            ObjectGuid GetGuidData(uint32 identifier) const
            {
                switch (identifier)
                {
                    case DATA_GO_CHAHCE_LEGION:
                        return chahcelegionGUID;
                }
                return ObjectGuid::Empty;
            }
                        
            void OnGameObjectRemove(GameObject* gameObject)
            {
                switch (gameObject->GetEntry())
                {
                    case GO_DOOR_MOARG_1:
                    case GO_DOOR_MOARG_2:
                    case GO_DOOR_NETHERMANCER:
                        AddDoor(gameObject, false);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_GATEWATCHER_GYROKILL:
                    case DATA_GATEWATCHER_IRON_HAND:
                    case DATA_MECHANOLORD_CAPACITUS:
                    case DATA_NETHERMANCER_SEPRETHREA:
                    case DATA_PATHALEON_THE_CALCULATOR:
                        break;
                    default:
                        break;
                }

                return true;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "M C " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* str)
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'M' && dataHead2 == 'C')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_mechanar_InstanceMapScript(map);
        }
};

void AddSC_instance_mechanar()
{
    new instance_mechanar();
}