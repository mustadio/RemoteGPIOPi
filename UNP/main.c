
#include <stdio.h>
/* #include <arpa/inet.h> */
/* #include <unistd.h> */
#include "unp.h"
#include "error.h"
#include "server_util.h"
#include "server_logic.h"


/* void showIncoming(int socketfd) */
/* { */
/*     printf("Incoming Request\n"); */
/*     return; */
/* } */

int main()
{
    int fd = createServerSocket(8888);
    processIncomingReq(fd, showAddress);
    return 0;
}


