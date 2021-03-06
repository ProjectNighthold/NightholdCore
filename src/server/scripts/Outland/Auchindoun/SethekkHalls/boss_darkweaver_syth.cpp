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
SDName: Boss_Darkweaver_Syth
SD%Complete: 85
SDComment: Shock spells/times need more work. Heroic partly implemented.
SDCategory: Auchindoun, Sethekk Halls
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Says
{
    SAY_SUMMON = 0,
    SAY_AGGRO,
    SAY_SLAY,
    SAY_DEATH
};

#define SPELL_FROST_SHOCK           21401 //37865
#define SPELL_FLAME_SHOCK           34354
#define SPELL_SHADOW_SHOCK          30138
#define SPELL_ARCANE_SHOCK          37132

#define SPELL_CHAIN_LIGHTNING       15659 //15305

#define SPELL_SUMMON_SYTH_FIRE      33537                   // Spawns 19203
#define SPELL_SUMMON_SYTH_ARCANE    33538                   // Spawns 19205
#define SPELL_SUMMON_SYTH_FROST     33539                   // Spawns 19204
#define SPELL_SUMMON_SYTH_SHADOW    33540                   // Spawns 19206

#define SPELL_FLAME_BUFFET          DUNGEON_MODE(33526, 38141)
#define SPELL_ARCANE_BUFFET         DUNGEON_MODE(33527, 38138)
#define SPELL_FROST_BUFFET          DUNGEON_MODE(33528, 38142)
#define SPELL_SHADOW_BUFFET         DUNGEON_MODE(33529, 38143)

class boss_darkweaver_syth : public CreatureScript
{
public:
    boss_darkweaver_syth() : CreatureScript("boss_darkweaver_syth") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_darkweaver_sythAI (creature);
    }

    struct boss_darkweaver_sythAI : public ScriptedAI
    {
        boss_darkweaver_sythAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 flameshock_timer;
        uint32 arcaneshock_timer;
        uint32 frostshock_timer;
        uint32 shadowshock_timer;
        uint32 chainlightning_timer;

        bool summon90;
        bool summon50;
        bool summon10;

        void Reset() override
        {
            flameshock_timer = 2000;
            arcaneshock_timer = 4000;
            frostshock_timer = 6000;
            shadowshock_timer = 8000;
            chainlightning_timer = 15000;

            summon90 = false;
            summon50 = false;
            summon10 = false;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            if (rand()%2)
                return;

            Talk(SAY_SLAY);
        }

        void JustSummoned(Creature* summoned) override
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                summoned->AI()->AttackStart(target);
        }

        void SythSummoning()
        {
            Talk(SAY_SUMMON);

            if (me->IsNonMeleeSpellCast(false))
                me->InterruptNonMeleeSpells(false);

            DoCast(me, SPELL_SUMMON_SYTH_ARCANE, true);   //front
            DoCast(me, SPELL_SUMMON_SYTH_FIRE, true);     //back
            DoCast(me, SPELL_SUMMON_SYTH_FROST, true);    //left
            DoCast(me, SPELL_SUMMON_SYTH_SHADOW, true);   //right
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (HealthBelowPct(90) && !summon90)
            {
                SythSummoning();
                summon90 = true;
            }

            if (HealthBelowPct(50) && !summon50)
            {
                SythSummoning();
                summon50 = true;
            }

            if (HealthBelowPct(10) && !summon10)
            {
                SythSummoning();
                summon10 = true;
            }

            if (flameshock_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_FLAME_SHOCK, false);

                flameshock_timer = urand(10000, 15000);
            }
            else
                flameshock_timer -= diff;

            if (arcaneshock_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_ARCANE_SHOCK, false);

                arcaneshock_timer = urand(10000, 15000);
            } else arcaneshock_timer -= diff;

            if (frostshock_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_FROST_SHOCK, false);

                frostshock_timer = urand(10000, 15000);
            }
            else
                frostshock_timer -= diff;

            if (shadowshock_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_SHADOW_SHOCK);

                shadowshock_timer = urand(10000, 15000);
            }
            else
                shadowshock_timer -= diff;

            if (chainlightning_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_CHAIN_LIGHTNING, false);

                chainlightning_timer = 25000;
            }
            else
                chainlightning_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

