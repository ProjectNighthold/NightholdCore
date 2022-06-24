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

#include "nexus.h"

enum Spells
{
    SPELL_ICE_NOVA                                  = 47772,
    H_SPELL_ICE_NOVA                                = 56935,
    SPELL_FIREBOMB                                  = 47773,
    H_SPELL_FIREBOMB                                = 56934,
    SPELL_GRAVITY_WELL                              = 47756,
    SPELL_TELESTRA_BACK                             = 47714,

    SPELL_FIRE_MAGUS_VISUAL                         = 47705,
    SPELL_FROST_MAGUS_VISUAL                        = 47706,
    SPELL_ARCANE_MAGUS_VISUAL                       = 47704
};

enum Creatures
{
    MOB_FIRE_MAGUS                                  = 26928,
    MOB_FROST_MAGUS                                 = 26930,
    MOB_ARCANE_MAGUS                                = 26929
};

enum Yells
{
    SAY_AGGRO                                       = 0,
    SAY_KILL                                        = 1,
    SAY_DEATH                                       = 2,
    SAY_MERGE                                       = 3,
    SAY_SPLIT                                       = 4
};

#define ACTION_MAGUS_DEAD                           1
#define DATA_SPLIT_PERSONALITY                      2

const Position  CenterOfRoom = {504.80f, 89.07f, -16.12f, 6.27f};

