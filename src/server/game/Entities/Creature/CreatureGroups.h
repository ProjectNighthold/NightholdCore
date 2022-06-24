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

#ifndef _FORMATIONS_H
#define _FORMATIONS_H

class Creature;
class CreatureGroup;

struct FormationInfo
{
    ObjectGuid::LowType leaderGUID;
    float follow_dist;
    float follow_angle;
    uint8 groupAI;
};

typedef std::unordered_map<ObjectGuid::LowType/*memberDBGUID*/, FormationInfo*>   CreatureGroupInfoType;

class FormationMgr
{
        FormationMgr() { }
        ~FormationMgr();

    public:
        static FormationMgr* instance();

        void AddCreatureToGroup(ObjectGuid::LowType const& group_id, Creature* creature);
        void RemoveCreatureFromGroup(CreatureGroup* group, Creature* creature);
        void LoadCreatureFormations();
        CreatureGroupInfoType CreatureGroupMap;
        FormationInfo* CreateCustomFormation(Creature* c);
};

class CreatureGroup
{
        Creature* m_leader; //Important do not forget sometimes to work with pointers instead synonims :D:D
        typedef std::map<Creature*, FormationInfo*>  CreatureGroupMemberType;
        CreatureGroupMemberType m_members;

        ObjectGuid::LowType m_groupID;
        bool m_Formed;

    public:
        //Group cannot be created empty
        explicit CreatureGroup(ObjectGuid::LowType const& id);
        ~CreatureGroup() {}

        Creature* getLeader() const { return m_leader; }
        ObjectGuid::LowType GetId() const { return m_groupID; }
        bool isEmpty() const { return m_members.empty(); }
        bool isFormed() const { return m_Formed; }

        void AddMember(Creature* member, FormationInfo* f = nullptr);
        void RemoveMember(Creature* member);
        void FormationReset(bool dismiss);

        void LeaderMoveTo(float x, float y, float z);
        void MemberAttackStart(Creature* member, Unit* target);

        CreatureGroupMemberType& GetMembers() { return m_members; }
};

#define sFormationMgr FormationMgr::instance()

#endif
