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

enum Says
{
    SAY_AGGRO = 0,
    SAY_SLAY,
    SAY_DEATH
};

#define SPELL_WHIRLWIND                              26083
#define SPELL_ENRAGE                                 28747            //Not sure if right ID.
#define SPELL_ENRAGEHARD                             28798

//Guard Spell
#define SPELL_WHIRLWINDADD                           26038
#define SPELL_KNOCKBACK                              26027

class boss_sartura : public CreatureScript
{
public:
    boss_sartura() : CreatureScript("boss_sartura") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_sarturaAI (creature);
    }

    struct boss_sarturaAI : public ScriptedAI
    {
        boss_sarturaAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 WhirlWind_Timer;
        uint32 WhirlWindRandom_Timer;
        uint32 WhirlWindEnd_Timer;
        uint32 AggroReset_Timer;
        uint32 AggroResetEnd_Timer;
        uint32 EnrageHard_Timer;

        bool Enraged;
        bool EnragedHard;
        bool WhirlWind;
        bool AggroReset;

        void Reset()
        {
            WhirlWind_Timer = 30000;
            WhirlWindRandom_Timer = urand(3000, 7000);
            WhirlWindEnd_Timer = 15000;
            AggroReset_Timer = urand(45000, 55000);
            AggroResetEnd_Timer = 5000;
            EnrageHard_Timer = 10*60000;

            WhirlWind = false;
            AggroReset = false;
            Enraged = false;
            EnragedHard = false;

        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
        }

         void JustDied(Unit* /*killer*/)
         {
             Talk(SAY_DEATH);
         }

         void KilledUnit(Unit* /*victim*/)
         {
             Talk(SAY_SLAY);
         }

        void UpdateAI(uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (WhirlWind)
            {
                if (WhirlWindRandom_Timer <= diff)
                {
                    //Attack random Gamers
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                    {
                        me->AddThreat(target, 1.0f);
                        me->TauntApply(target);
                        AttackStart(target);
                    }
                    WhirlWindRandom_Timer = urand(3000, 7000);
                } else WhirlWindRandom_Timer -= diff;

                if (WhirlWindEnd_Timer <= diff)
                {
                    WhirlWind = false;
                    WhirlWind_Timer = urand(25000, 40000);
                } else WhirlWindEnd_Timer -= diff;
            }

            if (!WhirlWind)
            {
                if (WhirlWind_Timer <= diff)
                {
                    DoCast(me, SPELL_WHIRLWIND);
                    WhirlWind = true;
                    WhirlWindEnd_Timer = 15000;
                } else WhirlWind_Timer -= diff;

                if (AggroReset_Timer <= diff)
                {
                    //Attack random Gamers
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                    {
                        me->AddThreat(target, 1.0f);
                        me->TauntApply(target);
                        AttackStart(target);
                    }
                    AggroReset = true;
                    AggroReset_Timer = urand(2000, 5000);
                } else AggroReset_Timer -= diff;

                if (AggroReset)
                {
                    if (AggroResetEnd_Timer <= diff)
                    {
                        AggroReset = false;
                        AggroResetEnd_Timer = 5000;
                        AggroReset_Timer = urand(35000, 45000);
                    } else AggroResetEnd_Timer -= diff;
                }

                //If she is 20% enrage
                if (!Enraged)
                {
                    if (!HealthAbovePct(20) && !me->IsNonMeleeSpellCast(false))
                    {
                        DoCast(me, SPELL_ENRAGE);
                        Enraged = true;
                    }
                }

                //After 10 minutes hard enrage
                if (!EnragedHard)
                {
                    if (EnrageHard_Timer <= diff)
                    {
                        DoCast(me, SPELL_ENRAGEHARD);
                        EnragedHard = true;
                    } else EnrageHard_Timer -= diff;
                }

                DoMeleeAttackIfReady();
            }
        }
    };

};

class mob_sartura_royal_guard : public CreatureScript
{
public:
    mob_sartura_royal_guard() : CreatureScript("mob_sartura_royal_guard") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_sartura_royal_guardAI (creature);
    }

    struct mob_sartura_royal_guardAI : public ScriptedAI
    {
        mob_sartura_royal_guardAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 WhirlWind_Timer;
        uint32 WhirlWindRandom_Timer;
        uint32 WhirlWindEnd_Timer;
        uint32 AggroReset_Timer;
        uint32 AggroResetEnd_Timer;
        uint32 KnockBack_Timer;

        bool WhirlWind;
        bool AggroReset;

        void Reset()
        {
            WhirlWind_Timer = 30000;
            WhirlWindRandom_Timer = urand(3000, 7000);
            WhirlWindEnd_Timer = 15000;
            AggroReset_Timer = urand(45000, 55000);
            AggroResetEnd_Timer = 5000;
            KnockBack_Timer = 10000;

            WhirlWind = false;
            AggroReset = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void UpdateAI(uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (!WhirlWind && WhirlWind_Timer <= diff)
            {
                DoCast(me, SPELL_WHIRLWINDADD);
                WhirlWind = true;
                WhirlWind_Timer = urand(25000, 40000);
                WhirlWindEnd_Timer = 15000;
            } else WhirlWind_Timer -= diff;

            if (WhirlWind)
            {
                if (WhirlWindRandom_Timer <= diff)
                {
                    //Attack random Gamers
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                    {
                        me->AddThreat(target, 1.0f);
                        me->TauntApply(target);
                        AttackStart(target);
                    }

                    WhirlWindRandom_Timer = urand(3000, 7000);
                } else WhirlWindRandom_Timer -= diff;

                if (WhirlWindEnd_Timer <= diff)
                {
                    WhirlWind = false;
                } else WhirlWindEnd_Timer -= diff;
            }

            if (!WhirlWind)
            {
                if (AggroReset_Timer <= diff)
                {
                    //Attack random Gamers
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true))
                    {
                        me->AddThreat(target, 1.0f);
                        me->TauntApply(target);
                        AttackStart(target);
                    }

                    AggroReset = true;
                    AggroReset_Timer = urand(2000, 5000);
                } else AggroReset_Timer -= diff;

                if (KnockBack_Timer <= diff)
                {
                    DoCast(me, SPELL_WHIRLWINDADD);
                    KnockBack_Timer = urand(10000, 20000);
                } else KnockBack_Timer -= diff;
            }

            if (AggroReset)
            {
                if (AggroResetEnd_Timer <= diff)
                {
                    AggroReset = false;
                    AggroResetEnd_Timer = 5000;
                    AggroReset_Timer = urand(30000, 40000);
                } else AggroResetEnd_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_sartura()
{
    new boss_sartura();
    new mob_sartura_royal_guard();
}
