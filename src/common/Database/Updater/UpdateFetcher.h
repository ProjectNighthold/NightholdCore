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

#ifndef UpdateFetcher_h__
#define UpdateFetcher_h__

#include "Define.h"
#include "DatabaseEnvFwd.h"
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

namespace boost
{
    namespace filesystem
    {
        class path;
    }
}

struct UpdateResult
{
    UpdateResult()
        : updated(0), recent(0), archived(0) { }

    UpdateResult(size_t const updated_, size_t const recent_, size_t const archived_)
        : updated(updated_), recent(recent_), archived(archived_) { }

    size_t updated;
    size_t recent;
    size_t archived;
};

class UpdateFetcher
{
    typedef boost::filesystem::path Path;

public:
    UpdateFetcher(Path const& updateDirectory,
        std::function<void(std::string const&)> const& apply,
        std::function<void(Path const& path)> const& applyFile,
        std::function<QueryResult(std::string const&)> const& retrieve);
    ~UpdateFetcher();

    UpdateResult Update(bool const redundancyChecks, bool const allowRehash,
                  bool const archivedRedundancy, int32 const cleanDeadReferencesMaxCount) const;

private:
    enum UpdateMode
    {
        MODE_APPLY,
        MODE_REHASH
    };

    enum State
    {
        RELEASED,
        ARCHIVED
    };

    struct AppliedFileEntry
    {
        AppliedFileEntry(std::string const& name_, std::string const& hash_, State state_, uint64 timestamp_)
            : name(name_), hash(hash_), state(state_), timestamp(timestamp_) { }

        std::string const name;

        std::string const hash;

        State const state;

        uint64 const timestamp;

        static inline State StateConvert(std::string const& state)
        {
            return (state == "RELEASED") ? RELEASED : ARCHIVED;
        }

        static inline std::string StateConvert(State const state)
        {
            return (state == RELEASED) ? "RELEASED" : "ARCHIVED";
        }

        std::string GetStateAsString() const
        {
            return StateConvert(state);
        }
    };

    struct DirectoryEntry;

    typedef std::pair<Path, State> LocaleFileEntry;

    struct PathCompare
    {
        bool operator()(LocaleFileEntry const& left, LocaleFileEntry const& right) const;
    };

    typedef std::set<LocaleFileEntry, PathCompare> LocaleFileStorage;
    typedef std::unordered_map<std::string, std::string> HashToFileNameStorage;
    typedef std::unordered_map<std::string, AppliedFileEntry> AppliedFileStorage;
    typedef std::vector<UpdateFetcher::DirectoryEntry> DirectoryStorage;

    LocaleFileStorage GetFileList() const;
    void FillFileListRecursively(Path const& path, LocaleFileStorage& storage,
        State const state, uint32 const depth) const;

    DirectoryStorage ReceiveIncludedDirectories() const;
    AppliedFileStorage ReceiveAppliedFiles() const;

    std::string ReadSQLUpdate(Path const& file) const;

    uint32 Apply(Path const& path) const;

    void UpdateEntry(AppliedFileEntry const& entry, uint32 const speed = 0) const;
    void RenameEntry(std::string const& from, std::string const& to) const;
    void CleanUp(AppliedFileStorage const& storage) const;

    void UpdateState(std::string const& name, State const state) const;

    std::unique_ptr<Path> const _sourceDirectory;

    std::function<void(std::string const&)> const _apply;
    std::function<void(Path const& path)> const _applyFile;
    std::function<QueryResult(std::string const&)> const _retrieve;
};

#endif // UpdateFetcher_h__
