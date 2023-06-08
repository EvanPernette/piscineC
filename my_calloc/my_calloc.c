#include <stdio.h>
#include <stdlib.h>

void *my_calloc(size_t size, size_t n)
{
    if (size <= 0 || n <= 0)
    {
        return NULL;
    }
    char *p;
    size_t tot = n * size;
    p = malloc(tot);
    if (p == NULL)
    {
        return p;
    }
    size_t x = 0;
    while (tot > x)
    {
        p[x] = 0;
        x++;
    }
    return p;
}
