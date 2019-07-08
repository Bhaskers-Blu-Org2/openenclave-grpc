/* Copyright (C) 2002-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _PTHREAD_H
#define _PTHREAD_H	1

#include <features.h>
#include <endian.h>
#include <sched.h>
#include <time.h>

#include <bits/pthreadtypes.h>
#include <bits/setjmp.h>
#include <bits/wordsize.h>


/* Detach state.  */
enum
{
  PTHREAD_CREATE_JOINABLE,
#define PTHREAD_CREATE_JOINABLE	PTHREAD_CREATE_JOINABLE
  PTHREAD_CREATE_DETACHED
#define PTHREAD_CREATE_DETACHED	PTHREAD_CREATE_DETACHED
};


/* Mutex types.  */
enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP
#if defined __USE_UNIX98 || defined __USE_XOPEN2K8
  ,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL
#endif
#ifdef __USE_GNU
  /* For compatibility.  */
  , PTHREAD_MUTEX_FAST_NP = PTHREAD_MUTEX_TIMED_NP
#endif
};


#ifdef __USE_XOPEN2K
/* Robust mutex or not flags.  */
enum
{
  PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
  PTHREAD_MUTEX_ROBUST,
  PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};
#endif


#if defined __USE_POSIX199506 || defined __USE_UNIX98
/* Mutex protocols.  */
enum
{
  PTHREAD_PRIO_NONE,
  PTHREAD_PRIO_INHERIT,
  PTHREAD_PRIO_PROTECT
};
#endif


#ifdef __PTHREAD_MUTEX_HAVE_PREV
# define PTHREAD_MUTEX_INITIALIZER \
  { { 0, 0, 0, 0, 0, __PTHREAD_SPINS, { 0, 0 } } }
# ifdef __USE_GNU
#  define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP \
  { { 0, 0, 0, 0, PTHREAD_MUTEX_RECURSIVE_NP, __PTHREAD_SPINS, { 0, 0 } } }
#  define PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP \
  { { 0, 0, 0, 0, PTHREAD_MUTEX_ERRORCHECK_NP, __PTHREAD_SPINS, { 0, 0 } } }
#  define PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP \
  { { 0, 0, 0, 0, PTHREAD_MUTEX_ADAPTIVE_NP, __PTHREAD_SPINS, { 0, 0 } } }

# endif
#else
# define PTHREAD_MUTEX_INITIALIZER \
  { { 0, 0, 0, 0, 0, { __PTHREAD_SPINS } } }
# ifdef __USE_GNU
#  define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP \
  { { 0, 0, 0, PTHREAD_MUTEX_RECURSIVE_NP, 0, { __PTHREAD_SPINS } } }
#  define PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP \
  { { 0, 0, 0, PTHREAD_MUTEX_ERRORCHECK_NP, 0, { __PTHREAD_SPINS } } }
#  define PTHREAD_ADAPTIVE_MUTEX_INITIALIZER_NP \
  { { 0, 0, 0, PTHREAD_MUTEX_ADAPTIVE_NP, 0, { __PTHREAD_SPINS } } }

# endif
#endif


/* Read-write lock types.  */
#if defined __USE_UNIX98 || defined __USE_XOPEN2K
enum
{
  PTHREAD_RWLOCK_PREFER_READER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
  PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
};

/* Define __PTHREAD_RWLOCK_INT_FLAGS_SHARED to 1 if pthread_rwlock_t
   has the shared field.  All 64-bit architectures have the shared field
   in pthread_rwlock_t.  */
#ifndef __PTHREAD_RWLOCK_INT_FLAGS_SHARED
# if __WORDSIZE == 64
#  define __PTHREAD_RWLOCK_INT_FLAGS_SHARED 1
# endif
#endif

/* Read-write lock initializers.  */
# define PTHREAD_RWLOCK_INITIALIZER \
  { { 0, 0, 0, 0, 0, 0, 0, 0, __PTHREAD_RWLOCK_ELISION_EXTRA, 0, 0 } }
# ifdef __USE_GNU
#  ifdef __PTHREAD_RWLOCK_INT_FLAGS_SHARED
#   define PTHREAD_RWLOCK_WRITER_NONRECURSIVE_INITIALIZER_NP \
  { { 0, 0, 0, 0, 0, 0, 0, 0, __PTHREAD_RWLOCK_ELISION_EXTRA, 0,					      \
	PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP } }
#  else
#   if __BYTE_ORDER == __LITTLE_ENDIAN
#    define PTHREAD_RWLOCK_WRITER_NONRECURSIVE_INITIALIZER_NP \
  { { 0, 0, 0, 0, 0, 0, PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP, \
      0, __PTHREAD_RWLOCK_ELISION_EXTRA, 0, 0 } }
