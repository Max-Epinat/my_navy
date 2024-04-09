/*
** EPITECH PROJECT, 2023
** B-CPE-110-MAR-1-1-organized-maxime.finaud
** File description:
** stru
*/

#include "my.h"
#pragma once

typedef struct navy_s {
    size_t len;
    FILE *fp1;
    char *pos1;
    FILE *fp2;
    char *pos2;

    int boat_size;
    char boat_size_char;
    char dep_boat_x;
    int dep_boat_y;
    char arr_boat_x;
    int arr_boat_y;

    char **buffer;
    char **empty_map;
    char *letter;
    char *bar;
    int lar;
    int lon;
    int yprint;
    int xprint;
    int x;
    int y;
    int coordx;
    int coordy;
    int nb_boats;

    pid_t pid1;
    pid_t pid2;
    int cheff;
    char *attack1;
    char *attack2;
    int p;
    int r;

}navy_t;
