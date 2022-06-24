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

#ifndef LOAD_LIB_H
#define LOAD_LIB_H

#include "Define.h"
#ifdef PLATFORM_WINDOWS
#undef PLATFORM_WINDOWS
#endif
#include <map>
#include <cstdint>
#include <string>

#ifndef _WIN32
int GetLastError();
#endif

#define FILE_FORMAT_VERSION    18

#pragma pack(push, 1)

union u_map_fcc
{
    char   fcc_txt[4];
    uint32 fcc;
};

//
// File version chunk
//
struct file_MVER
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;
    uint32 ver;
};

struct file_MWMO
{
    u_map_fcc fcc;
    uint32 size;
    char FileList[1];
};

class FileChunk
{
public:
    FileChunk(uint8* data_, uint32 size_) : data(data_), size(size_) { }
    ~FileChunk();

    uint8* data;
    uint32 size;

    template<class T>
    T* As() { return (T*)data; }
    void parseSubChunks();
    std::multimap<std::string, FileChunk*> subchunks;
    FileChunk* GetSubChunk(std::string const& name);
};

class ChunkedFile
{
public:
    uint8  *data;
    uint32  data_size;

    uint8 *GetData()     { return data; }
    uint32 GetDataSize() { return data_size; }

    ChunkedFile();
    virtual ~ChunkedFile();
    bool prepareLoadedData();
    bool loadFile(std::string const& fileName, bool log = true);
    void free();

    void parseChunks();
    std::multimap<std::string, FileChunk*> chunks;
    FileChunk* GetChunk(std::string const& name);
};

#pragma pack(pop)

#endif
