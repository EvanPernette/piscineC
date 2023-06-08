#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*f_cmp)(const void *, const void *);

int comp(const void *a, const void *b)
{
    int *a2 = (int *)a;
    int *b2 = (int *)b;
    if (*a2 < *b2)
    {
        return -1;
    }
    if (*a2 > *b2)
    {
        return 1;
    }
    return 0;
}

void insertion_sort(void **array, f_cmp comp)
{
    int count = 1;
    int count2 = 0;
    int count3 = 0;
    int len = 0;
    while (array[len] != NULL)
    {
        len++;
    }
    while (count < len)
    {
        count2 = 0;
        void *key = array[count];
        while (count2 < count && comp(array[count2], array[count]) < 0)
        {
            count2++;
        }
        if (count2 != count)
        {
            count3 = count;
            while (count3 > count2)
            {
                array[count3] = array[count3 - 1];
                count3--;
            }
            array[count2] = key;
        }
        count++;
    }
}
