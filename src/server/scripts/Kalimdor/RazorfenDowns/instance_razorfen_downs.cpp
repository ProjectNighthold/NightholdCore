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
#include "razorfen_downs.h"

#define    MAX_ENCOUNTER  1

class instance_razorfen_downs : public InstanceMapScript
{
public:
    instance_razorfen_downs() : InstanceMapScript("instance_razorfen_downs", 129) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_razorfen_downs_InstanceMapScript(map);
    }

    struct instance_razorfen_downs_InstanceMapScript : public InstanceScript
    {
        instance_razorfen_downs_InstanceMapScript(Map* map) : InstanceScript(map)
        {
        }

        ObjectGuid uiGongGUID;

        uint32 m_auiEncounter[MAX_ENCOUNTER];

        uint16 uiGongWaves;

        std::string str_data;

        void Initialize()
        {
            uiGongGUID.Clear();

            uiGongWaves = 0;

            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;

            saveStream << "T C " << m_auiEncounter[0]
                << ' ' << uiGongWaves;

            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;
            uint16 data0, data1;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1;

            if (dataHead1 == 'T' && dataHead2 == 'C')
            {
                m_auiEncounter[0] = data0;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;

                uiGongWaves = data1;
            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_GONG:
                    uiGongGUID = go->GetGUID();
                    if (m_auiEncounter[0] == DONE)
                        go->SetFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    break;
                default:
                    break;
            }
        }

        void SetData(uint32 uiType, uint32 uiData)
        {
            if (uiType == DATA_GONG_WAVES)
            {
                uiGongWaves = uiData;

                switch (uiGongWaves)
                {
                    case 9:
                    case 14:
                        if (GameObject* go = instance->GetGameObject(uiGongGUID))
                            go->RemoveFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case 1:
                    case 10:
                    case 16:
                    {
                        GameObject* go = instance->GetGameObject(uiGongGUID);

                        if (!go)
                            return;

                        go->SetFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);

                        uint32 uiCreature = 0;
                        uint8 uiSummonTimes = 0;

                        switch (uiGongWaves)
                        {
                            case 1:
                                uiCreature = CREATURE_TOMB_FIEND;
                                uiSummonTimes = 7;
                                break;
                            case 10:
                                uiCreature = CREATURE_TOMB_REAVER;
                                uiSummonTimes = 3;
                                break;
                            case 16:
                                uiCreature = CREATURE_TUTEN_KASH;
                                break;
                            default:
                                break;
                        }

                        if (Creature* creature = go->SummonCreature(uiCreature, 2502.635f, 844.140f, 46.896f, 0.633f))
                        {
                            if (uiGongWaves == 10 || uiGongWaves == 1)
                            {
                                for (uint8 i = 0; i < uiSummonTimes; ++i)
                                {
                                    if (Creature* summon = go->SummonCreature(uiCreature, 2502.635f + float(irand(-5, 5)), 844.140f + float(irand(-5, 5)), 46.896f, 0.633f))
                                        summon->GetMotionMaster()->MovePoint(0, 2533.479f + float(irand(-5, 5)), 870.020f + float(irand(-5, 5)), 47.678f);
                                }
                            }
                            creature->GetMotionMaster()->MovePoint(0, 2533.479f + float(irand(-5, 5)), 870.020f + float(irand(-5, 5)), 47.678f);
                        }
                        break;
                    }
                    default:
                        break;
                }
            }

            if (uiType == BOSS_TUTEN_KASH)
            {
                m_auiEncounter[0] = uiData;

                if (uiData == DONE)
                    SaveToDB();
            }
        }

        uint32 GetData(uint32 uiType) const
        {
            switch (uiType)
            {
                case DATA_GONG_WAVES:
                    return uiGongWaves;
            }

            return 0;
        }

        ObjectGuid GetGuidData(uint32 uiType) const
        {
            switch (uiType)
            {
                case DATA_GONG: return uiGongGUID;
            }

            return ObjectGuid::Empty;
        }
    };

};

void AddSC_instance_razorfen_downs()
{
    new instance_razorfen_downs();
}
