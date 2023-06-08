#include <stdio.h>

int my_strcasecmp(const char *s1, const char *s2)
{
    int count = 0;
    while (s1[count] != '\0' || s2[count] != '\0')
    {
        if (s1[count] > s2[count])
        {
            return 1;
        }
        if (s1[count] < s2[count])
        {
            return -1;
        }
        count++;
    }
    if (s1[count] == '\0' && s2[count] != '\0')
    {
        return -1;
    }
    if (s1[count] != '\0' && s2[count] == '\0')
    {
        return 1;
    }
    if (s1[count] == '\0' && s2[count] == '\0')
    {
        return 0;
    }
    return 0;
}
