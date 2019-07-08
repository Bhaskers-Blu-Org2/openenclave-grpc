#include <arpa/inet.h>
#include <errno.h>
#include "inet_types.h"
#include "helloworld_t.h"
uint32_t htonl(uint32_t a)
{
    oe_htonl_result_t retval;
    oe_host_ocall_htonl(&retval, a);
    errno = retval.error;
    return retval.ret;
}

uint16_t htons(uint16_t a)
{
    oe_htons_result_t retval;
    oe_host_ocall_htons(&retval, a);
    errno = retval.error;
    return retval.ret;
}

uint32_t ntohl(uint32_t a)
{
    oe_ntohl_result_t retval;
    oe_host_ocall_ntohl(&retval, a);
    errno = retval.error;
    return retval.ret;
}

uint16_t ntohs(uint16_t a)
{
    oe_ntohs_result_t retval;
    oe_host_ocall_ntohs(&retval, a);
    errno = retval.error;
    return retval.ret;
}

in_addr_t inet_addr(const char * a)
{
    oe_inet_addr_result_t retval;
    oe_host_ocall_inet_addr(&retval, a);
    errno = retval.error;
    return retval.ret;
}

in_addr_t inet_network(const char * a)
{
    oe_inet_network_result_t retval;
    oe_host_ocall_inet_network(&retval, a);
    errno = retval.error;
    return retval.ret;
}

char * inet_ntoa(struct in_addr a)
{
    oe_inet_ntoa_result_t retval;
    oe_host_ocall_inet_ntoa(&retval, a);
    errno = retval.error;
    return retval.ret;
}

int inet_pton(int a, const char * b, void * c)
{
    oe_inet_pton_result_t retval;
    int size = sizeof(struct in_addr);
    if(a == AF_INET6)
    {
        size = sizeof(struct in6_addr);
    }
    oe_host_ocall_inet_pton(&retval, a, b, c, size);
    errno = retval.error;
    return retval.ret;
}

const char * inet_ntop(int a, const void * b, char * c, socklen_t d)
{
    oe_inet_ntop_result_t retval;
    int size = sizeof(struct in_addr);
    if(a == AF_INET6)
    {
        size = sizeof(struct in6_addr);
    }

    oe_host_ocall_inet_ntop(&retval, a, b, size, c, d);
    errno = retval.error;
    return retval.ret;
}

int inet_aton(const char * a, struct in_addr * b)
{
    oe_inet_aton_result_t retval;
    oe_host_ocall_inet_aton(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

struct in_addr inet_makeaddr(in_addr_t a, in_addr_t b)
{
    oe_inet_makeaddr_result_t retval;
    oe_host_ocall_inet_makeaddr(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

in_addr_t inet_lnaof(struct in_addr a)
{
    oe_inet_lnaof_result_t retval;
    oe_host_ocall_inet_lnaof(&retval, a);
    errno = retval.error;
    return retval.ret;
}

in_addr_t inet_netof(struct in_addr a)
{
    oe_inet_netof_result_t retval;
    oe_host_ocall_inet_netof(&retval, a);
    errno = retval.error;
    return retval.ret;
}

