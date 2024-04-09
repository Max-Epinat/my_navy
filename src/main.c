/*
** EPITECH PROJECT, 2024
** B-PSU-100-MAR-1-1-navy-maxime.finaud
** File description:
** main
*/

#include "../includes/my.h"

int main(int ac, char **av)
{
    navy_t navy = {0};

    if (ac == 1 || ac > 3)
        return 84;
    if (ac == 2) {
        if (my_strcmp(av[1], "-h") == 0) {
            description();
            return 0;
        }
        if (error_coordpos1(&navy, ac, av) == 84)
            return 84;
        if (first_term(&navy, ac, av) == 84)
            return 84;
    } else {
        if (error_coordpos2(&navy, ac, av) == 84)
            return 84;
        if (sec_term(&navy, ac, av) == 84)
            return 84;
    }
}
