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
SDName: Boss_Selin_Fireheart
SD%Complete: 90
SDComment: Heroic and Normal Support. Needs further testing.
SDCategory: Magister's Terrace
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "magisters_terrace.h"

//Crystal effect spells
#define SPELL_FEL_CRYSTAL_COSMETIC      44374
#define SPELL_FEL_CRYSTAL_DUMMY         44329
#define SPELL_FEL_CRYSTAL_VISUAL        44355
#define SPELL_MANA_RAGE                 44320

//Selin's spells
#define SPELL_DRAIN_LIFE                44294
#define SPELL_FEL_EXPLOSION             44314

#define SPELL_DRAIN_MANA                46153               // Heroic only

#define CRYSTALS_NUMBER                 5
#define DATA_CRYSTALS                   6

#define CREATURE_FEL_CRYSTAL            24722

enum Texts
{
    SAY_AGGRO                           = 0,
    SAY_ENERGY                          = 1,
    SAY_EMPOWERED                       = 2,
    SAY_KILL_1                          = 3,
    SAY_KILL_2                          = 4,
    SAY_DEATH                           = 5,
    EMOTE_CRYSTAL                       = 6,
};

class boss_selin_fireheart : public CreatureScript
{
public:
    boss_selin_fireheart() : CreatureScript("boss_selin_fireheart") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_selin_fireheartAI (creature);
    };

    struct boss_selin_fireheartAI : public ScriptedAI
    {
        boss_selin_fireheartAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            Crystals.clear();
            if (instance)
            {
                uint32 size = instance->GetData(DATA_FEL_CRYSTAL_SIZE);
                for (uint8 i = 0; i < size; ++i)
                {
                    ObjectGuid guid = instance->GetGuidData(DATA_FEL_CRYSTAL);
                    TC_LOG_DEBUG(LOG_FILTER_TSCR, "Selin: Adding Fel Crystal " UI64FMTD " to list", guid.GetCounter());
                    Crystals.push_back(guid);
                }
            }
        }

        InstanceScript* instance;

        GuidList Crystals;

        uint32 DrainLifeTimer;
        uint32 DrainManaTimer;
        uint32 FelExplosionTimer;
        uint32 DrainCrystalTimer;
        uint32 EmpowerTimer;

        bool IsDraining;
        bool DrainingCrystal;

        ObjectGuid CrystalGUID;

        void Reset()
        {

            if (instance)
            {
                for (GuidList::const_iterator itr = Crystals.begin(); itr != Crystals.end(); ++itr)
                {
                    Unit* unit = Unit::GetUnit(*me, *itr);
                    if (unit)
                    {
                        if (!unit->isAlive())
                            CAST_CRE(unit)->Respawn();

                        unit->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }
                }

                instance->HandleGameObject(instance->GetGuidData(DATA_SELIN_ENCOUNTER_DOOR), true);
                instance->SetData(DATA_SELIN_EVENT, NOT_STARTED);
            } else TC_LOG_ERROR(LOG_FILTER_TSCR, ERROR_INST_DATA);

            DrainLifeTimer = urand(3000, 7000);
            DrainManaTimer = DrainLifeTimer + 5000;
            FelExplosionTimer = 2100;
            if (IsHeroic())
                DrainCrystalTimer = urand(10000, 15000);
            else
                DrainCrystalTimer = urand(20000, 25000);
            EmpowerTimer = 10000;

            IsDraining = false;
            DrainingCrystal = false;
            CrystalGUID.Clear();
        }

        void SelectNearestCrystal()
        {
            if (Crystals.empty())
                return;

            CrystalGUID.Clear();
            Unit* pCrystal = NULL;
            Unit* CrystalChosen = NULL;
            for (GuidList::const_iterator itr = Crystals.begin(); itr != Crystals.end(); ++itr)
            {
                pCrystal = NULL;
                pCrystal = Unit::GetUnit(*me, *itr);
                if (pCrystal && pCrystal->isAlive())
                {
                    if (!CrystalChosen || me->GetDistanceOrder(pCrystal, CrystalChosen, false))
                    {
                        CrystalGUID = pCrystal->GetGUID();
                        CrystalChosen = pCrystal;
                    }
                }
            }
            if (CrystalChosen)
            {
                Talk(SAY_ENERGY);
                Talk(EMOTE_CRYSTAL);

                CrystalChosen->CastSpell(CrystalChosen, SPELL_FEL_CRYSTAL_COSMETIC, true);

                float x, y, z;
                CrystalChosen->GetClosePoint(x, y, z, me->GetObjectSize(), CONTACT_DISTANCE);

                me->SetWalk(false);
                me->GetMotionMaster()->MovePoint(1, x, y, z);

                me->AddDelayedEvent(2500, [this] {
                    DrainingCrystal = true;
                });
                
            }
        }

        void ShatterRemainingCrystals()
        {
            if (Crystals.empty())
                return;

            for (GuidList::const_iterator itr = Crystals.begin(); itr != Crystals.end(); ++itr)
            {
                Creature* pCrystal = Unit::GetCreature(*me, *itr);
                if (pCrystal && pCrystal->isAlive())
                    pCrystal->Kill(pCrystal);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->SetPower(POWER_MANA, 0);
            Talk(SAY_AGGRO);

            if (instance)
                instance->HandleGameObject(instance->GetGuidData(DATA_SELIN_ENCOUNTER_DOOR), false);
         }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(RAND(SAY_KILL_1, SAY_KILL_2));
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type == POINT_MOTION_TYPE && id == 1)
            {
                Unit* CrystalChosen = Unit::GetUnit(*me, CrystalGUID);
                if (CrystalChosen && CrystalChosen->isAlive())
                {
                    CrystalChosen->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
                    CrystalChosen->CastSpell(me, SPELL_MANA_RAGE, true);
                    IsDraining = true;
                }
                else
                {
                    TC_LOG_ERROR(LOG_FILTER_TSCR, "Selin Fireheart unable to drain crystal as the crystal is either dead or despawned");
                    DrainingCrystal = false;
                }
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);

            if (!instance)
                return;

            instance->SetData(DATA_SELIN_EVENT, DONE);
            instance->HandleGameObject(instance->GetGuidData(DATA_SELIN_ENCOUNTER_DOOR), true);
            instance->HandleGameObject(instance->GetGuidData(DATA_SELIN_DOOR), true);
            ShatterRemainingCrystals();
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (!DrainingCrystal)
            {
                uint32 maxPowerMana = me->GetMaxPower(POWER_MANA);
                if (maxPowerMana && ((me->GetPower(POWER_MANA)*100 / maxPowerMana) < 10))
                {
                    if (DrainLifeTimer <= diff)
                    {
                        DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_DRAIN_LIFE);
                        DrainLifeTimer = 10000;
                    } else DrainLifeTimer -= diff;

                    // Heroic only
                    if (IsHeroic())
                    {
                        if (DrainManaTimer <= diff)
                        {
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 1), SPELL_DRAIN_MANA);
                            DrainManaTimer = 10000;
                        } else DrainManaTimer -= diff;
                    }
                }

                if (FelExplosionTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCast(false))
                    {
                        DoCast(me, SPELL_FEL_EXPLOSION);
                        FelExplosionTimer = 2000;
                    }
                } else FelExplosionTimer -= diff;

                // If below 10% mana, start recharging
                maxPowerMana = me->GetMaxPower(POWER_MANA);
                if (maxPowerMana && ((me->GetPower(POWER_MANA)*100 / maxPowerMana) < 10))
                {
                    if (DrainCrystalTimer <= diff)
                    {
                        SelectNearestCrystal();
                        if (IsHeroic())
                            DrainCrystalTimer = urand(10000, 15000);
                        else
                            DrainCrystalTimer = urand(20000, 25000);
                    } else DrainCrystalTimer -= diff;
                }

            }else
            {
                if (IsDraining)
                {
                    if (EmpowerTimer <= diff)
                    {
                        IsDraining = false;
                        DrainingCrystal = false;

                        Talk(SAY_EMPOWERED);

                        Unit* CrystalChosen = Unit::GetUnit(*me, CrystalGUID);
                        if (CrystalChosen && CrystalChosen->isAlive())
                            CrystalChosen->Kill(CrystalChosen);

                        CrystalGUID.Clear();

                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveChase(me->getVictim());
                    } else EmpowerTimer -= diff;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class mob_fel_crystal : public CreatureScript
{
public:
    mob_fel_crystal() : CreatureScript("mob_fel_crystal") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_fel_crystalAI (creature);
    };

    struct mob_fel_crystalAI : public ScriptedAI
    {
        mob_fel_crystalAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() {}
        void EnterCombat(Unit* /*who*/) {}
        void AttackStart(Unit* /*who*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}
        void UpdateAI(uint32 /*diff*/) {}

        void JustDied(Unit* /*killer*/)
        {
            if (InstanceScript* instance = me->GetInstanceScript())
            {
                Creature* Selin = (Unit::GetCreature(*me, instance->GetGuidData(DATA_SELIN)));
                if (Selin && Selin->isAlive())
                {
                    if (CAST_AI(boss_selin_fireheart::boss_selin_fireheartAI, Selin->AI())->CrystalGUID == me->GetGUID())
                    {
                        CAST_AI(boss_selin_fireheart::boss_selin_fireheartAI, Selin->AI())->DrainingCrystal = false;
                        CAST_AI(boss_selin_fireheart::boss_selin_fireheartAI, Selin->AI())->IsDraining = false;
                        CAST_AI(boss_selin_fireheart::boss_selin_fireheartAI, Selin->AI())->EmpowerTimer = 10000;
                        if (Selin->getVictim())
                        {
                            Selin->AI()->AttackStart(Selin->getVictim());
                            Selin->GetMotionMaster()->MoveChase(Selin->getVictim());
                        }
                    }
                }
            } else TC_LOG_ERROR(LOG_FILTER_TSCR, ERROR_INST_DATA);
        }
    };

};

void AddSC_boss_selin_fireheart()
{
    new boss_selin_fireheart();
    new mob_fel_crystal();
}
