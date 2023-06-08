#include <stdio.h>

int my_strcasecmp(const char *s1, const char *s2)
{
    int count2 = 0;
    while (s1[count2] != '\0' || s2[count2] != '\0')
    {
        count2++;
    }
    if (s1[count2] == '\0' && s2[count2] != '\0')
    {
        return -1;
    }
    if (s1[count2] != '\0' && s2[count2] == '\0')
    {
        return 1;
    }
    int count = 0;
    while (s1[count] != '\0' || s2[count] != '\0')
    {
        if (s1[count] >= 'A' && s1[count] <= 'Z')
        {
            if (s2[count] >= 'A' && s2[count] <= 'Z')
            {
                if (s1[count] > s2[count])
                {
                    return 1;
                }
                if (s1[count] < s2[count])
                {
                    return -1;
                }
            }
            else if (s2[count] >= 'a' && s2[count] <= 'z')
            {
                if (s1[count] > s2[count] - 32)
                {
                    return 1;
                }
                if (s1[count] < s2[count] - 32)
                {
                    return -1;
                }
            }
            else
            {
                if (s1[count] == 0 && s2[count] > 0)
                {
                    return -1;
                }
                if (s2[count] == 0 && s1[count] > 0)
                {
                    return 1;
                }
                if (s1[count] > s2[count])
                {
                    return 1;
                }
                if (s1[count] < s2[count])
                {
                    return -1;
                }
            }
        }
        else if (s1[count] >= 'a' && s1[count] <= 'z')
        {
            if (s2[count] >= 'A' && s2[count] <= 'Z')
            {
                if (s1[count] - 32 > s2[count])
                {
                    return 1;
                }
                if (s1[count] - 32 < s2[count])
                {
                    return -1;
                }
            }
            else if (s2[count] >= 'a' && s2[count] <= 'z')
            {
                if (s1[count] > s2[count])
                {
                    return 1;
                }
                if (s1[count] < s2[count])
                {
                    return -1;
                }
            }
        }
        else
        {
            if (s1[count] == 0 && s2[count] > 0)
            {
                return -1;
            }
            if (s2[count] == 0 && s1[count] > 0)
            {
                return 1;
            }
            if (s1[count] > s2[count])
            {
                return 1;
            }
            if (s1[count] < s2[count])
            {
                return -1;
            }
        }
        count++;
    }
    return 0;
}
