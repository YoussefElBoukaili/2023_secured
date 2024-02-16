/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** a simple printf function
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/my.h"

int switch_flag(const char *format, va_list ap)
{
    int num = 0;

    switch (*format) {
        case 'd':
        case 'i':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case '%':
            my_putchar('%');
            break;
    }
    return num;
}

int mini_printf(const char *format, ...)
{
    int num = 0;
    va_list ap;

    va_start(ap, format);
    while (*format != '\0'){
        if (*format == '%'){
            format++;
            num += switch_flag(format, ap);
        } else {
            my_putchar(*format);
        }
        format++;
    }
    va_end(ap);
    return num;
}
