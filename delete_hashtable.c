/*
** EPITECH PROJECT, 2023
** SECURED
** File description:
** delete_hashtable
*/

#include "include/hashtable.h"
#include <stdlib.h>

static void free_list(linked_list_t *list)
{
    linked_list_t *next;

    while (list != 0) {
        next = list->next;
        free(list->data->key);
        free(list->data->value);
        free(list->data);
        free(list);
        list = next;
    }
}

void delete_hashtable(hashtable_t *ht)
{
    if (ht == NULL || ht->hash == NULL)
        return;
    for (int i = 0; i < ht->size; i++) {
        free_list(ht->items[i]);
    }
    free(ht->items);
    ht->items = NULL;
    ht->hash = NULL;
    free(ht);
}
