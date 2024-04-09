/*
** EPITECH PROJECT, 2024
** B-PSU-100-MAR-1-1-navy-maxime.finaud
** File description:
** tests.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/my.h"

Test(my_printf, test_printf, .init = cr_redirect_stdout)
{
    char *str = "hello";
    int i = 42;
    int d = -42;

    my_printf("%s, %i, %d, %c, %%\n", str, i, d, 'c');
    cr_assert_stdout_eq_str("hello, 42, -42, c, %\n");
}

Test(length, integers_test, .init = cr_redirect_stdout) {
    char *toInt1 = "42";
    char *toInt2 = "-42";

    cr_assert(length(0) == 1);
    cr_assert(length(435) == 3);
    cr_assert(true_getnbr(toInt1) == 42);
    cr_assert(true_getnbr(toInt2) == -42);
    cr_assert(my_compute_power_rec(10, 3) == 1000);
    cr_assert(my_compute_power_rec(10, 11) == 0);
}

Test(my_strlen, str_test, .init = cr_redirect_stdout)
{
    char *lala1 = "lala";
    char *lala2 = "lala";
    char *lulu = "lulu";

    cr_assert(my_strlen(lulu) == 4);
    cr_assert(my_strcmp(lala1, lala2) == 0);
    cr_assert(my_strcmp(lala1, lulu) != 0);
}

Test(description, test_description, .init = cr_redirect_stdout)
{
    description();
    cr_assert_stdout_eq_str("./navy\n\n"
        "USAGE :\n"
        "\t./navy [first_player_pid] navy_positions\n"
        "DESCRIPTION :\n"
        "\tfirst_player_pid: only for the 2nd player. pid of the"
        "first player.\n\tnavy_positions: file representing the positions of"
        "the ships.\n");
}
