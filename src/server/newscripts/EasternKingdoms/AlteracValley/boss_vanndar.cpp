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
#include "ScriptedCreature.h"

enum Yells
{
    YELL_AGGRO                                    = 0,
    YELL_EVADE                                    = 1,
    YELL_RESPAWN                                  = 10,
    YELL_RANDOM                                   = 2,
    YELL_SPELL                                    = 3,
};

enum Spells
{
    SPELL_AVATAR                                  = 19135,
    SPELL_THUNDERCLAP                             = 15588,
    SPELL_STORMBOLT                               = 20685 // not sure
};

class boss_vanndar : public CreatureScript
{
public:
    boss_vanndar() : CreatureScript("boss_vanndar") {}

    struct boss_vanndarAI : public ScriptedAI
    {
        boss_vanndarAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 AvatarTimer;
        uint32 ThunderclapTimer;
        uint32 StormboltTimer;
        uint32 ResetTimer;
        uint32 YellTimer;

        void Reset() override
        {
            AvatarTimer        = 3 * IN_MILLISECONDS;
            ThunderclapTimer   = 4 * IN_MILLISECONDS;
            StormboltTimer     = 6 * IN_MILLISECONDS;
            ResetTimer         = 5 * IN_MILLISECONDS;
            YellTimer = urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(YELL_AGGRO);
        }

        void JustRespawned() override
        {
            Reset();
            Talk(YELL_RESPAWN);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (AvatarTimer <= diff)
            {
                if (auto victim = me->getVictim())
                    DoCast(victim, SPELL_AVATAR, false);

                AvatarTimer =  urand(15 * IN_MILLISECONDS, 20 * IN_MILLISECONDS);
            }
            else
                AvatarTimer -= diff;

            if (ThunderclapTimer <= diff)
            {
                if (auto victim = me->getVictim())
                    DoCast(victim, SPELL_THUNDERCLAP, false);

                ThunderclapTimer = urand(5 * IN_MILLISECONDS, 15 * IN_MILLISECONDS);
            }
            else
                ThunderclapTimer -= diff;

            if (StormboltTimer <= diff)
            {
                if (auto victim = me->getVictim())
                    DoCast(victim, SPELL_STORMBOLT, false);

                StormboltTimer = urand(10 * IN_MILLISECONDS, 25 * IN_MILLISECONDS);
            }
            else
                StormboltTimer -= diff;

            if (YellTimer <= diff)
            {
                Talk(YELL_RANDOM);
                YellTimer = urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS); //20 to 30 seconds
            }
            else
                YellTimer -= diff;

            // check if creature is not outside of building
            if (ResetTimer <= diff)
            {
                if (me->GetDistance2d(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY()) > 50)
                {
                    EnterEvadeMode();
                    Talk(YELL_EVADE);
                }
                ResetTimer = 5 * IN_MILLISECONDS;
            }
            else
                ResetTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_vanndarAI(creature);
    }
};

void AddSC_boss_vanndar()
{
    new boss_vanndar;
}