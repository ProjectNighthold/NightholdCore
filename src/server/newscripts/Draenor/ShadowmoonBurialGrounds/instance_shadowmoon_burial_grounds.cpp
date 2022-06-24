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

#include "shadowmoon_burial_grounds.h"

DoorData const doorData[] =
{
    {GO_SADANA_DOOR_ENTER,      DATA_SADANA,        DOOR_TYPE_ROOM,           BOUNDARY_NONE},
    {GO_SADANA_DOOR_EXIT,       DATA_SADANA,        DOOR_TYPE_PASSAGE,        BOUNDARY_NONE},
    {GO_NHALLISH_DOOR,          DATA_NHALLISH,      DOOR_TYPE_ROOM,           BOUNDARY_NONE},
    {GO_BONEMAW_DOOR_ENTER,     DATA_BONEMAW,       DOOR_TYPE_ROOM,           BOUNDARY_NONE},
    {GO_BONEMAW_DOOR_EXIT,      DATA_BONEMAW,       DOOR_TYPE_PASSAGE,        BOUNDARY_NONE},
};

class instance_shadowmoon_burial_grounds : public InstanceMapScript
{
public:
    instance_shadowmoon_burial_grounds() : InstanceMapScript("instance_shadowmoon_burial_grounds", 1176) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_shadowmoon_burial_grounds_InstanceMapScript(map);
    }

    struct instance_shadowmoon_burial_grounds_InstanceMapScript : public InstanceScript
    {
        instance_shadowmoon_burial_grounds_InstanceMapScript(Map* map) : InstanceScript(map) 
        {
            SetBossNumber(MAX_ENCOUNTER);
        }

        void Initialize()
        {
            LoadDoorData(doorData);
        }

        bool SetBossState(uint32 type, EncounterState state)
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;
            
            return true;
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_SADANA_DOOR_ENTER:
                case GO_SADANA_DOOR_EXIT:
                case GO_NHALLISH_DOOR:
                case GO_BONEMAW_DOOR_ENTER:
                case GO_BONEMAW_DOOR_EXIT:
                    AddDoor(go, true);
                    break;
                default:
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature)
        {
            /* switch (creature->GetEntry())
            {
                case :    
                    break;
            } */
        }

        void SetData(uint32 type, uint32 data)
        {
            /*switch (type)
            {
                default:
                    break;
            }*/
        }

        ObjectGuid GetGuidData(uint32 type) const
        {
            /* switch (type)
            {
                case :   
                    return ;
            } */
            return ObjectGuid::Empty;
        }

        uint32 GetData(uint32 type) const
        {
            return 0;
        }

        /* void Update(uint32 diff) 
        {
            // Challenge
            InstanceScript::Update(diff);
        } */
    };
};

void AddSC_instance_shadowmoon_burial_grounds()
{
    new instance_shadowmoon_burial_grounds();
}