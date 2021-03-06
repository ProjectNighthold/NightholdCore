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

#define _CRT_SECURE_NO_DEPRECATE

#include "loadlib.h"
#include <cstdio>

u_map_fcc MverMagic = { { 'R','E','V','M' } };

ChunkedFile::ChunkedFile()
{
    data = 0;
    data_size = 0;
}

ChunkedFile::~ChunkedFile()
{
    free();
}

bool ChunkedFile::loadFile(std::string const& fileName, bool log)
{
    free();
    FILE* f = fopen(fileName.c_str(), "rb");
    if (!f)
    {
        if (log)
            printf("No such file %s\n", fileName.c_str());
        return false;
    }

    fseek(f, 0, SEEK_END);
    data_size = ftell(f);
    rewind(f);

    data = new uint8[data_size];
    if (fread(data, data_size, 1, f) != 1)
    {
        fprintf(stderr, "ChunkedFile::loadFile Can't read %s, size=%u ferror %s\n", fileName.c_str(), uint32(data_size), strerror(ferror(f)));
        fclose(f);
        return false;
    }

    parseChunks();
    if (prepareLoadedData())
    {
        fclose(f);
        return true;
    }

    printf("ChunkedFile::loadFile Error loading %s\n", fileName.c_str());
    fclose(f);
    free();

    return false;
}

bool ChunkedFile::prepareLoadedData()
{
    FileChunk* chunk = GetChunk("MVER");
    if (!chunk)
        return false;

    // Check version
    file_MVER* version = chunk->As<file_MVER>();
    if (version->fcc != MverMagic.fcc)
        return false;
    if (version->ver != FILE_FORMAT_VERSION)
        return false;
    return true;
}

void ChunkedFile::free()
{
    for (auto chunk : chunks)
        delete chunk.second;

    chunks.clear();

    delete[] data;
    data = 0;
    data_size = 0;
}

u_map_fcc InterestingChunks[] =
{
    { { 'R', 'E', 'V', 'M' } },
    { { 'N', 'I', 'A', 'M' } },
    { { 'O', '2', 'H', 'M' } },
    { { 'K', 'N', 'C', 'M' } },
    { { 'T', 'V', 'C', 'M' } },
    { { 'O', 'M', 'W', 'M' } },
    { { 'Q', 'L', 'C', 'M' } },
    { { 'O', 'B', 'F', 'M' } }
};

bool IsInterestingChunk(u_map_fcc const& fcc)
{
    for (u_map_fcc const& f : InterestingChunks)
        if (f.fcc == fcc.fcc)
            return true;

    return false;
}

void ChunkedFile::parseChunks()
{
    uint8* ptr = GetData();
    // Make sure there's enough data to read u_map_fcc struct and the uint32 size after it
    while (ptr <= GetData() + GetDataSize() - 8)
    {
        u_map_fcc header = *(u_map_fcc*)ptr;
        if (IsInterestingChunk(header))
        {
            uint32 size = *(uint32*)(ptr + 4);
            if (size <= data_size)
            {
                std::swap(header.fcc_txt[0], header.fcc_txt[3]);
                std::swap(header.fcc_txt[1], header.fcc_txt[2]);

                FileChunk* chunk = new FileChunk(ptr, size);
                chunk->parseSubChunks();
                chunks.insert({ std::string(header.fcc_txt, 4), chunk });
            }

            // move to next chunk
            ptr += size + 8;
        }
        else
            ++ptr;
    }
}

FileChunk* ChunkedFile::GetChunk(std::string const& name)
{
    auto range = chunks.equal_range(name);
    if (std::distance(range.first, range.second) == 1)
        return range.first->second;

    return NULL;
}

FileChunk::~FileChunk()
{
    for (auto subchunk : subchunks)
        delete subchunk.second;

    subchunks.clear();
}

void FileChunk::parseSubChunks()
{
    uint8* ptr = data + 8; // skip self
    while (ptr < data + size)
    {
        u_map_fcc header = *(u_map_fcc*)ptr;
        if (IsInterestingChunk(header))
        {
            uint32 subsize = *(uint32*)(ptr + 4);
            if (subsize < size)
            {
                std::swap(header.fcc_txt[0], header.fcc_txt[3]);
                std::swap(header.fcc_txt[1], header.fcc_txt[2]);

                FileChunk* chunk = new FileChunk(ptr, subsize);
                chunk->parseSubChunks();
                subchunks.insert({ std::string(header.fcc_txt, 4), chunk });
            }

            // move to next chunk
            ptr += subsize + 8;
        }
        else
            ++ptr;
    }
}

FileChunk* FileChunk::GetSubChunk(std::string const& name)
{
    auto range = subchunks.equal_range(name);
    if (std::distance(range.first, range.second) == 1)
        return range.first->second;

    return NULL;
}
