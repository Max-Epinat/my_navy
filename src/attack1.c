/*
** EPITECH PROJECT, 2024
** B-PSU-100-MAR-1-1-navy-maxime.finaud
** File description:
** attack1
*/

#include "../includes/my.h"

extern int x[5];

void sig_coords1(int sig)
{
    x[1]++;
}

void sig_coords2(int sig)
{
    x[2]++;
}

void sig_coords3(int sig)
{
    x[3]++;
}

static int attack_extension(navy_t *navy)
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
        check_win_1(navy, x);
}

static int get_attack_coords_1(navy_t *navy)
{
    for (int y = 0; y < navy->attack1[0] - 64; y++) {
        usleep(5);
        if (kill(navy->pid2, SIGUSR1) == 84)
            return 84;
    }
    for (int z = 0; z < navy->attack1[1] - 48; z++) {
        usleep(5);
        if (kill(navy->pid2, SIGUSR2) == 84)
            return 84;
    }
}

int attack_player_1(navy_t *navy, int x[])
{
    size_t len = 2;

    my_printf("\nattack: ");
    getline(&navy->attack1, &len, stdin);
    if (navy->attack1[0] < 'A' || navy->attack1[0] > 'H' ||
        navy->attack1[1] < '1' || navy->attack1[1] > '8' ||
        navy->attack1[3] != '\0') {
        my_printf("wrong position");
        attack_player_1(navy, x);
    } else {
        signal(SIGUSR1, sig_coords3);
        if (get_attack_coords_1(navy) == 84)
            return 84;
        usleep(100000);
        attack_extension(navy);
    }
}

static char *hit_ships_2(navy_t *navy, char *hit, int posy, int posx)
{
    if (navy->buffer[posy][posx] != '.' && navy->buffer[posy][posx] != 'x' &&
        navy->buffer[posy][posx] != 'o') {
        hit = "hit";
        navy->buffer[posy][posx] = 'x';
        x[4]--;
        kill(navy->pid2, SIGUSR1);
    } else {
        hit = "missed";
        if (navy->buffer[posy][posx] != 'x')
            navy->buffer[posy][posx] = 'o';
    }
    return hit;
}

int attack_enemy_2(navy_t *navy, int x[])
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
    hit = hit_ships_2(navy, hit, posy, posx);
    my_printf("\nresult: %c%c:%s\n", 64 + x[1], 48 + x[2], hit);
    check_lose_1(navy, x);
}
