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
#include "ruins_of_ahnqiraj.h"
#include "Packets/WorldStatePackets.h"

class instance_ruins_of_ahnqiraj : public InstanceMapScript
{
    public:
        instance_ruins_of_ahnqiraj() : InstanceMapScript("instance_ruins_of_ahnqiraj", 509) {}

        struct instance_ruins_of_ahnqiraj_InstanceMapScript : public InstanceScript
        {
            instance_ruins_of_ahnqiraj_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(MAX_ENCOUNTER);

                _kurinaxxGUID.Clear();
                _rajaxxGUID.Clear();
                _moamGUID.Clear();
                _buruGUID.Clear();
                _ayamissGUID.Clear();
                _ossirianGUID.Clear();
            }

            uint32 update_worldstate;
            uint32 CurrectAllianceScore{};
            uint32 CurrectHordeScore{};
            uint32 AllianceScore{};
            uint32 HordeScore{};

            void Initialize() override
            {
                update_worldstate = 2000;

                AllianceScore = sWorld->getWorldState(WS_SCORE_CALL_OF_THE_SCARAB_ALLINCE);
                HordeScore = sWorld->getWorldState(WS_SCORE_CALL_OF_THE_SCARAB_HORDE);
                CurrectAllianceScore = AllianceScore;
                CurrectHordeScore = CurrectHordeScore;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_KURINAXX:
                        _kurinaxxGUID = creature->GetGUID();
                        break;
                    case NPC_RAJAXX:
                        _rajaxxGUID = creature->GetGUID();
                        break;
                    case NPC_MOAM:
                        _moamGUID = creature->GetGUID();
                        break;
                    case NPC_BURU:
                        _buruGUID = creature->GetGUID();
                        break;
                    case NPC_AYAMISS:
                        _ayamissGUID = creature->GetGUID();
                        break;
                    case NPC_OSSIRIAN:
                        _ossirianGUID = creature->GetGUID();
                        break;
                }
            }

            bool SetBossState(uint32 bossId, EncounterState state)
            {
                if (!InstanceScript::SetBossState(bossId, state))
                    return false;

                return true;
            }

            void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override
            {
                packet.Worldstates.emplace_back(static_cast<WorldStates>(12953), AllianceScore);
                packet.Worldstates.emplace_back(static_cast<WorldStates>(12952), HordeScore);
            }

            void Update(uint32 diff) override
            {
                if (update_worldstate <= diff)
                {
                    update_worldstate = 2000;

                    if (sGameEventMgr->IsActiveEvent(78))
                    {
                        instance->ApplyOnEveryPlayer([=](Player* player) -> void
                        {
                            AllianceScore = sWorld->getWorldState(WS_SCORE_CALL_OF_THE_SCARAB_ALLINCE);
                            HordeScore = sWorld->getWorldState(WS_SCORE_CALL_OF_THE_SCARAB_HORDE);

                            if (AllianceScore > CurrectAllianceScore)
                            {
                                CurrectAllianceScore = AllianceScore;
                                player->SendUpdateWorldState(static_cast<WorldStates>(12953), AllianceScore);
                            }

                            if (HordeScore > CurrectHordeScore)
                            {
                                CurrectHordeScore = AllianceScore;
                                player->SendUpdateWorldState(static_cast<WorldStates>(12952), HordeScore);
                            }
                        });
                    }
                }
                else
                    update_worldstate -= diff;
            }

            ObjectGuid GetGuidData(uint32 type) const
            {
                switch (type)
                {
                    case BOSS_KURINNAXX:
                        return _kurinaxxGUID;
                    case BOSS_RAJAXX:
                        return _rajaxxGUID;
                    case BOSS_MOAM:
                        return _moamGUID;
                    case BOSS_BURU:
                        return _buruGUID;
                    case BOSS_AYAMISS:
                        return _ayamissGUID;
                    case BOSS_OSSIRIAN:
                        return _ossirianGUID;
                }

                return ObjectGuid::Empty;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "R A" << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* data)
            {
                if (!data)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(data);

                char dataHead1, dataHead2;

                std::istringstream loadStream(data);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'R' && dataHead2 == 'A')
                {
                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > TO_BE_DECIDED)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        private:
            ObjectGuid _kurinaxxGUID;
            ObjectGuid _rajaxxGUID;
            ObjectGuid _moamGUID;
            ObjectGuid _buruGUID;
            ObjectGuid _ayamissGUID;
            ObjectGuid _ossirianGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_ruins_of_ahnqiraj_InstanceMapScript(map);
        }
};

void AddSC_instance_ruins_of_ahnqiraj()
{
    new instance_ruins_of_ahnqiraj();
}
