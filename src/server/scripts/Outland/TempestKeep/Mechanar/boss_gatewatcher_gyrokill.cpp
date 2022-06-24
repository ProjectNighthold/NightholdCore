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
SDName: boss_gatewatcher_gyrokill
SD%Complete: 99%
SDComment:
SDCategory: Tempest Keep, The Mechanar
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "mechanar.h"

enum Say
{
    SAY_AGGRO                       = 0,
    SAY_SLAY                        = 1,
    SAY_SAW_BLADEs                  = 2,
    SAY_DEATH                       = 3
};

enum Spells
{
    SPELL_STREAM_OF_MACHINE_FLUID   = 35311,
    SPELL_SAW_BLADE                 = 35318,
    H_SPELL_SAW_BLADE               = 39192,
    SPELL_SHADOW_POWER              = 35322,
    H_SPELL_SHADOW_POWER            = 39193
};

enum Events
{
    EVENT_STREAM_OF_MACHINE_FLUID   = 1,
    EVENT_SAW_BLADE                 = 2,
    EVENT_SHADOW_POWER              = 3
};

class boss_gatewatcher_gyrokill : public CreatureScript
{
    public:
        boss_gatewatcher_gyrokill() : CreatureScript("boss_gatewatcher_gyrokill") { }

        struct boss_gatewatcher_gyrokillAI : public BossAI
        {
            boss_gatewatcher_gyrokillAI(Creature* creature) : BossAI(creature, DATA_GATEWATCHER_GYROKILL)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
                if (instance)
                {
                    if (GameObject* cache = GameObject::GetGameObject(*me, instance->GetGuidData(DATA_GO_CHAHCE_LEGION)))
                        cache->RemoveFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_LOCKED);
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_STREAM_OF_MACHINE_FLUID, 10000);
                events.ScheduleEvent(EVENT_SAW_BLADE, 20000);
                events.ScheduleEvent(EVENT_SHADOW_POWER, 25000);
                Talk(SAY_AGGRO);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                Talk(SAY_SLAY);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STREAM_OF_MACHINE_FLUID:
                            DoCastVictim(SPELL_STREAM_OF_MACHINE_FLUID, true);
                            events.ScheduleEvent(EVENT_STREAM_OF_MACHINE_FLUID, urand(13000, 17000));
                            break;
                        case EVENT_SAW_BLADE:
                            DoCast(me, SPELL_SAW_BLADE);
                            Talk(SAY_SAW_BLADEs);
                            events.ScheduleEvent(EVENT_SAW_BLADE, urand(20000, 30000));
                            break;
                        case EVENT_SHADOW_POWER:
                            DoCast(me, SPELL_SHADOW_POWER);
                            events.ScheduleEvent(EVENT_SAW_BLADE, urand(25000, 35000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_gatewatcher_gyrokillAI(creature);
        }
};

void AddSC_boss_gatewatcher_gyrokill()
{
    new boss_gatewatcher_gyrokill();
}