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
#include "arena_of_annihilation.h"

class instance_arena_of_annihilation : public InstanceMapScript
{
public:
    instance_arena_of_annihilation() : InstanceMapScript("instance_arena_of_annihilation", 1031) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_arena_of_annihilation_InstanceMapScript(map);
    }

    struct instance_arena_of_annihilation_InstanceMapScript : public InstanceScript
    {
        instance_arena_of_annihilation_InstanceMapScript(Map* map) : InstanceScript(map) 
        {
            SetBossNumber(MAX_ENCOUNTER);
        }

        uint32 encounter[MAX_ENCOUNTER];
        ObjectGuid scarshellGUID;
        ObjectGuid jolgrumGUID;
        ObjectGuid liuyangGUID;
        ObjectGuid chaganGUID;
        ObjectGuid finalbossGUID;
        ObjectGuid go_doors;
        ObjectGuid gurgthockGUID;
        uint8 startevent;
        uint8 finaldata;

        void Initialize() override
        {
            memset(&encounter, 0, sizeof(encounter));
            startevent = 0;
            gurgthockGUID.Clear();
            scarshellGUID.Clear();
            jolgrumGUID.Clear();
            liuyangGUID.Clear();
            chaganGUID.Clear();
            finalbossGUID.Clear();
            finaldata = 0;
            go_doors.Clear();
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case DATA_SCAR_SHELL:
                {
                    switch (state)
                    {
                        case IN_PROGRESS:
                            if (Creature* gurgthock = instance->GetCreature(GetGuidData(NPC_GURGTHOCK)))
                                gurgthock->AI()->Talk(SAY_SCAR_SHELL_START);
                            break;
                        case DONE:
                            if (Creature* gurgthock = instance->GetCreature(GetGuidData(NPC_GURGTHOCK)))
                                gurgthock->AI()->Talk(SAY_SCAR_SHELL_END);
                            break;
                    }
                    break;
                }
                case DATA_JOLGRUM:
                {
                    switch (state)
                    {
                        case IN_PROGRESS:
                            if (Creature* gurgthock = instance->GetCreature(GetGuidData(NPC_GURGTHOCK)))
                                gurgthock->AI()->Talk(SAY_JOLGRUM_START);
                            break;
                        case DONE:
                            if (Creature* gurgthock = instance->GetCreature(GetGuidData(NPC_GURGTHOCK)))
                                gurgthock->AI()->Talk(SAY_JOLGRUM_END);
                            break;
                    }
                    break;
                }
                case DATA_LIUYANG:
                {
                    switch (state)
                    {
                        case IN_PROGRESS:
                            if (Creature* gurgthock = instance->GetCreature(GetGuidData(NPC_GURGTHOCK)))
                                gurgthock->AI()->Talk(SAY_LIUYANG_START);
                            break;
                        case DONE:
                            if (Creature* gurgthock = instance->GetCreature(GetGuidData(NPC_GURGTHOCK)))
                                gurgthock->AI()->Talk(SAY_LIUYANG_END);
                            break;
                    }
                    break;
                }
                case DATA_CHAGAN:
                {
                    switch (state)
                    {
                        case IN_PROGRESS:
                            if (Creature* gurgthock = instance->GetCreature(GetGuidData(NPC_GURGTHOCK)))
                                gurgthock->AI()->Talk(SAY_CHAGAN_START);
                            break;
                        case DONE:
                            if (Creature* gurgthock = instance->GetCreature(GetGuidData(NPC_GURGTHOCK)))
                                gurgthock->AI()->Talk(SAY_CHAGAN_END);
                            break;
                    }
                    break;
                }
                case DATA_FINAL_STAGE:
                    if (state == DONE)
                        if (Creature* gurgthock = instance->GetCreature(GetGuidData(NPC_GURGTHOCK)))
                            gurgthock->AI()->DoAction(ACTION_2);
                    break;
            }
            return true;
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_INNER_DOORS:
                    go_doors = go->GetGUID();
                    break;
                default:
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_SCAR_SHELL:
                    scarshellGUID = creature->GetGUID();
                    break;
                case NPC_JOLGRUM:
                    jolgrumGUID = creature->GetGUID();
                    break;
                case NPC_LIUYANG:
                    liuyangGUID = creature->GetGUID();
                    break;
                case NPC_FIREHOOF:
                    chaganGUID = creature->GetGUID();
                    break;
                case NPC_GURGTHOCK:
                    gurgthockGUID = creature->GetGUID();
                    break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch(type)
            {
                case DATA_START_EVENT:
                    startevent = data;
                    break;
                case DATA_SATAY:
                case DATA_KOBO:
                case DATA_MAKI:
                    finaldata = data;
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_DOOR:
                    return go_doors;
                case NPC_GURGTHOCK:
                    return gurgthockGUID;
                case DATA_SCAR_SHELL:
                    return scarshellGUID;
                case DATA_JOLGRUM:
                    return jolgrumGUID;
                case DATA_LIUYANG:
                    return liuyangGUID;
                case DATA_CHAGAN:
                    return chaganGUID;
                case DATA_FINAL_STAGE:
                    return finalbossGUID;
            }
            return ObjectGuid::Empty;
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_SATAY:
                case DATA_KOBO:
                case DATA_MAKI:
                    return finaldata;
                case DATA_START_EVENT:
                    return startevent;
            }
            return 0;
        }
    };
};

void AddSC_instance_arena_of_annihilation()
{
    new instance_arena_of_annihilation();
}