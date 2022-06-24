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
#include "gnomeregan.h"

#define    MAX_ENCOUNTER  1

class instance_gnomeregan : public InstanceMapScript
{
public:
    instance_gnomeregan() : InstanceMapScript("instance_gnomeregan", 90) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_gnomeregan_InstanceMapScript(map);
    }

    struct instance_gnomeregan_InstanceMapScript : public InstanceScript
    {
        instance_gnomeregan_InstanceMapScript(Map* map) : InstanceScript(map)
        {
        }

        uint32 m_auiEncounter[MAX_ENCOUNTER];

        ObjectGuid uiCaveInLeftGUID;
        ObjectGuid uiCaveInRightGUID;

        ObjectGuid uiBastmasterEmiShortfuseGUID;

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            uiCaveInLeftGUID.Clear();
            uiCaveInRightGUID.Clear();

            uiBastmasterEmiShortfuseGUID.Clear();
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            std::istringstream loadStream(in);
            loadStream >> m_auiEncounter[0];

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            {
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;
            }

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_BLASTMASTER_EMI_SHORTFUSE: uiBastmasterEmiShortfuseGUID = creature->GetGUID(); break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_CAVE_IN_LEFT:
                    uiCaveInLeftGUID = go->GetGUID();
                    if (m_auiEncounter[0] == DONE || m_auiEncounter[0] == NOT_STARTED)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_CAVE_IN_RIGHT:
                    uiCaveInRightGUID = go->GetGUID();
                    if (m_auiEncounter[0] == DONE || m_auiEncounter[0] == NOT_STARTED)
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
            }
        }

        void SetData(uint32 uiType, uint32 uiData)
        {
            switch (uiType)
            {
                case TYPE_EVENT:
                    m_auiEncounter[0] = uiData;
                    if (uiData == DONE)
                        SaveToDB();
                    break;
            }
        }

        uint32 GetData(uint32 uiType) const
        {
            switch (uiType)
            {
                case TYPE_EVENT:
                    return m_auiEncounter[0];
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 uiType) const
        {
            switch (uiType)
            {
                case DATA_GO_CAVE_IN_LEFT:              return uiCaveInLeftGUID;
                case DATA_GO_CAVE_IN_RIGHT:             return uiCaveInRightGUID;
                case DATA_NPC_BASTMASTER_EMI_SHORTFUSE: return uiBastmasterEmiShortfuseGUID;
            }

            return ObjectGuid::Empty;
        }
    };

};

void AddSC_instance_gnomeregan()
{
    new instance_gnomeregan();
}
