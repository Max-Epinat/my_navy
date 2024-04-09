/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-organized-maxime.finaud
** File description:
** my
*/

#pragma once

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include "struct.h"

int openpos(navy_t *navy, char **av);
int openpos2(navy_t *navy, char **av);
int stock_boatpos1(navy_t *navy);
int stock_boatpos2(navy_t *navy);
void description(void);
int my_getnbr(char *str);
int true_getnbr(char const *str);
int cross_map(navy_t *navy);
int my_printf(const char *format, ...);
int put_format(char specifier, va_list list);
int my_put_nbr(int nb);
int length(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_compute_power_rec(int nb, int p);
int my_strcmp(char *str1, char *str2);
char *my_strdup(char *str);
int my_strlen(char const *str);
int print_map(navy_t *navy);
int print_empty_map(navy_t *navy);
int fill_map(navy_t *navy);
int map_base(navy_t *navy);
int map_base_empty(navy_t *navy);
int first_term(navy_t *navy, int ac, char **av);
int sec_term(navy_t *navy, int ac, char **av);
int attack_player_1(navy_t *navy, int x[]);
int attack_enemy_1(navy_t *navy, int x[]);
int attack_player_2(navy_t *navy, int x[]);
int attack_enemy_2(navy_t *navy, int x[]);
int error_coord(navy_t *navy, int ac, char **av);
int error_coord2(navy_t *navy, int ac, char **av);
void sleep_time(void);
int sec_term_cond_extra(navy_t *navy);
static int attack_extension(navy_t *navy);
static int attack_extension2(navy_t *navy);
static void print_maps_term_one_updated(navy_t *navy);
void sig_coords1(int sig);
void sig_coords2(int sig);
int error_coord_subpos2(navy_t *navy, int ac, char **av);
int error_coord_subpos1(navy_t *navy, int ac, char **av);
int error_coordpos1(navy_t *navy, int ac, char **av);
int error_coordpos2(navy_t *navy, int ac, char **av);
void sig_coords3(int sig);
int check_win_1(navy_t *navy, int x[]);
int check_lose_1(navy_t *navy, int x[]);
