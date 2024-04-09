/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-organized-maxime.finaud
** File description:
** my_strdup
*/

#include "../includes/my.h"

char *my_strdup(char *str)
{
    int taille;
    char *str2;
    int i;

    taille = my_strlen(str);
    str2 = malloc(sizeof(char *) * (taille +1));
    for (i = 0; str[i] != '\0'; i++) {
        str2[i] = str[i];
    }
    str2[i] = '\0';
    return str2;
}
