#include <stdio.h>

int my_round(float n)
{
    int n2 = n;
    if (n >= 0)
    {
        float rest = n - n2;
        if (rest >= 0.50)
        {
            return n2 + 1;
        }
        return n2;
    }
    else
    {
        float rest = n2 - n;
        if (rest >= 0.50)
        {
            return n2 - 1;
        }
        return n2;
    }
    return 0;
}
