/*
   fskit: a library for creating multi-threaded in-RAM filesystems
   Copyright (C) 2014  Jude Nelson

   This program is dual-licensed: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License version 3 or later as
   published by the Free Software Foundation. For the terms of this
   license, see LICENSE.LGPLv3+ or <http://www.gnu.org/licenses/>.

   You are free to use this program under the terms of the GNU Lesser General
   Public License, but WITHOUT ANY WARRANTY; without even the implied
   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   See the GNU Lesser General Public License for more details.

   Alternatively, you are free to use this program under the terms of the
   Internet Software Consortium License, but WITHOUT ANY WARRANTY; without
   even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   For the terms of this license, see LICENSE.ISC or
   <http://www.isc.org/downloads/software-support-policy/isc-license/>.
*/

#include "debug.h"

int FSKIT_GLOBAL_DEBUG_LOCKS = 1;
int FSKIT_GLOBAL_DEBUG_MESSAGES = 1;
int FSKIT_GLOBAL_ERROR_MESSAGES = 1;

void fskit_set_debug_level( int d ) {
   FSKIT_GLOBAL_DEBUG_MESSAGES = d;
}

void fskit_set_error_level( int e ) {
   FSKIT_GLOBAL_ERROR_MESSAGES = e;
}

int fskit_get_debug_level() {
   return FSKIT_GLOBAL_DEBUG_MESSAGES;
}

int fskit_get_error_level() {
   return FSKIT_GLOBAL_ERROR_MESSAGES;
}
