/*
** EPITECH PROJECT, 2023
** SECURED
** File description:
** new hashtable
*/

#include "include/hashtable.h"
#include "include/linked_list.h"
#include <stdlib.h>

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *nh = malloc(sizeof(hashtable_t));
    linked_list_t **items = malloc(sizeof(linked_list_t *) * len);

    if (len <= 0 || hash == NULL)
        return NULL;
    nh->hash = hash;
    nh->size = len;
    nh->items = items;
    for (int i = 0; i < len; i++) {
        items[i] = 0;
    }
    return nh;
}
