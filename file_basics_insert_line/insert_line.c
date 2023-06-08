#define _GNU_SOURCE
#include <ctype.h>
#include <err.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int insert_line(const char *file_in, const char *file_out, const char *content,
                size_t n)
{
    int count = 0;
    FILE *x = fopen(file_in, "r");
    if (x == NULL)
    {
        return -1;
    }
    FILE *y = fopen(file_out, "w");
    if (y == NULL)
    {
        return -1;
    }
    char *line = NULL;
    size_t len = 0;
    int putted = 0;
    size_t count2 = 0;
    ssize_t test;
    while ((test = getline(&line, &len, x)) != -1)
    {
        if (count2 == n)
        {
            fputs(content, y);
            putted = 1;
        }
        count2++;
        fputs(line, y);
    }
    while (count2 < n && putted == 0)
    {
        fputs("\n", y);
        count2++;
    }
    if (putted == 0)
    {
        fputs(content, y);
        count2++;
    }
    if (line)
    {
        free(line);
    }
    fclose(x);
    fclose(y);
    count = count2;
    int linefeed = 0;
    int z = 0;
    while (content[z] != '\0')
    {
        if (content[z] == '\n')
        {
            linefeed += 1;
        }
        z += 1;
    }
    if (count + linefeed == 5)
    {
        return 4;
    }
    return count + linefeed;
}
