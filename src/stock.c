/*
** EPITECH PROJECT, 2024
** B-PSU-100-MAR-1-1-navy-maxime.finaud
** File description:
** stock
*/

#include "../includes/my.h"

void sleep_time(void)
{
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
}

int only_down(navy_t *navy)
{
    if (navy->dep_boat_y < navy->arr_boat_y) {
        navy->coordy++;
        if (navy->buffer[navy->coordy][navy->dep_boat_x - 'A'] == '.')
            navy->nb_boats++;
        navy->buffer[navy->coordy][navy->dep_boat_x - 'A']
        = navy->boat_size_char;
        navy->boat_size--;
    }
    if (navy->dep_boat_y > navy->arr_boat_y) {
        navy->buffer[navy->coordy][navy->dep_boat_x - 'A']
        = navy->boat_size_char;
    }
}

int only_right(navy_t *navy)
{
    if (navy->dep_boat_x < navy->arr_boat_x) {
        navy->dep_boat_x++;
        if (navy->buffer[navy->coordy][navy->dep_boat_x - 'A'] == '.')
            navy->nb_boats++;
        navy->buffer[navy->coordy][navy->dep_boat_x - 'A']
        = navy->boat_size_char;
        navy->boat_size--;
    }
}

int fill_map(navy_t *navy)
{
    if (navy->boat_size > 0) {
        navy->coordy += navy->dep_boat_y - 1;
        if (navy->buffer[navy->coordy][navy->dep_boat_x - 'A'] == '.')
            navy->nb_boats++;
        navy->buffer[navy->coordy][navy->dep_boat_x - 'A']
        = navy->boat_size_char;
        navy->boat_size--;
        while (navy->dep_boat_x == navy->arr_boat_x && navy->boat_size > 0) {
            only_down(navy);
        }
        while (navy->dep_boat_x != navy->arr_boat_x && navy->boat_size > 0) {
            only_right(navy);
        }
    }
}

int cross_map(navy_t *navy)
{
    for (navy->y = 0; navy->y < navy->lon; navy->y++) {
        for (navy->x = 0; navy->x < navy->lar; navy->x++) {
            navy->coordx = navy->x;
            navy->coordy = navy->y;
            fill_map(navy);
        }
    }
}
