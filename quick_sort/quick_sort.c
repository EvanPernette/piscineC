#include <stdio.h>

void quicksort_rec(int *tab, int pivot, int len)
{
    int mid;
    int count = 0;
    int count2 = 0;
    int aux;
    if (pivot < len)
    {
        mid = pivot;
        count = pivot;
        count2 = len;
        while (count < count2)
        {
            while (tab[count] <= tab[mid] && count <= len)
            {
                count++;
            }
            while (tab[count2] > tab[mid] && count2 >= pivot)
            {
                count2--;
            }
            if (count < count2)
            {
                aux = tab[count];
                tab[count] = tab[count2];
                tab[count2] = aux;
            }
        }
        aux = tab[count2];
        tab[count2] = tab[mid];
        tab[mid] = aux;
        quicksort_rec(tab, pivot, count2 - 1);
        quicksort_rec(tab, count2 + 1, len);
    }
}

void quicksort(int *tab, int len)
{
    if (tab != NULL)
    {
        quicksort_rec(tab, 0, len - 1);
    }
}
