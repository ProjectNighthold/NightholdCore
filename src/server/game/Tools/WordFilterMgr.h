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

#ifndef TRINITYCORE_WORDFILTERMGR_H
#define TRINITYCORE_WORDFILTERMGR_H

// #include <locale>
// #include <codecvt>

struct BadSentenceInfo
{
    std::string text{};
    uint32 id = 0; 
    int32 penalty = 0; 
    uint32 sourceMask = 0;
};


typedef std::map<ObjectGuid, uint64> ComplaintsByUsers; // guid -> complaint id
struct ComplaintInfoUser
{
    ComplaintsByUsers m_complaintsByUsers{};
    uint64 m_muteTime = 0;
    uint32 m_muteCount = 0;
};

typedef std::unordered_map<ObjectGuid, ComplaintInfoUser> ComplaintsInfo; // guid of offender -> him complaints

enum BadSentenceMask : uint32
{
    BS_PM       = 0x00000001,
    BS_MAIL     = 0x00000002,
    BS_LFG      = 0x00000004,
};

struct PlayerFloodInfo
{
    uint32 lastSayTimeLFG = 0;
    uint32 lastSayTimeGeneral = 0;
    std::map<size_t, uint32> phrasesCheck{};
    std::set<ObjectGuid> players{};

    std::set<std::string> mailPhrases{};
    std::set<size_t> mailFoundedBadWords{};
};

class WordFilterMgr
{
    WordFilterMgr();
    ~WordFilterMgr();

public:
    static WordFilterMgr* instance();

    /// Note for 0.6v : Will used std::map instead of std::unordered_map, because of problems with cross-platform compilation.
    // [letter][analogs] 
    typedef std::map<wchar_t, wchar_t> LetterAnalogMap;
    // [converted][original]
    typedef std::set<std::wstring> BadWordMap;
    typedef std::set<std::wstring> BadWordMapMail;
    typedef std::map <size_t, BadSentenceInfo> BadSentences;

    void LoadLetterAnalogs();
    void LoadBadWords();
    void LoadBadSentences();
    void LoadComplaints();

    std::string FindBadWord(std::string const& text, bool mail = false);

    // manipulations with container 
    bool AddBadWord(std::string const& badWord, bool toDB = false);
    void AddConvert(std::string const& badWord);
    bool AddBadWordMail(std::string const& badWord, bool toDB = false);
    bool RemoveBadWord(std::string const& badWord, bool fromDB = false);

    bool AddBadSentence(std::string badSentence, size_t hash, uint32 mask, int32 penalty = 10);
    void UpdatePenaltyForBadSentenceById(uint32 id, int32 penalty);

    size_t FilterMsgAndGetHash(std::string lowedMsg, LocaleConstant locale = LOCALE_enUS, bool* isValid = nullptr);
    void GeneralFilterWstring(std::wstring& msg, LocaleConstant locale = LOCALE_enUS, bool* isValid = nullptr);

    // element (const) accessor 
    BadWordMap GetBadWords() const;

    uint32 GetIdOfBadSentence(size_t hash);
    int32 GetPenaltyForBadSentence(size_t hash);
    uint32 GetSourceMaskForBadSentence(size_t hash);
    std::vector<BadSentenceInfo> GetBadSentenceList(uint32 page);
    uint32 GetLastIdBadSentences() const { return lastIdBadSentences;}

    PlayerFloodInfo& GetFloodInfo(uint32 accountid) { return m_floodInfo[accountid]; }
    bool AddComplaintForUser(const ObjectGuid& offender, const ObjectGuid& complainant, uint64 complaintId, const std::string& text);
private:
    LetterAnalogMap m_letterAnalogs;
    BadWordMap m_badWords;
    BadWordMapMail m_badWordsMail;

    BadSentences m_badSentences{};
    std::map<uint32, size_t> hashById{};
    uint32 lastIdBadSentences{};
    std::hash<std::wstring> hash_fn;
    
    ComplaintsInfo m_complaints{};
    std::map<uint32, PlayerFloodInfo> m_floodInfo{}; // account -> info
};

#define sWordFilterMgr WordFilterMgr::instance()

#endif