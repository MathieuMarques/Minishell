/*
** EPITECH PROJECT, 2022
** do_special_cmd.c
** File description:
** do_special_cmd
*/

#include "mysh.h"

int do_special_cmd(char **tab, env_t *env)
{
    if (my_strcmp(tab[0], "cd") == 0)
        return cd_command(tab, env);
    if (my_strcmp(tab[0], "setenv") == 0)
        return handler_setenv(env, tab);
    if (my_strcmp(tab[0], "unsetenv") == 0)
        return my_unsetenv(env, tab);
    if (my_strcmp(tab[0], "env") == 0) {
        display_arr(env->env);
        return 0;
    }
    if (my_strcmp(tab[0], "exit") == 0) {
        return do_exit(tab, env);
    }
    return -1;
}
