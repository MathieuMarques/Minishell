/*
** EPITECH PROJECT, 2022
** my_unsetenv.c
** File description:
** my_unsetenv
*/

#include "mysh.h"

void remove_var_env(env_t *env, int pos_env)
{
    int i = 0;

    for (i = pos_env; env->env[i] != NULL; i++) {
        env->env[i] = env->env[i + 1];
    }
    env->env[i] = NULL;
}

int my_unsetenv(env_t *env, char **tab)
{
    int size_tab = 0;
    int pos_env = 0;

    for (size_tab = 0; tab[size_tab] != NULL; size_tab++);
    if (size_tab < 2) {
        my_print_err("unsetenv: Too few arguments.\n");
        return 1;
    }
    for (int i = 1; tab[i] != NULL; i++) {
        pos_env = is_in_env(env->env, tab[i]);
        if (pos_env != -1)
            remove_var_env(env, pos_env);
    }
    return 0;
}
