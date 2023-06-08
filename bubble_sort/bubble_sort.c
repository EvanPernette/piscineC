#include <stddef.h>

void bubble_sort(int array[], size_t size)
{
    int test;
    if (size != 0)
    {
        test = 0;
        while (test == 0)
        {
            test = 1;
            for (size_t i = 0; i < size - 1; i++)
            {
                if (array[i] > array[i + 1])
                {
                    int temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                    test = 0;
                }
            }
        }
    }
}
