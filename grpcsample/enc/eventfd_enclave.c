#include <sys/eventfd.h>
#include <errno.h>
#include "eventfd_types.h"
#include "helloworld_t.h"
int eventfd(unsigned int a, int b)
{
    oe_eventfd_result_t retval;
    oe_host_ocall_eventfd(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

int eventfd_read(int a, eventfd_t * b)
{
    oe_eventfd_read_result_t retval;
    oe_host_ocall_eventfd_read(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

int eventfd_write(int a, eventfd_t b)
{
    oe_eventfd_write_result_t retval;
    oe_host_ocall_eventfd_write(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

