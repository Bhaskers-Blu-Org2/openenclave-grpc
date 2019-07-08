#ifndef __EDL_TYPES_inet__
#define __EDL_TYPES_inet__

#include <arpa/inet.h>

typedef struct _oe_htonl_result_t
{
    uint32_t ret;
    int error;
} oe_htonl_result_t;

typedef struct _oe_htons_result_t
{
    uint16_t ret;
    int error;
} oe_htons_result_t;

typedef struct _oe_ntohl_result_t
{
    uint32_t ret;
    int error;
} oe_ntohl_result_t;

typedef struct _oe_ntohs_result_t
{
    uint16_t ret;
    int error;
} oe_ntohs_result_t;

typedef struct _oe_inet_addr_result_t
{
    in_addr_t ret;
    int error;
} oe_inet_addr_result_t;

typedef struct _oe_inet_network_result_t
{
    in_addr_t ret;
    int error;
} oe_inet_network_result_t;

typedef struct _oe_inet_ntoa_result_t
{
    char * ret;
    int error;
} oe_inet_ntoa_result_t;

typedef struct _oe_inet_pton_result_t
{
    int ret;
    int error;
} oe_inet_pton_result_t;

typedef struct _oe_inet_ntop_result_t
{
    const char * ret;
    int error;
} oe_inet_ntop_result_t;

typedef struct _oe_inet_aton_result_t
{
    int ret;
    int error;
} oe_inet_aton_result_t;

typedef struct _oe_inet_makeaddr_result_t
{
    struct in_addr ret;
    int error;
} oe_inet_makeaddr_result_t;

typedef struct _oe_inet_lnaof_result_t
{
    in_addr_t ret;
    int error;
} oe_inet_lnaof_result_t;

typedef struct _oe_inet_netof_result_t
{
    in_addr_t ret;
    int error;
} oe_inet_netof_result_t;

#endif // __EDL_TYPES_inet__
