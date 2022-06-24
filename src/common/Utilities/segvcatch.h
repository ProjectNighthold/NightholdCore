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

#ifndef _SEGVCATCH_H
#define	_SEGVCATCH_H

/*! \brief segvcatch namespace


*/
namespace segvcatch
{

/*! Signal handler, used to redefine standart exception throwing. */
typedef void (*handler)();

/*! Initialize segmentation violation handler.
    \param h (optional) - optional user's signal handler. By default used an internal signal handler to throw
 std::runtime_error.
   */
void init_segv(handler h = 0);
void init_abrt(handler h = 0);

/*! Initialize floating point error handler.
    \param h - optional user's signal handler. By default used an internal signal handler to throw
 std::runtime_error.*/
void init_fpe(handler h = 0);

extern bool crash_ignore;

}

#endif	/* _SEGVCATCH_H */
