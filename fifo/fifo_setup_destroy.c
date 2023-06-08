#include <stdlib.h>

#include "fifo.h"

void fifo_pop(struct fifo *fifo)
{
    if (fifo->size != 0)
    {
        struct list *aux = fifo->head->next;
        free(fifo->head);
        fifo->head = aux;
        fifo->size -= 1;
    }
}

void fifo_clear(struct fifo *fifo)
{
    while (fifo->size != 0)
    {
        fifo_pop(fifo);
    }
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}
