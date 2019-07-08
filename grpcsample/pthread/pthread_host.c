#include <pthread.h>
#include <errno.h>
#include "pthread_types.h"

oe_pthread_condattr_init_result_t oe_host_ocall_pthread_condattr_init(pthread_condattr_t * a)
{
    oe_pthread_condattr_init_result_t result;
    result.ret = pthread_condattr_init(a);
    result.error = errno;
    return result;
}

oe_pthread_condattr_destroy_result_t oe_host_ocall_pthread_condattr_destroy(pthread_condattr_t * a)
{
    oe_pthread_condattr_destroy_result_t result;
    result.ret = pthread_condattr_destroy(a);
    result.error = errno;
    return result;
}

oe_pthread_condattr_getpshared_result_t oe_host_ocall_pthread_condattr_getpshared(const pthread_condattr_t * a, int * b)
{
    oe_pthread_condattr_getpshared_result_t result;
    result.ret = pthread_condattr_getpshared(a, b);
    result.error = errno;
    return result;
}

oe_pthread_condattr_setpshared_result_t oe_host_ocall_pthread_condattr_setpshared(pthread_condattr_t * a, int b)
{
    oe_pthread_condattr_setpshared_result_t result;
    result.ret = pthread_condattr_setpshared(a, b);
    result.error = errno;
    return result;
}

oe_pthread_condattr_getclock_result_t oe_host_ocall_pthread_condattr_getclock(const pthread_condattr_t * a, __clockid_t * b)
{
    oe_pthread_condattr_getclock_result_t result;
    result.ret = pthread_condattr_getclock(a, b);
    result.error = errno;
    return result;
}

oe_pthread_condattr_setclock_result_t oe_host_ocall_pthread_condattr_setclock(pthread_condattr_t * a, __clockid_t b)
{
    oe_pthread_condattr_setclock_result_t result;
    result.ret = pthread_condattr_setclock(a, b);
    result.error = errno;
    return result;
}

oe_pthread_attr_init_result_t oe_host_ocall_pthread_attr_init(pthread_attr_t * a)
{
    oe_pthread_attr_init_result_t result;
    result.ret = pthread_attr_init(a);
    result.error = errno;
    return result;
}

oe_pthread_attr_destroy_result_t oe_host_ocall_pthread_attr_destroy(pthread_attr_t * a)
{
    oe_pthread_attr_destroy_result_t result;
    result.ret = pthread_attr_destroy(a);
    result.error = errno;
    return result;
}

oe_pthread_attr_setdetachstate_result_t oe_host_ocall_pthread_attr_setdetachstate(pthread_attr_t * a, int b)
{
    oe_pthread_attr_setdetachstate_result_t result;
    result.ret = pthread_attr_setdetachstate(a, b);
    result.error = errno;
    return result;
}

