#include <stdio.h>

size_t my_strspn(const char *s, const char *accept)
{
    int count2 = 0;
    int count = 0;
    int found = 1;
    if ((s == NULL) || (accept == NULL))
    {
        return count;
    }
    while (s[count] != '\0' && found == 1)
    {
        count2 = 0;
        found = 0;
        while (accept[count2] != '\0' && found == 0)
        {
            if (accept[count2] == s[count])
            {
                found = 1;
                count++;
            }
            count2++;
        }
    }
    return count;
}
