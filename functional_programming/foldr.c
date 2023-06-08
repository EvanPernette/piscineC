#include <stddef.h>

int foldr(int *array, size_t len, int (*func)(int, int))
{
    size_t count = 0;
    int sum = 0;
    while (count < len)
    {
        sum = func(array[len - 1 - count], sum);
        count++;
    }
    return sum;
}
