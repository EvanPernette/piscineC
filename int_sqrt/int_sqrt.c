#include <stdio.h>

int int_sqrt(int n)
{
    if (n < 0)
    {
        return -1;
    }
    int sqrt = 0;
    while (sqrt * sqrt < n)
    {
        sqrt = sqrt + 1;
    }
    if (sqrt * sqrt != n)
    {
        sqrt = sqrt - 1;
    }
    return sqrt;
}
