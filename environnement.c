/*
** EPITECH PROJECT, 2022
** environnement.c
** File description:
** environnement
*/

#include "mysh.h"

env_t *create_env_t(char **env)
{
    env_t *envi = malloc(sizeof(env_t));

    envi->env = my_arrdup(env);
    return envi;
}

void free_env(env_t *env)
{
    for (int i = 0; env->env[i] != NULL; i++)
        free(env->env[i]);
    free(env->env);
    free(env);
}
