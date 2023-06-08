#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

struct fifo *fifo_init(void)
{
    struct fifo *newfifo = malloc(sizeof(struct fifo));
    newfifo->head = NULL;
    newfifo->tail = NULL;
    newfifo->size = 0;
    return newfifo;
}

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *push = malloc(sizeof(struct fifo));
    push->data = elt;
    push->next = fifo->head;
    fifo->size += 1;
    fifo->head = push;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_print(const struct fifo *fifo)
{
    size_t len = fifo->size;
    struct list *aux = fifo->head;
    while (len != 0)
    {
        printf("%d\n", aux->data);
        aux = aux->next;
        len--;
    }
}
