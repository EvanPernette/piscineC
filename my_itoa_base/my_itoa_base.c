#include <stdio.h>

char *my_itoa_base(int value, char *s, const char *base)
{
    int baz = 0;
    while (base[baz] != '\0')
    {
        baz++;
    }
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
    while (cop >= baz)
    {
        cop /= baz;
        count += 1;
    }

    if (neg == 1)
    {
        count++;
        s[count] = '\0';
        count--;
        while (count >= 1)
        {
            s[count] = base[value % baz];
            value /= baz;
            count--;
        }
    }
    else
    {
        s[count] = '\0';
        count--;
        while (count >= 0)
        {
            s[count] = base[value % baz];
            value /= baz;
            count--;
        }
    }
    return s;
}
