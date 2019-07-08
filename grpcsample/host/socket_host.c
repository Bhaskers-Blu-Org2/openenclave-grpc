#include <sys/socket.h>
#include <errno.h>
#include "socket_types.h"
#include "helloworld_u.h"

oe_socket_result_t oe_host_ocall_socket(int a, int b, int c)
{
    oe_socket_result_t result;
    result.ret = socket(a, b, c);
    result.error = errno;
    return result;
}

oe_socketpair_result_t oe_host_ocall_socketpair(int a, int b, int c, int d[2])
{
    oe_socketpair_result_t result;
    result.ret = socketpair(a, b, c, d);
    result.error = errno;
    return result;
}

oe_bind_result_t oe_host_ocall_bind(int a, const struct sockaddr * b, socklen_t c)
{
    oe_bind_result_t result;
    result.ret = bind(a, b, c);
    result.error = errno;
    return result;
}

oe_getsockname_result_t oe_host_ocall_getsockname(int a, struct sockaddr * b, socklen_t c_, socklen_t * c)
{
    oe_getsockname_result_t result;
    result.ret = getsockname(a, b, c);
    result.error = errno;
    return result;
}

oe_connect_result_t oe_host_ocall_connect(int a, const struct sockaddr * b, socklen_t c)
{
    oe_connect_result_t result;
    result.ret = connect(a, b, c);
    result.error = errno;
    return result;
}

oe_getpeername_result_t oe_host_ocall_getpeername(int a, struct sockaddr * b, socklen_t c_, socklen_t * c)
{
    oe_getpeername_result_t result;
    result.ret = getpeername(a, b, c);
    result.error = errno;
    return result;
}

oe_send_result_t oe_host_ocall_send(int a, const void * b, int c, int d)
{
    oe_send_result_t result;
    result.ret = send(a, b, c, d);
    result.error = errno;
    return result;
}

oe_recv_result_t oe_host_ocall_recv(int a, void * b, int c, int d)
{
    oe_recv_result_t result;
    result.ret = recv(a, b, c, d);
    result.error = errno;
    return result;
}

oe_sendto_result_t oe_host_ocall_sendto(int a, const void * b, int c, int d, const struct sockaddr * e, socklen_t f)
{
    oe_sendto_result_t result;
    result.ret = sendto(a, b, c, d, e, f);
    result.error = errno;
    return result;
}

oe_recvfrom_result_t oe_host_ocall_recvfrom(int a, void * b, int c, int d, struct sockaddr * e, socklen_t f_, socklen_t * f)
{
    oe_recvfrom_result_t result;
    result.ret = recvfrom(a, b, c, d, e, f);
    result.error = errno;
    return result;
}

        
oe_sendmsg_result_t oe_host_ocall_sendmsg(int a, struct msghdr * b, int c, void *msg_name, int msg_namelen, struct iovec *msg_iov, int msg_iovlen, void *msg_control, int msg_controllen, int msg_flags, void * iov_buffer, int total_iovlen)
{
    oe_sendmsg_result_t result;    
    memcpy(b->msg_name, msg_name, msg_namelen);
    b->msg_namelen = msg_namelen;
    b->msg_iov = msg_iov;
    b->msg_iovlen = msg_iovlen;
    memcpy(b->msg_control, msg_control, msg_controllen);
    b->msg_controllen = msg_controllen;
    b->msg_flags = msg_flags;
    
    int length_so_far = 0;
    for(int i =0 ;  i < msg_iovlen; i++)
    {
        b->msg_iov[i].iov_base = ((char*)iov_buffer) + length_so_far;
        b->msg_iov[i].iov_len = msg_iov[i].iov_len;
        length_so_far =length_so_far +  b->msg_iov[i].iov_len;
        //printf(" host b->msg_iov[i].iov_len = %d\n",b->msg_iov[i].iov_len);
    }
    /*for(int i =0 ; i < b->msg_iovlen; i++)
    {
      printf("host iov = %d of %d\n", i, b->msg_iovlen); 
      for(int k=0; k < b->msg_iov[i].iov_len; k++)
        printf("%02x\t", ((char*)(b->msg_iov[i].iov_base))[k]);
      printf(" host done printing iov \n\n");
    }
    printf("host side: b->msg_namlen=%d, b->msg_iovlen=%d, b->msg_controllen=%d, b->msg_flags=%d\n", b->msg_namelen, b->msg_iovlen, b->msg_controllen, b->msg_flags);*/

    result.ret = sendmsg(a, b, c);
    result.error = errno;

    //printf("sendmsg: ret=%d, errno=%d\n", result.ret, errno);
    return result;
}




