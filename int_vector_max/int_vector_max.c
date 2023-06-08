#include "int_vector_max.h"

#include <stdio.h>

int int_vector_max(const struct int_vector vec)
{
    size_t count = 1;
    int max = vec.data[0];
    while (count < vec.size)
    {
        if (vec.data[count] > max)
        {
            max = vec.data[count];
        }
        count++;
    }
    return max;
}
