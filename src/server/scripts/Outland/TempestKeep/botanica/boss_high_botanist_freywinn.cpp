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

/* ScriptData
SDName: Boss_High_Botanist_Freywinn
SD%Complete: 90
SDComment: some strange visual related to tree form(if aura lost before normal duration end). possible make summon&transform -process smoother(transform after delay)
SDCategory: Tempest Keep, The Botanica
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum eSays
{
    SAY_AGGRO       = 0,
    SAY_KILL        = 1,
    SAY_TREE        = 2,
    SAY_DEATH       = 3,
};

enum eSpells
{
    SPELL_TRANQUILITY          = 34550,
    SPELL_TREE_FORM            = 34551,
    SPELL_SUMMON_FRAYER        = 34557,
    SPELL_PLANT_WHITE          = 34759,
    SPELL_PLANT_GREEN          = 34761,
    SPELL_PLANT_BLUE           = 34762,
    SPELL_PLANT_RED            = 34763,
};

#define ENTRY_FRAYER                19953

class boss_high_botanist_freywinn : public CreatureScript
{
    public:
        boss_high_botanist_freywinn() : CreatureScript("boss_high_botanist_freywinn") {}

        struct boss_high_botanist_freywinnAI : public ScriptedAI
        {
            boss_high_botanist_freywinnAI(Creature* creature) : ScriptedAI(creature) {}

            GuidList Adds_List;

            uint32 SummonSeedling_Timer;
            uint32 TreeForm_Timer;
            uint32 MoveCheck_Timer;
            uint32 DeadAddsCount;
            bool MoveFree;

            void Reset() override
            {
                Adds_List.clear();

                SummonSeedling_Timer = 6000;
                TreeForm_Timer = 30000;
                MoveCheck_Timer = 1000;
                DeadAddsCount = 0;
                MoveFree = true;
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
            }

            void JustSummoned(Creature* summoned) override
            {
                if (summoned->GetEntry() == ENTRY_FRAYER)
                    Adds_List.push_back(summoned->GetGUID());
            }

            void DoSummonSeedling()
            {
                switch (rand()%4)
                {
                    case 0: DoCast(me, SPELL_PLANT_WHITE); break;
                    case 1: DoCast(me, SPELL_PLANT_GREEN); break;
                    case 2: DoCast(me, SPELL_PLANT_BLUE); break;
                    case 3: DoCast(me, SPELL_PLANT_RED); break;
                }
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_KILL);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (TreeForm_Timer <= diff)
                {
                    Talk(SAY_TREE);

                    if (me->IsNonMeleeSpellCast(false))
                        me->InterruptNonMeleeSpells(true);

                    me->RemoveAllAuras();

                    DoCast(me, SPELL_SUMMON_FRAYER, true);
                    DoCast(me, SPELL_TRANQUILITY, true);
                    DoCast(me, SPELL_TREE_FORM, true);

                    me->GetMotionMaster()->MoveIdle();
                    MoveFree = false;

                    TreeForm_Timer = 75000;
                }
                else
                    TreeForm_Timer -= diff;

                if (!MoveFree)
                {
                    if (MoveCheck_Timer <= diff)
                    {
                        if (!Adds_List.empty())
                        {
                            for (GuidList::iterator itr = Adds_List.begin(); itr != Adds_List.end(); ++itr)
                            {
                                if (Unit* temp = Unit::GetUnit(*me, *itr))
                                {
                                    if (!temp->isAlive())
                                    {
                                        Adds_List.erase(itr);
                                        ++DeadAddsCount;
                                        break;
                                    }
                                }
                            }
                        }

                        if (DeadAddsCount < 3 && TreeForm_Timer-30000 <= diff)
                            DeadAddsCount = 3;

                        if (DeadAddsCount >= 3)
                        {
                            Adds_List.clear();
                            DeadAddsCount = 0;

                            me->InterruptNonMeleeSpells(true);
                            me->RemoveAllAuras();
                            me->GetMotionMaster()->MoveChase(me->getVictim());
                            MoveFree = true;
                        }
                        MoveCheck_Timer = 500;
                    }
                    else
                        MoveCheck_Timer -= diff;

                    return;
                }

                /*if (me->HasAura(SPELL_TREE_FORM, 0) || me->HasAura(SPELL_TRANQUILITY, 0))
                    return;*/

                //one random seedling every 5 secs, but not in tree form
                if (SummonSeedling_Timer <= diff)
                {
                    DoSummonSeedling();
                    SummonSeedling_Timer = 6000;
                }
                else
                    SummonSeedling_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_high_botanist_freywinnAI(creature);
        }
};

void AddSC_boss_high_botanist_freywinn()
{
    new boss_high_botanist_freywinn();
}

