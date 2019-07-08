#include <stdio.h>
#include <netdb.h>
#include <errno.h>
#include "netdb_types.h"
#include "helloworld_t.h"
int getaddrinfo(const char * a, const char * b, const struct addrinfo * c, struct addrinfo ** d)
{
    oe_getaddrinfo_result_t retval;
    printf("getaddrinfo \n");
    oe_host_ocall_getaddrinfo(&retval, a, b, c, d);
    errno = retval.error;
    return retval.ret;
}

void freeaddrinfo(struct addrinfo * a)
{
    oe_freeaddrinfo_result_t retval;
    printf("freeaddrinfo \n");
    oe_host_ocall_freeaddrinfo(&retval, a);
    errno = retval.error;
}

int getnameinfo(const struct sockaddr * a, socklen_t b, char * c, socklen_t d, char * e, socklen_t f, int g)
{
    oe_getnameinfo_result_t retval;
    printf("getnameinfo\n");
    oe_host_ocall_getnameinfo(&retval, a, b, c, d, e, f, g);
    errno = retval.error;
    return retval.ret;
}

const char * gai_strerror(int a)
{
    oe_gai_strerror_result_t retval;
    oe_host_ocall_gai_strerror(&retval, a);
    errno = retval.error;
    return retval.ret;
}

void sethostent(int a)
{
    oe_sethostent_result_t retval;
    oe_host_ocall_sethostent(&retval, a);
    errno = retval.error;
}

void endhostent()
{
    oe_endhostent_result_t retval;
    oe_host_ocall_endhostent(&retval);
    errno = retval.error;
}

struct hostent * gethostent()
{
    oe_gethostent_result_t retval;
    printf("gethostent \n");
    oe_host_ocall_gethostent(&retval);
    errno = retval.error;
    return retval.ret;
}

void setnetent(int a)
{
    oe_setnetent_result_t retval;
    printf("setnetent\n");
    oe_host_ocall_setnetent(&retval, a);
    errno = retval.error;
}

void endnetent()
{
    oe_endnetent_result_t retval;
    oe_host_ocall_endnetent(&retval);
    errno = retval.error;
}

struct netent * getnetent()
{
    oe_getnetent_result_t retval;
    oe_host_ocall_getnetent(&retval);
    errno = retval.error;
    return retval.ret;
}

struct netent * getnetbyaddr(uint32_t a, int b)
{
    oe_getnetbyaddr_result_t retval;
    printf("getnetbyaddr\n");
    oe_host_ocall_getnetbyaddr(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

struct netent * getnetbyname(const char * a)
{
    oe_getnetbyname_result_t retval;
    printf("getnetbyname \n");
    oe_host_ocall_getnetbyname(&retval, a);
    errno = retval.error;
    return retval.ret;
}

void setservent(int a)
{
    oe_setservent_result_t retval;
    oe_host_ocall_setservent(&retval, a);
    errno = retval.error;
}

void endservent()
{
    oe_endservent_result_t retval;
    oe_host_ocall_endservent(&retval);
    errno = retval.error;
}

struct servent * getservent()
{
    oe_getservent_result_t retval;
    printf("getservent\n");
    oe_host_ocall_getservent(&retval);
    errno = retval.error;
    return retval.ret;
}

struct servent * getservbyname(const char * a, const char * b)
{
    oe_getservbyname_result_t retval;
    oe_host_ocall_getservbyname(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

struct servent * getservbyport(int a, const char * b)
{
    oe_getservbyport_result_t retval;
    oe_host_ocall_getservbyport(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

void setprotoent(int a)
{
    oe_setprotoent_result_t retval;
    oe_host_ocall_setprotoent(&retval, a);
    errno = retval.error;
}

void endprotoent()
{
    oe_endprotoent_result_t retval;
    oe_host_ocall_endprotoent(&retval);
    errno = retval.error;
}

struct protoent * getprotoent()
{
    oe_getprotoent_result_t retval;
    printf("get protoent\n");
    oe_host_ocall_getprotoent(&retval);
    errno = retval.error;
    return retval.ret;
}

struct protoent * getprotobyname(const char * a)
{
    oe_getprotobyname_result_t retval;
    printf("getprotobyname\n");
    oe_host_ocall_getprotobyname(&retval, a);
    errno = retval.error;
    return retval.ret;
}

struct protoent * getprotobynumber(int a)
{
    oe_getprotobynumber_result_t retval;
    printf("getprotobynumber\n");
    oe_host_ocall_getprotobynumber(&retval, a);
    errno = retval.error;
    return retval.ret;
}

struct hostent * gethostbyname(const char * a)
{
    oe_gethostbyname_result_t retval;
    printf("gethostbyname\n");
    oe_host_ocall_gethostbyname(&retval, a);
    errno = retval.error;
    return retval.ret;
}

struct hostent * gethostbyaddr(const void * a, socklen_t b, int c)
{
    oe_gethostbyaddr_result_t retval;
    printf("gethostbyaddr\n");
    oe_host_ocall_gethostbyaddr(&retval, a, b, c);
    errno = retval.error;
    return retval.ret;
}

int * __h_errno_location()
{
    oe___h_errno_location_result_t retval;
    oe_host_ocall___h_errno_location(&retval);
    errno = retval.error;
    return retval.ret;
}

void herror(const char * a)
{
    oe_herror_result_t retval;
    oe_host_ocall_herror(&retval, a);
    errno = retval.error;
}

const char * hstrerror(int a)
{
    oe_hstrerror_result_t retval;
    oe_host_ocall_hstrerror(&retval, a);
    errno = retval.error;
    return retval.ret;
}

int gethostbyname_r(const char * a, struct hostent * b, char * c, size_t d, struct hostent ** e, int * f)
{
    oe_gethostbyname_r_result_t retval;
    printf("gethostbyname_r\n");
    oe_host_ocall_gethostbyname_r(&retval, a, b, c, d, e, f);
    errno = retval.error;
    return retval.ret;
}

int gethostbyname2_r(const char * a, int b, struct hostent * c, char * d, size_t e, struct hostent ** f, int * g)
{
    oe_gethostbyname2_r_result_t retval;
    printf("gethostbyname2_r\n");
    oe_host_ocall_gethostbyname2_r(&retval, a, b, c, d, e, f, g);
    errno = retval.error;
    return retval.ret;
}

struct hostent * gethostbyname2(const char * a, int b)
{
    oe_gethostbyname2_result_t retval;
    printf("gethostbyname2\n");
    oe_host_ocall_gethostbyname2(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

int gethostbyaddr_r(const void * a, socklen_t b, int c, struct hostent * d, char * e, size_t f, struct hostent ** g, int * h)
{
    oe_gethostbyaddr_r_result_t retval;
    printf("gethostbyaddr_r\n");
    oe_host_ocall_gethostbyaddr_r(&retval, a, b, c, d, e, f, g, h);
    errno = retval.error;
    return retval.ret;
}

int getservbyport_r(int a, const char * b, struct servent * c, char * d, size_t e, struct servent ** f)
{
    oe_getservbyport_r_result_t retval;
    printf("getservbyport_r\n");
    oe_host_ocall_getservbyport_r(&retval, a, b, c, d, e, f);
    errno = retval.error;
    return retval.ret;
}

int getservbyname_r(const char * a, const char * b, struct servent * c, char * d, size_t e, struct servent ** f)
{
    oe_getservbyname_r_result_t retval;
    printf("getservbyname_r\n");
    oe_host_ocall_getservbyname_r(&retval, a, b, c, d, e, f);
    errno = retval.error;
    return retval.ret;
}

