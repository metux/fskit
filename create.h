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


#ifndef _FSKIT_CREATE_H_
#define _FSKIT_CREATE_H_

#include "debug.h"
#include "entry.h"

extern "C" {

int fskit_run_user_create( struct fskit_core* core, char const* path, struct fskit_entry* fent, mode_t mode, void** inode_data, void** handle_data );
int fskit_do_create( struct fskit_core* core, struct fskit_entry* parent, char const* path, mode_t mode, uint64_t user, uint64_t group, struct fskit_entry** ret_child, void** handle_data );

struct fskit_file_handle* fskit_create( struct fskit_core* core, char const* path, uint64_t user, uint64_t group, mode_t mode, int* err );

}

#endif
