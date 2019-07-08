#ifndef __EDL_TYPES_pthread__
#define __EDL_TYPES_pthread__

#include <pthread.h>

typedef struct _oe_pthread_condattr_init_result_t
{
    int ret;
    int error;
} oe_pthread_condattr_init_result_t;

typedef struct _oe_pthread_condattr_destroy_result_t
{
    int ret;
    int error;
} oe_pthread_condattr_destroy_result_t;

typedef struct _oe_pthread_condattr_getpshared_result_t
{
    int ret;
    int error;
} oe_pthread_condattr_getpshared_result_t;

typedef struct _oe_pthread_condattr_setpshared_result_t
{
    int ret;
    int error;
} oe_pthread_condattr_setpshared_result_t;

typedef struct _oe_pthread_condattr_getclock_result_t
{
    int ret;
    int error;
} oe_pthread_condattr_getclock_result_t;

typedef struct _oe_pthread_condattr_setclock_result_t
{
    int ret;
    int error;
} oe_pthread_condattr_setclock_result_t;

typedef struct _oe_pthread_attr_init_result_t
{
    int ret;
    int error;
} oe_pthread_attr_init_result_t;

typedef struct _oe_pthread_attr_destroy_result_t
{
    int ret;
    int error;
} oe_pthread_attr_destroy_result_t;

typedef struct _oe_pthread_attr_setdetachstate_result_t
{
    int ret;
    int error;
} oe_pthread_attr_setdetachstate_result_t;

#endif // __EDL_TYPES_pthread__
