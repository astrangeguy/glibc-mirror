/* ARCH_FORK definition for Linux fork implementation.  HPPA version.
   Copyright (C) 2005-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library.  If not, see
   <http://www.gnu.org/licenses/>.  */

#include <sched.h>
#include <signal.h>
#include <sysdep.h>
#include <tls.h>

/* Argument 1 - Clone flags.
            2 - Child stack pointer.
	    3 - Parent tid pointer.
	    4 - New TLS area pointer.
	    5 - Child tid pointer. */
#define ARCH_FORK() \
  INLINE_SYSCALL (clone, 5,						\
		  CLONE_CHILD_SETTID | CLONE_CHILD_CLEARTID | SIGCHLD,	\
                  NULL, NULL, NULL, &THREAD_SELF->tid)
