#ifndef __EDL_TYPES_fcntl__
#define __EDL_TYPES_fcntl__

#include <fcntl.h>

typedef struct _oe_creat_result_t
{
    int ret;
    int error;
} oe_creat_result_t;

typedef struct _oe_fcntl_result_t
{
    int ret;
    int error;
} oe_fcntl_result_t;

typedef struct _oe_open_result_t
{
    int ret;
    int error;
} oe_open_result_t;

typedef struct _oe_openat_result_t
{
    int ret;
    int error;
} oe_openat_result_t;

typedef struct _oe_posix_fadvise_result_t
{
    int ret;
    int error;
} oe_posix_fadvise_result_t;

typedef struct _oe_posix_fallocate_result_t
{
    int ret;
    int error;
} oe_posix_fallocate_result_t;

typedef struct _oe_lockf_result_t
{
    int ret;
    int error;
} oe_lockf_result_t;

#endif // __EDL_TYPES_fcntl__
