#include <stdio.h>
#include <stdlib.h>


int *add_int_ptr(int *a, int *b)
{
    *a = *a + *b;
    return a;
}
