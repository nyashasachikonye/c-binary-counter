//SCHKUZ002 MLKTSH012
#include <stdint.h>

void delay(void);
int main(void);
void infinite_loop(void);

int main(void)
{
    *(uint32_t*)0x40021014 |= 0x40000;
    *(uint16_t*)0x48000400 = 0x00005555;
    *(uint16_t*)0x48000414 = 0x00A0;
    infinite_loop();
}

void infinite_loop(void)
{
    while (1)
    {
        delay();
        *(uint16_t*)0x48000414 += 1;
    }
}

void delay(void)
{
    uint32_t *bar;
    bar = (uint32_t *)0x200000F0;
    *bar = 332388;
    volatile uint32_t i = 0;
    for(; i < (*bar); i++)
    {
        *(uint8_t*)0x200000F0 =-  i;

    }
}
