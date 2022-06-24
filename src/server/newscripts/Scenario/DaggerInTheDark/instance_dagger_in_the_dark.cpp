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
#include "dagger_in_the_dark.h"

class instance_dagger_in_the_dark : public InstanceMapScript
{
public:
    instance_dagger_in_the_dark() : InstanceMapScript("instance_dagger_in_the_dark", 1095) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_dagger_in_the_dark_InstanceMapScript(map);
    }

    struct instance_dagger_in_the_dark_InstanceMapScript : public InstanceScript
    {
        instance_dagger_in_the_dark_InstanceMapScript(Map* map) : InstanceScript(map)
        { }

        void Initialize() override
        {
        }

        void OnPlayerEnter(Player* player) override
        {
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case 0:
                default:
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case 0:
                default:
                    return ObjectGuid::Empty;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case 0:
                default:
                    return 0;
            }
        }
    };
};

void AddSC_instance_dagger_in_the_dark()
{
    new instance_dagger_in_the_dark();
}
