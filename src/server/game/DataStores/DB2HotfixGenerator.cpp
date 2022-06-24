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

#include "DB2HotfixGenerator.h"
#include "DB2Stores.h"
#include "Log.h"

void DB2HotfixGeneratorBase::LogMissingRecord(std::string const& storageName, uint32 recordId)
{
    TC_LOG_INFO(LOG_FILTER_SQL, "Hotfix specified for %s row id %u which does not exist", storageName.c_str(), recordId);
}

void DB2HotfixGeneratorBase::AddClientHotfix(uint32 tableHash, uint32 recordId)
{
    sDB2Manager.InsertNewHotfix(tableHash, recordId);
}
