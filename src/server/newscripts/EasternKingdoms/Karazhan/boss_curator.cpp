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
SDName: Boss_Curator
SD%Complete: 100
SDComment:
SDCategory: Karazhan
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_SUMMON,
    SAY_EVOCATE,
    SAY_ENRAGE,
    SAY_KILL,
    SAY_DEATH
};

//Flare spell info
#define SPELL_ASTRAL_FLARE_PASSIVE      30234               //Visual effect + Flare damage

//Curator spell info
#define SPELL_HATEFUL_BOLT              30383
#define SPELL_EVOCATION                 30254
#define SPELL_ENRAGE                    30403               //Arcane Infusion: Transforms Curator and adds damage.
#define SPELL_BERSERK                   26662

class boss_curator : public CreatureScript
{
public:
    boss_curator() : CreatureScript("boss_curator") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_curatorAI (creature);
    }

    struct boss_curatorAI : public ScriptedAI
    {
        boss_curatorAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 AddTimer;
        uint32 HatefulBoltTimer;
        uint32 BerserkTimer;

        bool Enraged;
        bool Evocating;

        void Reset() override
        {
            AddTimer = 10000;
            HatefulBoltTimer = 15000;                           //This time may be wrong
            BerserkTimer = 720000;                              //12 minutes
            Enraged = false;
            Evocating = false;

            me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_ARCANE, true);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_KILL);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            //always decrease BerserkTimer
            if (BerserkTimer <= diff)
            {
                //if evocate, then break evocate
                if (Evocating)
                {
                    if (me->HasAura(SPELL_EVOCATION))
                        me->RemoveAurasDueToSpell(SPELL_EVOCATION);

                    Evocating = false;
                }

                //may not be correct SAY (generic hard enrage)
                Talk(SAY_ENRAGE);

                me->InterruptNonMeleeSpells(true);
                DoCast(SPELL_BERSERK);

                //don't know if he's supposed to do summon/evocate after hard enrage (probably not)
                Enraged = true;
            } else BerserkTimer -= diff;

            if (Evocating)
            {
                //not supposed to do anything while evocate
                if (me->HasAura(SPELL_EVOCATION))
                    return;
                else
                    Evocating = false;
            }

            if (!Enraged)
            {
                if (AddTimer <= diff)
                {
                    //Summon Astral Flare
                    Creature* AstralFlare = DoSpawnCreature(17096, float(rand()%37), float(rand()%37), 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    Unit* target = NULL;
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0);

                    if (AstralFlare && target)
                    {
                        AstralFlare->CastSpell(AstralFlare, SPELL_ASTRAL_FLARE_PASSIVE, false);
                        AstralFlare->AI()->AttackStart(target);
                    }

                    //Reduce Mana by 10% of max health
                    if (int32 mana = me->GetMaxPower(POWER_MANA))
                    {
                        mana /= 10;
                        me->ModifyPower(POWER_MANA, -mana);

                        //if this get's us below 10%, then we evocate (the 10th should be summoned now)
                        if (me->GetPower(POWER_MANA)*100 / me->GetMaxPower(POWER_MANA) < 10)
                        {
                            Talk(SAY_EVOCATE);
                            me->InterruptNonMeleeSpells(false);
                            DoCast(me, SPELL_EVOCATION);
                            Evocating = true;
                            //no AddTimer cooldown, this will make first flare appear instantly after evocate end, like expected
                            return;
                        }
                        else
                        {
                            if (urand(0, 1) == 0)
                                Talk(SAY_SUMMON);
                        }
                    }

                    AddTimer = 10000;
                }
                else
                    AddTimer -= diff;

                if (!HealthAbovePct(15))
                {
                    Enraged = true;
                    DoCast(me, SPELL_ENRAGE, false);
                    Talk(SAY_ENRAGE);
                }
            }

            if (HatefulBoltTimer <= diff)
            {
                if (Enraged)
                    HatefulBoltTimer = 7000;
                else
                    HatefulBoltTimer = 15000;

                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 1))
                    DoCast(target, SPELL_HATEFUL_BOLT, false);

            }
            else
                HatefulBoltTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_curator()
{
    new boss_curator();
}
