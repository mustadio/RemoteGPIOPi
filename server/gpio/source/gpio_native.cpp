#include "gpio_native.h"

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdexcept>



GPIO_Native::GPIO_Native()
{
    const uint32_t BCM2708_PERI_BASE = 0x20000000;
    const uint32_t GPIO_BASE = BCM2708_PERI_BASE + 0x200000;
    const uint32_t BLOCK_SIZE = 4096;
    
    if ((mem_fd = open("/dev/mem", O_RDWR|O_SYNC) ) < 0)
        throw std::runtime_error("Failed to open /dev/mem, try checking permissions.");
    
    addr = mmap(
        NULL,
        BLOCK_SIZE,
        PROT_READ|PROT_WRITE,
        MAP_SHARED,
        mem_fd,     
        GPIO_BASE);

    if (addr == MAP_FAILED)
        throw std::runtime_error("mmap failed.");

}

GPIO_Native::~GPIO_Native()
{
}

void GPIO_Native::setMode(const uint8_t gpio_port, const GPIO_Native::Mode mode)
{
}

void GPIO_Native::setPort(const uint8_t gpio_port)
{
}

uint8_t GPIO_Native::readPort(const uint8_t gpio_port) const
{
    return 0;
}
