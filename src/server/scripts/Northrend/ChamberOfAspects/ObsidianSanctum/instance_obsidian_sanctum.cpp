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
#include "obsidian_sanctum.h"

#define MAX_ENCOUNTER     1

/* Obsidian Sanctum encounters:
0 - Sartharion
*/

class instance_obsidian_sanctum : public InstanceMapScript
{
public:
    instance_obsidian_sanctum() : InstanceMapScript("instance_obsidian_sanctum", 615) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_obsidian_sanctum_InstanceMapScript(map);
    }

    struct instance_obsidian_sanctum_InstanceMapScript : public InstanceScript
    {
        instance_obsidian_sanctum_InstanceMapScript(Map* map) : InstanceScript(map) {}

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        ObjectGuid m_uiSartharionGUID;
        ObjectGuid m_uiTenebronGUID;
        ObjectGuid m_uiShadronGUID;
        ObjectGuid m_uiVesperonGUID;

        bool m_bTenebronKilled;
        bool m_bShadronKilled;
        bool m_bVesperonKilled;

        void Initialize() override
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            m_uiSartharionGUID.Clear();
            m_uiTenebronGUID.Clear();
            m_uiShadronGUID.Clear();
            m_uiVesperonGUID.Clear();

            m_bTenebronKilled = false;
            m_bShadronKilled = false;
            m_bVesperonKilled = false;
        }

        bool IsEncounterInProgress() const override
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_SARTHARION:
                    m_uiSartharionGUID = creature->GetGUID();
                    break;
                //three dragons below set to active state once created.
                //we must expect bigger raid to encounter main boss, and then three dragons must be active due to grid differences
                case NPC_TENEBRON:
                    m_uiTenebronGUID = creature->GetGUID();
                    creature->setActive(true);
                    break;
                case NPC_SHADRON:
                    m_uiShadronGUID = creature->GetGUID();
                    creature->setActive(true);
                    break;
                case NPC_VESPERON:
                    m_uiVesperonGUID = creature->GetGUID();
                    creature->setActive(true);
                    break;
            }
        }

        void SetData(uint32 uiType, uint32 uiData) override
        {
            if (uiType == TYPE_SARTHARION_EVENT)
                m_auiEncounter[0] = uiData;
            else if (uiType == TYPE_TENEBRON_PREKILLED)
                m_bTenebronKilled = true;
            else if (uiType == TYPE_SHADRON_PREKILLED)
                m_bShadronKilled = true;
            else if (uiType == TYPE_VESPERON_PREKILLED)
                m_bVesperonKilled = true;
        }

        uint32 GetData(uint32 uiType) const override
        {
            if (uiType == TYPE_SARTHARION_EVENT)
                return m_auiEncounter[0];
            else if (uiType == TYPE_TENEBRON_PREKILLED)
                return m_bTenebronKilled;
            else if (uiType == TYPE_SHADRON_PREKILLED)
                return m_bShadronKilled;
            else if (uiType == TYPE_VESPERON_PREKILLED)
                return m_bVesperonKilled;

            return 0;
        }

        ObjectGuid GetGuidData(uint32 uiData) const override
        {
            switch (uiData)
            {
                case DATA_SARTHARION:
                    return m_uiSartharionGUID;
                case DATA_TENEBRON:
                    return m_uiTenebronGUID;
                case DATA_SHADRON:
                    return m_uiShadronGUID;
                case DATA_VESPERON:
                    return m_uiVesperonGUID;
            }
            return ObjectGuid::Empty;
        }
    };

};

void AddSC_instance_obsidian_sanctum()
{
    new instance_obsidian_sanctum();
}
