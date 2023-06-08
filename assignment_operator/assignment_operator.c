#include <stdio.h>

void plus_equal(int *a, int *b)
{
    if (b != NULL && a != NULL)
    {
        *a += *b;
    }
}

void minus_equal(int *a, int *b)
{
    if (b != NULL && a != NULL)
    {
        *a -= *b;
    }
}

void mult_equal(int *a, int *b)
{
    if (b != NULL && a != NULL)
    {
        *a *= *b;
    }
}

int div_equal(int *a, int *b)
{
    if (a == NULL || b == NULL || *b == 0)
    {
        return 0;
    }
    else
    {
        int r = *a % *b;
        *a = *a / *b;
        return r;
    }
}
