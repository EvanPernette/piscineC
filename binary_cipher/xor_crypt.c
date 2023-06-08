#include <stddef.h>

void my_xor_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    unsigned char *auxdata = (unsigned char *)data;
    unsigned char *auxkey = (unsigned char *)key;
    size_t count1 = 0;
    size_t count2 = 0;
    while (count1 < data_len)
    {
        if (count2 == key_len)
        {
            count2 = 0;
        }
        auxdata[count1] = auxdata[count1] ^ auxkey[count2];
        count2++;
        count1++;
    }
}
