#include <stdio.h>


double pi_generator(int precision)
{
    int res = 2;
    for (int i = 0; i < precision; i++)
    {
        res = 1 + ((1 + i) / ((2 * i) + 1)) * res;
    }
    return res;
}
