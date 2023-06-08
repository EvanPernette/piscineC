#include <stdio.h>

void display_square(int width)
{
    if (width > 1)
    {
        if (width % 2 == 0)
        {
            width++;
        }
        int cols = ((width + 1) / 2);
        for (int firstline = 0; firstline < width; firstline++)
        {
            putchar('*');
        }
        putchar('\n');
        for (int line = 0; line < cols - 2; line++)
        {
            putchar('*');
            for (int line = 0; line < width - 2; line++)
            {
                putchar(' ');
            }
            putchar('*');
            putchar('\n');
        }
        for (int firstline = 0; firstline < width; firstline++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    if (width == 1)
    {
        putchar('*');
        putchar('\n');
    }
}
