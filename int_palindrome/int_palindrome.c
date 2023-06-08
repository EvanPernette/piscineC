#include <stdio.h>

int int_palindrome(int n)
{
    int reverse = 10;
    int count = 10;
    if (n < 0)
    {
        n = n - (2 * n);
    }
    while (n / count > 10)
    {
        count = count * 10;
    }
    int aux = n;
    while (count > reverse)
    {
        if (n % reverse != aux / count)
        {
            return 0;
        }
        aux = aux % count;
        count /= 10;
        n /= 10;
    }
    return 1;
}
