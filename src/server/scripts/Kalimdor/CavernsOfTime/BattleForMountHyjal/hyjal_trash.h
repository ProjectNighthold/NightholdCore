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

#ifndef SC_HYJAL_TRASH_AI_H
#define SC_HYJAL_TRASH_AI_H

#include "hyjal.h"
#include "ScriptedEscortAI.h"

#define MINRAIDDAMAGE  700000//minimal damage before trash can drop loot and reputation, resets if faction leader dies

struct hyjal_trashAI : public npc_escortAI
{
    hyjal_trashAI(Creature* creature);

    void UpdateAI(uint32 diff);

    void JustDied(Unit* /*killer*/);

    void DamageTaken(Unit* done_by, uint32 &damage, DamageEffectType dmgType);

    public:
        InstanceScript* instance;
        bool IsEvent;
        uint32 Delay;
        uint32 LastOverronPos;
        bool IsOverrun;
        bool SetupOverrun;
        uint32 OverrunType;
        uint8 faction;
        bool useFlyPath;
        uint32 damageTaken;
        float DummyTarget[3];

    //private:
};
#endif
