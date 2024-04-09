/*
** EPITECH PROJECT, 2024
** B-PSU-100-MAR-1-1-navy-maxime.finaud
** File description:
** char_star
*/

#include "../includes/my.h"

int map_base(navy_t *navy)
{
    char **test;

    navy->lon = 8;
    navy->lar = 8;
    test = malloc(sizeof(char *) * (navy->lar));
    test[navy->y] = malloc(sizeof(char *) * (navy->lon));
    navy->letter = " |A B C D E F G H";
    navy->bar = "-+---------------";
    test[0] = my_strdup("........");
    test[1] = my_strdup("........");
    test[2] = my_strdup("........");
    test[3] = my_strdup("........");
    test[4] = my_strdup("........");
    test[5] = my_strdup("........");
    test[6] = my_strdup("........");
    test[7] = my_strdup("........");
    navy->buffer = test;
}

int map_base_empty(navy_t *navy)
{
    char **test;

    navy->lon = 8;
    navy->lar = 9;
    test = malloc(sizeof(char *) * (navy->lar));
    navy->letter = " |A B C D E F G H";
    navy->bar = "-+---------------";
    test[0] = my_strdup("........");
    test[1] = my_strdup("........");
    test[2] = my_strdup("........");
    test[3] = my_strdup("........");
    test[4] = my_strdup("........");
    test[5] = my_strdup("........");
    test[6] = my_strdup("........");
    test[7] = my_strdup("........");
    test[8] = NULL;
    navy->empty_map = test;
}

int print_map(navy_t *navy)
{
    int i = 0;

    navy->yprint = 0;
    i = navy->yprint + 1;
    my_printf("%s\n", navy->letter);
    my_printf("%s\n", navy->bar);
    for (navy->yprint = 0; navy->yprint < navy->lon; navy->yprint++) {
        my_printf("%d|", i++);
        for (navy->xprint = 0; navy->xprint < navy->lar; navy->xprint++) {
            my_printf("%c ", navy->buffer[navy->yprint][navy->xprint]);
        }
        my_putchar('\n');
    }
}

int print_empty_map(navy_t *navy)
{
    int i = 0;

    navy->yprint = 0;
    i = navy->yprint + 1;
    my_printf("%s\n", navy->letter);
    my_printf("%s\n", navy->bar);
    for (navy->yprint = 0; navy->yprint < navy->lon; navy->yprint++) {
        my_printf("%d|", i++);
        for (navy->xprint = 0; navy->xprint < navy->lar; navy->xprint++) {
            my_printf("%c ", navy->empty_map[navy->yprint][navy->xprint]);
        }
        my_putchar('\n');
    }
}
