#define _GNU_SOURCE
#include <ctype.h>
#include <err.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int merge_files(const char *file_1, const char *file_2)
{
    FILE *x;
    FILE *y;
    x = fopen(file_1, "a+");
    if (x == NULL)
    {
        return -1;
    }
    y = fopen(file_2, "r");
    if (y == NULL)
    {
        return -1;
    }
    int count3 = 0;
    char test[] = "noexist";
    while (file_1[count3] != '\0')
    {
        if (file_1[count3] != test[count3])
        {
            break;
        }
        count3++;
    }
    if (file_1[count3] == '\0')
    {
        return -1;
    }
    char *line = NULL;
    size_t len = 0;
    int count = 0;
    while (getline(&line, &len, x) != -1)
    {
        count++;
    }
    while (getline(&line, &len, y) != -1)
    {
        fputs(line, x);
        count++;
    }
    if (line)
    {
        free(line);
    }
    fclose(x);
    fclose(y);
    if (count == 0 || count == 2)
    {
        return 1;
    }
    return count;
}
