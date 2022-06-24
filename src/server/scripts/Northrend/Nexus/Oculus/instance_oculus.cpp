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
#include "Packets/WorldStatePackets.h"
#include "oculus.h"

DoorData const doorData[] =
{
    { GO_DRAGON_CAGE_DOOR,  DATA_DRAKOS,    DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { 0,                    0,              DOOR_TYPE_ROOM,     BOUNDARY_NONE }
};

Position const VerdisaMove       = { 949.188f, 1032.91f, 359.967f, 1.093027f  };
Position const BelgaristraszMove = { 941.453f, 1044.1f,  359.967f, 0.1984709f };
Position const EternosMove       = { 943.202f, 1059.35f, 359.967f, 5.757278f  };

class instance_oculus : public InstanceMapScript
{
    public:
        instance_oculus() : InstanceMapScript("instance_oculus", 578) { }

        struct instance_oculus_InstanceMapScript : public InstanceScript
        {
            instance_oculus_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                DrakosGUID.Clear();
                VarosGUID.Clear();
                UromGUID.Clear();
                EregosGUID.Clear();

                CentrifugueConstructCounter = 0;

                EregosCacheGUID.Clear();

                GreaterWhelpList.clear();

                BelgaristraszGUID.Clear();
                EternosGUID.Clear();
                VerdisaGUID.Clear();
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_DRAKOS:
                        DrakosGUID = creature->GetGUID();
                        break;
                    case NPC_VAROS:
                        VarosGUID = creature->GetGUID();
                        if (GetBossState(DATA_DRAKOS) == DONE)
                           creature->SetPhaseMask(1, true);
                        break;
                    case NPC_UROM:
                        UromGUID = creature->GetGUID();
                        if (GetBossState(DATA_VAROS) == DONE)
                            creature->SetPhaseMask(1, true);
                        break;
                    case NPC_EREGOS:
                        EregosGUID = creature->GetGUID();
                        if (GetBossState(DATA_UROM) == DONE)
                            creature->SetPhaseMask(1, true);
                        break;
                    case NPC_CENTRIFUGE_CONSTRUCT:
                        if (creature->isAlive())
                            DoUpdateWorldState(WorldStates::WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT, ++CentrifugueConstructCounter);
                        break;
                    case NPC_BELGARISTRASZ:
                        BelgaristraszGUID = creature->GetGUID();
                        if (GetBossState(DATA_DRAKOS) == DONE)
                        {
                            creature->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            creature->Relocate(BelgaristraszMove);
                        }
                        break;
                    case NPC_ETERNOS:
                        EternosGUID = creature->GetGUID();
                        if (GetBossState(DATA_DRAKOS) == DONE)
                        {
                            creature->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            creature->Relocate(EternosMove);
                        }
                        break;
                    case NPC_VERDISA:
                        VerdisaGUID = creature->GetGUID();
                        if (GetBossState(DATA_DRAKOS) == DONE)
                        {
                            creature->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            creature->Relocate(VerdisaMove);
                        }
                        break;
                    case NPC_GREATER_WHELP:
                        if (GetBossState(DATA_UROM) == DONE)
                        {
                            creature->SetPhaseMask(1, true);
                            GreaterWhelpList.push_back(creature->GetGUID());
                        }
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_DRAGON_CAGE_DOOR:
                        AddDoor(go, true);
                        break;
                    case GO_EREGOS_CACHE_N:
                    case GO_EREGOS_CACHE_H:
                        EregosCacheGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_DRAGON_CAGE_DOOR:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit) override
            {
                Creature* creature = unit->ToCreature();
                if (!creature)
                    return;

                if (creature->GetEntry() == NPC_CENTRIFUGE_CONSTRUCT)
                {
                     DoUpdateWorldState(WorldStates::WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT, --CentrifugueConstructCounter);

                     if (!CentrifugueConstructCounter)
                        if (Creature* varos = instance->GetCreature(VarosGUID))
                            varos->RemoveAllAuras();
                }
            }

            void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override
            {
                if (GetBossState(DATA_DRAKOS) == DONE && GetBossState(DATA_VAROS) != DONE)
                {
                    packet.Worldstates.emplace_back(WorldStates::WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW, 1);
                    packet.Worldstates.emplace_back(WorldStates::WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT, CentrifugueConstructCounter);
                }
                else
                {
                    packet.Worldstates.emplace_back(WorldStates::WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW, 0);
                    packet.Worldstates.emplace_back(WorldStates::WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT, 0);
                }
            }

            void ProcessEvent(WorldObject* /*unit*/, uint32 eventId) override
            {
                if (eventId != EVENT_CALL_DRAGON)
                    return;

                if (Creature* varos = instance->GetCreature(VarosGUID))
                    if (Creature* drake = varos->SummonCreature(NPC_AZURE_RING_GUARDIAN, varos->GetPositionX(), varos->GetPositionY(), varos->GetPositionZ() + 40))
                        drake->AI()->DoAction(ACTION_CALL_DRAGON_EVENT);
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_DRAKOS:
                        if (state == DONE)
                        {
                            DoUpdateWorldState(WorldStates::WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW, 1);
                            DoUpdateWorldState(WorldStates::WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT, CentrifugueConstructCounter);
                            FreeDragons();
                            if (Creature* varos = instance->GetCreature(VarosGUID))
                                varos->SetPhaseMask(1, true);
                        }
                        break;
                    case DATA_VAROS:
                        if (state == DONE)
                            DoUpdateWorldState(WorldStates::WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW, 0);
                            if (Creature* urom = instance->GetCreature(UromGUID))
                                urom->SetPhaseMask(1, true);
                        break;
                    case DATA_UROM:
                        if (state == DONE)
                        {
                            if (Creature* eregos = instance->GetCreature(EregosGUID))
                            {
                                eregos->SetPhaseMask(1, true);
                                GreaterWhelps();
                            }
                        }
                        break;
                    case DATA_EREGOS:
                        if (state == DONE)
                        {
                            if (GameObject* cache = instance->GetGameObject(EregosCacheGUID))
                            {
                                cache->SetRespawnTime(cache->GetRespawnDelay());
                                cache->RemoveFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            }
                        }
                        break;
                }

                return true;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_DRAKOS:
                        return DrakosGUID;
                    case DATA_VAROS:
                        return VarosGUID;
                    case DATA_UROM:
                        return UromGUID;
                    case DATA_EREGOS:
                        return EregosGUID;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            void FreeDragons()
            {
                if (Creature* belgaristrasz = instance->GetCreature(BelgaristraszGUID))
                {
                    belgaristrasz->SetWalk(true);
                    belgaristrasz->GetMotionMaster()->MovePoint(POINT_MOVE_OUT, BelgaristraszMove);
                }

                if (Creature* eternos = instance->GetCreature(EternosGUID))
                {
                    eternos->SetWalk(true);
                    eternos->GetMotionMaster()->MovePoint(POINT_MOVE_OUT, EternosMove);
                }

                if (Creature* verdisa = instance->GetCreature(VerdisaGUID))
                {
                    verdisa->SetWalk(true);
                    verdisa->GetMotionMaster()->MovePoint(POINT_MOVE_OUT, VerdisaMove);
                }
            }

            void GreaterWhelps()
            {
                for (GuidList::const_iterator itr = GreaterWhelpList.begin(); itr != GreaterWhelpList.end(); ++itr)
                    if (Creature* gwhelp = instance->GetCreature(*itr))
                        gwhelp->SetPhaseMask(1, true);
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "T O " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* str) override
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'T' && dataHead2 == 'O')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            ObjectGuid DrakosGUID;
            ObjectGuid VarosGUID;
            ObjectGuid UromGUID;
            ObjectGuid EregosGUID;

            ObjectGuid BelgaristraszGUID;
            ObjectGuid EternosGUID;
            ObjectGuid VerdisaGUID;

            uint8 CentrifugueConstructCounter;

            ObjectGuid EregosCacheGUID;

            GuidList GreaterWhelpList;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_oculus_InstanceMapScript(map);
        }
};

void AddSC_instance_oculus()
{
    new instance_oculus();
}
