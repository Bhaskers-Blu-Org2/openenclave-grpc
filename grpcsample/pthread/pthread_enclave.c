#include <pthread.h>
#include <errno.h>
#include "pthread_types.h"

int pthread_condattr_init(pthread_condattr_t * a)
{
    oe_pthread_condattr_init_result_t retval;
    oe_host_ocall_pthread_condattr_init(&retval, a);
    errno = retval.error;
    return retval.ret;
}

int pthread_condattr_destroy(pthread_condattr_t * a)
{
    oe_pthread_condattr_destroy_result_t retval;
    oe_host_ocall_pthread_condattr_destroy(&retval, a);
    errno = retval.error;
    return retval.ret;
}

int pthread_condattr_getpshared(const pthread_condattr_t *restrict a, int *restrict b)
{
    oe_pthread_condattr_getpshared_result_t retval;
    oe_host_ocall_pthread_condattr_getpshared(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

int pthread_condattr_setpshared(pthread_condattr_t * a, int b)
{
    oe_pthread_condattr_setpshared_result_t retval;
    oe_host_ocall_pthread_condattr_setpshared(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

int pthread_condattr_getclock(const pthread_condattr_t *restrict a, __clockid_t *restrict b)
{
    oe_pthread_condattr_getclock_result_t retval;
    oe_host_ocall_pthread_condattr_getclock(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

int pthread_condattr_setclock(pthread_condattr_t * a, __clockid_t b)
{
    oe_pthread_condattr_setclock_result_t retval;
    oe_host_ocall_pthread_condattr_setclock(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

int pthread_attr_init(pthread_attr_t * a)
{
    oe_pthread_attr_init_result_t retval;
    oe_host_ocall_pthread_attr_init(&retval, a);
    errno = retval.error;
    return retval.ret;
}

int pthread_attr_destroy(pthread_attr_t * a)
{
    oe_pthread_attr_destroy_result_t retval;
    oe_host_ocall_pthread_attr_destroy(&retval, a);
    errno = retval.error;
    return retval.ret;
}

int pthread_attr_setdetachstate(pthread_attr_t * a, int b)
{
    oe_pthread_attr_setdetachstate_result_t retval;
    oe_host_ocall_pthread_attr_setdetachstate(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

