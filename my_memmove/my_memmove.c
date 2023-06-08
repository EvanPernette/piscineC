#include <stdio.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
    char *auxdest = (char *)dest;
    char *auxsrc = (char *)src;
    size_t count = 0;
    if (auxsrc > auxdest)
    {
        while (count < n)
        {
            *auxdest = *auxsrc;
            auxdest++;
            auxsrc++;
            count++;
        }
    }
    else
    {
        while (count < n)
        {
            auxdest[n - 1 - count] = auxsrc[n - 1 - count];
            count++;
        }
    }
    return dest;
}
