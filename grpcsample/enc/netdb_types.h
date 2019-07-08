#ifndef __EDL_TYPES_netdb__
#define __EDL_TYPES_netdb__

#include <netdb.h>

typedef struct _oe_getaddrinfo_result_t
{
    int ret;
    int error;
} oe_getaddrinfo_result_t;

typedef struct _oe_freeaddrinfo_result_t
{
    int error;
} oe_freeaddrinfo_result_t;

typedef struct _oe_getnameinfo_result_t
{
    int ret;
    int error;
} oe_getnameinfo_result_t;

typedef struct _oe_gai_strerror_result_t
{
    const char * ret;
    int error;
} oe_gai_strerror_result_t;

typedef struct _oe_sethostent_result_t
{
    int error;
} oe_sethostent_result_t;

typedef struct _oe_endhostent_result_t
{
    int error;
} oe_endhostent_result_t;

typedef struct _oe_gethostent_result_t
{
    struct hostent * ret;
    int error;
} oe_gethostent_result_t;

typedef struct _oe_setnetent_result_t
{
    int error;
} oe_setnetent_result_t;

typedef struct _oe_endnetent_result_t
{
    int error;
} oe_endnetent_result_t;

typedef struct _oe_getnetent_result_t
{
    struct netent * ret;
    int error;
} oe_getnetent_result_t;

typedef struct _oe_getnetbyaddr_result_t
{
    struct netent * ret;
    int error;
} oe_getnetbyaddr_result_t;

typedef struct _oe_getnetbyname_result_t
{
    struct netent * ret;
    int error;
} oe_getnetbyname_result_t;

typedef struct _oe_setservent_result_t
{
    int error;
} oe_setservent_result_t;

typedef struct _oe_endservent_result_t
{
    int error;
} oe_endservent_result_t;

typedef struct _oe_getservent_result_t
{
    struct servent * ret;
    int error;
} oe_getservent_result_t;

typedef struct _oe_getservbyname_result_t
{
    struct servent * ret;
    int error;
} oe_getservbyname_result_t;

typedef struct _oe_getservbyport_result_t
{
    struct servent * ret;
    int error;
} oe_getservbyport_result_t;

typedef struct _oe_setprotoent_result_t
{
    int error;
} oe_setprotoent_result_t;

typedef struct _oe_endprotoent_result_t
{
    int error;
} oe_endprotoent_result_t;

typedef struct _oe_getprotoent_result_t
{
    struct protoent * ret;
    int error;
} oe_getprotoent_result_t;

typedef struct _oe_getprotobyname_result_t
{
    struct protoent * ret;
    int error;
} oe_getprotobyname_result_t;

typedef struct _oe_getprotobynumber_result_t
{
    struct protoent * ret;
    int error;
} oe_getprotobynumber_result_t;

typedef struct _oe_gethostbyname_result_t
{
    struct hostent * ret;
    int error;
} oe_gethostbyname_result_t;

typedef struct _oe_gethostbyaddr_result_t
{
    struct hostent * ret;
    int error;
} oe_gethostbyaddr_result_t;

typedef struct _oe___h_errno_location_result_t
{
    int * ret;
    int error;
} oe___h_errno_location_result_t;

typedef struct _oe_herror_result_t
{
    int error;
} oe_herror_result_t;

typedef struct _oe_hstrerror_result_t
{
    const char * ret;
    int error;
} oe_hstrerror_result_t;

typedef struct _oe_gethostbyname_r_result_t
{
    int ret;
    int error;
} oe_gethostbyname_r_result_t;

typedef struct _oe_gethostbyname2_r_result_t
{
    int ret;
    int error;
} oe_gethostbyname2_r_result_t;

typedef struct _oe_gethostbyname2_result_t
{
    struct hostent * ret;
    int error;
} oe_gethostbyname2_result_t;

typedef struct _oe_gethostbyaddr_r_result_t
{
    int ret;
    int error;
} oe_gethostbyaddr_r_result_t;

typedef struct _oe_getservbyport_r_result_t
{
    int ret;
    int error;
} oe_getservbyport_r_result_t;

typedef struct _oe_getservbyname_r_result_t
{
    int ret;
    int error;
} oe_getservbyname_r_result_t;

#endif // __EDL_TYPES_netdb__
