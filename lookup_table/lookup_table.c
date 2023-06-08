#include <stdio.h>

void apply_lut(unsigned char mat[4][4], const unsigned char lut[256])
{
    int i = 0;
    int count = 0;
    int count2 = 0;
    while (count < 4)
    {
        count2 = 0;
        while (count2 < 4)
        {
            i = mat[count][count2];
            mat[count][count2] = lut[i];
            count2++;
        }
        count++;
    }
}
