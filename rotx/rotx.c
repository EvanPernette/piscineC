#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void rot_x(char s[], int x)
{
    if (s != NULL)
    {
        int count = 0;
        int u = 0;
        while (s[count] != '\0')
        {
            if (x > 0)
            {
                if (s[count] >= 'A' && s[count] <= 'Z')
                {
                    u = x;
                    while (u > 0)
                    {
                        s[count] += 1;
                        if (s[count] > 'Z')
                        {
                            s[count] = 'A';
                        }
                        u--;
                    }
                }
                else if (s[count] >= 'a' && s[count] <= 'z')
                {
                    u = x;
                    while (u > 0)
                    {
                        s[count] = s[count] + 1;
                        if (s[count] > 'z')
                        {
                            s[count] = 'a';
                        }
                        u--;
                    }
                }
                else if (s[count] >= '0' && s[count] <= '9')
                {
                    u = x;
                    while (u > 0)
                    {
                        s[count] = s[count] + 1;
                        if (s[count] > '9')
                        {
                            s[count] = '0';
                        }
                        u--;
                    }
                }
            }
            if (x < 0)
            {
                if (s[count] >= 'a' && s[count] <= 'z')
                {
                    u = -x;
                    while (u > 0)
                    {
                        s[count] -= 1;
                        if (s[count] < 'a')
                        {
                            s[count] = 'z';
                        }
                        u--;
                    }
                }
                if (s[count] >= 'A' && s[count] <= 'Z')
                {
                    u = -x;
                    while (u > 0)
                    {
                        s[count] -= 1;
                        if (s[count] < 'A')
                        {
                            s[count] = 'Z';
                        }
                        u--;
                    }
                }
                else if (s[count] >= '0' && s[count] <= '9')
                {
                    u = -x;
                    while (u > 0)
                    {
                        s[count] = s[count] - 1;
                        if (s[count] < '0')
                        {
                            s[count] = '9';
                        }
                        u--;
                    }
                }
            }
            count++;
        }
    }
}

int main(int argc, char *argv[])
{
    char buf[2000];
    size_t nbytes = 2000;
    ssize_t x;
    if (argc != 2)
    {
        return 0;
    }
    x = read(0, buf, nbytes);
    int r = atoi(argv[1]);
    rot_x(buf, r);
    write(1, buf, x);
    return 0;
}
