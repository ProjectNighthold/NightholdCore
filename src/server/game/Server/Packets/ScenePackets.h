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

#ifndef ScenePackets_h__
#define ScenePackets_h__

#include "Packet.h"
#include "BattlePetPackets.h"
#include "AchievementPackets.h"

namespace WorldPackets
{
    namespace Scene
    {
        //< CMSG_SCENE_PLAYBACK_COMPLETE
        //< CMSG_SCENE_PLAYBACK_CANCELED
        class SceneInstance final : public ClientPacket
        {
        public:
            SceneInstance(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            uint32 SceneInstanceID = 0;
        };

        class CancelScene final : public ServerPacket
        {
        public:
            CancelScene(uint32 ID) : ServerPacket(SMSG_CANCEL_SCENE, 4), SceneInstanceID(ID) { }

            WorldPacket const* Write() override;

            uint32 SceneInstanceID = 0;
        };

        class PlayScene final : public ServerPacket
        {
        public:
            PlayScene() : ServerPacket(SMSG_PLAY_SCENE, 16 + 18 + 16) { }

            WorldPacket const* Write() override;

            uint32 SceneID = 0;
            uint32 PlaybackFlags = 0;
            uint32 SceneInstanceID = 0;
            uint32 SceneScriptPackageID = 0;
            ObjectGuid TransportGUID;
            TaggedPosition<Position::XYZO> Pos;
        };

        //< SMSG_SCENE_OBJECT_PET_BATTLE_FIRST_ROUND
        //< SMSG_SCENE_OBJECT_PET_BATTLE_ROUND_RESULT
        //< SMSG_SCENE_OBJECT_PET_BATTLE_REPLACEMENTS_MADE
        class PetBattleRound final : public ServerPacket
        {
        public:
            PetBattleRound(OpcodeServer opcode) : ServerPacket(opcode) { }

            WorldPacket const* Write() override;

            ObjectGuid SceneObjectGUID;
            BattlePet::RoundResult MsgData;
        };

        class SceneObjectFinalRound final : public ServerPacket
        {
        public:
            SceneObjectFinalRound() : ServerPacket(SMSG_SCENE_OBJECT_PET_BATTLE_FINAL_ROUND) { }

            WorldPacket const* Write() override;

            ObjectGuid SceneObjectGUID;
            BattlePet::FinalRound MsgData;
        };

        class PetBattleFinished final : public ServerPacket
        {
        public:
            PetBattleFinished() : ServerPacket(SMSG_SCENE_OBJECT_PET_BATTLE_FINISHED, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid SceneObjectGUID;
        };

        class SceneTriggerEvent final : public ClientPacket
        {
        public:
            SceneTriggerEvent(WorldPacket&& packet) : ClientPacket(CMSG_SCENE_TRIGGER_EVENT, std::move(packet)) { }

            void Read() override;

            std::string Event;
            uint32 SceneInstanceID = 0;
        };

        class SceneObjectPetBattleInitialUpdate final : public ServerPacket
        {
        public:
            SceneObjectPetBattleInitialUpdate() : ServerPacket(SMSG_SCENE_OBJECT_PET_BATTLE_INITIAL_UPDATE) { }

            WorldPacket const* Write() override;

            ObjectGuid SceneObjectGUID;
            BattlePet::PetBattleFullUpdate MsgData;
        };
    }
}

#endif // ScenePackets_h__
