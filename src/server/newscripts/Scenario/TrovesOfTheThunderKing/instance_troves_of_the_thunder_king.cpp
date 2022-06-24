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

#include "MiscPackets.h"
#include "troves_of_the_thunder_king.h"

class instance_troves_of_the_thunder_king : public InstanceMapScript
{
public:
    instance_troves_of_the_thunder_king() : InstanceMapScript("instance_troves_of_the_thunder_king", 1135) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_troves_of_the_thunder_king_InstanceMapScript(map);
    }

    struct instance_troves_of_the_thunder_king_InstanceMapScript : public InstanceScript
    {
        instance_troves_of_the_thunder_king_InstanceMapScript(Map* map) : InstanceScript(map)
        { }

        void Initialize() override
        {
            start = NOT_STARTED;
            pilarMasterGUIDs.clear();
        }

        void OnPlayerEnter(Player* player) override
        {
            std::vector<uint16> WorldMapAreaIds;
            WorldMapAreaIds.emplace_back(770);
            WorldMapAreaIds.emplace_back(748);
            WorldMapAreaIds.emplace_back(907);
            WorldMapAreaIds.emplace_back(910);
            player->GetSession()->SendSetPhaseShift(std::vector<WorldPackets::Misc::PhaseShiftDataPhase>(), std::vector<uint16>(), WorldMapAreaIds, std::vector<uint16>(), 8);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_LIGHTING_PILAR_TARGET_BUNNY:
                    creature->SetReactState(REACT_PASSIVE);
                    break;
                case NPC_LIGHTING_PILAR_MASTER_BUNNY:
                    pilarMasterGUIDs.push_back(creature->GetGUID());
                    break;
                default:
                    break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_EVENT_STARTED:
                    start = data;
                    if (data == DONE)
                        for (GuidVector::const_iterator itr = pilarMasterGUIDs.begin(); itr != pilarMasterGUIDs.end(); ++itr)
                            if (Creature* cre = instance->GetCreature(*itr))
                                cre->AI()->DoAction(ACTION_1);
                    break;
                default:
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_EVENT_STARTED:
                    return start;
                default:
                    return 0;
            }
        }

    private:
        uint32 start;
        GuidVector pilarMasterGUIDs;
    };
};

void AddSC_instance_troves_of_the_thunder_king()
{
    new instance_troves_of_the_thunder_king();
}
