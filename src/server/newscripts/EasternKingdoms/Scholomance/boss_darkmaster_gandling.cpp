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
SDName: Boss_Darkmaster_Gandling
SD%Complete: 75
SDComment: Doors missing in instance script.
SDCategory: Scholomance
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "scholomance.h"

enum Spells
{
    SPELL_INCINERATE  = 113136,
    SPELL_IMMOLATE    = 113141,
    SPELL_RISE        = 113143,
    SPELL_FIRE_DUMMY  = 114910,
};

class boss_darkmaster_gandling : public CreatureScript
{
public:
    boss_darkmaster_gandling() : CreatureScript("boss_darkmaster_gandling") { }

    struct boss_darkmaster_gandlingAI : public BossAI
    {
        boss_darkmaster_gandlingAI(Creature* creature) : BossAI(creature, DATA_DARKMASTER)
        {
            InstanceScript* instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 incinerate;
        uint32 immolate;
        uint32 rise;

        void Reset()
        {
           _Reset();
           if (!me->HasAura(SPELL_FIRE_DUMMY))
               me->AddAura(SPELL_FIRE_DUMMY, me);
           me->SetReactState(REACT_DEFENSIVE);
           incinerate = 0;
           immolate = 0;
           rise = 0;

        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            if (me->HasAura(SPELL_FIRE_DUMMY))
                me->RemoveAurasDueToSpell(SPELL_FIRE_DUMMY);
            incinerate = 3000;
            immolate = 10000;
            rise = 20000;
        }

       /* void JustSummond(Creature* summon)
        {
            summons.Summon(summon);
            DoZoneInCombat(summon, 75.0f);
        }*/

        void JustDied(Unit* /*killer*/)
        {
          _JustDied();
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (rise <= diff)
            {
                DoCast(me, SPELL_RISE);
                rise = 20000; 
            }
            else
                rise -= diff;

            if (immolate <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                    DoCast(target, SPELL_IMMOLATE);
                immolate = 10000;
            }
            else
                immolate -= diff;

            if (incinerate <= diff)
            {
                if (me->getVictim())
                    DoCast(me->getVictim(), SPELL_INCINERATE);
                incinerate = 3000; 
            }
            else
                incinerate -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_darkmaster_gandlingAI (creature);
    }

};

class npc_failed_student : public CreatureScript
{
    public:
        npc_failed_student() : CreatureScript("npc_failed_student") {}

        struct npc_failed_studentAI : public ScriptedAI
        {
            npc_failed_studentAI(Creature* creature) : ScriptedAI(creature)
            {
                InstanceScript* instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            
            void Reset()
            {
                DoZoneInCombat(me, 75.0f);
            }

            void UpdateAI(uint32 diff)
            {
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_failed_studentAI(creature);
        }
};

void AddSC_boss_darkmaster_gandling()
{
    new boss_darkmaster_gandling();
    new npc_failed_student();
}
