/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-organized-maxime.finaud
** File description:
** my_getnbr
*/

#include "../includes/my.h"

int my_getnbr(char *str)
{
    int i = 0;
    int nb = 0;

    for (; str[i] != ' ' && str[i] != '\n'; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
            nb = (nb * 10) + (str[i] - 48);
        }
    }
    return nb;
}

int true_getnbr(char const *str)
{
    int nb = 0;
    int sign = 1;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            sign = sign * -1;
        }
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - '0';
            i++;
                } else {
            break;
        }
    }
    return (nb * sign);
}
