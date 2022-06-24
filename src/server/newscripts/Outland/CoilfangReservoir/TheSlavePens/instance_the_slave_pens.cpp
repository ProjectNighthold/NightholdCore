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
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "the_slave_pens.h"

class instance_the_slave_pens : public InstanceMapScript
{
public:
    instance_the_slave_pens() : InstanceMapScript("instance_the_slave_pens", 547) { }

    struct instance_the_slave_pens_InstanceMapScript : public InstanceScript
    {
        instance_the_slave_pens_InstanceMapScript(Map* map) : InstanceScript(map) 
        { 
            SetBossNumber(MAX_ENCOUNTER);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_AHUNE:
                AhuneGUID = creature->GetGUID();
                break;
            case NPC_LUMA:
                LumaGUID = creature->GetGUID();
                break;

            default:
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_AHUNE_ICE_STONE:
                goahuneicestoneGUID = go->GetGUID();
                break;
            default:
                break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case NPC_AHUNE:
                return AhuneGUID;
            case NPC_LUMA:
                return LumaGUID;
            case GO_AHUNE_ICE_STONE:
                return goahuneicestoneGUID;

            default:
                break;
            }
            return ObjectGuid::Empty;
        }

    protected:
        ObjectGuid AhuneGUID;
        ObjectGuid LumaGUID;
        ObjectGuid goahuneicestoneGUID;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_the_slave_pens_InstanceMapScript(map);
    }
};

void AddSC_instance_the_slave_pens()
{
    new instance_the_slave_pens();
}