/* ELEMENTALS */
class mob_syth_fire : public CreatureScript
{
public:
    mob_syth_fire() : CreatureScript("mob_syth_fire") {}

    struct mob_syth_fireAI : public ScriptedAI
    {
        mob_syth_fireAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 flameshock_timer;
        uint32 flamebuffet_timer;

        void Reset() override
        {
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
            flameshock_timer = 2500;
            flamebuffet_timer = 5000;
        }

        void EnterCombat(Unit* /*who*/) override {}

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (flameshock_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_FLAME_SHOCK, false);

                flameshock_timer = 5000;
            }
            else
                flameshock_timer -= diff;

            if (flamebuffet_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_FLAME_BUFFET, false);

                flamebuffet_timer = 5000;
            }
            else
                flamebuffet_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_syth_fireAI (creature);
    }
};

class mob_syth_arcane : public CreatureScript
{
public:
    mob_syth_arcane() : CreatureScript("mob_syth_arcane") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_syth_arcaneAI (creature);
    }

    struct mob_syth_arcaneAI : public ScriptedAI
    {
        mob_syth_arcaneAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 arcaneshock_timer;
        uint32 arcanebuffet_timer;

        void Reset() override
        {
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, true);
            arcaneshock_timer = 2500;
            arcanebuffet_timer = 5000;
        }

        void EnterCombat(Unit* /*who*/) override {}

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (arcaneshock_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_ARCANE_SHOCK, false);

                arcaneshock_timer = 5000;
            } 
            else
                arcaneshock_timer -= diff;

            if (arcanebuffet_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_ARCANE_BUFFET, false);

                arcanebuffet_timer = 5000;
            }
            else
                arcanebuffet_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class mob_syth_frost : public CreatureScript
{
public:
    mob_syth_frost() : CreatureScript("mob_syth_frost") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_syth_frostAI (creature);
    }

    struct mob_syth_frostAI : public ScriptedAI
    {
        mob_syth_frostAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 frostshock_timer;
        uint32 frostbuffet_timer;

        void Reset() override
        {
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
            frostshock_timer = 2500;
            frostbuffet_timer = 5000;
        }

        void EnterCombat(Unit* /*who*/) override {}

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (frostshock_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_FROST_SHOCK);

                frostshock_timer = 5000;
            }
            else
                frostshock_timer -= diff;

            if (frostbuffet_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_FROST_BUFFET, false);

                frostbuffet_timer = 5000;
            }
            else
                frostbuffet_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class mob_syth_shadow : public CreatureScript
{
public:
    mob_syth_shadow() : CreatureScript("mob_syth_shadow") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_syth_shadowAI (creature);
    }

    struct mob_syth_shadowAI : public ScriptedAI
    {
        mob_syth_shadowAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 shadowshock_timer;
        uint32 shadowbuffet_timer;

        void Reset() override
        {
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_SHADOW, true);
            shadowshock_timer = 2500;
            shadowbuffet_timer = 5000;
        }

        void EnterCombat(Unit* /*who*/) override {}

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (shadowshock_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_SHADOW_SHOCK);

                shadowshock_timer = 5000;
            }
            else
                shadowshock_timer -= diff;

            if (shadowbuffet_timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_SHADOW_BUFFET, false);

                shadowbuffet_timer = 5000;
            }
            else
                shadowbuffet_timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_darkweaver_syth()
{
    new boss_darkweaver_syth();
    new mob_syth_fire();
    new mob_syth_arcane();
    new mob_syth_frost();
    new mob_syth_shadow();
}
