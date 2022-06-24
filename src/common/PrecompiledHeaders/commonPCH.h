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
 
#include "BoundingIntervalHierarchy.h"
#include "Common.h"
#include "Config.h"
#include "Define.h"
#include "Errors.h"
#include "GitRevision.h"
#include "Log.h"
#include "MapTree.h"
#include "ModelInstance.h"
#include "Util.h"
#include "VMapDefinitions.h"
#include "WorldModel.h"
#include <G3D/Ray.h>
#include <G3D/Vector3.h>
#include <algorithm>
#include <cstring>
#include <memory>
#include <mutex>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
