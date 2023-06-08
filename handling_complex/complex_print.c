#include <stdio.h>

#include "complex.h"

void print_complex(struct complex a)
{
    if (a.img < 0)
    {
        a.img = -a.img;
        printf("complex(%.2f - %.2fi)", a.real, a.img);
    }
    else
    {
        printf("complex(%.2f + %.2fi)", a.real, a.img);
    }
}
