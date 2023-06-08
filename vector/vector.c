#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

struct vector *vector_init(size_t n)
{
    if (n <= 0)
    {
        return NULL;
    }
    struct vector *vec = malloc(sizeof(struct vector));
    if (!vec)
    {
        return NULL;
    }
    int *the_data = malloc(sizeof(int) * n);
    if (!the_data)
    {
        free(vec);
        return NULL;
    }
    vec->capacity = n;
    vec->size = 0;
    vec->data = the_data;
    return vec;
}

void vector_destroy(struct vector *v)
{
    if (v != NULL)
    {
        free(v->data);
        free(v);
    }
}

struct vector *vector_resize(struct vector *v, size_t n)
{
    if (v == NULL || n <= 0)
    {
        return NULL;
    }
    else if (v->capacity == 0)
    {
        return NULL;
    }
    else if (n == v->capacity)
    {
        return v;
    }
    v->data = realloc(v->data, n * sizeof(int));
    if (v->size > n)
    {
        v->size = n;
    }
    if (v->capacity == 0)
    {
        return NULL;
    }
    v->capacity = n;
    return v;
}

struct vector *vector_append(struct vector *v, int elt)
{
    if (v == NULL || elt <= 0)
    {
        return NULL;
    }
    if (v->capacity == v->size)
    {
        vector_resize(v, 2 * v->capacity);
    }
    v->data[v->size++] = elt;
    return v;
}

void vector_print(const struct vector *v)
{
    if (v || v->size > 0)
    {
        size_t count = 0;
        while (count < v->size)
        {
            printf("%d", v->data[count]);
            if (count == v->size - 1)
            {
                break;
            }
            else
            {
                printf(",");
            }
            count += 1;
        }
    }
    printf("\n");
}

struct vector *vector_reset(struct vector *v, size_t n)
{
    if (v == NULL || n <= 0)
    {
        return NULL;
    }
    vector_destroy(v);
    return vector_init(n);
}

struct vector *vector_insert(struct vector *v, size_t i, int elt)
{
    if (v == NULL || i > v->size)
    {
        return NULL;
    }
    if (v->size == v->capacity)
    {
        v = vector_resize(v, v->capacity * 2);
    }
    size_t count = v->size++;
    while (count > i)
    {
        v->data[count] = v->data[count - 1];
        count--;
    }
    v->data[i] = elt;
    return v;
}

struct vector *vector_remove(struct vector *v, size_t i)
{
    if (v == NULL || i > v->size)
    {
        return NULL;
    }
    for (size_t j = i + 1; j < v->size && v->size != 1; j++)
    {
        v->data[j - 1] = v->data[j];
    }
    v->size = v->size - 1;
    if (v->size * 2 < v->capacity)
    {
        vector_resize(v, v->capacity / 2);
    }
    return v;
}
