#include <stdint.h>
#include <fcntl.h>
#include <errno.h>
#include "fcntl_types.h"
#include "helloworld_t.h"
int creat(const char * a, mode_t b)
{
    oe_creat_result_t retval;
    oe_host_ocall_creat(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

int fcntl(int a, int b, long c)
{
    oe_fcntl_result_t retval;
    oe_host_ocall_fcntl(&retval, a, b, (int64_t)c);
    errno = retval.error;
    return retval.ret;
}

int open(const char * a, int b)
{
    oe_open_result_t retval;
    oe_host_ocall_open(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

int openat(int a, const char * b, int c)
{
    oe_openat_result_t retval;
    oe_host_ocall_openat(&retval, a, b, c);
    errno = retval.error;
    return retval.ret;
}

int posix_fadvise(int a, off_t b, off_t c, int d)
{
    oe_posix_fadvise_result_t retval;
    oe_host_ocall_posix_fadvise(&retval, a, b, c, d);
    errno = retval.error;
    return retval.ret;
}

int posix_fallocate(int a, off_t b, off_t c)
{
    oe_posix_fallocate_result_t retval;
    oe_host_ocall_posix_fallocate(&retval, a, b, c);
    errno = retval.error;
    return retval.ret;
}

int lockf(int a, int b, off_t c)
{
    oe_lockf_result_t retval;
    oe_host_ocall_lockf(&retval, a, b, c);
    errno = retval.error;
    return retval.ret;
}

