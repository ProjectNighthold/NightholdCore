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

#ifndef TRINITY_PETAI_H
#define TRINITY_PETAI_H

#include "CreatureAI.h"
#include "Timer.h"

class Creature;
class Spell;

class PetAI : public CreatureAI
{
public:

    explicit PetAI(Creature* c);

    void InitializeAI() override;
    void EnterEvadeMode() override;
    void JustDied(Unit* /*who*/) override;

    void UpdateAI(uint32) override;
    static int Permissible(const Creature*);

    void KilledUnit(Unit* /*victim*/) override;
    void AttackStart(Unit* target) override;
    void MovementInform(uint32 moveType, uint32 data) override;
    void OwnerDamagedBy(Unit* attacker) override;
    void OwnerAttacked(Unit* target) override;
    void ReceiveEmote(Player* player, uint32 textEmote) override;

private:
    bool _needToStop();
    void _stopAttack();

    void UpdateAllies();

    TimeTracker i_tracker;
    GuidSet m_AllySet;
    uint32 m_updateAlliesTimer;
    uint32 m_timeCheckSelf;

    Unit* SelectNextTarget();
    void HandleReturnMovement();
    void DoAttack(Unit* target, bool chase);
    bool CanAttack(Unit* target);
};
#endif

