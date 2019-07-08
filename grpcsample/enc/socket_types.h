#ifndef __EDL_TYPES_socket__
#define __EDL_TYPES_socket__

#include <sys/socket.h>

typedef struct _oe_socket_result_t
{
    int ret;
    int error;
} oe_socket_result_t;

typedef struct _oe_socketpair_result_t
{
    int ret;
    int error;
} oe_socketpair_result_t;

typedef struct _oe_bind_result_t
{
    int ret;
    int error;
} oe_bind_result_t;

typedef struct _oe_getsockname_result_t
{
    int ret;
    int error;
} oe_getsockname_result_t;

typedef struct _oe_connect_result_t
{
    int ret;
    int error;
} oe_connect_result_t;

typedef struct _oe_getpeername_result_t
{
    int ret;
    int error;
} oe_getpeername_result_t;

typedef struct _oe_send_result_t
{
    ssize_t ret;
    int error;
} oe_send_result_t;

typedef struct _oe_recv_result_t
{
    ssize_t ret;
    int error;
} oe_recv_result_t;

typedef struct _oe_sendto_result_t
{
    ssize_t ret;
    int error;
} oe_sendto_result_t;

typedef struct _oe_recvfrom_result_t
{
    ssize_t ret;
    int error;
} oe_recvfrom_result_t;

typedef struct _oe_sendmsg_result_t
{
    ssize_t ret;
    int error;
} oe_sendmsg_result_t;

typedef struct _oe_recvmsg_result_t
{
    ssize_t ret;
    int error;
} oe_recvmsg_result_t;

typedef struct _oe_getsockopt_result_t
{
    int ret;
    int error;
} oe_getsockopt_result_t;

typedef struct _oe_setsockopt_result_t
{
    int ret;
    int error;
} oe_setsockopt_result_t;

typedef struct _oe_listen_result_t
{
    int ret;
    int error;
} oe_listen_result_t;

typedef struct _oe_accept_result_t
{
    int ret;
    int error;
} oe_accept_result_t;

typedef struct _oe_shutdown_result_t
{
    int ret;
    int error;
} oe_shutdown_result_t;

typedef struct _oe_sockatmark_result_t
{
    int ret;
    int error;
} oe_sockatmark_result_t;

typedef struct _oe_isfdtype_result_t
{
    int ret;
    int error;
} oe_isfdtype_result_t;

#endif // __EDL_TYPES_socket__
