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

#include "blackrock_depths.h"

enum Yells
{
    SAY_AGGRO                                              = 0,
    SAY_SLAY                                               = 1
};

enum Spells
{
    SPELL_HANDOFTHAURISSAN                                 = 17492,
    SPELL_AVATAROFFLAME                                    = 15636
};

class boss_emperor_dagran_thaurissan : public CreatureScript
{
public:
    boss_emperor_dagran_thaurissan() : CreatureScript("boss_emperor_dagran_thaurissan") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_draganthaurissanAI (creature);
    }

    struct boss_draganthaurissanAI : public ScriptedAI
    {
        boss_draganthaurissanAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 HandOfThaurissan_Timer;
        uint32 AvatarOfFlame_Timer;
        //uint32 Counter;

        void Reset() override
        {
            HandOfThaurissan_Timer = 4000;
            AvatarOfFlame_Timer = 25000;
            //Counter= 0;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            me->CallForHelp(VISIBLE_RANGE);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (!instance)
                return;

            if (Creature* Moira = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_MOIRA)))
            {
                Moira->AI()->EnterEvadeMode();
                Moira->setFaction(35);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (HandOfThaurissan_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_HANDOFTHAURISSAN);

                //3 Hands of Thaurissan will be casted
                //if (Counter < 3)
                //{
                //    HandOfThaurissan_Timer = 1000;
                //    ++Counter;
                //}
                //else
                //{
                    HandOfThaurissan_Timer = 5000;
                    //Counter = 0;
                //}
            }
            else
                HandOfThaurissan_Timer -= diff;

            //AvatarOfFlame_Timer
            if (AvatarOfFlame_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_AVATAROFFLAME);
                AvatarOfFlame_Timer = 18000;
            }
            else
                AvatarOfFlame_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_draganthaurissan()
{
    new boss_emperor_dagran_thaurissan();
}
