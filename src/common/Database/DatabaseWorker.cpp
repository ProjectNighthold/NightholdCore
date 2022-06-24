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

#include "DatabaseEnv.h"
#include "DatabaseWorker.h"
#include "SQLOperation.h"
#include "MySQLConnection.h"
#include "MySQLThreading.h"
#include "ProducerConsumerQueue.h"

#include <cds/init.h>
#include <cds/gc/hp.h>

DatabaseWorker::DatabaseWorker(ProducerConsumerQueue<SQLOperation*>* newQueue, MySQLConnection* connection)
{
    _connection = connection;
    _queue = newQueue;
    _cancelationToken = false;
    _workerThread = std::thread(&DatabaseWorker::WorkerThread, this);
}

DatabaseWorker::~DatabaseWorker()
{
    _cancelationToken = true;

    _queue->Cancel();

    _workerThread.join();
}

void DatabaseWorker::WorkerThread()
{
    if (!_queue)
        return;

    cds::threading::Manager::attachThread();

    for (;;)
    {
        SQLOperation* operation = nullptr;

        _queue->WaitAndPop(operation);

        if (_cancelationToken || !operation)
            return;

        operation->SetConnection(_connection);
        operation->call();

        delete operation;
    }
    cds::threading::Manager::detachThread();
}
