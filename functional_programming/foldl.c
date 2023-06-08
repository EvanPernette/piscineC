#include <stddef.h>

int foldl(int *array, size_t len, int (*func)(int, int))
{
    size_t count = 0;
    int sum = 0;
    while (count < len)
    {
        sum = func(sum, array[count]);
        count++;
    }
    return sum;
}
