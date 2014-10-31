#include <sys/socket.h>
#include <arpa/inet.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "unp.h"
#include "error.h"
#include "server_util.h"



int createServerSocket(in_port_t port)
{
    struct sockaddr_in servaddr;
    int listenfd;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if ((bind(listenfd, (SA*)&servaddr, sizeof(servaddr))) < 0) {
        err_sys("bind error!");
    }
    if ((listen(listenfd, 1024)) <0) {
        err_sys("listen error!");
    }
    return listenfd;
}

int processIncomingReq(int listenfd, procfunc handler)
{
    struct sockaddr_in cliaddr;
    int connfd;
    socklen_t len;
    pid_t childpid;
    for ( ; ; ) {
        if ((connfd =
             accept(listenfd, (SA*)&cliaddr, &len)) < 0) {
            err_sys("accept error!");
        }
        if ((childpid = fork()) == 0) {
            close(listenfd);
            handler(connfd);
            exit(0);
        }
        close(connfd);
    }
    return 0;
}

