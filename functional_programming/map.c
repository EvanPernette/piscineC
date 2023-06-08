#include <stddef.h>

void map(int *array, size_t len, void (*func)(int *))
{
    size_t count = 0;
    while (count < len)
    {
        func(array);
        array++;
        count++;
    }
}
