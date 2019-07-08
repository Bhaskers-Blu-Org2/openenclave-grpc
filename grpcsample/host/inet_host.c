#include <arpa/inet.h>
#include <errno.h>
#include "inet_types.h"
#include "helloworld_u.h"

oe_htonl_result_t oe_host_ocall_htonl(uint32_t a)
{
    oe_htonl_result_t result;
    result.ret = htonl(a);
    result.error = errno;
    return result;
}

oe_htons_result_t oe_host_ocall_htons(uint16_t a)
{
    oe_htons_result_t result;
    result.ret = htons(a);
    result.error = errno;
    return result;
}

oe_ntohl_result_t oe_host_ocall_ntohl(uint32_t a)
{
    oe_ntohl_result_t result;
    result.ret = ntohl(a);
    result.error = errno;
    return result;
}

oe_ntohs_result_t oe_host_ocall_ntohs(uint16_t a)
{
    oe_ntohs_result_t result;
    result.ret = ntohs(a);
    result.error = errno;
    return result;
}

oe_inet_addr_result_t oe_host_ocall_inet_addr(const char * a)
{
    oe_inet_addr_result_t result;
    result.ret = inet_addr(a);
    result.error = errno;
    return result;
}

oe_inet_network_result_t oe_host_ocall_inet_network(const char * a)
{
    oe_inet_network_result_t result;
    result.ret = inet_network(a);
    result.error = errno;
    return result;
}

oe_inet_ntoa_result_t oe_host_ocall_inet_ntoa(struct in_addr a)
{
    oe_inet_ntoa_result_t result;
    result.ret = inet_ntoa(a);
    result.error = errno;
    return result;
}

oe_inet_pton_result_t oe_host_ocall_inet_pton(int a, const char * b, void * c, int d)
{
    oe_inet_pton_result_t result;
    result.ret = inet_pton(a, b, c);
    result.error = errno;
    return result;
}

oe_inet_ntop_result_t oe_host_ocall_inet_ntop(int a, const void * b, int e, char * c, socklen_t d)
{
    oe_inet_ntop_result_t result;
    result.ret = inet_ntop(a, b, c, d);
    result.error = errno;
    return result;
}

oe_inet_aton_result_t oe_host_ocall_inet_aton(const char * a, struct in_addr * b)
{
    oe_inet_aton_result_t result;
    result.ret = inet_aton(a, b);
    result.error = errno;
    return result;
}

oe_inet_makeaddr_result_t oe_host_ocall_inet_makeaddr(in_addr_t a, in_addr_t b)
{
    oe_inet_makeaddr_result_t result;
    result.ret = inet_makeaddr(a, b);
    result.error = errno;
    return result;
}

oe_inet_lnaof_result_t oe_host_ocall_inet_lnaof(struct in_addr a)
{
    oe_inet_lnaof_result_t result;
    result.ret = inet_lnaof(a);
    result.error = errno;
    return result;
}

oe_inet_netof_result_t oe_host_ocall_inet_netof(struct in_addr a)
{
    oe_inet_netof_result_t result;
    result.ret = inet_netof(a);
    result.error = errno;
    return result;
}

