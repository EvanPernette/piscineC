#include <stdio.h>

int my_strstr(const char *haystack, const char *needle)
{
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    while (needle[count3] != '\0')
    {
        count3++;
    }
    if (count3 == 0)
    {
        return 0;
    }
    while (haystack[count] != '\0')
    {
        while (needle[count2] == haystack[count + count2]
               && needle[count2] != '\0' && haystack[count + count2] != '\0')
        {
            count2++;
        }
        if (count2 == count3)
        {
            return count;
        }
        count2 = 0;
        count++;
    }
    return -1;
}
