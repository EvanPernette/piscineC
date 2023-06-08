#include <stdio.h>

void my_strlowcase(char *str)
{
    if (str != NULL)
    {
        int count = 0;
        while (str[count] != '\0')
        {
            if (str[count] >= 'A' && str[count] <= 'Z')
            {
                str[count] += 32;
            }
            count++;
        }
    }
}
