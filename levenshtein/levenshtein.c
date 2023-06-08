#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t levenshtein(const char *s1, const char *s2)
{
    size_t lens1 = 0;
    size_t lens2 = 0;
    while (s1[lens1] != '\0')
    {
        lens1 += 1;
    }
    while (s2[lens2] != '\0')
    {
        lens2 += 1;
    }
    size_t *lev = malloc(sizeof(size_t) * ((lens1 + 1) * (lens2 + 1)));
    for (size_t w = 0; w < (lens1 + 1) * (lens2 + 1); w++)
    {
        lev[w] = 0;
    }
    unsigned int count = 0;
    for (unsigned int i = 0; i <= lens1; i++)
    {
        lev[i * (lens2 + 1)] = i;
    }
    for (unsigned int j = 0; j <= lens2; j++)
    {
        lev[j] = j;
    }
    for (unsigned int i = 1; i <= lens1; i++)
    {
        for (unsigned int j = 1; j <= lens2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                count = 0;
            }
            else
            {
                count = 1;
            }
            if (((lev[(i - 1) * (lens2 + 1) + j] + 1)
                 < (lev[i * (lens2 + 1) + j - 1] + 1))
                && ((lev[(i - 1) * (lens2 + 1) + j] + 1)
                    < (lev[(i - 1) * (lens2 + 1) + j - 1] + count)))
            {
                lev[i * (lens2 + 1) + j] = lev[(i - 1) * (lens2 + 1) + j] + 1;
            }
            else if (((lev[i * (lens2 + 1) + j - 1] + 1)
                      < lev[(i - 1) * (lens2 + 1) + j] + 1)
                     && ((lev[i * (lens2 + 1) + j - 1] + 1)
                         < (lev[(i - 1) * (lens2 + 1) + j - 1] + count)))
            {
                lev[i * (lens2 + 1) + j] = lev[i * (lens2 + 1) + j - 1] + 1;
            }
            else
            {
                lev[i * (lens2 + 1) + j] =
                    lev[(i - 1) * (lens2 + 1) + j - 1] + count;
            }
        }
    }
    size_t res = lev[(lens1 + 1) * (lens2 + 1) - 1];
    free(lev);
    return res;
}
