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
#include "fall_of_shan_bu.h"

class instance_fall_of_shan_bu : public InstanceMapScript
{
public:
    instance_fall_of_shan_bu() : InstanceMapScript("instance_fall_of_shan_bu", 1126) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_fall_of_shan_bu_InstanceMapScript(map);
    }

    struct instance_fall_of_shan_bu_InstanceMapScript : public InstanceScript
    {
        instance_fall_of_shan_bu_InstanceMapScript(Map* map) : InstanceScript(map)
        { }

        void Initialize() override
        {
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case 1:
                    break;
                default:
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case 1:
                    return 0;
                default:
                    break;
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case 1:
                    return ObjectGuid::Empty;
                default:
                    break;
            }
            return ObjectGuid::Empty;
        }
    };
};

void AddSC_instance_fall_of_shan_bu()
{
    new instance_fall_of_shan_bu();
}
