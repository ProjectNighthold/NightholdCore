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

#include "vmapexport.h"
#include "wdtfile.h"
#include "adtfile.h"
#include <cstdio>

char * wdtGetPlainName(char * FileName)
{
    char * szTemp;

    if((szTemp = strrchr(FileName, '\\')) != NULL)
        FileName = szTemp + 1;
    return FileName;
}

WDTFile::WDTFile(char* file_name, char* file_name1):WDT(file_name), gnWMO(0)
{
    filename.append(file_name1,strlen(file_name1));
}

bool WDTFile::init(char* /*map_id*/, unsigned int mapID)
{
    if (WDT.isEof())
        return false;

    char fourcc[5];
    uint32 size;

    std::string dirname = std::string(szWorkDirWmo) + "/dir_bin";
    FILE *dirfile;
    dirfile = fopen(dirname.c_str(), "ab");
    if(!dirfile)
    {
        // printf("Can't open dirfile!'%s'\n", dirname.c_str());
        return false;
    }

    while (!WDT.isEof())
    {
        WDT.read(fourcc,4);
        WDT.read(&size, 4);

        flipcc(fourcc);
        fourcc[4] = 0;

        size_t nextpos = WDT.getPos() + size;

        if (!strcmp(fourcc,"MAIN")) { }
        if (!strcmp(fourcc,"MWMO"))
        {
            if (!size)
                break;

            char *buf = new char[size];
            WDT.read(buf, size);
            char *p = buf;
            while (p < buf + size)
            {
                char* s = wdtGetPlainName(p);
                FixNameCase(s, strlen(s));
                p = p + strlen(p) + 1;
                gWmoInstansName.push_back(s);
            }
            delete[] buf;
        }
        else if (!strcmp(fourcc, "MODF")) // changed on legion
        {
            if (!size)
                break;

            gnWMO = (int)size / 64;
            for (int i = 0; i < gnWMO; ++i)
            {
                int id;
                WDT.read(&id, 4);
                WMOInstance inst(WDT, gWmoInstansName[id].c_str(), mapID, 65, 65, dirfile);
            }
        }
        WDT.seek((int)nextpos);
    }

    WDT.close();
    fclose(dirfile);
    return true;
}

WDTFile::~WDTFile(void)
{
    WDT.close();
}

ADTFile* WDTFile::GetMap(int x, int z)
{
    if (!(x >= 0 && z >= 0 && x < 64 && z < 64))
        return NULL;

    char name[512];

    sprintf(name, "World\\Maps\\%s\\%s_%d_%d_obj0.adt", filename.c_str(), filename.c_str(), x, z);
    return new ADTFile(name);
}
