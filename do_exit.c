/*
** EPITECH PROJECT, 2022
** do_exit.c
** File description:
** do_exit
*/

#include "mysh.h"

void exit_program(char **tab, env_t *env, int value)
{
    free_tab(tab);
    free_env(env);
    my_printf("exit\n");
    exit(value);
}

int error_exit(char **tab)
{
    int nb_args = 0;

    for (nb_args = 0; tab[nb_args] != NULL; nb_args++);
    if (nb_args > 2) {
        my_print_err("exit: Expression Syntax.\n");
        return 84;
    }
    if (nb_args == 1)
        return 0;
    if ((tab[1][0] >= '0' && tab[1][0] <= '9') ||
        tab[1][0] == '-') {
            if (is_number(tab[1]) == 0) {
                my_print_err("exit: Badly formed number.\n");
                return 84;
            }
    } else {
        my_print_err("exit: Expression Syntax.\n");
        return 84;
    }
}

int do_exit(char **tab, env_t *env)
{
    int nb_args = 0;
    int val = 0;

    if (error_exit(tab) == 84)
        return 1;
    for (nb_args = 0; tab[nb_args] != NULL; nb_args++);
    if (nb_args == 1)
        exit_program(tab, env, 0);
    if (nb_args == 2) {
        val = my_getnbr(tab[1]);
        free_tab(tab);
        free_env(env);
        my_printf("exit\n");
        exit(val);
    }
    return 1;
}
