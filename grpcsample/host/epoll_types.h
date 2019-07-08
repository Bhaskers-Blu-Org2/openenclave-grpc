#ifndef __EDL_TYPES_epoll__
#define __EDL_TYPES_epoll__

#include <sys/epoll.h>

typedef struct _oe_epoll_create_result_t
{
    int ret;
    int error;
} oe_epoll_create_result_t;

typedef struct _oe_epoll_create1_result_t
{
    int ret;
    int error;
} oe_epoll_create1_result_t;

typedef struct _oe_epoll_ctl_result_t
{
    int ret;
    int error;
} oe_epoll_ctl_result_t;

typedef struct _oe_epoll_wait_result_t
{
    int ret;
    int error;
} oe_epoll_wait_result_t;

typedef struct _oe_epoll_pwait_result_t
{
    int ret;
    int error;
} oe_epoll_pwait_result_t;

#endif // __EDL_TYPES_epoll__
