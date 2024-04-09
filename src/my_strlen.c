/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Write a function that displays, one-by-one, char
*/

#include "../includes/my.h"

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count = count +1;
    }
    return count;
    return 0;
}
