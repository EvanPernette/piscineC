#include <stdio.h>

void rot_x(char *s, int x)
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
            }
            if (x < 0)
            {
                if (s[count] >= 'a' && s[count] <= 'z')
                {
                    s[count] += x;
                    if (s[count] < 'a')
                    {
                        s[count] += 26;
                    }
                }
                if (s[count] >= 'A' && s[count] <= 'Z')
                {
                    s[count] += x;
                    if (s[count] < 'A')
                    {
                        s[count] += 26;
                    }
                }
            }
            count++;
        }
    }
}
