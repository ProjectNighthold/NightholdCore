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

#ifndef TRINITY_GUARDAI_H
#define TRINITY_GUARDAI_H

#include "ScriptedCreature.h"

class Creature;

class GuardAI : public ScriptedAI
{
    public:
        explicit GuardAI(Creature* creature);

        static int Permissible(Creature const* creature);
        bool CanSeeAlways(WorldObject const* obj);

        void EnterEvadeMode();
        void JustDied(Unit* killer);
};
#endif

