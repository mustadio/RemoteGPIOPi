#ifndef __GPIO_NATIVE_H__
#define __GPIO_NATIVE_H__

#include <stdint.h>

class GPIO_Native
{
public:
    enum Mode
    {
        IN,
        OUT
    };
    GPIO_Native();
    ~GPIO_Native();
    void setMode(const unsigned char gpio_port, const GPIO_Native::Mode mode);
    void setPort(const unsigned char gpio_port);
    unsigned char readPort(const unsigned char gpio_port) const;

private:
    unsigned long addr_p;
    int mem_fd;

private:
    GPIO_Native(const GPIO_Native &x);
    GPIO_Native& operator=(const GPIO_Native &x);

    
};


#endif
