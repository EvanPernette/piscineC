#include <stdio.h>

unsigned char rol(unsigned char value, unsigned char roll)
{
    int mask = 1 << 7;
    int mask2;
    while (roll > 0)
    {
        mask2 = (value & mask) >> 7;
        if (mask2 == 1)
        {
            value -= mask;
        }
        value = value * 2;
        value += mask2;
        roll--;
    }
    return value;
}
