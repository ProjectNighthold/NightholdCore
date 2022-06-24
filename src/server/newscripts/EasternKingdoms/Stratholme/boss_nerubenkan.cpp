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
SDName: Boss_Nerubenkan
SD%Complete: 70
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

#define SPELL_ENCASINGWEBS          4962
#define SPELL_PIERCEARMOR           6016
#define SPELL_CRYPT_SCARABS         31602
#define SPELL_RAISEUNDEADSCARAB     17235

class boss_nerubenkan : public CreatureScript
{
public:
    boss_nerubenkan() : CreatureScript("boss_nerubenkan") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_nerubenkanAI (creature);
    }

    struct boss_nerubenkanAI : public ScriptedAI
    {
        boss_nerubenkanAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 EncasingWebs_Timer;
        uint32 PierceArmor_Timer;
        uint32 CryptScarabs_Timer;
        uint32 RaiseUndeadScarab_Timer;

        void Reset()
        {
            CryptScarabs_Timer = 3000;
            EncasingWebs_Timer = 7000;
            PierceArmor_Timer = 19000;
            RaiseUndeadScarab_Timer = 3000;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
                instance->SetData(TYPE_NERUB, IN_PROGRESS);
        }

        void RaiseUndeadScarab(Unit* victim)
        {
            if (Creature* pUndeadScarab = DoSpawnCreature(10876, float(irand(-9, 9)), float(irand(-9, 9)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 180000))
                if (pUndeadScarab->AI())
                    pUndeadScarab->AI()->AttackStart(victim);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //EncasingWebs
            if (EncasingWebs_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_ENCASINGWEBS);
                EncasingWebs_Timer = 30000;
            } else EncasingWebs_Timer -= diff;

            //PierceArmor
            if (PierceArmor_Timer <= diff)
            {
                if (urand(0, 3) < 2)
                    DoCast(me->getVictim(), SPELL_PIERCEARMOR);
                PierceArmor_Timer = 35000;
            } else PierceArmor_Timer -= diff;

            //CryptScarabs_Timer
            if (CryptScarabs_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CRYPT_SCARABS);
                CryptScarabs_Timer = 20000;
            } else CryptScarabs_Timer -= diff;

            //RaiseUndeadScarab
            if (RaiseUndeadScarab_Timer <= diff)
            {
                RaiseUndeadScarab(me->getVictim());
                RaiseUndeadScarab_Timer = 16000;
            } else RaiseUndeadScarab_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_nerubenkan()
{
    new boss_nerubenkan();
}
