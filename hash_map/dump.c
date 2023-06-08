#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"

void hash_map_dump(struct hash_map *hash_map)
{
    size_t count = 0;
    struct hash_map *aux = hash_map;
    struct pair_list *aux2;
    while (count < aux->size)
    {
        aux2 = aux->data[count];
        while (aux2 != NULL)
        {
            printf("%s: %s", aux2->key, aux2->value);
            if (aux2->next != NULL)
            {
                printf(", ");
            }
            else
            {
                printf("\n");
            }
            aux2 = aux2->next;
        }
        count++;
    }
}
