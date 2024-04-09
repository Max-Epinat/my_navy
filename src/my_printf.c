/*
** EPITECH PROJECT, 2024
** B-MUL-100-MAR-1-1-myradar-maxime.finaud
** File description:
** my_printf
*/

#include "../includes/my.h"


int put_format(char specifier, va_list list)
{
    switch (specifier) {
    case 'c':
        my_putchar(va_arg(list, int));
        break;
    case 's':
        my_putstr(va_arg(list, char *));
        break;
    case 'd':
        my_put_nbr(va_arg(list, int));
        break;
    case 'i':
        my_put_nbr(va_arg(list, int));
        break;
    default:
        write(1, &specifier, 1);
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int code_error = -1;
    int nb_print = 0;

    va_start(list, format);
    while (*format != '\0') {
        if (*format == '%') {
            put_format(*(++format), list);
            nb_print++;
        } else {
            write(1, format, 1);
            nb_print++;
        }
        ++format;
    }
    va_end(list);
    code_error = nb_print;
    return code_error;
}
