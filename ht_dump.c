/*
** EPITECH PROJECT, 2023
** SECURED
** File description:
** ht_dump
*/

#include "include/hashtable.h"
#include "include/my.h"
#include <stdlib.h>

void print_list(linked_list_t *list)
{
    while (list != NULL) {
        mini_printf("> %d - %s\n", list->data->hash_num, list->data->value);
        list = list->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    int i;
    linked_list_t *list;

    if (ht == NULL)
        return;
    for (i = 0; i < ht->size; i++) {
        mini_printf("[%d]:\n", i);
        list = ht->items[i];
        if (list != NULL) {
            print_list(list);
        }
    }
}
