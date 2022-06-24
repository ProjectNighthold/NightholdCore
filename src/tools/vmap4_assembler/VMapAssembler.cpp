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

#include <string>
#include <iostream>

#include "TileAssembler.h"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "usage: " << argv[0] << " <raw data dir> <vmap dest dir>" << std::endl;
        return 1;
    }

    std::string src = argv[1];
    std::string dest = argv[2];

    std::cout << "using " << src << " as source directory and writing output to " << dest << std::endl;

    VMAP::TileAssembler* ta = new VMAP::TileAssembler(src, dest);

    if (!ta->convertWorld2())
    {
        std::cout << "exit with errors" << std::endl;
        delete ta;
        return 1;
    }

    delete ta;
    std::cout << "Ok, all done" << std::endl;
    return 0;
}
