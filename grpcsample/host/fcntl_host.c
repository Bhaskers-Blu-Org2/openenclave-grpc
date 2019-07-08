#include <fcntl.h>
#include <errno.h>
#include "fcntl_types.h"
#include "helloworld_u.h"
oe_creat_result_t oe_host_ocall_creat(const char * a, mode_t b)
{
    oe_creat_result_t result;
    result.ret = creat(a, b);
    result.error = errno;
    return result;
}

oe_fcntl_result_t oe_host_ocall_fcntl(int a, int b, int64_t c)
{
    oe_fcntl_result_t result;
    result.ret = fcntl(a, b, c);
    result.error = errno;
    return result;
}

oe_open_result_t oe_host_ocall_open(const char * a, int b)
{
    oe_open_result_t result;
    result.ret = open(a, b);
    result.error = errno;
    return result;
}

oe_openat_result_t oe_host_ocall_openat(int a, const char * b, int c)
{
    oe_openat_result_t result;
    result.ret = openat(a, b, c);
    result.error = errno;
    return result;
}

oe_posix_fadvise_result_t oe_host_ocall_posix_fadvise(int a, off_t b, off_t c, int d)
{
    oe_posix_fadvise_result_t result;
    result.ret = posix_fadvise(a, b, c, d);
    result.error = errno;
    return result;
}

oe_posix_fallocate_result_t oe_host_ocall_posix_fallocate(int a, off_t b, off_t c)
{
    oe_posix_fallocate_result_t result;
    result.ret = posix_fallocate(a, b, c);
    result.error = errno;
    return result;
}

oe_lockf_result_t oe_host_ocall_lockf(int a, int b, off_t c)
{
    oe_lockf_result_t result;
    result.ret = lockf(a, b, c);
    result.error = errno;
    return result;
}

