#include <netdb.h>
#include <errno.h>
#include "netdb_types.h"
#include "helloworld_u.h"
oe_getaddrinfo_result_t oe_host_ocall_getaddrinfo(const char * a, const char * b, const struct addrinfo * c, struct addrinfo ** d)
{
    oe_getaddrinfo_result_t result;
    result.ret = getaddrinfo(a, b, c, d);
    result.error = errno;
    return result;
}

oe_freeaddrinfo_result_t oe_host_ocall_freeaddrinfo(struct addrinfo * a)
{
    oe_freeaddrinfo_result_t result;
    freeaddrinfo(a);
    result.error = errno;
    return result;
}

oe_getnameinfo_result_t oe_host_ocall_getnameinfo(const struct sockaddr * a, socklen_t b, char * c, socklen_t d, char * e, socklen_t f, int g)
{
    oe_getnameinfo_result_t result;
    result.ret = getnameinfo(a, b, c, d, e, f, g);
    result.error = errno;
    return result;
}

oe_gai_strerror_result_t oe_host_ocall_gai_strerror(int a)
{
    oe_gai_strerror_result_t result;
    result.ret = gai_strerror(a);
    result.error = errno;
    return result;
}

oe_sethostent_result_t oe_host_ocall_sethostent(int a)
{
    oe_sethostent_result_t result;
    sethostent(a);
    result.error = errno;
    return result;
}

oe_endhostent_result_t oe_host_ocall_endhostent()
{
    oe_endhostent_result_t result;
    endhostent();
    result.error = errno;
    return result;
}

oe_gethostent_result_t oe_host_ocall_gethostent()
{
    oe_gethostent_result_t result;
    result.ret = gethostent();
    result.error = errno;
    return result;
}

oe_setnetent_result_t oe_host_ocall_setnetent(int a)
{
    oe_setnetent_result_t result;
    setnetent(a);
    result.error = errno;
    return result;
}

oe_endnetent_result_t oe_host_ocall_endnetent()
{
    oe_endnetent_result_t result;
    endnetent();
    result.error = errno;
    return result;
}

oe_getnetent_result_t oe_host_ocall_getnetent()
{
    oe_getnetent_result_t result;
    result.ret = getnetent();
    result.error = errno;
    return result;
}

oe_getnetbyaddr_result_t oe_host_ocall_getnetbyaddr(uint32_t a, int b)
{
    oe_getnetbyaddr_result_t result;
    result.ret = getnetbyaddr(a, b);
    result.error = errno;
    return result;
}

oe_getnetbyname_result_t oe_host_ocall_getnetbyname(const char * a)
{
    oe_getnetbyname_result_t result;
    result.ret = getnetbyname(a);
    result.error = errno;
    return result;
}

oe_setservent_result_t oe_host_ocall_setservent(int a)
{
    oe_setservent_result_t result;
    setservent(a);
    result.error = errno;
    return result;
}

oe_endservent_result_t oe_host_ocall_endservent()
{
    oe_endservent_result_t result;
    endservent();
    result.error = errno;
    return result;
}

oe_getservent_result_t oe_host_ocall_getservent()
{
    oe_getservent_result_t result;
    result.ret = getservent();
    result.error = errno;
    return result;
}

oe_getservbyname_result_t oe_host_ocall_getservbyname(const char * a, const char * b)
{
    oe_getservbyname_result_t result;
    result.ret = getservbyname(a, b);
    result.error = errno;
    return result;
}

oe_getservbyport_result_t oe_host_ocall_getservbyport(int a, const char * b)
{
    oe_getservbyport_result_t result;
    result.ret = getservbyport(a, b);
    result.error = errno;
    return result;
}

oe_setprotoent_result_t oe_host_ocall_setprotoent(int a)
{
    oe_setprotoent_result_t result;
    setprotoent(a);
    result.error = errno;
    return result;
}

oe_endprotoent_result_t oe_host_ocall_endprotoent()
{
    oe_endprotoent_result_t result;
    endprotoent();
    result.error = errno;
    return result;
}

oe_getprotoent_result_t oe_host_ocall_getprotoent()
{
    oe_getprotoent_result_t result;
    result.ret = getprotoent();
    result.error = errno;
    return result;
}

oe_getprotobyname_result_t oe_host_ocall_getprotobyname(const char * a)
{
    oe_getprotobyname_result_t result;
    result.ret = getprotobyname(a);
    result.error = errno;
    return result;
}

oe_getprotobynumber_result_t oe_host_ocall_getprotobynumber(int a)
{
    oe_getprotobynumber_result_t result;
    result.ret = getprotobynumber(a);
    result.error = errno;
    return result;
}

oe_gethostbyname_result_t oe_host_ocall_gethostbyname(const char * a)
{
    oe_gethostbyname_result_t result;
    result.ret = gethostbyname(a);
    result.error = errno;
    return result;
}

oe_gethostbyaddr_result_t oe_host_ocall_gethostbyaddr(const void * a, socklen_t b, int c)
{
    oe_gethostbyaddr_result_t result;
    result.ret = gethostbyaddr(a, b, c);
    result.error = errno;
    return result;
}

oe___h_errno_location_result_t oe_host_ocall___h_errno_location()
{
    oe___h_errno_location_result_t result;
    result.ret = __h_errno_location();
    result.error = errno;
    return result;
}

oe_herror_result_t oe_host_ocall_herror(const char * a)
{
    oe_herror_result_t result;
    herror(a);
    result.error = errno;
    return result;
}

oe_hstrerror_result_t oe_host_ocall_hstrerror(int a)
{
    oe_hstrerror_result_t result;
    result.ret = hstrerror(a);
    result.error = errno;
    return result;
}

oe_gethostbyname_r_result_t oe_host_ocall_gethostbyname_r(const char * a, struct hostent * b, char * c, size_t d, struct hostent ** e, int * f)
{
    oe_gethostbyname_r_result_t result;
    result.ret = gethostbyname_r(a, b, c, d, e, f);
    result.error = errno;
    return result;
}

oe_gethostbyname2_r_result_t oe_host_ocall_gethostbyname2_r(const char * a, int b, struct hostent * c, char * d, size_t e, struct hostent ** f, int * g)
{
    oe_gethostbyname2_r_result_t result;
    result.ret = gethostbyname2_r(a, b, c, d, e, f, g);
    result.error = errno;
    return result;
}

oe_gethostbyname2_result_t oe_host_ocall_gethostbyname2(const char * a, int b)
{
    oe_gethostbyname2_result_t result;
    result.ret = gethostbyname2(a, b);
    result.error = errno;
    return result;
}

oe_gethostbyaddr_r_result_t oe_host_ocall_gethostbyaddr_r(const void * a, socklen_t b, int c, struct hostent * d, char * e, size_t f, struct hostent ** g, int * h)
{
    oe_gethostbyaddr_r_result_t result;
    result.ret = gethostbyaddr_r(a, b, c, d, e, f, g, h);
    result.error = errno;
    return result;
}

oe_getservbyport_r_result_t oe_host_ocall_getservbyport_r(int a, const char * b, struct servent * c, char * d, size_t e, struct servent ** f)
{
    oe_getservbyport_r_result_t result;
    result.ret = getservbyport_r(a, b, c, d, e, f);
    result.error = errno;
    return result;
}

oe_getservbyname_r_result_t oe_host_ocall_getservbyname_r(const char * a, const char * b, struct servent * c, char * d, size_t e, struct servent ** f)
{
    oe_getservbyname_r_result_t result;
    result.ret = getservbyname_r(a, b, c, d, e, f);
    result.error = errno;
    return result;
}

