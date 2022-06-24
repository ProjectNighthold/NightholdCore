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
#include "ScriptedCreature.h"
#include "scarlet_halls.h"

DoorData const doorData[] =
{
    {GO_BRAUN_DOOR,       DATA_BRAUN,         DOOR_TYPE_PASSAGE,    BOUNDARY_NONE},
    {GO_HARLAN_DOOR,      DATA_HARLAN,        DOOR_TYPE_ROOM,       BOUNDARY_NONE},
    {0,                   0,                  DOOR_TYPE_ROOM,       BOUNDARY_NONE}, // END
};

class instance_scarlet_halls : public InstanceMapScript
{
public:
    instance_scarlet_halls() : InstanceMapScript("instance_scarlet_halls", 1001) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_scarlet_halls_InstanceMapScript(map);
    }

    struct instance_scarlet_halls_InstanceMapScript : public InstanceScript
    {
        instance_scarlet_halls_InstanceMapScript(Map* map) : InstanceScript(map) 
        {
            SetBossNumber(MAX_ENCOUNTER);
        }

        ObjectGuid BraunGUID;
        ObjectGuid HarlanGUID;
        ObjectGuid KoeglerGUID;

        void Initialize()
        {
            LoadDoorData(doorData);
            BraunGUID.Clear();
            HarlanGUID.Clear();
            KoeglerGUID.Clear();
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
                case GO_HARLAN_DOOR:
                case GO_BRAUN_DOOR:
                    AddDoor(go, true);
                    break;
                default:
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_HOUNDMASTER_BRAUN:    
                    BraunGUID = creature->GetGUID(); 
                    break;
                case NPC_ARMSMASTER_HARLAN:        
                    HarlanGUID = creature->GetGUID(); 
                    break;
                case NPC_FLAMEWEAVER_KOEGLER:     
                    KoeglerGUID = creature->GetGUID();
                    break;
            }
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
            switch (type)
            {
                case NPC_HOUNDMASTER_BRAUN:   
                    return BraunGUID;
                case NPC_ARMSMASTER_HARLAN:              
                    return HarlanGUID;
                case NPC_FLAMEWEAVER_KOEGLER:                  
                    return KoeglerGUID;
            }
            return ObjectGuid::Empty;
        }

        uint32 GetData(uint32 type) const override
        {
            return 0;
        }

        void Update(uint32 diff) 
        {
            // Challenge
            InstanceScript::Update(diff);
        }
    };
};

void AddSC_instance_scarlet_halls()
{
    new instance_scarlet_halls();
}