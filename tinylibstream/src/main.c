#include <ctype.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libstream.h"

int main()
{
    FILE * x = fopen("test.txt", "r+");
    int count = 0;
    while (count < 35)
    {
        fputc('1',x);
        fputc('1',x);
        printf("%c ", fgetc(x));
        fputc('1',x);
        count++;
    }
    fclose(x);
}

int main()
{
    struct stream * x = lbs_fopen("test.txt", "r+");
    x->buffering_mode = STREAM_BUFFERED;
    int count = 0;
    while (count < 35)
    {
        lbs_fputc('1',x);
        lbs_fputc('1',x);
        printf("%c ", lbs_fgetc(x));
        lbs_fputc('1',x);
        count++;
    }
    lbs_fclose(x);
}
