/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** tkt
*/

#include "../includes/my.h"

int length(int nb)
{
    int len = 0;
    int number = nb;

    if (nb == 0) {
        len = 1;
    }
    while (number > 0) {
        len++;
        number = number / 10;
    }
    return len;
}

int my_put_nbr(int nb)
{
    if (nb < 0){
        nb = -nb;
        my_putchar('-');
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}
