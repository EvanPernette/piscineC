#include <stdio.h>

int main(int argc, char *argv[])
{
    char *a = argv[2];
    if (argc != 3)
    {
        return 1;
    }
    else
    {
        for (char k = '0'; k < *a; k++)
        {
            puts(argv[1]);
        }
    }
    return 0;
}
