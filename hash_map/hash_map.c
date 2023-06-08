#include "hash_map.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct hash_map *hash_map_init(size_t size)
{
    struct hash_map *x = malloc(sizeof(struct hash_map));
    if (x == NULL)
    {
        return NULL;
    }
    x->size = size;
    x->data = calloc(size, sizeof(struct pair_list));
    return x;
}

bool hash_map_insert(struct hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (hash_map == NULL || hash_map->size == 0)
    {
        *updated = false;
        return false;
    }
    struct pair_list *ins = malloc(sizeof(struct pair_list));
    if (ins == NULL)
    {
        *updated = false;
        return false;
    }
    ins->key = key;
    ins->value = value;
    ins->next = NULL;
    size_t test = hash(key);
    struct pair_list *aux2;
    struct pair_list *aux3;
    if (hash_map->size != 0)
    {
        test = test % hash_map->size;
        if (hash_map->data[test] == NULL)
        {
            hash_map->data[test] = ins;
        }
        else
        {
            aux3 = hash_map->data[test];
            aux2 = hash_map->data[test];
            while (aux2->next != NULL)
            {
                if (aux2->key == key)
                {
                    *updated = true;
                    aux2->value = value;
                    free(ins);
                    return true;
                }
                aux2 = aux2->next;
            }
            ins->next = aux3;
            hash_map->data[test] = ins;
        }
    }
    *updated = false;
    return true;
}

void hash_map_free(struct hash_map *hash_map)
{
    if (hash_map != NULL)
    {
        size_t count = 0;
        struct pair_list *aux;
        while (count < hash_map->size)
        {
            while (hash_map->data[count] != NULL)
            {
                aux = hash_map->data[count];
                hash_map->data[count] = hash_map->data[count]->next;
                free(aux);
            }
            count++;
        }
        free(hash_map->data);
        free(hash_map);
    }
}

const char *hash_map_get(const struct hash_map *hash_map, const char *key)
{
    if (hash_map == NULL)
    {
        return NULL;
    }
    size_t count = 0;
    struct pair_list *aux2;
    while (count < hash_map->size)
    {
        aux2 = hash_map->data[count];
        while (aux2 != NULL)
        {
            if (aux2->key == key)
            {
                return aux2->value;
            }
            aux2 = aux2->next;
        }
        count++;
    }
    return NULL;
}

bool hash_map_remove(struct hash_map *hash_map, const char *key)
{
    if (hash_map == NULL)
    {
        return false;
    }
    size_t count = 0;
    size_t count2 = 0;
    struct pair_list *aux2 = NULL;
    struct pair_list *aux3;
    struct pair_list *aux4;
    while (count < hash_map->size)
    {
        aux4 = hash_map->data[count];
        count2 = 0;
        aux2 = NULL;
        while (aux4 != NULL)
        {
            if (aux4->key == key)
            {
                if (count2 == 0 && aux4->next == NULL)
                {
                    free(aux4);
                    hash_map->data[count] = NULL;
                }
                else if (count2 == 0)
                {
                    aux3 = aux4->next;
                    free(aux4);
                    hash_map->data[count] = aux3;
                }
                else
                {
                    aux3 = aux4->next;
                    free(aux4);
                    aux2->next = aux3;
                }
                return true;
            }
            aux2 = aux4;
            aux4 = aux4->next;
            count2++;
        }
        count++;
    }
    return false;
}