#   else
#    define PTHREAD_RWLOCK_WRITER_NONRECURSIVE_INITIALIZER_NP \
  { { 0, 0, 0, 0, 0, 0, 0, 0, 0, PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,\
      0 } }
#   endif
#  endif
# endif
#endif  /* Unix98 or XOpen2K */


/* Scheduler inheritance.  */
enum
{
  PTHREAD_INHERIT_SCHED,
#define PTHREAD_INHERIT_SCHED   PTHREAD_INHERIT_SCHED
  PTHREAD_EXPLICIT_SCHED
#define PTHREAD_EXPLICIT_SCHED  PTHREAD_EXPLICIT_SCHED
};


/* Scope handling.  */
enum
{
  PTHREAD_SCOPE_SYSTEM,
#define PTHREAD_SCOPE_SYSTEM    PTHREAD_SCOPE_SYSTEM
  PTHREAD_SCOPE_PROCESS
#define PTHREAD_SCOPE_PROCESS   PTHREAD_SCOPE_PROCESS
};


/* Process shared or private flag.  */
enum
{
  PTHREAD_PROCESS_PRIVATE,
#define PTHREAD_PROCESS_PRIVATE PTHREAD_PROCESS_PRIVATE
  PTHREAD_PROCESS_SHARED
#define PTHREAD_PROCESS_SHARED  PTHREAD_PROCESS_SHARED
};



/* Conditional variable handling.  */
#define PTHREAD_COND_INITIALIZER { { 0, 0, 0, 0, 0, (void *) 0, 0, 0 } }


/* Cleanup buffers */
struct _pthread_cleanup_buffer
{
  void (*__routine) (void *);             /* Function to call.  */
  void *__arg;                            /* Its argument.  */
  int __canceltype;                       /* Saved cancellation type. */
  struct _pthread_cleanup_buffer *__prev; /* Chaining of cleanup functions.  */
};

/* Cancellation */
enum
{
  PTHREAD_CANCEL_ENABLE,
#define PTHREAD_CANCEL_ENABLE   PTHREAD_CANCEL_ENABLE
  PTHREAD_CANCEL_DISABLE
#define PTHREAD_CANCEL_DISABLE  PTHREAD_CANCEL_DISABLE
};
enum
{
  PTHREAD_CANCEL_DEFERRED,
#define PTHREAD_CANCEL_DEFERRED	PTHREAD_CANCEL_DEFERRED
  PTHREAD_CANCEL_ASYNCHRONOUS
#define PTHREAD_CANCEL_ASYNCHRONOUS	PTHREAD_CANCEL_ASYNCHRONOUS
};
#define PTHREAD_CANCELED ((void *) -1)


/* Single execution handling.  */
#define PTHREAD_ONCE_INIT 0


#ifdef __USE_XOPEN2K
/* Value returned by 'pthread_barrier_wait' for one of the threads after
   the required number of threads have called this function.
   -1 is distinct from 0 and all errno constants */
# define PTHREAD_BARRIER_SERIAL_THREAD -1
#endif


__BEGIN_DECLS


/* Initialize condition variable attribute ATTR.  */
extern int pthread_condattr_init (pthread_condattr_t *__attr)
     __THROW __nonnull ((1));

/* Destroy condition variable attribute ATTR.  */
extern int pthread_condattr_destroy (pthread_condattr_t *__attr)
     __THROW __nonnull ((1));

/* Get the process-shared flag of the condition variable attribute ATTR.  */
extern int pthread_condattr_getpshared (const pthread_condattr_t *
					__restrict __attr,
					int *__restrict __pshared)
     __THROW __nonnull ((1, 2));

/* Set the process-shared flag of the condition variable attribute ATTR.  */
extern int pthread_condattr_setpshared (pthread_condattr_t *__attr,
					int __pshared) __THROW __nonnull ((1));

#ifdef __USE_XOPEN2K
/* Get the clock selected for the condition variable attribute ATTR.  */
extern int pthread_condattr_getclock (const pthread_condattr_t *
				      __restrict __attr,
				      __clockid_t *__restrict __clock_id)
     __THROW __nonnull ((1, 2));

/* Set the clock selected for the condition variable attribute ATTR.  */
extern int pthread_condattr_setclock (pthread_condattr_t *__attr,
				      __clockid_t __clock_id)
     __THROW __nonnull ((1));
#endif


extern int pthread_attr_init(pthread_attr_t *attr); 

extern int pthread_attr_destroy(pthread_attr_t *attr); 


extern int pthread_attr_setdetachstate(pthread_attr_t *attr, int type); 


__END_DECLS

#endif	/* pthread.h */
