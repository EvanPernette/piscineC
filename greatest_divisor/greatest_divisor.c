#include <stdio.h>

unsigned int greatest_divisor(unsigned int n)
{
    int count = 1;
    unsigned max = 1;
    int x = n / 2;
    while (x >= count)
    {
        if ((n % count) == 0)
        {
            max = count;
        }
        count++;
    }
    return max;
}
