#include <stdio.h>

int main(void)
{
    for (char letter = 'a'; letter <= 'z'; letter++)
    {
        putchar(letter);
        if (letter != 'z')
        {
            putchar(' ');
        }
    }
    putchar('\n');
    return 0;
}
