#ifndef __IO_H__
#define __IO_H__

#include <stddef.h>

ssize_t readn(int fd, void *vptr, size_t n);
ssize_t writen(int fd, const void *vptr, size_t n);
ssize_t readline(int fd, void *vptr, size_t len);
ssize_t readlinebuf(void **vptrptr);

#endif
