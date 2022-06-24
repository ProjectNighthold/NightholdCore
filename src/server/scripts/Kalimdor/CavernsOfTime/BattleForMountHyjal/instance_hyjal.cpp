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
SDName: Instance_Mount_Hyjal
SD%Complete: 100
SDComment: Instance Data Scripts and functions to acquire mobs and set encounter status for use in various Hyjal Scripts
SDCategory: Caverns of Time, Mount Hyjal
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "hyjal_trash.h"

enum Misc
{
    MAX_ENCOUNTER       = 5,

    GO_ANCIENT_GEM      = 185557,
};
/* Battle of Mount Hyjal encounters:
0 - Rage Winterchill event
1 - Anetheron event
2 - Kaz'rogal event
3 - Azgalor event
4 - Archimonde event
*/

class instance_hyjal : public InstanceMapScript
{
public:
    instance_hyjal() : InstanceMapScript("instance_hyjal", 534) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_mount_hyjal_InstanceMapScript(map);
    }

    struct instance_mount_hyjal_InstanceMapScript : public InstanceScript
    {
        instance_mount_hyjal_InstanceMapScript(Map* map) : InstanceScript(map) {}

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        std::string str_data;

        GuidList m_uiAncientGemGUID;

        ObjectGuid RageWinterchill;
        ObjectGuid Anetheron;
        ObjectGuid Kazrogal;
        ObjectGuid Azgalor;
        ObjectGuid Archimonde;
        ObjectGuid JainaProudmoore;
        ObjectGuid Thrall;
        ObjectGuid TyrandeWhisperwind;
        ObjectGuid HordeGate;
        ObjectGuid ElfGate;

        uint32 Trash;

        uint32 hordeRetreat;
        uint32 allianceRetreat;
        bool ArchiYell;

        uint32 RaidDamage;

        #define YELL_EFFORTS        "All of your efforts have been in vain, for the draining of the World Tree has already begun. Soon the heart of your world will beat no more."
        #define YELL_EFFORTS_NAME   "Archimonde"

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            m_uiAncientGemGUID.clear();

            RageWinterchill.Clear();
            Anetheron.Clear();
            Kazrogal.Clear();
            Azgalor.Clear();
            Archimonde.Clear();
            JainaProudmoore.Clear();
            Thrall.Clear();
            TyrandeWhisperwind.Clear();
            HordeGate.Clear();
            ElfGate.Clear();
            ArchiYell = false;
            RaidDamage = 0;

            Trash = 0;

            hordeRetreat = 0;
            allianceRetreat = 0;
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case 182060:
                    HordeGate = go->GetGUID();
                    if (allianceRetreat)
                        HandleGameObject(ObjectGuid::Empty, true, go);
                    else
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case 182061:
                    ElfGate = go->GetGUID();
                    if (hordeRetreat)
                        HandleGameObject(ObjectGuid::Empty, true, go);
                    else
                        HandleGameObject(ObjectGuid::Empty, false, go);
                    break;
                case GO_ANCIENT_GEM:
                    m_uiAncientGemGUID.push_back(go->GetGUID());
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case 17767: RageWinterchill = creature->GetGUID(); break;
                case 17808: Anetheron = creature->GetGUID(); break;
                case 17888: Kazrogal = creature->GetGUID();  break;
                case 17842: Azgalor = creature->GetGUID(); break;
                case 17968: Archimonde = creature->GetGUID(); break;
                case 17772: JainaProudmoore = creature->GetGUID(); break;
                case 17852: Thrall = creature->GetGUID(); break;
                case 17948: TyrandeWhisperwind = creature->GetGUID(); break;
            }
        }

        ObjectGuid GetGuidData(uint32 identifier) const
        {
            switch (identifier)
            {
                case DATA_RAGEWINTERCHILL: return RageWinterchill;
                case DATA_ANETHERON: return Anetheron;
                case DATA_KAZROGAL: return Kazrogal;
                case DATA_AZGALOR: return Azgalor;
                case DATA_ARCHIMONDE: return Archimonde;
                case DATA_JAINAPROUDMOORE: return JainaProudmoore;
                case DATA_THRALL: return Thrall;
                case DATA_TYRANDEWHISPERWIND: return TyrandeWhisperwind;
            }

            return ObjectGuid::Empty;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case DATA_RAGEWINTERCHILLEVENT:
                    m_auiEncounter[0] = data;
                    break;
                case DATA_ANETHERONEVENT:
                    m_auiEncounter[1] = data;
                    break;
                case DATA_KAZROGALEVENT:
                    m_auiEncounter[2] = data;
                    break;
                case DATA_AZGALOREVENT:
                    {
                        m_auiEncounter[3] = data;
                        if (data == DONE)
                        {
                            if (ArchiYell)
                                break;

                            ArchiYell = true;

                            Creature* creature = instance->GetCreature(Azgalor);
                            Creature* archimonde = instance->GetCreature(Archimonde);
                            if (creature && archimonde)
                            {
                                Creature* unit = creature->SummonCreature(21987, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 10000);
                                Map* map = creature->GetMap();
                                if (map->IsDungeon() && unit)
                                    archimonde->AI()->Talk(8);
                            }
                        }
                    }
                    break;
                case DATA_ARCHIMONDEEVENT:
                    m_auiEncounter[4] = data;
                    break;
                case DATA_RESET_TRASH_COUNT:
                    Trash = 0;
                    break;
                case DATA_TRASH:
                    if (data)
                        Trash = data;
                    else
                        Trash--;
                    DoUpdateWorldState(WorldStates::WORLD_STATE_ENEMYCOUNT, Trash);
                    break;
                case TYPE_RETREAT:
                    if (data == SPECIAL)
                    {
                        if (!m_uiAncientGemGUID.empty())
                        {
                            for (GuidList::const_iterator itr = m_uiAncientGemGUID.begin(); itr != m_uiAncientGemGUID.end(); ++itr)
                            {
                                //don't know how long it expected
                                DoRespawnGameObject(*itr, DAY);
                            }
                        }
                    }
                    break;
                case DATA_ALLIANCE_RETREAT:
                    allianceRetreat = data;
                    HandleGameObject(HordeGate, true);
                    SaveToDB();
                    break;
                case DATA_HORDE_RETREAT:
                    hordeRetreat = data;
                    HandleGameObject(ElfGate, true);
                    SaveToDB();
                    break;
                case DATA_RAIDDAMAGE:
                    RaidDamage += data;
                    if (RaidDamage >= MINRAIDDAMAGE)
                        RaidDamage = MINRAIDDAMAGE;
                    break;
                case DATA_RESET_RAIDDAMAGE:
                    RaidDamage = 0;
                    break;
            }

             TC_LOG_DEBUG(LOG_FILTER_TSCR, "Instance Hyjal: Instance data updated for event %u (Data=%u)", type, data);

            if (data == DONE)
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' ' << m_auiEncounter[2] << ' '
                    << m_auiEncounter[3] << ' ' << m_auiEncounter[4]
                    << ' ' << allianceRetreat << ' ' << hordeRetreat
                    << ' ' << RaidDamage;

                str_data = saveStream.str();

                SaveToDB();
                OUT_SAVE_INST_DATA_COMPLETE;
            }

        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_RAGEWINTERCHILLEVENT: return m_auiEncounter[0];
                case DATA_ANETHERONEVENT:      return m_auiEncounter[1];
                case DATA_KAZROGALEVENT:       return m_auiEncounter[2];
                case DATA_AZGALOREVENT:        return m_auiEncounter[3];
                case DATA_ARCHIMONDEEVENT:     return m_auiEncounter[4];
                case DATA_TRASH:               return Trash;
                case DATA_ALLIANCE_RETREAT:    return allianceRetreat;
                case DATA_HORDE_RETREAT:       return hordeRetreat;
                case DATA_RAIDDAMAGE:          return RaidDamage;
            }
            return 0;
        }

        std::string GetSaveData()
        {
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
            std::istringstream loadStream(in);
            loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3] >> m_auiEncounter[4] >> allianceRetreat >> hordeRetreat >> RaidDamage;
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)                // Do not load an encounter as IN_PROGRESS - reset it instead.
                    m_auiEncounter[i] = NOT_STARTED;
            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};

void AddSC_instance_mount_hyjal()
{
    new instance_hyjal();
}
