#include <stdio.h>
#include <sys/socket.h>
#include <errno.h>
#include "socket_types.h"
#include "helloworld_t.h"
int socket(int a, int b, int c)
{
    oe_socket_result_t retval;
    oe_host_ocall_socket(&retval, a, b, c);
    errno = retval.error;
    return retval.ret;
}

int socketpair(int a, int b, int c, int d[2])
{
    oe_socketpair_result_t retval;
    oe_host_ocall_socketpair(&retval, a, b, c, d);
    errno = retval.error;
    return retval.ret;
}

int bind(int a, const struct sockaddr * b, socklen_t c)
{
    oe_bind_result_t retval;
    oe_host_ocall_bind(&retval, a, b, c);
    errno = retval.error;
    return retval.ret;
}

int getsockname(int a, struct sockaddr * b, socklen_t * c)
{
    oe_getsockname_result_t retval;
    printf("getsockname called\n");
    oe_host_ocall_getsockname(&retval, a, b, *c, c);
    errno = retval.error;
    return retval.ret;
}

int connect(int a, const struct sockaddr * b, socklen_t c)
{
    oe_connect_result_t retval;
    printf("connect called\n");
    oe_host_ocall_connect(&retval, a, b, c);
    errno = retval.error;
    return retval.ret;
}

int getpeername(int a, struct sockaddr * b, socklen_t * c)
{
    oe_getpeername_result_t retval;
    printf("getpeername called n");
    oe_host_ocall_getpeername(&retval, a, b, *c, c);
    errno = retval.error;
    return retval.ret;
}

ssize_t send(int a, const void * b, size_t c, int d)
{
    oe_send_result_t retval;
    int len =(int) c;
    printf("send called\n");
    oe_host_ocall_send(&retval, a, b, len, d);
    errno = retval.error;
    return retval.ret;
}

ssize_t recv(int a, void * b, size_t c, int d)
{
    oe_recv_result_t retval;
    int len =(int)c;
    printf("recv called \n");
    oe_host_ocall_recv(&retval, a, b, len, d);
    errno = retval.error;
    return retval.ret;
}

ssize_t sendto(int a, const void * b, int c, int d, const struct sockaddr * e, socklen_t f)
{
    oe_sendto_result_t retval;
    printf("sendto called\n");
    oe_host_ocall_sendto(&retval, a, b, c, d, e, f);
    errno = retval.error;
    return retval.ret;
}

ssize_t recvfrom(int a, void * b, int c, int d, struct sockaddr * e, socklen_t * f)
{
    oe_recvfrom_result_t retval;
    printf("recvfrom called\n");
    oe_host_ocall_recvfrom(&retval, a, b, c, d, e, *f, f);
    errno = retval.error;
    return retval.ret;
}






ssize_t sendmsg(int a, const struct msghdr * b, int c)
{
    oe_sendmsg_result_t retval;
    int total_len = 0;
    //printf("sendmsg called\n");
    for (int i =0 ; i < b->msg_iovlen; i++)
    {
      total_len =total_len +  b->msg_iov[i].iov_len;
    }
    //printf("sendmsg called total bytes: total_len=%d\n", total_len);
    char *iovbuff = (char *)malloc(total_len);
    if(!iovbuff)
    {
      abort();
    }
    char *start = iovbuff;
    for(int i =0 ; i < b->msg_iovlen; i++)
    { 
      memcpy(start, b->msg_iov[i].iov_base, b->msg_iov[i].iov_len);
      start = start +  b->msg_iov[i].iov_len;
    }
    /*for(int i =0 ; i < b->msg_iovlen; i++)
    {
      printf("Enclave iov = %d of %d\n", i, b->msg_iovlen); 
      for(int k=0; k < b->msg_iov[i].iov_len; k++)
        printf("%02x\t", ((char*)(b->msg_iov[i].iov_base))[k]);
      printf(" Enclave done printing iov \n\n");
    }
    printf("Enclave side: b->msg_namlen=%d, b->msg_iovlen=%d, b->msg_controllen=%d, b->msg_flags=%d\n", b->msg_namelen, b->msg_iovlen, b->msg_controllen, b->msg_flags);*/
    
    int actual_msg_namelen;
    oe_host_ocall_sendmsg(&retval, a, (struct msghdr*)b, c, b->msg_name, b->msg_namelen, (struct iovec*)b->msg_iov, b->msg_iovlen, b->msg_control, b->msg_controllen,  b->msg_flags, iovbuff, total_len);
    errno = retval.error;
    return retval.ret;
}

ssize_t recvmsg(int a, struct msghdr * b, int c)
{
    oe_recvmsg_result_t retval;
    
    if(b->msg_iovlen != 1)
    {
      abort();
    }
    //printf("revcmsg called\n");
     
   
    int actual_msg_namelen, actual_msg_controllen, actual_msg_iovlen;
    int actual_individual_iovlen;
    
    oe_host_ocall_recvmsg(&retval, a, b, c,  b->msg_name, b->msg_namelen, &actual_msg_namelen,  (struct iovec*)b->msg_iov, b->msg_iovlen, &actual_msg_iovlen,
    b->msg_control, b->msg_controllen, &actual_msg_controllen, &b->msg_flags, b->msg_iov[0].iov_base, b->msg_iov[0].iov_len, &actual_individual_iovlen );  
    
    b->msg_namelen = actual_msg_namelen;
    b->msg_controllen = actual_msg_controllen;
    b->msg_iov[0].iov_len = actual_individual_iovlen;
    b->msg_iovlen = actual_msg_iovlen;
     
    errno = retval.error;
    b = nullptr;
    return retval.ret;
}

int getsockopt(int a, int b, int c, void * d, socklen_t * e)
{
    oe_getsockopt_result_t retval;
    oe_host_ocall_getsockopt(&retval, a, b, c, d, *e, e);
    errno = retval.error;
    return retval.ret;
}

int setsockopt(int a, int b, int c, const void * d, socklen_t e)
{
    oe_setsockopt_result_t retval;
    oe_host_ocall_setsockopt(&retval, a, b, c, d, e);
    errno = retval.error;
    return retval.ret;
}

int listen(int a, int b)
{
    oe_listen_result_t retval;
    oe_host_ocall_listen(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

int accept(int a, struct sockaddr * b, socklen_t * c)
{
    oe_accept_result_t retval;
    oe_host_ocall_accept(&retval, a, b, *c, c);
    errno = retval.error;
    return retval.ret;
}

int shutdown(int a, int b)
{
    oe_shutdown_result_t retval;
    oe_host_ocall_shutdown(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

int sockatmark(int a)
{
    oe_sockatmark_result_t retval;
    oe_host_ocall_sockatmark(&retval, a);
    errno = retval.error;
    return retval.ret;
}

int isfdtype(int a, int b)
{
    oe_isfdtype_result_t retval;
    oe_host_ocall_isfdtype(&retval, a, b);
    errno = retval.error;
    return retval.ret;
}

