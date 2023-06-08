 #include <ctype.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libstream.h"

struct stream *lbs_fopen(const char * filename, const char *mode)
{
    struct stream  *fp = malloc(sizeof(struct stream));
    int test;
    int count = 0;
    fp->error = 0;
    fp->io_operation = STREAM_WRITING;
    fp->already_read = 0;
    fp->buffered_size = 0;
    while ( count < LBS_BUFFER_SIZE)
    {
        fp->buffer[count] = 0;
        count++;
    }
    if (strcmp(mode, "r") == 0)
    {
        if((test = open(filename, O_RDONLY)) != -1)
        {
            fp->flags = O_RDONLY;
            fp->fd = test;
            if (isatty(fp->fd))
            {
                fp->buffering_mode = STREAM_LINE_BUFFERED;
            }
            else
            {
                fp->buffering_mode = STREAM_BUFFERED;
            }
        }
        else
        {
            free(fp);
            return NULL;
        }
    }
    else if (strcmp(mode, "r+") == 0)
    {
        if((test = open(filename, O_RDWR)) != -1)
        {
            fp->flags = O_RDWR;
            fp->fd = test;
            if (isatty(fp->fd))
            {
                fp->buffering_mode = STREAM_LINE_BUFFERED;
            }
            else
            {
                fp->buffering_mode = STREAM_BUFFERED;
            }
        }
        else
        {
            free(fp);
            return NULL;
        }
    }
    else if (strcmp(mode, "w") == 0)
    {
        if((test = open(filename, O_CREAT|O_WRONLY|O_TRUNC)) != -1)
        {
            fp->flags = O_CREAT|O_WRONLY|O_TRUNC;
            fp->fd = test;
            if (isatty(fp->fd))
            {
                fp->buffering_mode = STREAM_LINE_BUFFERED;
            }
            else
            {
                fp->buffering_mode = STREAM_BUFFERED;
            }
        }
        else
        {
            free(fp);
            return NULL;
        }
    }
    else if (strcmp(mode, "w+") == 0)
    {
        if((test = open(filename, O_CREAT|O_RDWR|O_TRUNC)) != -1)
        {
            fp->flags = O_CREAT|O_RDWR|O_TRUNC;
            fp->fd = test;
            if (isatty(fp->fd))
            {
                fp->buffering_mode = STREAM_LINE_BUFFERED;
            }
            else
            {
                fp->buffering_mode = STREAM_BUFFERED;
            }
        }
        else
        {
            free(fp);
            return NULL;
        }
    }
    else
    {
        free(fp);
        return NULL;
    }
    return fp;
}

struct stream *lbs_fdopen(int fd, const char *mode)
{
    if (fd == -1)
    {
        return NULL;
    }
    struct stream  *fp = malloc(sizeof(struct stream ));
    size_t count;
    // init param
    fp->error = 0;
    fp->fd = fd;
    fp->io_operation = STREAM_WRITING;
    int satR = isatty(fp->fd);
    if (satR == 1)
    {
        fp->buffering_mode = STREAM_LINE_BUFFERED;
    }
    else if (satR == 0)
    {
        fp->buffering_mode = STREAM_BUFFERED;
    }
    else
    {
        free(fp);
        return NULL;
    }
    fp->already_read = 0;
    while ( count < LBS_BUFFER_SIZE)
    {
        fp->buffer[count] = 0;
        count++;
    }
    fp->buffered_size = 0;
    if (strcmp(mode, "r") == 0)
    {
        fp->flags = O_RDONLY;
    }
    else if (strcmp(mode, "r+") == 0)
    {
        fp->flags = O_RDWR;
    }
    else if (strcmp(mode, "w") == 0)
    {
        fp->flags = O_CREAT|O_WRONLY|O_TRUNC;
    }
    else if (strcmp(mode, "w+") == 0)
    {
        fp->flags = O_CREAT|O_RDWR|O_TRUNC;
    }
    else
    {
        free(fp);
        return NULL;
    }
    return fp;
}

int lbs_fclose(struct stream *file)
{
    int c;
    c = lbs_fflush(file);
    if (c == EOF)
    {
        close(file->fd);
        free(file);
        return 0;
    }
    else
    {
        close(file->fd);
        free(file);
        return 1;
    }
}

int lbs_fputc(int c, struct stream *stream)
{

    if ( stream->flags == O_RDONLY)
    {
        stream->error = 1;
        return -1;
    }
    if (stream->io_operation == STREAM_READING)
    {
        lbs_fflush(stream);
    }
    stream->io_operation = STREAM_WRITING;
    if (stream->buffered_size == 31)
    {
        stream->buffer[stream->buffered_size] = c;
        lbs_fflush(stream);
    }
    else
    {
        if (c == '\n' && stream->buffering_mode == STREAM_LINE_BUFFERED)
        {
            lbs_fflush(stream);
        }
        else
        {
            if (stream->buffering_mode == STREAM_UNBUFFERED)
            {
                stream->buffer[stream->buffered_size] = c;
                stream->buffered_size += 1;
                lbs_fflush(stream);
            }
            else
            {
                stream->buffer[stream->buffered_size] = c;
                stream->buffered_size += 1;
            }
        }
    }
    return c;
}

int lbs_fgetc(struct stream *stream)
{
    if (stream->flags == (O_CREAT|O_WRONLY|O_TRUNC))
    {
        stream->error = 1;
        return -1;
    }
    if (stream->io_operation == STREAM_WRITING)
    {
        lbs_fflush(stream);
    }
    stream->io_operation = STREAM_READING;
    size_t count = 0;
    while (count < stream->buffered_size && stream->buffer[count] != 0)
    {
        count++;
     //   printf("%ld :%ld\n",stream->already_read, stream->buffered_size);
    //  printf("coutn :%ld\n", stream->buffered_size);
    }
    if (stream->buffered_size == stream->already_read)
    {
        count = 0;
     //   printf("callread\n");
        stream->buffered_size = read(stream->fd, stream->buffer, 32);
    //    printf("%ld\n", stream->buffered_size);
        stream->already_read = 0;
    }
    if (stream->buffered_size <= stream->already_read)
    {
        stream->error = 1;
        return -1;
    }
    unsigned char aux = stream->buffer[stream->already_read];
    stream->already_read++;
    return aux;
}

int lbs_fflush(struct stream *stream)
{
    int count = 0;
    if (stream->io_operation == STREAM_READING)
    {
        while (count < 32)
        {
           // printf("%d, %c\n",count ,stream->buffer[count]);
            stream->buffer[count] = 0;
            count++;
        }
        if (stream_remaining_buffered(stream) == 0)
        {
            stream->buffered_size = 0;
            stream->already_read = 0;
        }
        else
        {
            size_t x = stream_remaining_buffered(stream) - 2*stream_remaining_buffered(stream);
            stream->buffered_size = 0;
            stream->already_read = 0;
            lseek(stream->fd, x, SEEK_CUR);
        }
    }
    else
    {
        if (stream->io_operation == STREAM_WRITING)
        {
                if (stream->buffered_size > 0)
                {
                    write(stream->fd, stream->buffer,stream->buffered_size );
                }
                stream->already_read = 0;
                count = 0;
                while (count < 32)
                {
                    stream->buffer[count] = 0;
                    count++;
                }
                stream->buffered_size = 0;
        }
        else
        {
            stream->error = 1;
            return EOF;
        }
    }
    return 0;
}
