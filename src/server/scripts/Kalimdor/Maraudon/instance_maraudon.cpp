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

/*
This placeholder for the instance is needed for dungeon finding to be able
to give credit after the boss defined in lastEncounterDungeon is killed.
Without it, the party doing random dungeon won't get satchel of spoils and
gets instead the deserter debuff.
*/

#include "ScriptMgr.h"
#include "InstanceScript.h"

class instance_maraudon : public InstanceMapScript
{
public:
    instance_maraudon() : InstanceMapScript("instance_maraudon", 349) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_maraudon_InstanceMapScript(map);
    }

    struct instance_maraudon_InstanceMapScript : public InstanceScript
    {
        instance_maraudon_InstanceMapScript(Map* map) : InstanceScript(map) { }
    };
};

void AddSC_instance_maraudon()
{
    new instance_maraudon();
}
