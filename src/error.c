/*
** EPITECH PROJECT, 2024
** B-PSU-100-MAR-1-1-navy-maxime.finaud
** File description:
** error
*/

#include "../includes/my.h"

int error_coordpos1(navy_t *navy, int ac, char **av)
{
    navy->fp1 = fopen(av[1], "r");
    if (!navy->fp1)
        return 84;
    while (getline(&navy->pos1, &navy->len, navy->fp1) != -1) {
        stock_boatpos1(navy);
        if (navy->dep_boat_x != navy->arr_boat_x &&
            navy->dep_boat_y != navy->arr_boat_y)
            return 84;
        if (navy->dep_boat_x == navy->arr_boat_x &&
            navy->boat_size != navy->arr_boat_y - navy->dep_boat_y + 1)
            return 84;
        if (navy->dep_boat_y == navy->arr_boat_y &&
            navy->boat_size != navy->arr_boat_x - navy->dep_boat_x + 1)
            return 84;
        if (error_coord_subpos1(navy, ac, av) == 84)
            return 84;
    }
    fclose(navy->fp1);
    if (openpos(navy, av) == 84)
        return 84;
}

int error_coord_subpos1(navy_t *navy, int ac, char **av)
{
    if (navy->boat_size >= 5 && navy->boat_size <= 1)
        return 84;
    if (navy->dep_boat_y >= 9 && navy->dep_boat_y <= 0)
        return 84;
    if (navy->arr_boat_y >= 9 && navy->arr_boat_y <= 0)
        return 84;
    if (navy->dep_boat_x && navy->dep_boat_y ==
    navy->arr_boat_x && navy->arr_boat_y) {
        return 84;
    }
}

int error_coordpos2(navy_t *navy, int ac, char **av)
{
    navy->fp2 = fopen(av[2], "r");
    if (!navy->fp2)
        return 84;
    while (getline(&navy->pos2, &navy->len, navy->fp2) != -1) {
        stock_boatpos2(navy);
        if (navy->dep_boat_x != navy->arr_boat_x &&
            navy->dep_boat_y != navy->arr_boat_y)
            return 84;
        if (navy->dep_boat_x == navy->arr_boat_x &&
            navy->boat_size != navy->arr_boat_y - navy->dep_boat_y + 1)
            return 84;
        if (navy->dep_boat_y == navy->arr_boat_y &&
            navy->boat_size != navy->arr_boat_x - navy->dep_boat_x + 1)
            return 84;
        if (error_coord_subpos2(navy, ac, av) == 84)
            return 84;
    }
    fclose(navy->fp2);
    if (openpos2(navy, av) == 84)
        return 84;
}

int error_coord_subpos2(navy_t *navy, int ac, char **av)
{
    if (navy->boat_size >= 5 && navy->boat_size <= 1)
        return 84;
    if (navy->dep_boat_y >= 9 && navy->dep_boat_y <= 0)
        return 84;
    if (navy->arr_boat_y >= 9 && navy->arr_boat_y <= 0)
        return 84;
    if (navy->dep_boat_x && navy->dep_boat_y ==
    navy->arr_boat_x && navy->arr_boat_y) {
        return 84;
    }
}
