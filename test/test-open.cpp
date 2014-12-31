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


#include "test-open.h"

int main( int argc, char** argv ) {
   
   struct fskit_core core;
   int rc;
   char name_buf[10];
   struct fskit_file_handle* fh = NULL;
   void* output;
   
   rc = fskit_test_begin( &core, NULL );
   if( rc != 0 ) {
      exit(1);
   }
   
   for( int i = 0; i < 256; i++ ) {
      
      sprintf(name_buf, "/%d", i );
      
      fh = fskit_create( &core, name_buf, 0, i, 0644, &rc );
      
      if( fh == NULL ) {
         fskit_error("fskit_create(%s) rc = %d\n", name_buf, rc );
         exit(1);
      }
      
      fskit_close( &core, fh );
   }
   
   int num_flags = 5;
   int flags[] = {
      O_RDONLY,
      O_RDWR,
      O_WRONLY,
      O_TRUNC | O_RDWR,
      O_TRUNC | O_WRONLY
   };
   
   for( int i = 0; i < 256; i++ ) {
      
      sprintf(name_buf, "/%d", i );
      
      int f = flags[ i % num_flags ];
      
      fh = fskit_open( &core, name_buf, 0, i, f, 0, &rc );
      
      if( fh == NULL ) {
         fskit_error("fskit_create(%s) rc = %d\n", name_buf, rc );
         exit(1);
      }
      
      fskit_debug("Open %s (flags = %x) handle = %p\n", name_buf, f, fh );
      
      fskit_close( &core, fh );
   }
   
   fskit_print_tree( stdout, &core.root );
   
   fskit_test_end( &core, &output );
   return 0;
}