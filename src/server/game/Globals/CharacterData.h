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

#ifndef _CHARACTER_DATA_STORE_H
#define _CHARACTER_DATA_STORE_H

struct CharcterTemplateClass
{
    CharcterTemplateClass(uint8 factionGroup, uint8 classID);

    uint8 FactionGroup;
    uint8 ClassID;
};

struct CharacterTemplateItem
{
    uint64 RaceMask;
    uint32 ItemID;
    uint32 Count;
    uint8 ClassID;
    uint8 FactionGroup;
};

struct CharacterTemplateQuest
{
    uint64 RaceMask;
    uint32 QuestID;
    uint8 ClassID;
    uint8 FactionGroup;
};

struct CharacterTemplateSpell
{
    uint64 RaceMask;
    uint32 SpellID;
    uint8 ClassID;
    uint8 FactionGroup;
};

struct CharacterTemplateTitle
{
    uint64 RaceMask;
    uint32 TitleID;
    uint8 ClassID;
    uint8 FactionGroup;
};

struct CharacterTemplate
{
    std::vector<CharcterTemplateClass> Classes;
    std::vector<CharacterTemplateItem> Items;
    std::vector<CharacterTemplateQuest> Quests;
    std::vector<CharacterTemplateSpell> Spells;
    std::vector<CharacterTemplateTitle> Titles;
    uint64 RaceMask;
    uint32 TemplateSetID;
    uint32 Money;
    uint16 MapID;
    uint16 iLevel;
    Position Pos;
    std::string Name;
    std::string Description;
    uint8 Level;
    uint8 fromID;
};

typedef std::unordered_map<uint32, CharacterTemplate> CharacterTemplateContainer;
typedef std::map<uint32, uint32> CharacterConversionMap;

class CharacterDataStoreMgr
{
    CharacterDataStoreMgr();
    ~CharacterDataStoreMgr();

public:
    static CharacterDataStoreMgr* instance();

    void LoadCharacterTemplates();
    CharacterTemplateContainer const& GetCharacterTemplates() const;
    CharacterTemplate const* GetCharacterTemplate(uint32 id) const;

    void LoadFactionChangeAchievements();
    void LoadFactionChangeItems();
    void LoadFactionChangeSpells();
    void LoadFactionChangeReputations();
    void LoadFactionChangeTitles();

    CharacterConversionMap GetFactionChangeAchievements();
    CharacterConversionMap GetFactionChangeItems();
    CharacterConversionMap GetFactionChangeSpells();
    CharacterConversionMap GetFactionChangeReputation();
    CharacterConversionMap GetFactionChangeTitles();

    void LoadReservedPlayersNames();
    bool IsReservedName(std::string const& name) const;

    static ResponseCodes CheckPlayerName(std::string const& name, LocaleConstant locale, bool create = false);
    static PetNameInvalidReason CheckPetName(std::string const& name);
    static bool IsValidCharterName(std::string const& name, LocaleConstant locale = LOCALE_enUS);

    static bool CheckDeclinedNames(std::wstring w_ownname, DeclinedName const& names);
private:
    CharacterConversionMap _factionChangeAchievements;
    CharacterConversionMap _factionChangeItems;
    CharacterConversionMap _factionChangeSpells;
    CharacterConversionMap _factionChangeReputation;
    CharacterConversionMap _factionChangeTitles;
    std::set<std::wstring> _reservedNamesStore;
    CharacterTemplateContainer _characterTemplateStore;
};

#define sCharacterDataStore CharacterDataStoreMgr::instance()

#endif
