/*
** EPITECH PROJECT, 2023
** SECURED
** File description:
** ht_delete
*/

#include "include/hashtable.h"
#include "include/my.h"
#include <stdlib.h>

void delete_node(linked_list_t **head,
    linked_list_t *prev, linked_list_t *current)
{
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current->data->key);
    free(current->data->value);
    free(current->data);
    free(current);
}

int ht_delete(hashtable_t *ht, char *key)
{
    int hash_value;
    int index;
    linked_list_t *list;
    linked_list_t *prev = NULL;

    if (key == NULL || ht == NULL || ht->hash == NULL || key[0] == '\0')
        return 84;
    hash_value = (ht->hash)(key, ht->size);
    index = hash_value % ht->size;
    list = ht->items[index];
    while (list != NULL) {
        if (my_strcmp(list->data->key, key) == 0) {
            delete_node(&(ht->items[index]), prev, list);
            return 0;
        }
        prev = list;
        list = list->next;
    }
    return 84;
}
