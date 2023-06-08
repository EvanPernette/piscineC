#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Hello World!\n");
    }
    for (int k = 1; k < argc; k++)
    {
        printf("Hello %s!\n", argv[k]);
    }
    return 0;
}
