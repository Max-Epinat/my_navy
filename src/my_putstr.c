/*
** EPITECH PROJECT, 2023
** Projet7
** File description:
** ojojojo
*/

#include "../includes/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
