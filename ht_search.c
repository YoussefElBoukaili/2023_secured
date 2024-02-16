/*
** EPITECH PROJECT, 2023
** SECURED
** File description:
** ht_search
*/

#include "include/hashtable.h"
#include "include/my.h"
#include <stdlib.h>

char *ht_search(hashtable_t *ht, char *key)
{
    int hash_value;
    int index;
    linked_list_t *list;

    if (key == NULL || ht == NULL || key[0] == '\0' || ht->hash == NULL)
        return NULL;
    hash_value = (ht->hash)(key, ht->size);
    index = hash_value % ht->size;
    list = ht->items[index];
    while (list != NULL) {
        if (my_strcmp(list->data->key, key) == 0) {
            return list->data->value;
        }
        list = list->next;
    }
    return NULL;
}
