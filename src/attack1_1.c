/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-navy-maxime.finaud
** File description:
** attack1_1.c
*/

#include "../includes/my.h"

extern int x[5];

int check_win_1(navy_t *navy, int x[])
{
    if (x[5] == 14) {
        my_printf("\nmy navy:\n");
        print_map(navy);
        my_printf("\nenemy navy:\n");
        print_empty_map(navy);
        my_printf("\nI won\n");
        return 0;
    } else {
        attack_enemy_2(navy, x);
    }
}

int check_lose_1(navy_t *navy, int x[])
{
    if (x[4] == 0) {
        my_printf("\nmy navy:\n");
        print_map(navy);
        my_printf("\nenemy navy:\n");
        print_empty_map(navy);
        my_printf("\nEnemy won\n");
        return 1;
    } else {
        print_maps_term_one_updated(navy);
    }
}

static void print_maps_term_one_updated(navy_t *navy)
{
    my_printf("\nmy navy:\n");
    print_map(navy);
    my_printf("\nenemy navy:\n");
    print_empty_map(navy);
    x[0] = 0;
    x[1] = 0;
    x[2] = 0;
    x[3] = 0;
    attack_player_1(navy, x);
}
