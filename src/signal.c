/*
** EPITECH PROJECT, 2024
** B-PSU-100-MAR-1-1-navy-maxime.finaud
** File description:
** signal
*/

#include "../includes/my.h"

int x[5] = {0};

void signal_handler(int sig)
{
    x[0]++;
}

void signal_multiply(int sig)
{
    x[0] *= 10;
}

static void print_maps_term_one(navy_t *navy)
{
    my_printf("\nenemy connected\n");
    sleep_time();
    usleep(200000);
    my_printf("\nmy navy:\n");
    print_map(navy);
    my_printf("\nenemy navy:\n");
    map_base_empty(navy);
    print_empty_map(navy);
}

static void print_maps_term_two(navy_t *navy)
{
    my_printf("my_pid: %d\n\nsuccessfully connected to enemy\n", navy->pid2);
    usleep(200000);
    my_printf("\nmy navy:\n");
    print_map(navy);
    my_printf("\nenemy navy:\n");
    map_base_empty(navy);
    print_empty_map(navy);
}

int first_term(navy_t *navy, int ac, char **av)
{
    navy->fp1 = fopen(av[1], "r");
    if (!navy->fp1)
        return 84;
    navy->pid1 = getpid();
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_multiply);
    my_printf("my_pid: %d\n\nwaiting for enemy...\n", navy->pid1);
    while (1) {
        navy->pid2 = x[0];
        if (x[0] > navy->pid1)
            break;
        usleep(100000);
    }
    print_maps_term_one(navy);
    navy->pid2 = x[0];
    x[0] = 0;
    x[4] = 14;
    if (attack_player_1(navy, x))
        return 84;
}

static int sec_term_cond(navy_t *navy)
{
    navy->r = length(navy->pid2 - 1);
    while (navy->r > 0 || navy->p != navy->pid2) {
        usleep(50);
        if (sec_term_cond_extra(navy) == 84)
            return 84;
    }
    return 0;
}

int sec_term_cond_extra(navy_t *navy)
{
    if (navy->pid2 / my_compute_power_rec(10, navy->r) == navy->p) {
        if (kill(navy->pid1, SIGUSR2) == -1)
            return 84;
        navy->r--;
        navy->p *= 10;
    } else {
        if (kill(navy->pid1, SIGUSR1) == 84)
            return 84;
        navy->p++;
    }
    return 0;
}

int sec_term(navy_t *navy, int ac, char **av)
{
    navy->fp2 = fopen(av[2], "r");
    if (!navy->fp2)
        return 84;
    navy->pid1 = true_getnbr(av[1]);
    navy->pid2 = getpid();
    if (sec_term_cond(navy) == 84)
        return 84;
    print_maps_term_two(navy);
    x[4] = 14;
    if (attack_enemy_1(navy, x) == 84)
        return 84;
}
