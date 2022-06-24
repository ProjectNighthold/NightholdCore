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

#ifndef TRINITY_GAMEOBJECTAI_H
#define TRINITY_GAMEOBJECTAI_H

#include "Object.h"
#include "GameObject.h"
#include "CreatureAI.h"

class GameObjectAI
{
    protected:
        GameObject* const go;
    public:
        explicit GameObjectAI(GameObject* g) : go(g) {}
        virtual ~GameObjectAI() = default;

        virtual void UpdateAI(uint32 /*diff*/) {}

        virtual void InitializeAI() { Reset(); }

        virtual void Reset() {};

        // Pass parameters between AI
        virtual void DoAction(const int32 /*param = 0 */) {}
        virtual void SetGUID(ObjectGuid const& /*guid*/, int32 /*id = 0 */) {}
        virtual ObjectGuid GetGUID(int32 /*id = 0 */) { return ObjectGuid::Empty; }

        static int Permissible(GameObject const* go);

        virtual bool GossipUse(Player* /*player*/) { return false; }
        virtual bool GossipHello(Player* /*player*/) { return false; }
        virtual bool GossipSelect(Player* /*player*/, uint32 /*sender*/, uint32 /*action*/) { return false; }
        virtual bool GossipSelectCode(Player* /*player*/, uint32 /*sender*/, uint32 /*action*/, char const* /*code*/) { return false; }
        virtual bool QuestAccept(Player* /*player*/, Quest const* /*quest*/) { return false; }
        virtual bool QuestReward(Player* /*player*/, Quest const* /*quest*/, uint32 /*opt*/) { return false; }
        virtual uint32 GetDialogStatus(Player* /*player*/) { return 100; }
        virtual void Destroyed(Player* /*player*/, uint32 /*eventId*/) {}
        virtual uint32 GetData(uint32 /*id*/) { return 0; }
        virtual void SetData64(uint32 /*id*/, uint64 /*value*/) {}
        virtual uint64 GetData64(uint32 /*id*/) { return 0; }
        virtual void SetData(uint32 /*id*/, uint32 /*value*/) {}
        virtual void OnStateChanged(uint32 /*state*/, Unit* /*unit*/) {}
        virtual void EventInform(uint32 /*eventId*/) {}
};

class NullGameObjectAI : public GameObjectAI
{
    public:
        explicit NullGameObjectAI(GameObject* g);

        void UpdateAI(uint32 /*diff*/) {}

        static int Permissible(GameObject const* /*go*/) { return PERMIT_BASE_IDLE; }
};
#endif
