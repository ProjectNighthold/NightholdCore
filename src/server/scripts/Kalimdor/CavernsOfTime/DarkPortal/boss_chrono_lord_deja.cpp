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
SDName: Boss_Chrono_Lord_Deja
SD%Complete: 65
SDComment: All abilities not implemented
SDCategory: Caverns of Time, The Dark Portal
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "dark_portal.h"

enum eEnums
{
    SAY_ENTER                   = 0,
    SAY_AGGRO                   = 1,
    SAY_BANISH                  = 2,
    SAY_SLAY                    = 3,
    SAY_DEATH                   = 4,

    SPELL_ARCANE_BLAST          = 31457,
    H_SPELL_ARCANE_BLAST        = 38538,
    SPELL_ARCANE_DISCHARGE      = 31472,
    H_SPELL_ARCANE_DISCHARGE    = 38539,
    SPELL_TIME_LAPSE            = 31467,
    SPELL_ATTRACTION            = 38540                       //Not Implemented (Heroic mode)
};

class boss_chrono_lord_deja : public CreatureScript
{
public:
    boss_chrono_lord_deja() : CreatureScript("boss_chrono_lord_deja") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_chrono_lord_dejaAI (creature);
    }

    struct boss_chrono_lord_dejaAI : public ScriptedAI
    {
        boss_chrono_lord_dejaAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 ArcaneBlast_Timer;
        uint32 TimeLapse_Timer;
        uint32 Attraction_Timer;
        uint32 ArcaneDischarge_Timer;

        void Reset()
        {
            ArcaneBlast_Timer = 18000+rand()%5000;
            TimeLapse_Timer = 10000+rand()%5000;
            ArcaneDischarge_Timer = 20000+rand()%10000;
            Attraction_Timer = 25000+rand()%10000;
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
        }

        void MoveInLineOfSight(Unit* who)
        {
            //Despawn Time Keeper
            if (who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == C_TIME_KEEPER)
            {
                if (me->IsWithinDistInMap(who, 20.0f))
                {
                    Talk(SAY_BANISH);
                    me->DealDamage(who, who->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                }
            }

            ScriptedAI::MoveInLineOfSight(who);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);

            if (instance)
                instance->SetData(TYPE_RIFT, SPECIAL);
        }

        void UpdateAI(uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Arcane Blast
            if (ArcaneBlast_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_ARCANE_BLAST);
                ArcaneBlast_Timer = 15000+rand()%10000;
            } else ArcaneBlast_Timer -= diff;

            //Arcane Discharge
            if (ArcaneDischarge_Timer <= diff)
            {
                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                DoCast(target, SPELL_ARCANE_DISCHARGE, false);
                ArcaneDischarge_Timer = 20000+rand()%10000;
            } else ArcaneDischarge_Timer -= diff;

            //Time Lapse
            if (TimeLapse_Timer <= diff)
            {
                Talk(SAY_BANISH);
                DoCast(SPELL_TIME_LAPSE);
                TimeLapse_Timer = 15000+rand()%10000;
            } else TimeLapse_Timer -= diff;

            if (IsHeroic())
            {
                if (Attraction_Timer <= diff)
                {
                    DoCast(SPELL_ATTRACTION);
                    Attraction_Timer = 25000+rand()%10000;
                } else Attraction_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_chrono_lord_deja()
{
    new boss_chrono_lord_deja();
}