oe_recvmsg_result_t oe_host_ocall_recvmsg(int a, struct msghdr* b,
        int c, void* msg_name, int msg_namelen,  int *actual_msg_namelen,  struct iovec *msg_iov, int msg_iovlen, int * actual_msg_iovlen, void *msg_control, int msg_controllen, int *actual_msg_controllen,  int *actual_msg_flags, void *individual_iov_base, int individual_iovlen, int *individual_actualiovlen)
{
     oe_recvmsg_result_t result;
     
     //printf("msg_iovlen = %d\n", msg_iovlen);
     if(msg_iovlen != 1)
     {
       abort();
     }
     
      struct msghdr message;
      b->msg_name=msg_name;
      b->msg_namelen=msg_namelen;
      b->msg_iov=msg_iov;
      b->msg_iov[0].iov_base=(char*)individual_iov_base;
      b->msg_iov[0].iov_len=individual_iovlen;
      b->msg_iovlen=msg_iovlen;
      b->msg_control=msg_control;
      b->msg_controllen=msg_controllen;
      b->msg_flags= *actual_msg_flags;     
      
    result.ret = recvmsg(a, b, c);
    *actual_msg_namelen = b->msg_namelen;
    *actual_msg_controllen = b->msg_controllen;
    *actual_msg_iovlen = b->msg_iov[0].iov_len;
    *actual_msg_flags = b->msg_flags;
    result.error = errno;
    
    //printf("recvmsg: ret=%d, errno=%d\n", result.ret, errno);
    return result;
}

oe_getsockopt_result_t oe_host_ocall_getsockopt(int a, int b, int c, void * d, socklen_t e_, socklen_t * e)
{
    oe_getsockopt_result_t result;
    result.ret = getsockopt(a, b, c, d, e);
    result.error = errno;
    return result;
}

oe_setsockopt_result_t oe_host_ocall_setsockopt(int a, int b, int c, const void * d, socklen_t e)
{
    oe_setsockopt_result_t result;
    result.ret = setsockopt(a, b, c, d, e);
    result.error = errno;
    return result;
}

oe_listen_result_t oe_host_ocall_listen(int a, int b)
{
    oe_listen_result_t result;
    result.ret = listen(a, b);
    result.error = errno;
    return result;
}

oe_accept_result_t oe_host_ocall_accept(int a, struct sockaddr * b, socklen_t c_, socklen_t * c)
{
    oe_accept_result_t result;
    result.ret = accept(a, b, c);
    result.error = errno;
    return result;
}

oe_shutdown_result_t oe_host_ocall_shutdown(int a, int b)
{
    oe_shutdown_result_t result;
    result.ret = shutdown(a, b);
    result.error = errno;
    return result;
}

oe_sockatmark_result_t oe_host_ocall_sockatmark(int a)
{
    oe_sockatmark_result_t result;
    result.ret = sockatmark(a);
    result.error = errno;
    return result;
}

oe_isfdtype_result_t oe_host_ocall_isfdtype(int a, int b)
{
    oe_isfdtype_result_t result;
    result.ret = isfdtype(a, b);
    result.error = errno;
    return result;
}

