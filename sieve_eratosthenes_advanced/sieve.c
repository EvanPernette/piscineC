#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    int prem = 0;
    if (n > 2)
    {
        int *era = calloc(n + 1, sizeof(int));
        for (int i = 2; i * i < n; i++)
        {
            if (era[i] == 0)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    era[j] = 1;
                }
            }
        }
        for (int i = 2; i < n; i++)
        {
            if (era[i] == 0)
            {
                prem++;
            }
        }
        free(era);
        printf("%d\n", prem);
    }
}
