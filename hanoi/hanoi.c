#include <stdio.h>

void hanoi_rec(unsigned n, char D, char A, char I)
{
    if (n != 0)
    {
        hanoi_rec(n - 1, D, I, A);
        putchar(D);
        putchar('-');
        putchar('>');
        putchar(A);
        putchar('\n');
        hanoi_rec(n - 1, I, A, D);
    }
}

void hanoi(unsigned n)
{
    hanoi_rec(n, '1', '3', '2');
}
