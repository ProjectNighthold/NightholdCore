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

#ifndef DB2_DATABASE_LOADER_H
#define DB2_DATABASE_LOADER_H

#include "DB2FileLoader.h"
#include <string>
#include <vector>

enum HotfixDatabaseStatements : uint32;

struct DB2LoadInfo : public DB2FileLoadInfo
{
    DB2LoadInfo();
    DB2LoadInfo(DB2FieldMeta const* fields, std::size_t fieldCount, DB2Meta const* meta, HotfixDatabaseStatements statement);

    HotfixDatabaseStatements Statement;
};

class DB2DatabaseLoader
{
public:
    DB2DatabaseLoader(std::string const& storageName, DB2LoadInfo const* loadInfo) : _storageName(storageName), _loadInfo(loadInfo) { }

    char* Load(uint32& records, char**& indexTable, char*& stringHolders, std::vector<char*>& stringPool);
    void LoadStrings(uint32 locale, uint32 records, char** indexTable, std::vector<char*>& stringPool);
    static char* AddString(char const** holder, std::string const& value);

private:
    std::string _storageName;
    DB2LoadInfo const* _loadInfo;
};

#endif
