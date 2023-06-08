#include <stdio.h>

char *my_strcpy(char *dest, const char *source)
{
    int count = 0;
    while (source[count] != '\0')
    {
        dest[count] = source[count];
        count++;
    }
    dest[count] = '\0';
    return dest;
}
