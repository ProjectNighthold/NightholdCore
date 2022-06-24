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

/*
 * Interaction between core and LFGScripts
 */

#pragma once

#include "SharedDefines.h"
#include "ScriptMgr.h"

class Player;
class Group;

namespace lfg
{

class LFGPlayerScript : public PlayerScript
{
    public:
        LFGPlayerScript();

        // Player Hooks
        void OnLogout(Player* player) override;
        void OnLogin(Player* player) override;
        void OnMapChanged(Player* player) override;
};

class LFGGroupScript : public GroupScript
{
    public:
        LFGGroupScript();

        // Group Hooks
        void OnAddMember(Group* group, ObjectGuid const& guid) override;
        void OnRemoveMember(Group* group, ObjectGuid const& guid, RemoveMethod method, ObjectGuid const& kicker, char const* reason) override;
        void OnDisband(Group* group) override;
        void OnChangeLeader(Group* group, ObjectGuid const& newLeaderGuid, ObjectGuid const& oldLeaderGuid) override;
        void OnInviteMember(Group* group, ObjectGuid const& guid) override;
};

} // namespace lfg
