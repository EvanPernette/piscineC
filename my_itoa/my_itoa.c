#include <stdio.h>
#include <stdlib.h>

char *my_itoa(int value, char *s)
{
    int count = 1;
    int cop = value;
    int neg = 0;
    if (value < 0)
    {
        s[0] = '-';
        value = -value;
        cop = value;
        neg = 1;
    }
    while (cop > 10)
    {
        cop /= 10;
        count += 1;
    }

    if (neg == 1)
    {
        count++;
        s[count] = '\0';
        count--;
        while (count >= 1)
        {
            s[count] = value % 10 + '0';
            value /= 10;
            count--;
        }
    }
    else
    {
        s[count] = '\0';
        count--;
        while (count >= 0)
        {
            s[count] = value % 10 + '0';
            value /= 10;
            count--;
        }
    }
    return s;
}
