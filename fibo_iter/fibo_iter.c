#include <stdio.h>

unsigned long fibo_iter(unsigned long n)
{
    unsigned long fibo1 = 0;
    unsigned long fibo2 = 1;
    unsigned long aux = 0;
    unsigned long count = 0;
    while (count < n)
    {
        aux = fibo2;
        fibo2 = fibo1 + fibo2;
        fibo1 = aux;
        count++;
    }
    return fibo1;
}
