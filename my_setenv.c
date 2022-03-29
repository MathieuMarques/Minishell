/*
** EPITECH PROJECT, 2022
** my_setenv.c
** File description:
** my_setenv
*/

#include "mysh.h"

int is_in_env(char **env, char *name)
{
    int len = my_strlen(name);
    char *str = malloc(len + 2);
    char *cpy;

    my_strcpy(str, name);
    my_strcat(str, "=");
    for (int i = 0; env[i] != NULL; i++) {
        cpy = my_strdup(env[i]);
        if (my_strlen(cpy) > len + 1)
            cpy[len + 1] = '\0';
        if (my_strcmp(cpy, str) == 0) {
            free(cpy);
            free(str);
            return i;
        }
        free(cpy);
    }
    free(str);
    return -1;
}

void my_setenv(env_t *env, char *name, char *value)
{
    int ret = is_in_env(env->env, name);
    int len = my_strlen(name) + 1;
    int len_env = 0;

    if (ret != -1) {
        env->env[ret] = malloc((len + my_strlen(value) + 1) * sizeof(char));
        my_strcpy(env->env[ret], name);
        my_strcat(env->env[ret], "=");
        my_strcat(env->env[ret], value);
    }
    if (ret == -1) {
        env->env = increase_size_arr(env->env);
        for (len_env = 0; env->env[len_env] != NULL; len_env++);
        env->env[len_env] = malloc((len + my_strlen(value) + 1) * sizeof(char));
        my_strcpy(env->env[len_env], name);
        my_strcat(env->env[len_env], "=");
        my_strcat(env->env[len_env], value);
        env->env[len_env + 1] = NULL;
    }
}

int is_error_setenv(char *name)
{
    if (name[0] != '_' &&
        !(name[0] >= 'a' && name[0] <= 'z') &&
        !(name[0] >= 'A' && name[0] <= 'Z'))
        return 2;
    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] != '.' && name[i] != '_' &&
            !(name[i] >= '0' && name[i] <= '9') &&
            !(name[i] >= 'a' && name[i] <= 'z') &&
            !(name[i] >= 'A' && name[i] <= 'Z'))
            return 1;
    }
    return 0;
}

void print_error_setenv(int err)
{
    if (err == 1) {
        my_print_err("setenv: Variable name must contain \
alphanumeric characters.\n");
    }
    if (err == 2) {
        my_print_err("setenv: Variable name must begin with a letter.\n");
    }
}

int handler_setenv(env_t *env, char **tab)
{
    int size_tab = 0;
    for (size_tab = 0; tab[size_tab] != NULL; size_tab++);
    if (size_tab == 1) {
        for (int i = 0; env->env[i] != NULL; i++) {
            my_printf("%s\n", env->env[i]);
        }
        return 0;
    }
    int err = is_error_setenv(tab[1]);
    if (err != 0) {
        print_error_setenv(err);
        return 1;
    } else {
        if (size_tab == 2)
            my_setenv(env, tab[1], "");
        if (size_tab == 3)
            my_setenv(env, tab[1], tab[2]);
        return 0;
    }
}
