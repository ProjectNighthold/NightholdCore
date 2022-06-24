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

#ifndef TRINITY_REACTORAI_H
#define TRINITY_REACTORAI_H

#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "CreatureTextMgr.h"

class Unit;
typedef std::map<ObjectGuid, EventMap> PlayerEventMap;

class ReactorAI : public CreatureAI
{
    public:

        explicit ReactorAI(Creature* c) : CreatureAI(c), CreatureTexts(nullptr), CreatureCombatTexts(nullptr) {}

        void MoveInLineOfSight(Unit*);

        void Reset();
        void InitializeAI();
        void UpdateAI(uint32);
        static int Permissible(const Creature*);
        void EnterCombat(Unit* who);
        void JustDied(Unit* killer);

        void AddClientVisibility(ObjectGuid guid) override;
        void RemoveClientVisibility(ObjectGuid guid) override;

        void AttackedBy(Unit* who) override;
    protected:
        EventMap spellCasts;
        EventMap events;
        EventMap textCombatEvents;
        PlayerEventMap textEvents;
        CreatureTextGroup const* CreatureTexts;
        CreatureTextGroup const* CreatureCombatTexts;
};
#endif

