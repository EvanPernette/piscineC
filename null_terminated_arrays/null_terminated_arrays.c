#include <stdio.h>

void reverse_matrix(const char ***matrix)
{
    int l = 0;
    while (matrix[l])
    {
        l += 1;
    }
    int count = 0;
    int count2 = l - 1;
    const char **aux;
    while (count < count2)
    {
        aux = matrix[count];
        matrix[count] = matrix[count2];
        matrix[count2] = aux;
        count++;
        count2--;
    }
    int l2 = 0;
    while (l2 < l)
    {
        int num = 0;
        while (matrix[l2][num])
        {
            num += 1;
        }
        count = 0;
        count2 = num - 1;
        const char *aux;
        while (count < count2)
        {
            aux = matrix[l2][count];
            matrix[l2][count] = matrix[l2][count2];
            matrix[l2][count2] = aux;
            count++;
            count2--;
        }
        l2++;
    }
}
