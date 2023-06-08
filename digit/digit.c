#include <stdio.h>

unsigned int digit(int n, int k)
{
    if (n <= 0 || k <= 0)
    {
        return 0;
    }
    int x = n % 10;
    int count = 1;
    while (n > 10)
    {
        x = n % 10;
        if (x == k)
        {
            return count;
        }
        n /= 10;
        count++;
    }
    if (x == k)
    {
        return count;
    }
    return 0;
}
