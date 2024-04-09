/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** an recursive function that returns the first argument
** raised to the power p, where p is the second argument
*/

#include "../includes/my.h"

int my_compute_power_rec(int nb, int p)
{
    if ((p > 0) && (p <= 9)) {
        return nb * my_compute_power_rec(nb, p - 1);
    } else if (p < 0 || p > 9) {
        return 0;
    } else {
        return 1;
    }
}
