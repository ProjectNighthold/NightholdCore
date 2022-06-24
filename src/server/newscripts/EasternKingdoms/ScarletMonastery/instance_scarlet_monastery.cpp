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

#include "scarlet_monastery.h"

DoorData const doorData[] =
{
    {GO_THALNOS_DOOR,     DATA_THALNOS,       DOOR_TYPE_PASSAGE,    BOUNDARY_NONE},
    {GO_KORLOFF_DOOR,     DATA_KORLOFF,       DOOR_TYPE_PASSAGE,    BOUNDARY_NONE},
    {GO_WHITEMANE_DOOR,   DATA_WHITEMANE,     DOOR_TYPE_SPAWN_HOLE, BOUNDARY_NONE},
    {0,                   0,                  DOOR_TYPE_ROOM,       BOUNDARY_NONE}, // END
};

class instance_scarlet_monastery : public InstanceMapScript
{
public:
    instance_scarlet_monastery() : InstanceMapScript("instance_scarlet_monastery", 1004) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_scarlet_monastery_InstanceMapScript(map);
    }

    struct instance_scarlet_monastery_InstanceMapScript : public InstanceScript
    {
        instance_scarlet_monastery_InstanceMapScript(Map* map) : InstanceScript(map) 
        {
            SetBossNumber(MAX_ENCOUNTER);
        }

        ObjectGuid PumpkinShrineGUID;
        ObjectGuid HorsemanGUID;
        ObjectGuid HeadGUID;
        ObjectGuid thalnosGUID;
        GuidSet HorsemanAdds;
        ObjectGuid durandGUID;
        ObjectGuid whitemaneGUID;
        ObjectGuid zombieGUID;

        uint32 encounter[MAX_ENCOUNTER];

        void Initialize()
        {
            LoadDoorData(doorData);
            memset(&encounter, 0, sizeof(encounter));

            PumpkinShrineGUID.Clear();
            HorsemanGUID.Clear();
            HeadGUID.Clear();
            thalnosGUID.Clear();
            durandGUID.Clear();
            whitemaneGUID.Clear();
            HorsemanAdds.clear();
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
                case GO_PUMPKIN_SHRINE: 
                    PumpkinShrineGUID = go->GetGUID();
                    break;
                case GO_THALNOS_DOOR:
                case GO_KORLOFF_DOOR:
                case GO_WHITEMANE_DOOR:
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
                case NPC_HORSEMAN:
                    HorsemanGUID = creature->GetGUID();
                    break;
                case NPC_HEAD:
                    HeadGUID = creature->GetGUID();
                    break;
                case NPC_PUMPKIN:
                    HorsemanAdds.insert(creature->GetGUID());
                    break;
                case NPC_THALNOS:
                    thalnosGUID = creature->GetGUID();
                    break;
                case NPC_DURAND:
                    durandGUID = creature->GetGUID();
                    break;
                case NPC_WHITEMANE:
                    whitemaneGUID = creature->GetGUID();
                    break;
                case NPC_EMPOWERED_ZOMBIE:
                    zombieGUID = creature->GetGUID();
                    break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
            case GO_PUMPKIN_SHRINE:
                HandleGameObject(PumpkinShrineGUID, false);
                break;
            case DATA_HORSEMAN_EVENT:
                encounter[0] = data;
                if (data == DONE)
                {
                    for (GuidSet::const_iterator itr = HorsemanAdds.begin(); itr != HorsemanAdds.end(); ++itr)
                    {
                        Creature* add = instance->GetCreature(*itr);
                        if (add && add->isAlive())
                            add->Kill(add);
                    }
                    HorsemanAdds.clear();
                    HandleGameObject(PumpkinShrineGUID, false);
                }
                break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const
        {
            switch (type)
            {
                case GO_PUMPKIN_SHRINE:
                    return PumpkinShrineGUID;
                case NPC_HORSEMAN:
                    return HorsemanGUID;
                case NPC_HEAD:
                    return HeadGUID;
                case NPC_EMPOWERED_ZOMBIE:
                    return zombieGUID;
                case DATA_THALNOS:
                    return thalnosGUID;
                case DATA_DURAND:
                    return durandGUID;
                case DATA_WHITEMANE:
                    return whitemaneGUID;
            }
            return ObjectGuid::Empty;
        }

        uint32 GetData(uint32 type) const override
        {
            if (type == DATA_HORSEMAN_EVENT)
                return encounter[0];
            return 0;
        }

        void Update(uint32 diff) 
        {
            // Challenge
            InstanceScript::Update(diff);
        }
    };
};

void AddSC_instance_scarlet_monastery()
{
    new instance_scarlet_monastery();
}