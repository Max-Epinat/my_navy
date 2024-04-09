/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-sokoban-maxime.finaud
** File description:
** my_strncpy
*/

#include "../includes/my.h"

int my_strcmp(char *str1, char *str2)
{
    int i;
    int total = 0;

    for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            total = str1[i] - str2[i];
            break;
        }
    }
    return total;
}
