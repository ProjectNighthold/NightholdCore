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

/* ScriptData
SDName: Instance_Halls_of_Lightning
SD%Complete: 90%
SDComment: All ready.
SDCategory: Halls of Lightning
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "halls_of_lightning.h"

/* Halls of Lightning encounters:
0 - General Bjarngrim
1 - Volkhan
2 - Ionar
3 - Loken
*/

class instance_halls_of_lightning : public InstanceMapScript
{
public:
    instance_halls_of_lightning() : InstanceMapScript("instance_halls_of_lightning", 602) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_halls_of_lightning_InstanceMapScript(map);
    }

    struct instance_halls_of_lightning_InstanceMapScript : public InstanceScript
    {
        instance_halls_of_lightning_InstanceMapScript(Map* map) : InstanceScript(map) {}

        uint32 m_auiEncounter[MAX_ENCOUNTER];

        ObjectGuid m_uiGeneralBjarngrimGUID;
        ObjectGuid m_uiIonarGUID;
        ObjectGuid m_uiLokenGUID;
        ObjectGuid m_uiVolkhanGUID;

        ObjectGuid m_uiBjarngrimDoorGUID;
        ObjectGuid m_uiVolkhanDoorGUID;
        ObjectGuid m_uiIonarDoorGUID;
        ObjectGuid m_uiLokenDoorGUID;
        ObjectGuid m_uiLokenGlobeGUID;

        void Initialize() override
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            m_uiGeneralBjarngrimGUID.Clear();
            m_uiVolkhanGUID.Clear();
            m_uiIonarGUID.Clear();
            m_uiLokenGUID.Clear();

            m_uiBjarngrimDoorGUID.Clear();
            m_uiVolkhanDoorGUID.Clear();
            m_uiIonarDoorGUID.Clear();
            m_uiLokenDoorGUID.Clear();
            m_uiLokenGlobeGUID.Clear();
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_BJARNGRIM:
                    m_uiGeneralBjarngrimGUID = creature->GetGUID();
                    break;
                case NPC_VOLKHAN:
                    m_uiVolkhanGUID = creature->GetGUID();
                    break;
                case NPC_IONAR:
                    m_uiIonarGUID = creature->GetGUID();
                    break;
                case NPC_LOKEN:
                    m_uiLokenGUID = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_BJARNGRIM_DOOR:
                    m_uiBjarngrimDoorGUID = go->GetGUID();
                    if (m_auiEncounter[0] == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    else
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_VOLKHAN_DOOR:
                    m_uiVolkhanDoorGUID = go->GetGUID();
                    if (m_auiEncounter[1] == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    else
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_IONAR_DOOR:
                    m_uiIonarDoorGUID = go->GetGUID();
                    if (m_auiEncounter[2] == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    else
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_LOKEN_DOOR:
                    m_uiLokenDoorGUID = go->GetGUID();
                    if (m_auiEncounter[3] == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    else
                        go->SetGoState(GO_STATE_READY);
                    break;
                case GO_LOKEN_THRONE:
                    m_uiLokenGlobeGUID = go->GetGUID();
                    break;
            }
        }

        void SetData(uint32 uiType, uint32 uiData) override
        {
            switch (uiType)
            {
                case TYPE_BJARNGRIM:
                    if (uiData == DONE)
                        if (GameObject* pDoor = instance->GetGameObject(m_uiBjarngrimDoorGUID))
                            pDoor->SetGoState(GO_STATE_ACTIVE);
                    m_auiEncounter[0] = uiData;
                    break;
                case TYPE_VOLKHAN:
                    if (uiData == DONE)
                        if (GameObject* pDoor = instance->GetGameObject(m_uiVolkhanDoorGUID))
                            pDoor->SetGoState(GO_STATE_ACTIVE);
                    m_auiEncounter[1] = uiData;
                    break;
                case TYPE_IONAR:
                    if (uiData == DONE)
                        if (GameObject* pDoor = instance->GetGameObject(m_uiIonarDoorGUID))
                            pDoor->SetGoState(GO_STATE_ACTIVE);
                    m_auiEncounter[2] = uiData;
                    break;
                case TYPE_LOKEN:
                    if (uiData == DONE)
                    {
                        if (GameObject* pDoor = instance->GetGameObject(m_uiLokenDoorGUID))
                            pDoor->SetGoState(GO_STATE_ACTIVE);

                        // Appears to be type 5 GO with animation. Need to figure out how this work, code below only placeholder
                        if (GameObject* pGlobe = instance->GetGameObject(m_uiLokenGlobeGUID))
                            pGlobe->SetGoState(GO_STATE_ACTIVE);
                    }
                    m_auiEncounter[3] = uiData;
                    break;
            }

            if (uiData == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 uiType) const override
        {
            switch (uiType)
            {
                case TYPE_BJARNGRIM:
                    return m_auiEncounter[0];
                case TYPE_VOLKHAN:
                    return m_auiEncounter[1];
                case TYPE_IONAR:
                    return m_auiEncounter[2];
                case TYPE_LOKEN:
                    return m_auiEncounter[3];
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 uiData) const override
        {
            switch (uiData)
            {
                case DATA_BJARNGRIM:
                    return m_uiGeneralBjarngrimGUID;
                case DATA_VOLKHAN:
                    return m_uiVolkhanGUID;
                case DATA_IONAR:
                    return m_uiIonarGUID;
                case DATA_LOKEN:
                    return m_uiLokenGUID;
            }
            return ObjectGuid::Empty;
        }

        std::string GetSaveData() override
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "H L " << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' '
            << m_auiEncounter[2] << ' ' << m_auiEncounter[3];

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(const char* in) override
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;
            uint16 data0, data1, data2, data3;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3;

            if (dataHead1 == 'H' && dataHead2 == 'L')
            {
                m_auiEncounter[0] = data0;
                m_auiEncounter[1] = data1;
                m_auiEncounter[2] = data2;
                m_auiEncounter[3] = data3;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;
            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};

void AddSC_instance_halls_of_lightning()
{
    new instance_halls_of_lightning();
}
