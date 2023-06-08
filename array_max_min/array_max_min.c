#include <stdio.h>

void array_max_min(int tab[], size_t len, int *max, int *min)
{
    size_t k = 0;
    int save = tab[0];
    int save2 = tab[0];
    if (tab != NULL || len != 0)
    {
        while (k < len)
        {
            if (save < tab[k])
            {
                save = tab[k];
            }
            if (save2 > tab[k])
            {
                save2 = tab[k];
            }
            k++;
        }
        *max = save;
        *min = save2;
    }
}
