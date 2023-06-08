#include "bsearch.h"

#include <stdio.h>

int *binary_search(int *begin, int *end, int elt)
{
    if (end == begin)
    {
        return begin;
    }
    int *mid;
    int *auxend;
    int *auxbegin;
    int count;
    while (begin < end)
    {
        auxend = end;
        auxbegin = begin;
        mid = begin;
        count = 0;
        while (auxend > auxbegin)
        {
            auxbegin++;
            count++;
        }
        count = count / 2;
        while (count > 0)
        {
            mid++;
            count--;
        }
        if (end == begin)
        {
            return begin;
        }
        else if (elt > *mid)
        {
            mid++;
            begin = mid;
        }
        else
        {
            end = mid;
        }
    }
    return begin;
}
