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
SDName: Instance_Temple_of_Ahnqiraj
SD%Complete: 80
SDComment:
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "temple_of_ahnqiraj.h"
#include "Packets/WorldStatePackets.h"

class instance_temple_of_ahnqiraj : public InstanceMapScript
{
public:
    instance_temple_of_ahnqiraj() : InstanceMapScript("instance_temple_of_ahnqiraj", 531) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_temple_of_ahnqiraj_InstanceMapScript(map);
    }

    struct instance_temple_of_ahnqiraj_InstanceMapScript : public InstanceScript
    {
        instance_temple_of_ahnqiraj_InstanceMapScript(Map* map) : InstanceScript(map) {}

        //If Vem is dead...
        bool IsBossDied[3];

        //Storing Skeram, Vem and Kri.
        ObjectGuid SkeramGUID;
        ObjectGuid VemGUID;
        ObjectGuid KriGUID;
        ObjectGuid VeklorGUID;
        ObjectGuid VeknilashGUID;

        uint32 BugTrioDeathCount;

        uint32 CthunPhase;

        uint32 update_worldstate;
        uint32 CurrectAllianceScore{};
        uint32 CurrectHordeScore{};
        uint32 AllianceScore{};
        uint32 HordeScore{};

        void Initialize()
        {
            IsBossDied[0] = false;
            IsBossDied[1] = false;
            IsBossDied[2] = false;

            SkeramGUID.Clear();
            VemGUID.Clear();
            KriGUID.Clear();
            VeklorGUID.Clear();
            VeknilashGUID.Clear();

            BugTrioDeathCount = 0;

            CthunPhase = 0;

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
                case 15263: SkeramGUID = creature->GetGUID(); break;
                case 15544: VemGUID = creature->GetGUID(); break;
                case 15511: KriGUID = creature->GetGUID(); break;
                case 15276: VeklorGUID = creature->GetGUID(); break;
                case 15275: VeknilashGUID = creature->GetGUID(); break;
            }
        }

        bool IsEncounterInProgress() const
        {
            //not active in AQ40
            return false;
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

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_VEMISDEAD:
                    if (IsBossDied[0])
                        return 1;
                    break;

                case DATA_VEKLORISDEAD:
                    if (IsBossDied[1])
                        return 1;
                    break;

                case DATA_VEKNILASHISDEAD:
                    if (IsBossDied[2])
                        return 1;
                    break;

                case DATA_BUG_TRIO_DEATH:
                    return BugTrioDeathCount;

                case DATA_CTHUN_PHASE:
                    return CthunPhase;
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 identifier) const
        {
            switch (identifier)
            {
                case DATA_SKERAM:
                    return SkeramGUID;
                case DATA_VEM:
                    return VemGUID;
                case DATA_KRI:
                    return KriGUID;
                case DATA_VEKLOR:
                    return VeklorGUID;
                case DATA_VEKNILASH:
                    return VeknilashGUID;
            }
            return ObjectGuid::Empty;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_VEM_DEATH:
                    IsBossDied[0] = true;
                    break;

                case DATA_BUG_TRIO_DEATH:
                    ++BugTrioDeathCount;
                    break;

                case DATA_VEKLOR_DEATH:
                    IsBossDied[1] = true;
                    break;

                case DATA_VEKNILASH_DEATH:
                    IsBossDied[2] = true;
                    break;

                case DATA_CTHUN_PHASE:
                    CthunPhase = data;
                    break;
            }
        }
    };
};

void AddSC_instance_temple_of_ahnqiraj()
{
    new instance_temple_of_ahnqiraj();
}
