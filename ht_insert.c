/*
** EPITECH PROJECT, 2023
** SECURED
** File description:
** ht_insert
*/

#include "include/hashtable.h"
#include "include/my.h"
#include <stdlib.h>

hashcontent_t *search_item(hashtable_t *ht, char *key, int index)
{
    linked_list_t *list = ht->items[index];

    while (list != NULL) {
        if (my_strcmp(list->data->key, key) == 0) {
            return list->data;
        }
        list = list->next;
    }
    return NULL;
}

static int update_cur(hashcontent_t *cur, char *value)
{
    free(cur->value);
    cur->value = my_strdup(value);
    return 0;
}

static int check_data(hashtable_t *ht, char *key, char *value)
{
    if (key == NULL || value == NULL || ht == NULL ||
        key[0] == '\0' || value[0] == '\0' || (ht->hash) == NULL)
        return 84;
    return 0;
}

static int add_new_item(hashtable_t *ht, char *key,
    char *value, int hash_value)
{
    hashcontent_t *hc;
    int index = hash_value % ht->size;

    hc = malloc(sizeof(hashcontent_t));
    hc->hash_num = hash_value;
    hc->key = my_strdup(key);
    hc->value = my_strdup(value);
    push_to_list(&((ht->items)[index]), hc);
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    hashcontent_t *hc;
    int hash_value;
    int index;
    hashcontent_t *cur;

    if (check_data(ht, key, value))
        return 84;
    hash_value = (ht->hash)(key, ht->size);
    index = hash_value % ht->size;
    cur = search_item(ht, key, index);
    if (cur != NULL)
        return update_cur(cur, value);
    return add_new_item(ht, key, value, hash_value);
}
