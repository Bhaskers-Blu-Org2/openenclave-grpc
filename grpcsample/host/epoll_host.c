#include <sys/epoll.h>

#include <errno.h>
#include "epoll_types.h"
#include "helloworld_u.h"
oe_epoll_create_result_t oe_host_ocall_epoll_create(int a)
{
    oe_epoll_create_result_t result;
    result.ret = epoll_create(a);
    result.error = errno;
    return result;
}

oe_epoll_create1_result_t oe_host_ocall_epoll_create1(int a)
{
    oe_epoll_create1_result_t result;
    result.ret = epoll_create1(a);
    result.error = errno;
    return result;
}

oe_epoll_ctl_result_t oe_host_ocall_epoll_ctl(int a, int b, int c, struct epoll_event * d)
{
    oe_epoll_ctl_result_t result;
    result.ret = epoll_ctl(a, b, c, d);
    result.error = errno;
    return result;
}

oe_epoll_wait_result_t oe_host_ocall_epoll_wait(int a, struct epoll_event * b, int c, int d)
{
    oe_epoll_wait_result_t result;
    result.ret = epoll_wait(a, b, c, d);
    result.error = errno;
    return result;
}

oe_epoll_pwait_result_t oe_host_ocall_epoll_pwait(int a, struct epoll_event * b, int c, int d, const sigset_t * e)
{
    oe_epoll_pwait_result_t result;
    result.ret = epoll_pwait(a, b, c, d, e);
    result.error = errno;
    return result;
}

