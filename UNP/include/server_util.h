#ifndef __SERVER_UTIL_H__
#define __SERVER_UTIL_H__

#include <netinet/in.h>

typedef void (*procfunc) (int socketfd);

int createServerSocket(in_port_t port);
int processIncomingReq(int listenfd, procfunc handler);

#endif