class boss_magus_telestra : public CreatureScript
{
public:
    boss_magus_telestra() : CreatureScript("boss_magus_telestra") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_magus_telestraAI (creature);
    }

    struct boss_magus_telestraAI : public ScriptedAI
    {
        boss_magus_telestraAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        ObjectGuid uiFireMagusGUID;
        ObjectGuid uiFrostMagusGUID;
        ObjectGuid uiArcaneMagusGUID;

        bool Split;
        bool bFireMagusDead;
        bool bFrostMagusDead;
        bool bArcaneMagusDead;
        bool bIsWaitingToAppear;

        uint32 CheckPersonal;
        uint32 uiIsWaitingToAppearTimer;
        uint32 uiIceNovaTimer;
        uint32 uiFireBombTimer;
        uint32 uiGravityWellTimer;
        uint32 uiCooldown;

        uint8 Phase;
        uint8 splitPersonality;
        time_t time[3];

        void Reset() override
        {
            Phase = 0;
            //These times are probably wrong
            uiIceNovaTimer =  7*IN_MILLISECONDS;
            uiFireBombTimer =  0;
            uiGravityWellTimer = 15*IN_MILLISECONDS;
            uiCooldown = 0;
            CheckPersonal = 0;

            uiFireMagusGUID.Clear();
            uiFrostMagusGUID.Clear();
            uiArcaneMagusGUID.Clear();

            for (uint8 n = 0; n < 3; ++n)
                time[n] = 0;

            splitPersonality = 0;
            Split = false;
            bIsWaitingToAppear = false;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetVisible(true);

            if (instance)
                instance->SetData(DATA_MAGUS_TELESTRA_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);

            if (instance)
                instance->SetData(DATA_MAGUS_TELESTRA_EVENT, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(DATA_MAGUS_TELESTRA_EVENT, DONE);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(SAY_KILL);
        }

        void DoAction(int32 const action) override
        {
            switch (action)
            {
            case ACTION_MAGUS_DEAD:
                splitPersonality++;
                if (!CheckPersonal)
                    CheckPersonal = 5000;
                else
                {
                    CheckPersonal = 0;
                    CheckPersonal = 5000;
                }
                break;
            }
        }
        
       bool GetSplit()
       {
           return Split;
       }

       uint32 GetCheckPersonal()
       {
           return CheckPersonal;
       }

        ObjectGuid SplitPersonality(uint32 entry)
        {
            if (Creature* Summoned = me->SummonCreature(entry, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 1*IN_MILLISECONDS))
            {
                switch (entry)
                {
                    case MOB_FIRE_MAGUS:
                    {
                        Summoned->CastSpell(Summoned, SPELL_FIRE_MAGUS_VISUAL, false);
                        break;
                    }
                    case MOB_FROST_MAGUS:
                    {
                        Summoned->CastSpell(Summoned, SPELL_FROST_MAGUS_VISUAL, false);
                        break;
                    }
                    case MOB_ARCANE_MAGUS:
                    {
                        Summoned->CastSpell(Summoned, SPELL_ARCANE_MAGUS_VISUAL, false);
                        break;
                    }
                }
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    Summoned->AI()->AttackStart(target);
                return Summoned->GetGUID();
            }
            return ObjectGuid::Empty;
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            if (summon->isAlive())
                return;

            if (summon->GetGUID() == uiFireMagusGUID)
            {
                me->AI()->DoAction(ACTION_MAGUS_DEAD);
                bFireMagusDead = true;
            }
            else if (summon->GetGUID() == uiFrostMagusGUID)
            {
                me->AI()->DoAction(ACTION_MAGUS_DEAD);
                bFrostMagusDead = true;
            }
            else if (summon->GetGUID() == uiArcaneMagusGUID)
            {
                me->AI()->DoAction(ACTION_MAGUS_DEAD);
                bArcaneMagusDead = true;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (CheckPersonal)
            {
                if (CheckPersonal <= diff)
                {
                    if (splitPersonality == 3 && !Split)
                    {
                        Split = true;
                        CheckPersonal = 0;
                        splitPersonality = 0;
                    }
                    else
                    {
                        splitPersonality = 0;
                        CheckPersonal = 0;

                    }
                }
                else CheckPersonal -= diff;
            }

            if (bIsWaitingToAppear)
            {
                me->StopMoving();
                me->AttackStop();
                if (uiIsWaitingToAppearTimer <= diff)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    bIsWaitingToAppear = false;
                } else uiIsWaitingToAppearTimer -= diff;
                return;
            }

            if ((Phase == 1) ||(Phase == 3))
            {
                if (bFireMagusDead && bFrostMagusDead && bArcaneMagusDead)
                {
                    for (uint8 n = 0; n < 3; ++n)
                        time[n] = 0;
                    me->GetMotionMaster()->Clear();
                    me->SetPosition(CenterOfRoom.GetPositionX(), CenterOfRoom.GetPositionY(), CenterOfRoom.GetPositionZ(), CenterOfRoom.GetOrientation());
                    DoCast(me, SPELL_TELESTRA_BACK);
                    me->SetVisible(true);
                    if (Phase == 1)
                        Phase = 2;
                    if (Phase == 3)
                        Phase = 4;
                    uiFireMagusGUID.Clear();
                    uiFrostMagusGUID.Clear();
                    uiArcaneMagusGUID.Clear();
                    bIsWaitingToAppear = true;
                    uiIsWaitingToAppearTimer = 4*IN_MILLISECONDS;
                    Talk(SAY_MERGE);
                }
                else
                    return;
            }

            if ((Phase == 0) && HealthBelowPct(50))
            {
                Phase = 1;
                me->CastStop();
                me->RemoveAllAuras();
                me->SetVisible(false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                uiFireMagusGUID = SplitPersonality(MOB_FIRE_MAGUS);
                uiFrostMagusGUID = SplitPersonality(MOB_FROST_MAGUS);
                uiArcaneMagusGUID = SplitPersonality(MOB_ARCANE_MAGUS);
                bFireMagusDead = false;
                bFrostMagusDead = false;
                bArcaneMagusDead = false;
                Talk(SAY_SPLIT);
                return;
            }

            if (IsHeroic() && (Phase == 2) && HealthBelowPct(10))
            {
                Phase = 3;
                me->CastStop();
                me->RemoveAllAuras();
                me->SetVisible(false);
                Split = false;
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                uiFireMagusGUID = SplitPersonality(MOB_FIRE_MAGUS);
                uiFrostMagusGUID = SplitPersonality(MOB_FROST_MAGUS);
                uiArcaneMagusGUID = SplitPersonality(MOB_ARCANE_MAGUS);
                bFireMagusDead = false;
                bFrostMagusDead = false;
                bArcaneMagusDead = false;
                Talk(SAY_SPLIT);
                return;
            }

            if (uiCooldown)
            {
                if (uiCooldown <= diff)
                    uiCooldown = 0;
                else
                {
                    uiCooldown -= diff;
                    return;
                }
            }

            if (uiIceNovaTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    DoCast(target, SPELL_ICE_NOVA, false);
                    uiCooldown = 1500;
                }
                uiIceNovaTimer = 15*IN_MILLISECONDS;
            } else uiIceNovaTimer -= diff;

            if (uiGravityWellTimer <= diff)
            {
                if (Unit* target = me->getVictim())
                {
                    DoCast(target, SPELL_GRAVITY_WELL);
                    uiCooldown = 6*IN_MILLISECONDS;
                }
                uiGravityWellTimer = 15*IN_MILLISECONDS;
            } else uiGravityWellTimer -= diff;

            if (uiFireBombTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    DoCast(target, SPELL_FIREBOMB, false);
                    uiCooldown = 2*IN_MILLISECONDS;
                }
                uiFireBombTimer = 2*IN_MILLISECONDS;
            } else uiFireBombTimer -=diff;

            DoMeleeAttackIfReady();
        }
    };

};

class achievement_split_personality : public AchievementCriteriaScript
{
    public:
        achievement_split_personality() : AchievementCriteriaScript("achievement_split_personality")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Tel = target->ToCreature())
                if (boss_magus_telestra::boss_magus_telestraAI * TelAI = CAST_AI(boss_magus_telestra::boss_magus_telestraAI, Tel->AI()))
                    if (TelAI->GetSplit())
                        return true;

            return false;
        }
};

void AddSC_boss_magus_telestra()
{
    new boss_magus_telestra();
    new achievement_split_personality();
}
