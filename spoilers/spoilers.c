#include <ctype.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        write(2, "Invalid number of arguments\n", 28);
        return 1;
    }
    int x = open(argv[1], O_RDONLY);

    if (x == -1)
    {
        write(2, "Could not open file\n", 20);
        return 1;
    }
    char buf[1000];
    char res[1000];
    if (read(x, buf, 1) == -1)
    {
        write(2, "File is not long enough\n", 24);
        return 1;
    }
    res[0] = buf[0];
    int count2 = 1;
    char buf2[1];
    while (read(x, buf2, 1) != 0)
    {
        res[count2] = buf2[0];
        count2++;
    }
    count2--;
    while (isspace(res[count2]) != 0)
    {
        count2--;
    }
    if (count2 < 2)
    {
        write(2, "File is not long enough\n", 24);
        return 1;
    }
    char res2[2];
    res2[1] = res[count2];
    count2--;
    while (isspace(res[count2]) != 0)
    {
        count2--;
    }
    res2[0] = res[count2];
    write(1, res2, 2);
    write(1, "\n", 1);
    close(x);
    return 0;
}
