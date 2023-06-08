#include <stdio.h>

int top_of_the_hill(int tab[], size_t len)
{
    if (len == 0)
    {
        return -1;
    }
    int ascend = 1;
    size_t count = 1;
    int topof = 0;
    int save = tab[0];
    size_t count2 = 0;
    while (count < len)
    {
        if (tab[count] < 0)
        {
            return -1;
        }
        if (ascend == 1)
        {
            if (tab[count] < save)
            {
                topof = count - count2 - 1;
                ascend = 0;
                count--;
                save = tab[count];
                count2 = 0;
            }
            else if (tab[count] > save)
            {
                save = tab[count];
                topof = count;
                count2 = 0;
            }
            else
            {
                count2 = 0;
                while (tab[count + count2] == save)
                {
                    save = tab[count2 + count];
                    count2++;
                }
                count = count2 + count;
                count2++;
            }
        }
        else
        {
            if (tab[count] > save)
            {
                return -1;
            }
            else
            {
                save = tab[count];
            }
        }
        count++;
    }
    return topof;
}
