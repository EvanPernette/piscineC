#include <stdio.h>

int my_pow(int a, int b)
{
    int n = 1;
    int tot = 1;
    if (b % 2 == 0)
    {
        while (n <= b)
        {
            tot *= a * a;
            n += 2;
        }
    }
    else
    {
        tot = a;
        while (n <= b - 1)
        {
            tot *= a * a;
            n += 2;
        }
    }
    return tot;
}
