#include "int_vector_insert_sort.h"

#include <stdio.h>

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int aux = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = aux;
    return vec;
}

struct int_vector int_vector_insert_sort(struct int_vector vec)
{
    size_t count = 1;
    size_t count2;
    while (count < vec.size)
    {
        count2 = count;
        while (count2 > 0 && vec.data[count2 - 1] > vec.data[count2])
        {
            vec = swap(vec, count2 - 1, count2);
            count2--;
        }
        count++;
    }
    return vec;
}
