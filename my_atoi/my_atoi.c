#include <stdio.h>

int my_atoi(const char *str)
{
    int count = 0;
    int count1 = 1;
    int count2 = 0;
    int count3 = 0;
    int res = 0;
    while (str[count2] == ' ')
    {
        count2++;
    }
    if (str[count2] == '+' || str[count2] == '-')
    {
        count = count2 + 1;
    }
    else
    {
        count = count2;
    }
    count3 = count;
    while (str[count + 1] != '\0')
    {
        if (str[count] >= '0' && str[count] <= '9')
        {
            count1 *= 10;
        }
        else
        {
            return 0;
        }
        count++;
    }
    while (str[count3] != '\0')
    {
        if (str[count3] >= '0' && str[count3] <= '9')
        {
            res += (str[count3] - 48) * count1;
            count1 = count1 / 10;
        }
        else
        {
            return 0;
        }
        count3++;
    }
    if (str[count2] == '-')
    {
        return -res;
    }
    return res;
}
