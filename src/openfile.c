/*
** EPITECH PROJECT, 2024
** B-PSU-100-MAR-1-1-navy-maxime.finaud
** File description:
** openfile
*/

#include "../includes/my.h"

int openpos(navy_t *navy, char **av)
{
    map_base(navy);
    navy->fp1 = fopen(av[1], "r");
    while (getline(&navy->pos1, &navy->len, navy->fp1) != -1) {
        stock_boatpos1(navy);
        cross_map(navy);
    }
    if (navy->nb_boats != 14)
        return 84;
}

int openpos2(navy_t *navy, char **av)
{
    map_base(navy);
    navy->fp2 = fopen(av[2], "r");
    while (getline(&navy->pos2, &navy->len, navy->fp2) != -1) {
        stock_boatpos2(navy);
        cross_map(navy);
    }
    if (navy->nb_boats != 14)
        return 84;
}

int stock_boatpos1(navy_t *navy)
{
    navy->boat_size = (navy->pos1[0]) - 48;
    navy->boat_size_char = (navy->pos1[0]);
    navy->dep_boat_x = navy->pos1[2];
    navy->dep_boat_y = navy->pos1[3] - 48;
    navy->arr_boat_x = navy->pos1[5];
    navy->arr_boat_y = navy->pos1[6] - 48;
}

int stock_boatpos2(navy_t *navy)
{
    navy->boat_size = (navy->pos2[0]) - 48;
    navy->boat_size_char = (navy->pos2[0]);
    navy->dep_boat_x = navy->pos2[2];
    navy->dep_boat_y = navy->pos2[3] - 48;
    navy->arr_boat_x = navy->pos2[5];
    navy->arr_boat_y = navy->pos2[6] - 48;
}
