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
SDName: Instance_Gruuls_Lair
SD%Complete: 100
SDComment:
SDCategory: Gruul's Lair
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "gruuls_lair.h"

#define MAX_ENCOUNTER 2

/* Gruuls Lair encounters:
1 - High King Maulgar event
2 - Gruul event
*/

class instance_gruuls_lair : public InstanceMapScript
{
public:
    instance_gruuls_lair() : InstanceMapScript("instance_gruuls_lair", 565) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_gruuls_lair_InstanceMapScript(map);
    }

    struct instance_gruuls_lair_InstanceMapScript : public InstanceScript
    {
        instance_gruuls_lair_InstanceMapScript(Map* map) : InstanceScript(map) {}

        uint32 m_auiEncounter[MAX_ENCOUNTER];

        ObjectGuid MaulgarEvent_Tank;
        ObjectGuid KigglerTheCrazed;
        ObjectGuid BlindeyeTheSeer;
        ObjectGuid OlmTheSummoner;
        ObjectGuid KroshFirehand;
        ObjectGuid Maulgar;

        ObjectGuid MaulgarDoor;
        ObjectGuid GruulDoor;

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            MaulgarEvent_Tank.Clear();
            KigglerTheCrazed.Clear();
            BlindeyeTheSeer.Clear();
            OlmTheSummoner.Clear();
            KroshFirehand.Clear();
            Maulgar.Clear();

            MaulgarDoor.Clear();
            GruulDoor.Clear();
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case 18835: KigglerTheCrazed = creature->GetGUID(); break;
                case 18836: BlindeyeTheSeer = creature->GetGUID();  break;
                case 18834: OlmTheSummoner = creature->GetGUID();   break;
                case 18832: KroshFirehand = creature->GetGUID();    break;
                case 18831: Maulgar = creature->GetGUID();          break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case 184468:
                    MaulgarDoor = go->GetGUID();
                    if (m_auiEncounter[0] == DONE)
                        HandleGameObject(ObjectGuid::Empty, true, go);
                    break;
                case 184662:
                    GruulDoor = go->GetGUID();
                    break;
            }
        }

        void SetGuidData(uint32 type, ObjectGuid data)
        {
            if (type == DATA_MAULGAREVENT_TANK)
                MaulgarEvent_Tank = data;
        }

        ObjectGuid GetGuidData(uint32 identifier) const
        {
            switch (identifier)
            {
                case DATA_MAULGAREVENT_TANK:    return MaulgarEvent_Tank;
                case DATA_KIGGLERTHECRAZED:     return KigglerTheCrazed;
                case DATA_BLINDEYETHESEER:      return BlindeyeTheSeer;
                case DATA_OLMTHESUMMONER:       return OlmTheSummoner;
                case DATA_KROSHFIREHAND:        return KroshFirehand;
                case DATA_MAULGARDOOR:          return MaulgarDoor;
                case DATA_GRUULDOOR:            return GruulDoor;
                case DATA_MAULGAR:              return Maulgar;
            }
            return ObjectGuid::Empty;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case DATA_MAULGAREVENT:
                    if (data == DONE)
                        HandleGameObject(MaulgarDoor, true);
                    m_auiEncounter[0] = data;
                    break;

                case DATA_GRUULEVENT:
                    if (data == IN_PROGRESS)
                        HandleGameObject(GruulDoor, false);
                    else
                        HandleGameObject(GruulDoor, true);
                    m_auiEncounter[1] = data;
                    break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_MAULGAREVENT: return m_auiEncounter[0];
                case DATA_GRUULEVENT:   return m_auiEncounter[1];
            }
            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;
            std::ostringstream stream;
            stream << m_auiEncounter[0] << ' ' << m_auiEncounter[1];

            OUT_SAVE_INST_DATA_COMPLETE;
            return stream.str();
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);
            std::istringstream stream(in);
            stream >> m_auiEncounter[0] >> m_auiEncounter[1];
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)                // Do not load an encounter as "In Progress" - reset it instead.
                    m_auiEncounter[i] = NOT_STARTED;
            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};

void AddSC_instance_gruuls_lair()
{
    new instance_gruuls_lair();
}
