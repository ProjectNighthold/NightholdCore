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
SDName: Instance_Utgarde_Keep
SD%Complete: 90
SDComment: Instance Data Scripts and functions to acquire mobs and set encounter status for use in various Utgarde Keep Scripts
SDCategory: Utgarde Keep
EndScriptData */

#include "utgarde_keep.h"

#define MAX_ENCOUNTER     3

#define ENTRY_BELLOW_1          186688
#define ENTRY_BELLOW_2          186689
#define ENTRY_BELLOW_3          186690

#define ENTRY_FORGEFIRE_1       186692
#define ENTRY_FORGEFIRE_2       186693
#define ENTRY_FORGEFIRE_3       186691

#define ENTRY_GLOWING_ANVIL_1   186609
#define ENTRY_GLOWING_ANVIL_2   186610
#define ENTRY_GLOWING_ANVIL_3   186611

#define ENTRY_GIANT_PORTCULLIS_1    186756
#define ENTRY_GIANT_PORTCULLIS_2    186694

/* Utgarde Keep encounters:
0 - Prince Keleseth
1 - Skarvald Dalronn
2 - Ingvar the Plunderer
*/

class instance_utgarde_keep : public InstanceMapScript
{
public:
    instance_utgarde_keep() : InstanceMapScript("instance_utgarde_keep", 574) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
       return new instance_utgarde_keep_InstanceMapScript(map);
    }

    struct instance_utgarde_keep_InstanceMapScript : public InstanceScript
    {
        instance_utgarde_keep_InstanceMapScript(Map* map) : InstanceScript(map) {}

        ObjectGuid Keleseth;
        ObjectGuid Skarvald;
        ObjectGuid Dalronn;
        ObjectGuid Ingvar;

        ObjectGuid forge_bellow[3];
        ObjectGuid forge_fire[3];
        ObjectGuid forge_anvil[3];
        ObjectGuid portcullis[2];

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        uint32 forge_event[3];
        std::string str_data;

       void Initialize() override
       {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            Keleseth.Clear();
            Skarvald.Clear();
            Dalronn.Clear();
            Ingvar.Clear();

            for (uint8 i = 0; i < 3; ++i)
            {
                forge_bellow[i].Clear();
                forge_fire[i].Clear();
                forge_anvil[i].Clear();
                forge_event[i] = NOT_STARTED;
            }

            portcullis[0].Clear();
            portcullis[1].Clear();
        }

        bool IsEncounterInProgress() const override
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        Player* GetPlayerInMap()
        {
            Map::PlayerList const& players = instance->GetPlayers();

            if (!players.isEmpty())
            {
                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                {
                    if (Player* player = itr->getSource())
                    return player;
                }
            }

            TC_LOG_DEBUG(LOG_FILTER_TSCR, "Instance Utgarde Keep: GetPlayerInMap, but PlayerList is empty!");
            return NULL;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case 23953:    Keleseth = creature->GetGUID();             break;
                case 24201:    Dalronn = creature->GetGUID();              break;
                case 24200:    Skarvald = creature->GetGUID();             break;
                case 23954:    Ingvar = creature->GetGUID();               break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            //door and object id
            case ENTRY_BELLOW_1: forge_bellow[0] = go->GetGUID();
            if (forge_event[0] != NOT_STARTED)HandleGameObject(ObjectGuid::Empty, true, go);break;
            case ENTRY_BELLOW_2: forge_bellow[1] = go->GetGUID();
            if (forge_event[1] != NOT_STARTED)HandleGameObject(ObjectGuid::Empty, true, go);break;
            case ENTRY_BELLOW_3: forge_bellow[2] = go->GetGUID();
            if (forge_event[2] != NOT_STARTED)HandleGameObject(ObjectGuid::Empty, true, go);break;
            case ENTRY_FORGEFIRE_1: forge_fire[0] = go->GetGUID();
            if (forge_event[0] != NOT_STARTED)HandleGameObject(ObjectGuid::Empty, true, go);break;
            case ENTRY_FORGEFIRE_2: forge_fire[1] = go->GetGUID();
            if (forge_event[1] != NOT_STARTED)HandleGameObject(ObjectGuid::Empty, true, go);break;
            case ENTRY_FORGEFIRE_3: forge_fire[2] = go->GetGUID();
            if (forge_event[2] != NOT_STARTED)HandleGameObject(ObjectGuid::Empty, true, go);break;
            case ENTRY_GLOWING_ANVIL_1: forge_anvil[0] = go->GetGUID();
            if (forge_event[0] != NOT_STARTED)HandleGameObject(ObjectGuid::Empty, true, go);break;
            case ENTRY_GLOWING_ANVIL_2: forge_anvil[1] = go->GetGUID();
            if (forge_event[1] != NOT_STARTED)HandleGameObject(ObjectGuid::Empty, true, go);break;
            case ENTRY_GLOWING_ANVIL_3: forge_anvil[2] = go->GetGUID();
            if (forge_event[2] != NOT_STARTED)HandleGameObject(ObjectGuid::Empty, true, go);break;
            case ENTRY_GIANT_PORTCULLIS_1: portcullis[0] = go->GetGUID();
            if (m_auiEncounter[2] == DONE)HandleGameObject(ObjectGuid::Empty, true, go);break;
            case ENTRY_GIANT_PORTCULLIS_2: portcullis[1] = go->GetGUID();
            if (m_auiEncounter[2] == DONE)HandleGameObject(ObjectGuid::Empty, true, go);break;
            }
        }

        ObjectGuid GetGuidData(uint32 identifier) const override
        {
            switch (identifier)
            {
                case DATA_PRINCEKELESETH:         return Keleseth;
                case DATA_DALRONN:                return Dalronn;
                case DATA_SKARVALD:               return Skarvald;
                case DATA_INGVAR:                 return Ingvar;
            }

            return ObjectGuid::Empty;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
            case DATA_PRINCEKELESETH_EVENT:
                m_auiEncounter[0] = data;
                break;
            case DATA_SKARVALD_DALRONN_EVENT:
                m_auiEncounter[1] = data;
                break;
            case DATA_INGVAR_EVENT:
                if (data == DONE)
                {
                    HandleGameObject(portcullis[0], true);
                    HandleGameObject(portcullis[1], true);
                }
                m_auiEncounter[2] = data;
                break;
            case EVENT_FORGE_1:
                if (data == NOT_STARTED)
                {
                    HandleGameObject(forge_bellow[0], false);
                    HandleGameObject(forge_fire[0], false);
                    HandleGameObject(forge_anvil[0], false);
                }else
                {
                    HandleGameObject(forge_bellow[0], true);
                    HandleGameObject(forge_fire[0], true);
                    HandleGameObject(forge_anvil[0], true);
                }
                forge_event[0] = data;
                break;
            case EVENT_FORGE_2:
                if (data == NOT_STARTED)
                {
                    HandleGameObject(forge_bellow[1], false);
                    HandleGameObject(forge_fire[1], false);
                    HandleGameObject(forge_anvil[1], false);
                }else
                {
                    HandleGameObject(forge_bellow[1], true);
                    HandleGameObject(forge_fire[1], true);
                    HandleGameObject(forge_anvil[1], true);
                }
                forge_event[1] = data;
                break;
            case EVENT_FORGE_3:
                if (data == NOT_STARTED)
                {
                    HandleGameObject(forge_bellow[2], false);
                    HandleGameObject(forge_fire[2], false);
                    HandleGameObject(forge_anvil[2], false);
                }else
                {
                    HandleGameObject(forge_bellow[2], true);
                    HandleGameObject(forge_fire[2], true);
                    HandleGameObject(forge_anvil[2], true);
                }
                forge_event[2] = data;
                break;
            }

            if (data == DONE)
            {
                SaveToDB();
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_PRINCEKELESETH_EVENT:     return m_auiEncounter[0];
                case DATA_SKARVALD_DALRONN_EVENT:   return m_auiEncounter[1];
                case DATA_INGVAR_EVENT:             return m_auiEncounter[2];
            }

            return 0;
        }

        std::string GetSaveData() override
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "U K " << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' '
                << m_auiEncounter[2] << ' ' << forge_event[0] << ' ' << forge_event[1] << ' ' << forge_event[2];

            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
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
            uint16 data0, data1, data2, data3, data4, data5;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4 >> data5;

            if (dataHead1 == 'U' && dataHead2 == 'K')
            {
                m_auiEncounter[0] = data0;
                m_auiEncounter[1] = data1;
                m_auiEncounter[2] = data2;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;

                forge_event[0] = data3;
                forge_event[1] = data4;
                forge_event[2] = data5;

            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};

void AddSC_instance_utgarde_keep()
{
    new instance_utgarde_keep();
}
