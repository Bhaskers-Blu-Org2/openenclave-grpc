#include <sys/eventfd.h>
#include <errno.h>
#include "eventfd_types.h"
#include "helloworld_u.h"

oe_eventfd_result_t oe_host_ocall_eventfd(unsigned int a, int b)
{
    oe_eventfd_result_t result;
    result.ret = eventfd(a, b);
    result.error = errno;
    return result;
}

oe_eventfd_read_result_t oe_host_ocall_eventfd_read(int a, eventfd_t * b)
{
    oe_eventfd_read_result_t result;
    result.ret = eventfd_read(a, b);
    result.error = errno;
    return result;
}

oe_eventfd_write_result_t oe_host_ocall_eventfd_write(int a, eventfd_t b)
{
    oe_eventfd_write_result_t result;
    result.ret = eventfd_write(a, b);
    result.error = errno;
    return result;
}

