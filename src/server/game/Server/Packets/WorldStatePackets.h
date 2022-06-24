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

#ifndef WorldStatePackets_h__
#define WorldStatePackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace WorldState
    {
        class InitWorldStates final : public ServerPacket
        {
        public:
            InitWorldStates() : ServerPacket(SMSG_INIT_WORLD_STATES, 12) { }
            
            WorldPacket const* Write() override;

            struct WorldStateInfo
            {
                WorldStateInfo(WorldStates variableID, int32 value) : VariableID(variableID), Value(value) { }
                WorldStateInfo(uint32 variableID, int32 value) : VariableID(variableID), Value(value) { }

                uint32 VariableID;
                int32 Value;
            };
            
            std::vector<WorldStateInfo> Worldstates;
            uint32 AreaID = 0;
            uint32 SubareaID = 0;
            uint32 MapID = 0;
        };

        class UpdateWorldState final : public ServerPacket
        {
        public:
            UpdateWorldState() : ServerPacket(SMSG_UPDATE_WORLD_STATE, 9) { }

            WorldPacket const* Write() override;

            int32 Value = 0;
            WorldStates VariableID = WS_NONE;
            bool Hidden = false;
        };

        struct ElaspedTimer
        {
            ElaspedTimer() { }
            ElaspedTimer(uint32 timerID, time_t currentDuration) : TimerID(timerID), CurrentDuration(currentDuration) { }

            uint32 TimerID = 0;
            time_t CurrentDuration = time_t(0);
        };
        
        class StartElapsedTimer final : public ServerPacket
        {
        public:
            StartElapsedTimer() : ServerPacket(SMSG_START_ELAPSED_TIMER, 8) { }

            WorldPacket const* Write() override;

            ElaspedTimer Timer;
        };

        class StartElapsedTimers final : public ServerPacket
        {
        public:
            StartElapsedTimers() : ServerPacket(SMSG_START_ELAPSED_TIMERS, 4) { }

            WorldPacket const* Write() override;

            std::vector<ElaspedTimer> Timers;
        };
    }
}

#endif // WorldStatePackets_h__
