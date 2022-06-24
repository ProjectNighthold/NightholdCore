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

#ifndef _BATTLE_PET_DATA_STORE_H
#define _BATTLE_PET_DATA_STORE_H

struct BattlePetTemplate
{
    uint32 CreatureID;
    uint32 BreedMask;
    uint32 MinQuality;
    uint32 minlevel;
    uint32 maxlevel;
    uint32 Species;
    std::set<uint32> BreedIDs;
};

struct BattlePetNpcTeamMember
{
    uint32 Specie;
    uint32 maxlevel;
    uint32 minlevel;
    uint32 minquality;
    uint32 breadsMask;
    uint32 Ability[3];
    std::set<uint32> BreedIDs;
};

typedef std::map<uint32, BattlePetTemplate> BattlePetTemplateContainer;
typedef std::map<uint32, BattlePetTemplate*> BattlePetTemplateMap;
typedef std::map<uint32, std::vector<BattlePetNpcTeamMember>> BattlePetNpcTeamMembers;

class BattlePetDataStoreMgr
{
    BattlePetDataStoreMgr();
    ~BattlePetDataStoreMgr();

public:
    static BattlePetDataStoreMgr* instance();

    void Initialize();
    void LoadBattlePetTemplate();
    void LoadBattlePetNpcTeamMember();
    void ComputeBattlePetSpawns();

    BattlePetTemplate const* GetBattlePetTemplate(uint32 species) const;
    BattlePetTemplate const* GetBattlePetTemplateByEntry(uint32 CreatureID) const;
    uint16 GetRandomBreedID(std::set<uint32> BreedIDs);
    uint8 GetWeightForBreed(uint16 breedID);
    uint8 GetRandomQuailty();
    std::vector<BattlePetNpcTeamMember> GetPetBattleTrainerTeam(uint32 npcID);
private:
    BattlePetTemplateContainer _battlePetTemplateStore;
    BattlePetTemplateMap _battlePetTemplate;
    BattlePetNpcTeamMembers _battlePetNpcTeamMembers;
};

#define sBattlePetDataStore BattlePetDataStoreMgr::instance()

#endif
