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

#include "QueryCallbackProcessor.h"
#include "QueryCallback.h"
#include <algorithm>

QueryCallbackProcessor::QueryCallbackProcessor()
{
}

QueryCallbackProcessor::~QueryCallbackProcessor()
{
}

void QueryCallbackProcessor::AddQuery(QueryCallback&& query)
{
    _callbacks.emplace_back(std::move(query));
}

void QueryCallbackProcessor::ProcessReadyQueries()
{
    if (_callbacks.empty())
        return;

    std::vector<QueryCallback> updateCallbacks{std::move(_callbacks)};

    updateCallbacks.erase(std::remove_if(updateCallbacks.begin(), updateCallbacks.end(), [](QueryCallback& callback)
    {
        return callback.InvokeIfReady() == QueryCallback::Completed;
    }), updateCallbacks.end());

    _callbacks.insert(_callbacks.end(), std::make_move_iterator(updateCallbacks.begin()), std::make_move_iterator(updateCallbacks.end()));
}
