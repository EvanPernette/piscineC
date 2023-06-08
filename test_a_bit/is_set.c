#include <stdio.h>

unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned short flag_unset = 1 << (n - 1);
    unsigned short bit = value & flag_unset;
    if (bit > 0)
    {
        return 1;
    }
    return bit;
}
