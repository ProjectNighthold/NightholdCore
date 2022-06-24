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

#ifndef MODEL_H
#define MODEL_H

#include "vec3d.h"
#include "modelheaders.h"
#include <vector>

class MPQFile;

Vec3D fixCoordSystem(Vec3D v);

class Model
{
private:
    void _unload()
    {
        delete[] vertices;
        delete[] indices;
        vertices = NULL;
        indices = NULL;
    }
    std::string filename;
public:
    ModelHeader header;
    Vec3D* vertices;
    uint16* indices;

    bool open();
    bool ConvertToVMAPModel(char const* outfilename);

    Model(std::string& filename);
    ~Model() { _unload(); }
};

class ModelInstance
{
public:
    uint32 id;
    Vec3D pos, rot;
    uint16 scale, flags;
    float sc;

    ModelInstance() : id(0), scale(0), flags(0), sc(0.0f) {}
    ModelInstance(MPQFile& f, char const* ModelInstName, uint32 mapID, uint32 tileX, uint32 tileY, FILE* pDirfile);

};

#endif
