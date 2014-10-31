#include <unistd.h>
#include <errno.h>
#include "unp.h"

static ssize_t read_cnt = 0;
static char *read_ptr = NULL;
static char read_buf[MAXLINE] = {};

ssize_t                         /* Read "n" bytes from a descriptor. */
readn(int fd, void *vptr, size_t n)
{
    size_t  nleft;
    ssize_t nread;
    char   *ptr;

    ptr = vptr;
    nleft = n;
    while (nleft > 0) {
        if ( (nread = read(fd, ptr, nleft)) < 0) {
            if (errno == EINTR)
                nread = 0;      /* and call read() again */
            else
                return (-1);
        } else if (nread == 0)
            break;              /* EOF */

        nleft -= nread;
        ptr += nread;
    }
    return (n - nleft);         /* return >= 0 */
}

ssize_t                         /* Write "n" bytes to a descriptor. */
writen(int fd, const void *vptr, size_t n)
{
    size_t nleft;
    ssize_t nwritten;
    const char *ptr;

    ptr = vptr;
    nleft = n;
    while (nleft > 0) {
        if ( (nwritten = write(fd, ptr, nleft)) <= 0) {
            if (nwritten < 0 && errno == EINTR)
                nwritten = 0;   /* and call write() again */
            else
                return (-1);    /* error */
         }

         nleft -= nwritten;
         ptr += nwritten;
    }
    return (n);
}


static ssize_t my_read(int fd, char *ptr)
{
    if (read_cnt <= 0) {
        again:
        if ((read_cnt = read(fd, read_buf, MAXLINE) < 0)) {
            if (errno == EINTR)
                goto again;
            return -1;
        }
        else if(read_cnt == 0) {
            return 0;
        }
        read_ptr = read_buf;
    }
    read_cnt--;
    *ptr = *read_ptr++;
    return 1;
}

ssize_t readline(int fd, void *vptr, size_t len)
{
    ssize_t rc, n;
    char *ptr, c;
    ptr = (char*)vptr;
    for (n = 0; n < len; n++) {
        if ((rc = my_read(fd, &c) == 1)) {
            *ptr++ = c;
            if (c == '\n') {
                break;
            }
        }
        else if (rc == 0) {
            *ptr = 0;
            return (n-1);
        }
        else {
            return -1;
        }
    }
    *ptr = 0;
    return n;
}

ssize_t readlinebuf(void **vptrptr)
{
    if (read_cnt)
        *vptrptr = read_ptr;
    return (read_cnt);
}
