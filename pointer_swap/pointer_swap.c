#include <stdio.h>

void pointer_swap(int **a, int **b)
{
    int *aux = *a;
    *a = *b;
    *b = aux;
}
