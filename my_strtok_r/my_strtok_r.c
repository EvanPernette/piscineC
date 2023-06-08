#include <stdio.h>
#include <stdlib.h>

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    if (str == NULL)
    {
        str = *saveptr;
    }
    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }
    int count2 = 0;
    int count;
    int found = 1;
    count = 0;
    while (*str != '\0' && found == 1)
    {
        count = 0;
        found = 0;
        while (delim[count] != '\0')
        {
            if (delim[count] == *str)
            {
                *str = '\0';
                str++;
                found = 1;
            }
            count++;
        }
    }
    char *save = str;
    if (*str == '\0')
    {
        return NULL;
    }
    found = 1;
    while (*str != '\0')
    {
        count2 = 0;
        while (delim[count2] != '\0')
        {
            if (delim[count2] == *str)
            {
                *str = '\0';
                str++;
                count = 0;
                while (*str != '\0' && found == 1)
                {
                    count = 0;
                    found = 0;
                    while (delim[count] != '\0')
                    {
                        if (delim[count] == *str)
                        {
                            *str = '\0';
                            str++;
                            found = 1;
                        }
                        count++;
                    }
                }
                *saveptr = str;
                return save;
            }
            count2++;
        }
        str++;
    }
    if (*str == '\0')
    {
        *saveptr = str;
        return save;
    }
    return NULL;
}
