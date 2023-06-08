#include "dlist.h"

#include <stdio.h>
#include <stdlib.h>

struct dlist *dlist_init(void)
{
    struct dlist *res = malloc(sizeof(struct dlist));
    res->head = NULL;
    res->tail = NULL;
    res->size = 0;
    return res;
}

int dlist_push_front(struct dlist *list, int element)
{
    if (element < 0)
    {
        return 0;
    }
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    new->data = element;
    new->next = NULL;
    new->prev = NULL;
    if (list->size == 0)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        new->next = list->head;
        list->head->prev = new;
        list->head = new;
    }
    list->size += 1;
    return 1;
}

void dlist_print(const struct dlist *list)
{
    struct dlist_item *aux = list->head;
    while (aux)
    {
        printf("%d\n", aux->data);
        aux = aux->next;
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    if (element < 0)
    {
        return 0;
    }
    struct dlist_item *new = malloc(sizeof(struct dlist_item));
    new->data = element;
    new->next = NULL;
    new->prev = NULL;
    if (list->size == 0)
    {
        list->head = new;
        list->tail = new;
    }
    else
    {
        new->prev = list->tail;
        list->tail->next = new;
        list->tail = new;
    }
    list->size += 1;
    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}

int dlist_get(struct dlist *list, size_t index)
{
    if (index > list->size)
    {
        return -1;
    }
    size_t count = 0;
    struct dlist_item *aux = list->head;
    while (count < index)
    {
        aux = aux->next;
        count++;
    }
    return aux->data;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (index > dlist_size(list) || element < 0)
    {
        return -1;
    }
    if (index == 0)
    {
        dlist_push_front(list, element);
    }
    else if (index == dlist_size(list))
    {
        dlist_push_back(list, element);
    }
    else
    {
        struct dlist_item *aux = list->head;
        size_t count = 0;
        while (count < index)
        {
            aux = aux->next;
            count++;
        }
        struct dlist_item *b = aux->prev;
        struct dlist_item *new = malloc(sizeof(struct dlist_item));
        new->next = aux;
        new->prev = b;
        new->data = element;
        aux->prev = new;
        b->next = new;
        list->size += 1;
    }
    return 1;
}

int dlist_find(const struct dlist *list, int element)
{
    int count = 0;
    struct dlist_item *aux = list->head;
    while (aux != NULL)
    {
        if (aux->data == element)
        {
            return count;
        }
        aux = aux->next;
        count++;
    }
    return -1;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    if (index >= dlist_size(list))
    {
        return -1;
    }
    int res = dlist_get(list, index);
    if (index == 0)
    {
        struct dlist_item *aux = list->head;
        size_t count = 0;
        while (count < index)
        {
            aux = aux->next;
            count++;
        }
        list->head = aux->next;
        if (list->size == 1)
        {
            list->tail = NULL;
            free(aux);
        }
        else
        {
            aux->prev = NULL;
            free(aux);
        }
    }
    else if (index == dlist_size(list) - 1)
    {
        struct dlist_item *aux = list->head;
        size_t count = 0;
        while (count < index)
        {
            aux = aux->next;
            count++;
        }
        list->tail = aux->prev;
        if (list->size == 1)
        {
            list->head = NULL;
            free(aux);
        }
        else
        {
            struct dlist_item *p = aux->prev;
            p->next = NULL;
            free(aux);
        }
    }
    else
    {
        struct dlist_item *aux = list->head;
        size_t count = 0;
        while (count < index)
        {
            aux = aux->next;
            count++;
        }
        struct dlist_item *prevv = aux->prev;
        struct dlist_item *nexx = aux->next;
        prevv->next = nexx;
        nexx->prev = prevv;
        free(aux);
    }
    list->size -= 1;
    return res;
}

void dlist_map_square(struct dlist *list)
{
    struct dlist_item *aux = list->head;
    while (aux != NULL)
    {
        aux->data *= aux->data;
        aux = aux->next;
    }
}

void dlist_reverse(struct dlist *list)
{
    size_t count = 0;
    size_t count2 = list->size;
    struct dlist_item *aux = list->head;
    struct dlist_item *aux2 = list->tail;
    while (count < count2)
    {
        int aux1 = aux->data;
        aux->data = aux2->data;
        aux2->data = aux1;
        aux2 = aux2->prev;
        aux = aux->next;
        count++;
        count2--;
    }
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (index >= list->size)
    {
        return NULL;
    }
    struct dlist_item *aux = list->head;
    size_t count = 0;
    while (count < index)
    {
        aux = aux->next;
        count++;
    }
    struct dlist *new = dlist_init();
    while (aux != NULL)
    {
        dlist_push_back(new, aux->data);
        aux = aux->next;
        dlist_remove_at(list, index);
    }
    return new;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    struct dlist_item *aux = list2->head;
    int len = list2->size;
    int count = 0;
    while (count < len)
    {
        dlist_push_back(list1, aux->data);
        aux = aux->next;
        dlist_remove_at(list2, 0);
        count += 1;
    }
}
