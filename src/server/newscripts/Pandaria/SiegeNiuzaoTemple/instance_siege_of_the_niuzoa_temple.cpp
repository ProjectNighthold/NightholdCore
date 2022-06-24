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

#include "siege_of_the_niuzoa_temple.h"

class instance_siege_of_the_niuzoa_temple : public InstanceMapScript
{
public:
    instance_siege_of_the_niuzoa_temple() : InstanceMapScript("instance_siege_of_the_niuzoa_temple", 1011) {}

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_siege_of_the_niuzoa_temple_InstanceMapScript(map);
    }

    struct instance_siege_of_the_niuzoa_temple_InstanceMapScript : public InstanceScript
    {
        ObjectGuid jinbakGuid;
        ObjectGuid vojakGuid;
        ObjectGuid pavalakGuid;
        ObjectGuid neronokGuid;

        instance_siege_of_the_niuzoa_temple_InstanceMapScript(Map* map) : InstanceScript(map) {}

        void Initialize() override
        {
            jinbakGuid.Clear();
            vojakGuid.Clear();
            pavalakGuid.Clear();
            neronokGuid.Clear();
        }
        
        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_JINBAK:
                    jinbakGuid = creature->GetGUID();
                    break;
                case NPC_VOJAK:
                    vojakGuid = creature->GetGUID();
                    break;
                case NPC_PAVALAK:
                    pavalakGuid = creature->GetGUID();
                    break;
                case NPC_NERONOK:
                    neronokGuid = creature->GetGUID();
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case NPC_JINBAK:    return jinbakGuid;
                case NPC_VOJAK:     return vojakGuid;
                case NPC_PAVALAK:   return pavalakGuid;
                case NPC_NERONOK:   return neronokGuid;
            }

            return ObjectGuid::Empty;
        }

        void Update(uint32 diff) override
        {
            // Challenge
            InstanceScript::Update(diff);
        }
    };

};

void AddSC_instance_siege_of_the_niuzoa_temple()
{
    new instance_siege_of_the_niuzoa_temple();
}
