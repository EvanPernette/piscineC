#include <stdio.h>

void str_revert(char str[])
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    count -= 1;
    int count2 = 0;
    int aux;
    while (count2 < count)
    {
        aux = str[count];
        str[count] = str[count2];
        str[count2] = aux;
        count--;
        count2++;
    }
}
