#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <stddef.h>
#include <unistd.h>
#include "server_logic.h"
#include "unp.h"
#include "io.h"
#include <errno.h>
#include "error.h"

void showAddress(int socketfd)
{
    struct sockaddr_in cliaddr;
    socklen_t len;
    char    buf[MAXLINE];
    char    readbuf[MAXLINE];
    ssize_t num;
    if ((getpeername(socketfd, (SA*)&cliaddr, &len)) < 0) {
        printf("error\n");
        return;
    }
    else {
        printf("connected from %s, port %d\n",
               inet_ntop(AF_INET, &cliaddr.sin_addr, buf, sizeof(buf)),
               htons(cliaddr.sin_port));
    }
    
again:
    while ( (num = read(socketfd, readbuf, MAXLINE)) > 0) {
        printf("receive from socket %s\n", readbuf);
        /* writen(socketfd, readbuf, num); */
    }
    if (num < 0 && errno == EINTR)
        goto again;
    else if (num < 0)
        err_sys("str_echo: read error");

    

    /* if ((num = read(socketfd, readbuf, sizeof(readbuf))) < 0) { */
    /*     printf("read from socket error!\n"); */
    /*     return; */
    /* } */
    /* printf("receive from socket %s\n", readbuf); */
    /* writen(socketfd, readbuf, num); */
    return;
}
