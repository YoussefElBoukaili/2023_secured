/*
** EPITECH PROJECT, 2023
** MY_STRNCPY
** File description:
** Function that duplicates a string and returns it
*/

#include "include/my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = -1;

    do {
        i++;
        str[i] = src[i];
    } while (str[i] != '\0');
    return str;
}
