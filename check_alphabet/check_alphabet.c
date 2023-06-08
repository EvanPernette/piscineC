#include <stdio.h>

int check_alphabet(const char *str, const char *alphabet)
{
    int count = 0;
    int count2 = 0;
    int test = 0;
    if (alphabet == NULL)
    {
        return 1;
    }
    while (alphabet[count] != '\0')
    {
        count2 = 0;
        test = 0;
        while (str[count2] != '\0')
        {
            if (alphabet[count] == str[count2])
            {
                test = 1;
                break;
            }
            count2++;
        }
        if (test == 0)
        {
            return 0;
        }
        count++;
    }
    return 1;
}
