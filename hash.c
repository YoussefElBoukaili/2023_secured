/*
** EPITECH PROJECT, 2023
** SECURED
** File description:
** hash function
*/

#include "include/my.h"
#include <stdlib.h>

static int get_digits(unsigned long long sum)
{
    unsigned long long prime = 982451653;
    unsigned long long res;

    res = (sum * prime) % 100000;
    return (int)res;
}

int hash(char *key, int len)
{
    int v = 0;
    int i = 2;

    if (len <= 0 || key == NULL)
        return 84;
    while (*key != '\0') {
        v += (*key) * i;
        i = i * i;
        key++;
    }
    return get_digits(v);
}
