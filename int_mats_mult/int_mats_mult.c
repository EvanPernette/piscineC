#include <stdio.h>

void mat_mult(int **mat1, int **mat2, size_t *matrices_size, int **out)
{
    size_t count = 0;
    size_t count2 = 0;
    size_t count3 = 0;
    while (count < matrices_size[0])
    {
        count2 = 0;
        while (count2 < matrices_size[2])
        {
            count3 = 0;
            while (count3 < matrices_size[1])
            {
                out[count][count2] +=
                    mat1[count][count3] * mat2[count3][count2];
                count3++;
            }
            count2++;
        }
        count++;
    }
}
