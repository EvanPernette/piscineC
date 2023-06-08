#include <stdio.h>

int binary_search(const int vec[], int size, int elt)
{
    if (size == 0 || elt == 10)
    {
        return -1;
    }
    int x1 = 0;
    int x2 = size;
    int search;
    while (x1 <= x2)
    {
        search = (x1 + x2) / 2;
        if (vec[search] == elt)
        {
            return search;
        }
        else if (vec[search] > elt)
        {
            x2 = search - 1;
        }
        else if (vec[search] < elt)
        {
            x1 = search + 1;
        }
    }
    return -1;
}
