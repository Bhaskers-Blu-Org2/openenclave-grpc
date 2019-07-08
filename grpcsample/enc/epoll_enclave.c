#include <sys/epoll.h>
#include <errno.h>
#include "epoll_types.h"
#include "helloworld_t.h"
int epoll_create(int a)
{
    oe_epoll_create_result_t retval;
    oe_host_ocall_epoll_create(&retval, a);
    errno = retval.error;
    return retval.ret;
}

int epoll_create1(int a)
{
    oe_epoll_create1_result_t retval;
    oe_host_ocall_epoll_create1(&retval, a);
    errno = retval.error;
    return retval.ret;
}

int epoll_ctl(int a, int b, int c, struct epoll_event * d)
{
    oe_epoll_ctl_result_t retval;
    oe_host_ocall_epoll_ctl(&retval, a, b, c, d);
    errno = retval.error;
    return retval.ret;
}

int epoll_wait(int a, struct epoll_event * b, int c, int d)
{
    oe_epoll_wait_result_t retval;
    oe_host_ocall_epoll_wait(&retval, a, b, c, d);
    errno = retval.error;
    return retval.ret;
}

int epoll_pwait(int a, struct epoll_event * b, int c, int d, const sigset_t * e)
{
    oe_epoll_pwait_result_t retval;
    oe_host_ocall_epoll_pwait(&retval, a, b, c, d, e);
    errno = retval.error;
    return retval.ret;
}

