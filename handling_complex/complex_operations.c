#include <stdio.h>

#include "complex.h"

struct complex neg_complex(struct complex a)
{
    a.img = -a.img;
    a.real = -a.real;
    return a;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex res;
    res.img = a.img + b.img;
    res.real = a.real + b.real;
    return res;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex res;
    res.img = a.img - b.img;
    res.real = a.real - b.real;
    return res;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex res;
    res.img = (a.real * b.img) + (a.img * b.real);
    res.real = (a.real * b.real) - (a.img * b.img);
    return res;
}

struct complex div_complex(struct complex a, struct complex b)
{
    struct complex res;
    res.real = ((a.real * b.real) + (a.img * b.img))
        / ((b.real * b.real) + (b.img * b.img));
    res.img = ((a.img * b.real) - (a.real * b.img))
        / ((b.real * b.real) + (b.img * b.img));
    return res;
}
