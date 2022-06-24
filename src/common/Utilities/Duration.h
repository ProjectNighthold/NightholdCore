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

#ifndef _DURATION_H_
#define _DURATION_H_

#include <chrono>

/// Milliseconds shorthand typedef.
typedef std::chrono::milliseconds Milliseconds;

/// Seconds shorthand typedef.
typedef std::chrono::seconds Seconds;

/// Minutes shorthand typedef.
typedef std::chrono::minutes Minutes;

/// Hours shorthand typedef.
typedef std::chrono::hours Hours;

/// Point in time shorthand typedef.
typedef std::chrono::steady_clock::time_point TimePoint;

/// Represents a monotonic clock typedef.
typedef std::chrono::steady_clock SteadyClock;

/// The system-wide real time wall clock typedef.
typedef std::chrono::system_clock SystemClock;

/// Represents a time interval typedef.
typedef std::chrono::system_clock::duration Duration;

/// Makes std::chrono_literals globally available.
// ToDo: Enable this when TC supports C++14.
// using namespace std::chrono_literals;

#endif // _DURATION_H_
