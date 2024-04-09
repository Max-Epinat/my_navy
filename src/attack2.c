/*
** EPITECH PROJECT, 2023
** B-PSU-100-MAR-1-1-navy-maxime.finaud
** File description:
** attack2.c
*/

#include "../includes/my.h"

extern int x[5];

void print_maps_term_two_updated(navy_t *navy)
{
    my_printf("\nmy navy:\n");
    print_map(navy);
    my_printf("\nenemy navy:\n");
    print_empty_map(navy);
    x[0] = 0;
    x[1] = 0;
    x[2] = 0;
    x[3] = 0;
    attack_enemy_1(navy, x);
}

static int get_attack_coords_2(navy_t *navy)
{
    for (int y = 0; y < navy->attack1[0] - 64; y++) {
        usleep(5);
        if (kill(navy->pid1, SIGUSR1) == 84)
            return 84;
    }
    for (int z = 0; z < navy->attack1[1] - 48; z++) {
        usleep(5);
        if (kill(navy->pid1, SIGUSR2) == 84)
            return 84;
    }
}

int attack_player_2(navy_t *navy, int x[])
{
    size_t len = 2;

    my_printf("\nattack: ");
    getline(&navy->attack1, &len, stdin);
    if (navy->attack1[0] < 'A' || navy->attack1[0] > 'H' ||
        navy->attack1[1] < '1' || navy->attack1[1] > '8' ||
        navy->attack1[3] != '\0') {
        my_printf("wrong position");
        attack_player_2(navy, x);
    } else {
        signal(SIGUSR1, sig_coords3);
        if (get_attack_coords_2(navy) == 84)
            return 84;
        usleep(100000);
        attack_extension2(navy);
    }
}

static int check_win_2(navy_t *navy, int x[])
{
    if (x[5] == 14) {
        my_printf("\nmy navy:\n");
        print_map(navy);
        my_printf("\nenemy navy:\n");
        print_empty_map(navy);
        my_printf("\nI won\n");
        return 0;
    } else {
        print_maps_term_two_updated(navy);
    }
}

static int attack_extension2(navy_t *navy)
{
    char *hit = NULL;

    if (x[3] > 0) {
        hit = "hit";
        navy->empty_map[navy->attack1[1] - '1']
        [navy->attack1[0] - 'A'] = 'x';
        x[5]++;
    } else {
        hit = "missed";
        if (navy->empty_map[navy->attack1[1] - '1']
            [navy->attack1[0] - 'A'] != 'x') {
                navy->empty_map[navy->attack1[1] - '1']
                    [navy->attack1[0] - 'A'] = 'o';
            }
    }
    my_printf("\nresult: %c%c:%s\n",
    navy->attack1[0], navy->attack1[1], hit);
    check_win_2(navy, x);
}

static char *hit_ships_1(navy_t *navy, char *hit, int posy, int posx)
{
    if (navy->buffer[posy][posx] != '.' && navy->buffer[posy][posx] != 'x' &&
        navy->buffer[posy][posx] != 'o') {
        hit = "hit";
        navy->buffer[posy][posx] = 'x';
        x[4]--;
        kill(navy->pid1, SIGUSR1);
    } else {
        hit = "missed";
        if (navy->buffer[posy][posx] != 'x')
            navy->buffer[posy][posx] = 'o';
    }
    return hit;
}

static int check_lose_2(navy_t *navy, int x[])
{
    if (x[4] == 0) {
        my_printf("\nmy navy:\n");
        print_map(navy);
        my_printf("\nenemy navy:\n");
        print_empty_map(navy);
        my_printf("\nEnemy won\n");
        return 1;
    } else {
        attack_player_2(navy, x);
    }
}

int attack_enemy_1(navy_t *navy, int x[])
{
    size_t len;
    int posx;
    int posy;
    char *hit = NULL;

    my_printf("\nwaiting for enemy's attack...\n");
    signal(SIGUSR1, sig_coords1);
    signal(SIGUSR2, sig_coords2);
    while (1) {
        if (x[2] > 0)
            break;
        usleep(1000000);
    }
    sleep_time();
    posx = x[1] - 1;
    posy = x[2] - 1;
    hit = hit_ships_1(navy, hit, posy, posx);
    my_printf("\nresult: %c%c:%s\n", 64 + x[1], 48 + x[2], hit);
    check_lose_2(navy, x);
}
