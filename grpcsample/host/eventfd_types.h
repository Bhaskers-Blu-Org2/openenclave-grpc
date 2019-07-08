#ifndef __EDL_TYPES_eventfd__
#define __EDL_TYPES_eventfd__

#include <sys/eventfd.h>

typedef struct _oe_eventfd_result_t
{
    int ret;
    int error;
} oe_eventfd_result_t;

typedef struct _oe_eventfd_read_result_t
{
    int ret;
    int error;
} oe_eventfd_read_result_t;

typedef struct _oe_eventfd_write_result_t
{
    int ret;
    int error;
} oe_eventfd_write_result_t;

#endif // __EDL_TYPES_eventfd__
