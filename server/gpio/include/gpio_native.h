#ifndef __GPIO_NATIVE_H__
#define __GPIO_NATIVE_H__

#include <cstdint>

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
    void setMode(const uint8_t gpio_port, const GPIO_Native::Mode mode);
    void setPort(const uint8_t gpio_port);
    uint8_t readPort(const uint8_t gpio_port) const;

private:
    void *addr;
    int mem_fd;

private:
    GPIO_Native(const GPIO_Native &x);
    GPIO_Native& operator=(const GPIO_Native &x);

    
};


#endif
