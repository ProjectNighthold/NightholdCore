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

#include "Random.h"
#include "Common.h"
#include "Errors.h"
#include "SFMT.h"
#include <boost/thread/tss.hpp>

static boost::thread_specific_ptr<SFMTRand> sfmtRand;
static SFMTEngine engine;

static SFMTRand* GetRng()
{
    SFMTRand* rand = sfmtRand.get();

    if (!rand)
    {
        rand = new SFMTRand();
        sfmtRand.reset(rand);
    }

    return rand;
}

int32 irand(int32 min, int32 max)
{
    if (min > max)
        return int32(GetRng()->IRandom(max, min));
    return int32(GetRng()->IRandom(min, max));
}

uint32 urand(uint32 min, uint32 max)
{
    if (min > max)
        return GetRng()->URandom(max, min);
    return GetRng()->URandom(min, max);
}

uint32 urandms(uint32 min, uint32 max)
{
    if (min > max)
        return GetRng()->URandom(max * IN_MILLISECONDS, min * IN_MILLISECONDS);
    return GetRng()->URandom(min * IN_MILLISECONDS, max * IN_MILLISECONDS);
}

float frand(float min, float max)
{
    if (min > max)
        return float(GetRng()->Random() * (min - max) + max);
    return float(GetRng()->Random() * (max - min) + min);
}

uint32 rand32()
{
    return GetRng()->BRandom();
}

double rand_norm()
{
    return GetRng()->Random();
}

double rand_chance()
{
    return GetRng()->Random() * 100.0;
}

uint32 urandweighted(size_t count, double const* chances)
{
    std::discrete_distribution<uint32> dd(chances, chances + count);
    return dd(SFMTEngine::Instance());
}

SFMTEngine& SFMTEngine::Instance()
{
    return engine;
}
