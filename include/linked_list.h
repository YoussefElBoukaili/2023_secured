/*
** EPITECH PROJECT, 2023
** Organized
** File description:
** LINKED_LIST_H
*/

#ifndef LINKED_LIST_H
    #define LINKED_LIST_H

typedef struct hashcontent_s {
    int hash_num;
    char *key;
    char *value;
} hashcontent_t;

typedef struct linked_list_s {
    hashcontent_t *data;
    struct linked_list_s *next;
} linked_list_t;

void push_to_list(linked_list_t **begin, hashcontent_t *data);

#endif /* LINKED_LIST_H */
