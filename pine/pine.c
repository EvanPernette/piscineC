#include <stdio.h>

int pine(unsigned n)
{
    if (n < 3)
    {
        return 1;
    }
    int x = n;
    for (unsigned int p = 0; p < n; p++)
    {
        for (unsigned int k = 0; k < x - 1 - p; k++)
        {
            putchar(' ');
        }
        for (unsigned int x = 0; x < (2 * p) + 1; x++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    for (unsigned int p = 0; p < (n / 2); p++)
    {
        for (int k = 0; k < x - 1; k++)
        {
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }
    return 0;
}
