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

#include "model.h"
#include "dbcfile.h"
#include "adtfile.h"
#include "vmapexport.h"

#include <algorithm>
#include <stdio.h>

bool ExtractSingleModel(std::string& fname)
{
    if (fname.substr(fname.length() - 4, 4) == ".mdx")
    {
        fname.erase(fname.length() - 2, 2);
        fname.append("2");
    }

    std::string originalName = fname;

    char* name = GetPlainName((char*)fname.c_str());
    FixNameCase(name, strlen(name));
    FixNameSpaces(name, strlen(name));

    std::string output(szWorkDirWmo);
    output += "/";
    output += name;

    if (FileExists(output.c_str()))
        return true;

    Model mdl(originalName);
    if (!mdl.open())
        return false;

    return mdl.ConvertToVMAPModel(output.c_str());
}

void ExtractGameobjectModels()
{
    printf("Extracting GameObject models...");
    DBCFile dbc("DBFilesClient\\GameObjectDisplayInfo.db2", "nifffffffft");
    if(!dbc.open())
    {
        printf("Fatal error: Invalid GameObjectDisplayInfo.db2 file format!\n");
        exit(1);
    }

    DBCFile fileData("DBFilesClient\\FileDataComplete.dbc", "nss", true);
    if (!fileData.open())
    {
        printf("Fatal error: Invalid FileDataComplete.dbc file format!\n");
        exit(1);
    }

    std::string basepath = szWorkDirWmo;
    basepath += "/";
    std::string path;

    std::string modelListPath = basepath + "temp_gameobject_models";
    FILE* modelList = fopen(modelListPath.c_str(), "wb");
    if (!modelList)
    {
        printf("Fatal error: Could not open file %s\n", modelListPath.c_str());
        return;
    }

    size_t maxFileId = fileData.getMaxId() + 1;
    uint32* fileDataIndex = new uint32[maxFileId];
    memset(fileDataIndex, 0, maxFileId * sizeof(uint32));

    for (size_t i = 0; i < fileData.getRecordCount(); ++i)
        fileDataIndex[fileData.getRecord(i).getUInt(0)] = i;

    for (DBCFile::Iterator it = dbc.begin(); it != dbc.end(); ++it)
    {
        uint32 fileId = it->getUInt(0);
        if (!fileId)
            continue;

        uint32 fileIndex = fileDataIndex[fileId];
        if (!fileIndex)
            continue;
            
        std::string filepath = fileData.getRecord(fileIndex).getString(1);
        std::string filename = fileData.getRecord(fileIndex).getString(2);

        path = filepath + filename;
        if (path.length() < 4)
            continue;

        FixNameCase((char*)path.c_str(), path.size());
        char* name = GetPlainName((char*)path.c_str());
        FixNameSpaces(name, strlen(name));

        char* ch_ext = GetExtension(name);
        if (!ch_ext)
            continue;

        strToLower(ch_ext);

        bool result = false;
        if (!strcmp(ch_ext, ".wmo"))
            result = ExtractSingleWmo(path);
        else if (!strcmp(ch_ext, ".mdl"))   // TODO: extract .mdl files, if needed
            continue;
        else if (!strcmp(ch_ext, ".mdx") || !strcmp(ch_ext, ".m2"))
            result = ExtractSingleModel(path);

        if (result)
        {
            uint32 displayID = it->getUInt(0);
            uint32 pathLength = strlen(name);
            fwrite(&displayID, sizeof(uint32), 1, modelList);
            fwrite(&pathLength, sizeof(uint32), 1, modelList);
            fwrite(name, sizeof(char), pathLength, modelList);
        }
    }

    fclose(modelList);

    delete[] fileDataIndex;

    printf("Done!\n");
}
